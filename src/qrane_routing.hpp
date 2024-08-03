#include "qrane_graph.hpp"
#include "qrane_parser.h"
#include "qrane_program.hpp"

#define QISKIT_LAYOUT_METHOD "\"sabre\""
#define QISKIT_ROUTING_METHOD "\"sabre\""
#define QISKIT_OPTIMIZATION_LEVEL "0"
#define TKET_LAYOUT_METHOD "GraphPlacement"

extern yy::qrane_parser::symbol_type yylex();
extern FILE *yyin;

typedef std::pair<qrane_reg, qrane_qop> state;

// Circuit, (initial_mapping, final_mapping)
typedef std::pair<std::shared_ptr<qrane_program>,
                  std::pair<qrane_reg, qrane_reg>>
    qrane_routing_result;

class qrane_routing {

public:
  qrane_routing(qrane_graph<qop_id> dependences, std::string coupling_file);

  qrane_statementlist reconcile_mappings(qrane_reg init, qrane_reg goal);
  qrane_routing_result
  export_to_qiskit(std::shared_ptr<qrane_program> subcircuit,
                   qrane_options *opt);
  qrane_routing_result export_to_tket(std::shared_ptr<qrane_program> subcircuit,
                                      qrane_options *opt);

  bool simulate_circuit_execution(qrane_statementlist qops,
                                  qrane_reg initial_mapping);

private:
  qrane_graph<qop_id> dependences;
  qrane_graph<qubit_id> coupling;

  class state {
  public:
    qrane_reg reg;
    std::shared_ptr<qrane_qop> swap;
    std::shared_ptr<state> pred;
    unsigned int depth;
    state(qrane_reg reg, std::shared_ptr<qrane_qop> swap,
          std::shared_ptr<state> pred, unsigned int depth);
    bool operator==(const state &rhs) const;
  };

  class state_hasher {
  public:
    std::size_t operator()(const state &s) const;
  };

  class reg_hasher {
  public:
    std::size_t operator()(const qrane_reg &s) const;
  };

  class state_comparator {
  private:
    std::shared_ptr<qrane_graph<qubit_id>> coupling;
    std::shared_ptr<qrane_reg> goal;
    std::unordered_map<qrane_reg, float, reg_hasher> score_table;

  public:
    state_comparator(std::shared_ptr<qrane_graph<qubit_id>> coupling,
                     std::shared_ptr<qrane_reg> goal);

    float score_state(const state &s) const;
    bool operator()(const state &a, const state &b) const;
  };

  qrane_statementlist generate_swap_sequence(state &s);
  qrane_statementlist concurrent_swaps_over_register_subset(qrane_reg subset);
  qrane_statementlist all_swaps_on_coupling_graph();
  qrane_reg register_subset_accessed_by_qops(qrane_statementlist qops);
};