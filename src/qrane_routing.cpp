
#include "qrane_routing.hpp"
#include "Python.h"
#include "omp.h"
#include <fstream>
#include <limits>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <unordered_set>

qrane_routing::qrane_routing(qrane_graph<qop_id> dependences,
                             std::string coupling_file) {
  this->dependences = dependences;
  this->coupling =
      qrane_graph<qubit_id>::read_from_edge_list_file(coupling_file, false);
};

qrane_routing::state::state(qrane_reg reg, std::shared_ptr<qrane_qop> swap,
                            std::shared_ptr<state> pred, unsigned int depth) {
  this->reg = reg;
  this->swap = swap;
  this->pred = pred;
  this->depth = depth;
};

bool qrane_routing::state::operator==(const state &rhs) const {
  bool c0 = this->reg == rhs.reg;
  bool c1 = this->swap == rhs.swap;
  return c0 && c1;
};

std::size_t qrane_routing::state_hasher::operator()(const state &s) const {
  std::size_t val = 0;
  std::hash<qubit_id> hasher;
  for (const auto &n : s.reg) {
    val ^= hasher(n.second) + 0x9e3779b9 + (val << 6) + (val >> 2);
  }
  val ^= hasher(s.swap->arg(0)->get_index()) + 0x9e3779b9 + (val << 6) +
         (val >> 2);
  val ^= hasher(s.swap->arg(1)->get_index()) + 0x9e3779b9 + (val << 6) +
         (val >> 2);
  return val;
};

std::size_t qrane_routing::reg_hasher::operator()(const qrane_reg &r) const {
  std::size_t val = 0;
  std::hash<qubit_id> hasher;
  for (const auto &n : r) {
    val ^= hasher(n.first + n.second) + 0x9e3779b9 + (val << 6) + (val >> 2);
  }
  return val;
};

qrane_routing::state_comparator::state_comparator(
    std::shared_ptr<qrane_graph<qubit_id>> coupling,
    std::shared_ptr<qrane_reg> goal) {
  this->coupling = coupling;
  this->goal = goal;
  this->score_table = std::unordered_map<qrane_reg, float, reg_hasher>();
};

/*
    This function scores a given state via a function
    of the form: f(s) = g(s) + h(s), where:

    g(s) = depth of state s in the search tree
    h(s) = sum of the shortest path from each (q in s, p in goal)
           pair after the application of the accompanying SWAP
           on the register; the sum is then divided by two.
*/
float qrane_routing::state_comparator::score_state(const state &s) const {
  float g, h = 0.0;

  // if (score_table.count(s.reg)) {
  // h = score_table.at(s.reg);
  //} else {
  for (const auto &qubit : s.reg) {
    unsigned int len = this->coupling->unweighted_shortest_path_length(
        qubit.first, this->goal->at(qubit.first));
    h += len;
  }
  //    score_table.insert(std::make_pair(s.reg, h));
  //}

  // h /= 2; // This makes it admissible
  g = s.depth;
  return g + h;
};

bool qrane_routing::state_comparator::operator()(const state &a,
                                                 const state &b) const {
  return score_state(a) > score_state(b);
};

qrane_statementlist qrane_routing::generate_swap_sequence(state &s) {
  auto swaps = qrane_statementlist();
  while (s.pred != NULL) {
    swaps.append(std::static_pointer_cast<qrane_statement>(s.swap));
    s = *s.pred;
  }
  swaps.reverse();
  return swaps;
};

/*
    Utilize A* search to find the optimal sequence of swaps
    to transform qubit mapping "init" into mapping "goal".
    This is called the "token-swapping" problem.

    https://si2.epfl.ch/~demichel/publications/archive/2020/ISMVL_bruno.pdf
*/
qrane_statementlist qrane_routing::reconcile_mappings(qrane_reg init,
                                                      qrane_reg goal) {
  qrane_routing::state_comparator comp(
      std::make_shared<qrane_graph<qubit_id>>(coupling),
      std::make_shared<qrane_reg>(goal));
  std::priority_queue<state, std::vector<state>,
                      qrane_routing::state_comparator>
      traversal(comp);
  qrane_statementlist swaps = all_swaps_on_coupling_graph();
  auto explored = std::unordered_set<state, state_hasher>();

  traversal.push(state(
      init, qrane_qop::make_unassigned_2Q_gate("SWAP", "q", -1, -1), NULL, 0));

  init.print_current_mapping();
  goal.print_current_mapping();

  while (!traversal.empty()) {
    state top = traversal.top();
    traversal.pop();

    if (explored.count(top)) {
      continue;
    }

    if (top.reg == goal) {
      return generate_swap_sequence(top);
    }

    for (auto &swap : swaps) {
      auto swap_qop = std::dynamic_pointer_cast<qrane_qop>(swap);
      qrane_reg new_reg = top.reg;
      new_reg.permute_register(swap_qop);
      state z =
          state(new_reg, swap_qop, std::make_shared<state>(top), top.depth + 1);
      traversal.push(z);
    }
    explored.insert(top);
  }
  return qrane_statementlist();
};

/*
    This function generates a SWAP over each edge
    in the coupling graph that has at least one end
    in the set of qubits in "subset". Thus, if "subset"
    represents the entire qubit register, this function
    returns one SWAP per edge in coupling.
*/
qrane_statementlist
qrane_routing::concurrent_swaps_over_register_subset(qrane_reg subset) {
  qrane_statementlist swaps = qrane_statementlist();
  for (const auto &qubit : subset) {
    for (const auto &neighbor : this->coupling.get_neighbors(qubit.first)) {
      auto swap = qrane_qop::make_unassigned_2Q_gate("SWAP", subset.get_name(),
                                                     qubit.first, neighbor);
      swaps.append(swap);
    }
  }
  return swaps;
};

qrane_statementlist qrane_routing::all_swaps_on_coupling_graph() {
  qrane_statementlist swaps = qrane_statementlist();
  std::set<std::pair<qubit_id, qubit_id>> seen;
  for (const auto &entry : this->coupling) {
    for (const auto &neighbor : entry.second) {
      auto pair0 = std::make_pair(entry.first, neighbor);
      auto pair1 = std::make_pair(neighbor, entry.first);
      if (seen.count(pair0) || seen.count(pair1)) {
        continue;
      }
      auto swap = qrane_qop::make_unassigned_2Q_gate("SWAP", "qreg",
                                                     entry.first, neighbor);
      swaps.append(swap);
      seen.insert(pair0);
      seen.insert(pair1);
    }
  }
  return swaps;
};

qrane_reg
qrane_routing::register_subset_accessed_by_qops(qrane_statementlist qops) {
  qrane_reg subset =
      qrane_reg(statement_type::REG, reg_type::QREG, "qreg", "q");
  for (const auto &statement : qops) {
    auto qop = std::dynamic_pointer_cast<qrane_qop>(statement);
    for (const auto &arg : qop->get_arguments()) {
      subset.insert(arg->get_index());
    }
  }
  return subset;
};

/*
qrane_routing_result qrane_routing::export_to_qiskit(
    std::shared_ptr<qrane_program> subcircuit, qrane_options* opt) {
    std::string qasm_str = subcircuit->get_qasm_string();
    std::string coupling_str = this->coupling.to_python_tuple_list();
    std::string result_path = "./scripts/routed.qasm";
    std::string mapping_path = "./scripts/mapping.txt";

    std::ostringstream strm;
    strm << "import qiskit" << std::endl; strm << "from qiskit import
QuantumCircuit, execute, BasicAer"                        << std::endl; strm <<
"from qiskit.compiler import transpile"                                       <<
std::endl; strm << "import warnings" << std::endl; strm <<
"warnings.filterwarnings(\"ignore\", category=DeprecationWarning)"            <<
std::endl; strm << "backend = BasicAer.get_backend('qasm_simulator')" <<
std::endl; strm << "original = QuantumCircuit.from_qasm_str(\"\"\"" << qasm_str
<< "\"\"\")"     << std::endl; strm << "routed = transpile(" << std::endl; strm
<< "    circuits = original," << std::endl; strm << "    coupling_map = " <<
coupling_str << ","                                  << std::endl; strm << "
layout_method = " << QISKIT_LAYOUT_METHOD << ","                         <<
std::endl; strm << "    routing_method = " << QISKIT_ROUTING_METHOD << "," <<
std::endl; strm << "    optimization_level = " << QISKIT_OPTIMIZATION_LEVEL <<
")"               << std::endl; strm << "routed.qasm(filename = \"" <<
result_path << "\")"                           << std::endl; strm << "mapping =
routed._layout.get_physical_bits()"                                << std::endl;
    strm << "q, l = \'\', \'\'" << std::endl; strm << "with open(\"" <<
mapping_path << "\", \'w\') as f:"                          << std::endl; strm
<< "    for v in sorted(mapping):" << std::endl; strm << "        q = str(v)" <<
std::endl; strm << "        if (mapping[v].register.name == \'ancilla\'): l = q"
<< std::endl; strm << "        else: l = str(mapping[v].index)" << std::endl;
    strm << "        f.write(\"{} {}\\n\".format(q, l))" << std::endl;

        PyRun_SimpleString(strm.str().c_str());

    auto routed = std::make_shared<qrane_program>(opt);
    FILE* qasm = fopen(result_path.c_str(), "r");
        yyin = qasm;
        yy::qrane_parser main_parser(routed);
        int result = main_parser();
        fclose(yyin);

    qrane_reg initial = qrane_reg::trivial_layout(routed->qreg_size);
    qrane_reg final = qrane_reg::read_from_edge_list_file(mapping_path);

        return qrane_routing_result(routed, std::make_pair(initial, final));
};
*/

qrane_routing_result
qrane_routing::export_to_tket(std::shared_ptr<qrane_program> subcircuit,
                              qrane_options *opt) {
  std::string qasm_str = subcircuit->get_qasm_string();
  std::string coupling_str = this->coupling.to_python_tuple_list();
  std::string result_path = "./scripts/routed.qasm";
  std::string initial_path = "./scripts/initial.txt";
  std::string final_path = "./scripts/final.txt";

  std::ostringstream strm;
  strm << "import pytket" << std::endl;
  strm << "from pytket.routing import Architecture, " << TKET_LAYOUT_METHOD
       << std::endl;
  strm << "from pytket.passes import PlacementPass, RoutingPass" << std::endl;
  strm << "from pytket.qasm import circuit_from_qasm_str, circuit_to_qasm"
       << std::endl;
  strm << "from pytket.predicates import CompilationUnit" << std::endl;
  strm << "arch = Architecture(" << coupling_str << ")" << std::endl;
  strm << "place = PlacementPass(" << TKET_LAYOUT_METHOD << "(arch))"
       << std::endl;
  strm << "route = RoutingPass(arch, bridge_lookahead=0, bridge_interactions=0)"
       << std::endl;
  strm << "circuit = circuit_from_qasm_str(\"\"\"" << qasm_str << "\"\"\")"
       << std::endl;
  strm << "comp = CompilationUnit(circuit)" << std::endl;
  strm << "place.apply(comp)" << std::endl;
  strm << "route.apply(comp)" << std::endl;
  strm << "circuit_to_qasm(comp.circuit, \"" << result_path << "\")"
       << std::endl;
  strm << "q, l = '', ''" << std::endl;
  strm << "with open(\"" << initial_path << "\", 'w') as f:" << std::endl;
  strm << "    for v in sorted(comp.initial_map):" << std::endl;
  strm << "        l = str(v.index).strip('[]')" << std::endl;
  strm << "        q = str(comp.initial_map[v].index).strip('[]')" << std::endl;
  strm << "        f.write(\"{} {}\\n\".format(q, l))" << std::endl;
  strm << "with open(\"" << final_path << "\", 'w') as f:" << std::endl;
  strm << "    for v in sorted(comp.final_map):" << std::endl;
  strm << "        l = str(v.index).strip('[]')" << std::endl;
  strm << "        q = str(comp.final_map[v].index).strip('[]')" << std::endl;
  strm << "        f.write(\"{} {}\\n\".format(q, l))" << std::endl;

  PyRun_SimpleString(strm.str().c_str());

  auto routed = std::make_shared<qrane_program>(opt);
  FILE *qasm = fopen(result_path.c_str(), "r");
  yyin = qasm;
  yy::qrane_parser main_parser(routed);
  int result = main_parser();
  fclose(yyin);

  std::cout << routed->get_qasm_string();

  qrane_reg initial = qrane_reg::read_from_edge_list_file(initial_path);
  qrane_reg final = qrane_reg::read_from_edge_list_file(final_path);

  return qrane_routing_result(routed, std::make_pair(initial, final));
};

bool qrane_routing::simulate_circuit_execution(qrane_statementlist qops,
                                               qrane_reg initial_mapping) {
  auto execute = qops.get_statements_in_queue();
  auto reg = initial_mapping;

  std::shared_ptr<qrane_qop> qop;
  bool valid;
  while (!execute.empty()) {
    qop = std::dynamic_pointer_cast<qrane_qop>(execute.front());

    // If qop is a 2Q gate
    if (qop->is_2Q_gate()) {

      // If it is a swap, permute the register
      if (qop->get_operation() == "SWAP") {
        reg.permute_register(qop);

        // If it is a normal 2Q gate, check if it is valid
      } else {
        valid = this->coupling.contains_edge(qop->arg(0)->get_index(),
                                             qop->arg(1)->get_index());
        if (!valid) {
          return false;
        }
      }
    }
    execute.pop();
  }
  return true;
};