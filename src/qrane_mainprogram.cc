/*
Qrane
Filename: qrane_mainprogram.cc
Creation date: June 28, 2020
Copyright (C) 2020

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "qrane_mainprogram.hh"
#include "math.h"
#include "omp.h"
#include "qrane_codegen.hh"
#include "qrane_ctr.hh"
#include "stdlib.h"
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <random>
#include <regex>
#include <sstream>
#include <string.h>

/*
  Default constructor. Initialize isl context and the AST.
*/
qrane_mainprogram::qrane_mainprogram() {
  ctx = isl_ctx_alloc();
  scop = new t_qrane_scop();
  stmtlist = nullptr;
  num_points = 0;
  num_qops = -1;
  num_qubit_exprs = 0;
  qreg_seen = false;
};

qrane_mainprogram::qrane_mainprogram(const qrane_options *opt) {
  ctx = isl_ctx_alloc();
  scop = new t_qrane_scop();
  this->opt = opt;
  stmtlist = nullptr;
  num_points = 0;
  num_qops = -1;
  num_qubit_exprs = 0;
  qreg_seen = false;
};

/*
  Default destructor. Free the isl context.
*/
qrane_mainprogram::~qrane_mainprogram() {
  // delete scop;
  // isl_printer_free(printer);
  // isl_ctx_free(ctx);
};

/*
  Retrieve the stmtlist for debugging purposes.
*/
qrane_stmtlist *qrane_mainprogram::get_stmtlist() { return this->stmtlist; };

std::vector<qrane_statement *> qrane_mainprogram::get_1Q_gates() {
  return this->stmtlist->get_1Q_gates();
};

std::vector<qrane_statement *> qrane_mainprogram::get_2Q_gates() {
  return this->stmtlist->get_2Q_gates();
};

unsigned int qrane_mainprogram::get_num_qops() { return this->num_qops; };

unsigned int qrane_mainprogram::get_num_domains() {
  assert(!scop->final_domain_list.empty());
  return scop->final_domain_list.size();
};

void qrane_mainprogram::set_unchanged_domains(std::vector<qrane_domain> doms) {
  this->unchanged_domains = doms;
};

qrane_deps qrane_mainprogram::get_deps() { return this->deps; };

void qrane_mainprogram::set_deps(qrane_deps deps) { this->deps = deps; };

time_dependence_graph qrane_mainprogram::get_ddg() { return this->deps.ddg; };

void qrane_mainprogram::set_ddg(time_dependence_graph ddg) {
  this->deps.ddg = ddg;
};

void qrane_mainprogram::set_membership(membership_map membership) {
  this->deps.membership = membership;
};

unsigned long long qrane_mainprogram::get_num_points() {
  assert(!scop->final_domain_list.empty());
  if (num_points == 0) {
    compute_num_points();
  }
  return num_points;
}

void qrane_mainprogram::compute_num_points() {
  assert(!scop->final_domain_list.empty());
  for (const auto &dom : scop->final_domain_list) {
    this->num_points += dom.stmt_count;
  }
};

unsigned int qrane_mainprogram::get_time_min() const {
  const membership_map &membership = deps.get_membership();
  unsigned int min = std::numeric_limits<unsigned int>::max();
  for (const auto &entry : membership) {
    if (entry.first < min) {
      min = entry.first;
    }
  }
  return min;
};

unsigned int qrane_mainprogram::get_time_max() const {
  const membership_map &membership = deps.get_membership();
  unsigned int max = std::numeric_limits<unsigned int>::min();
  for (const auto &entry : membership) {
    if (entry.first > max) {
      max = entry.first;
    }
  }
  return max;
};

void qrane_mainprogram::increment_num_qops() { this->num_qops += 1; }

void qrane_mainprogram::set_subcircuit_num(unsigned int num) {
  this->subcircuit_num = num;
}

void qrane_mainprogram::set_substrs(std::vector<qrane_stmtlist *> stmts) {
  this->substrs = stmts;
}

void qrane_mainprogram::set_num_qops(unsigned int num_qops) {
  this->num_qops = num_qops;
}

unsigned long long qrane_mainprogram::get_num_qubit_exprs() {
  return this->num_qubit_exprs;
}

bool qrane_mainprogram::check_all_qops_accounted() {
  compute_num_points();
  if (opt->chunk > 1 || opt->substr) {
    this->num_qops += 1;
  }
  std::cout << "num_qops: " << this->num_qops << ", "
            << "num_points: " << this->num_points << std::endl;
  return this->num_qops == this->num_points;
};

t_qrane_scop *qrane_mainprogram::get_scop() { return this->scop; }

bool vec_size_compare(const std::vector<unsigned int> &a,
                      const std::vector<unsigned int> &b) {
  return a.size() < b.size();
};

bool id_vec_size_compare(
    const std::pair<std::string, std::vector<unsigned int>> &a,
    const std::pair<std::string, std::vector<unsigned int>> &b) {
  return a.second.size() < b.second.size();
};

bool rg_compare(const std::pair<std::pair<unsigned int, float>,
                                std::deque<unsigned int>> &a,
                const std::pair<std::pair<unsigned int, float>,
                                std::deque<unsigned int>> &b) {
  return a.second.size() < b.second.size();
}

void qrane_mainprogram::set_scop(t_qrane_scop *new_scop) {
  this->scop = new_scop;
  this->deps.membership = scop->membership;
}

/*
    Add the provided stmtlist to this object. If the stmtlist contains
  no qrane_statements of statement_type::QOP, then we exit the program.
  Otherwise, program proceeds to parse the stmtlist to build the
  qrane_domain objects that partition the qops into distinct groups.

  Params:
    stmtlist: qrane_stmtlist object that holds all statements in the file.
  Return:
    none
*/
void qrane_mainprogram::add_stmtlist(qrane_stmtlist *stmtlist) {
  this->stmtlist = stmtlist;
  if (this->stmtlist->get_qops().empty()) {
    std::cout << "No qops to work with." << std::endl;
    exit(1);
  }
  // num_qops = this->stmtlist->get_qops().size();
};

void qrane_mainprogram::parse_domains() {

  // Started counting at -1, so increment here so num_qops represents max
  // of range 0, (n-1)
  num_qops += 1;

  this->deps = qrane_deps(this->stmtlist->get_qops());

  if (!opt->quiet) {
    std::cout << "Converting statements to qrane tuples ... ";
  }
  convert_stmtlist_to_vector_form();
  if (!opt->quiet) {
    std::cout << " Done.\n";
  }

  if (!opt->quiet) {
    std::cout << "Constructing domains of one dimension ... ";
  }
  if (opt->process_mode == PROCESS_DDG) {
    process_ddg();
  } else {
    process_circuit();
  }
  if (!opt->quiet) {
    std::cout << " Done.\n";
  }

  if (!opt->quiet) {
    std::cout << "Attempting iterative merging of lower dimension domains to "
                 "higher dimension domains ... ";
  }
  combine_domains();
  if (!opt->quiet) {
    std::cout << " Done.\n";
  }

  // Solve all domain access relations
  for (auto &dom : unchanged_domains) {
    dom.back_substitution(ctx);
    // this->num_points += dom.stmt_count;
  }
};

void qrane_mainprogram::build_dependence_graph() {
  std::vector<qrane_statement *> qops = stmtlist->get_qops();
  qrane_qop *qop;

  for (std::size_t i = 0; i < qops.size(); ++i) {
    qop = (qrane_qop *)qops[i];
    add_dependence_vertex(qop);
  }
}

void qrane_mainprogram::convert_vector_form_to_plinko_grid() {
  for (std::size_t i = 0; i < qreg_size; ++i) {
    circuit.push_back(std::deque<unsigned int>());
  }
  std::size_t i;
  for (auto &elem : qops_list) {
    unsigned int global = std::get<QOP_NUM_GLOBAL>(elem.second);
    auto args = std::get<ARGS>(elem.second);

    for (i = 0; i < args.size(); ++i) {
      circuit[args[i]].push_back(global);
    }
  };
};

bool circuit_is_empty(plinko_grid &circ) {
  for (std::size_t i = 0; i < circ.size(); ++i) {
    if (circ[i].size() > 0) {
      return false;
    }
  }
  return true;
};

std::vector<unsigned int>
qrane_mainprogram::get_ones_from_level(std::vector<unsigned int> &level) {
  std::vector<unsigned int> ones;
  for (std::size_t i = 0; i < level.size(); ++i) {
    if (std::get<ARGS>(qops_list[level[i]]).size() == 1) {
      ones.push_back(level[i]);
    }
  }
  return ones;
};

std::vector<unsigned int>
qrane_mainprogram::get_twos_from_level(std::vector<unsigned int> &level) {
  std::vector<unsigned int> seen = std::vector<unsigned int>();
  std::vector<unsigned int> twos;
  for (std::size_t i = 0; i < level.size(); ++i) {
    std::vector<int> args = std::get<ARGS>(qops_list[level[i]]);
    if (args.size() == 2 &&
        std::find(seen.begin(), seen.end(), level[i]) == seen.end()) {
      twos.push_back(level[i]);
      seen.push_back(level[i]);
    }
  }
  return twos;
};

void qrane_mainprogram::create_fresh_domain(isl_ctx *ctx,
                                            std::vector<unsigned int> &path) {
  // Construct the domain object
  std::string gate_id = std::get<GATE_TYPE>(qops_list[path[0]]);
  unsigned int args = std::get<ARGS>(qops_list[path[0]]).size();
  qrane_domain dom =
      qrane_domain(ctx, num_domains, gate_id, args, this->qops_list, path);
  this->domain_map[num_domains] = dom;
  this->deps.update_membership_graph_1D_phase(path, num_domains);
  this->deps.decrement_in_degrees_of_path_neighbors(path);
  num_domains += 1;
};

// CIRCUIT with ITERATIVE BUILDING
void qrane_mainprogram::process_circuit() {
  if (!opt->quiet) {
    std::cout << "Building circuit form ... " << std::flush;
  }
  convert_vector_form_to_plinko_grid();
  if (!opt->quiet) {
    std::cout << " Done.\n" << std::flush;
  }

  std::vector<std::vector<unsigned int>> all_paths;
  std::vector<unsigned int> chosen_path;
  std::vector<bool> grouped = std::vector<bool>(num_qops, false);
  unsigned int points_processed = 0;

  // Do the processing
  while (points_processed != num_qops) {
    std::vector<unsigned int> frontier =
        get_next_grid_row(circuit, grouped, qreg_size);
    if (frontier.empty()) {
      break;
    }

    chosen_path = one_qubit_clearing_policy(frontier);
    // chosen_path = look_ahead_policy(frontier, opt->breadth_limit);

#pragma omp critical
    create_fresh_domain(ctx, chosen_path);

    for (unsigned int val : chosen_path) {
      grouped[val] = true;
    }

    points_processed += chosen_path.size();
  }
};

// DEPENDENCE GRAPH with ITERATIVE BUILDING
void qrane_mainprogram::process_ddg() {
  deps.initialize_frontier_processing();
  std::vector<std::vector<unsigned int>> all_paths;
  std::vector<unsigned int> chosen_path;
  unsigned int points_processed = 0;
  std::cout << std::endl;

  // Do the processing
  while (points_processed != num_qops) {
    std::vector<unsigned int> frontier = deps.get_dependence_frontier();
    if (frontier.empty()) {
      break;
    }

    std::cout << "Frontr: ";
    for (auto val : frontier) {
      std::cout << val << " ";
    }
    std::cout << std::endl;

    chosen_path = one_qubit_clearing_policy(frontier);
    // chosen_path = look_ahead_policy(frontier, opt->breadth_limit);

    std::cout << "Chosen: ";
    for (auto val : chosen_path) {
      std::cout << val << " ";
    }
    std::cout << std::endl;

// Create the new domain and store it in the domain_map
#pragma omp critical
    create_fresh_domain(ctx, chosen_path);

    points_processed += chosen_path.size();
  }
};

std::vector<unsigned int>
qrane_mainprogram::one_qubit_clearing_policy(std::vector<unsigned int> &level) {
  std::vector<unsigned int> ones = get_ones_from_level(level);
  std::vector<unsigned int> twos = get_twos_from_level(level);
  if (!ones.empty()) {
    return find_longest_ones_path(ones, qreg_size);
  } else {
    return find_longest_twos_path(twos, qreg_size);
  }
};

std::vector<unsigned int>
qrane_mainprogram::look_ahead_policy(std::vector<unsigned int> &level,
                                     unsigned int depth) {
  std::vector<unsigned int> ones = get_ones_from_level(level);
  std::vector<unsigned int> twos = get_twos_from_level(level);
  if (depth == 0) {
    if (ones.size() > twos.size()) {
      return find_longest_ones_path(ones, qreg_size);
    } else if (ones.size() < twos.size()) {
      return find_longest_twos_path(twos, qreg_size);
    } else {
      return find_longest_ones_path(twos, qreg_size);
    }
  }
  std::array<unsigned int, 2> forecast =
      deps.dependence_graph_lookahead_breadth(level, depth, num_qops,
                                              qops_list);
  if (twos.empty()) {
    return find_longest_ones_path(ones, qreg_size);
  } else if (ones.empty()) {
    return find_longest_twos_path(twos, qreg_size);
  } else {
    if (forecast[0] < forecast[1]) {
      return find_longest_ones_path(ones, qreg_size);
    } else if (forecast[0] > forecast[1]) {
      return find_longest_twos_path(twos, qreg_size);
    } else {
      return find_longest_ones_path(ones, qreg_size);
    }
  }
};

/*
        Notes:
        - What to do if we pull a level (ones or twos) and we have several
   different gate types?
                -- 1. Create temporary gate_type -> uint map for each type in
   the level
           2. Find longest path for each gate type
                   3. Return the longest one
*/
std::vector<unsigned int>
qrane_mainprogram::find_longest_ones_path(std::vector<unsigned int> &ones,
                                          std::size_t qreg_size) {

  // Get the points of the most frequently occurring gate type on this level
  std::vector<unsigned int> freq_gate_points =
      get_most_frequent_gate_type(ones);

  // Find the longest path and store it
  stride_graph sg = generate_stride_graph(freq_gate_points, qreg_size, 0);
  std::vector<unsigned int> ordering =
      qrane_utils::adj_list_topological_ordering(sg);
  std::vector<unsigned int> longest_path =
      longest_valid_path_search(sg, ordering);

  return longest_path;
};

std::vector<unsigned int>
qrane_mainprogram::find_longest_twos_path(std::vector<unsigned int> &twos,
                                          std::size_t qreg_size) {

  // Get the points of the most frequently occurring gate type on this level
  std::vector<unsigned int> freq_gate_points =
      get_most_frequent_gate_type(twos);

  ray_graph rg = generate_ray_graph(freq_gate_points, qreg_size);
  // while (true) {
  if (rg.empty()) {
    assert(false);
  }

  // Grab the largest adjacency list
  auto max_it = std::max_element(rg.begin(), rg.end(), rg_compare);

  // Convert the deque to a vector
  auto level = std::vector<unsigned int>();
  level.reserve(max_it->second.size());
  std::copy(max_it->second.begin(), max_it->second.end(),
            std::back_inserter(level));

  // Remove the level from the ray graph
  rg.erase(max_it->first);

  // Generate stride graph from the level
  stride_graph G = generate_stride_graph(level, qreg_size, 0);
  auto ordering = qrane_utils::adj_list_topological_ordering(G);
  auto selected_path = longest_valid_path_search(G, ordering);

  // if (!selected_path.empty()) { gate_type_paths.push_back(selected_path);
  // break;}
  //}
  // Return the largest path found of all gate_types
  return selected_path;
};

std::vector<unsigned int> qrane_mainprogram::get_most_frequent_gate_type(
    const std::vector<unsigned int> &level) {
  std::unordered_map<std::string, std::vector<unsigned int>> separated_points;
  for (const auto point : level) {
    std::string gate_type = std::get<GATE_TYPE>(qops_list[point]);
    separated_points[gate_type].push_back(point);
  }
  return std::max_element(separated_points.begin(), separated_points.end(),
                          id_vec_size_compare)
      ->second;
};

plinko_grid qrane_mainprogram::generate_plinko_grid(qasm_ops_list &qops,
                                                    unsigned int qreg_size) {
  plinko_grid ret = plinko_grid(qreg_size);
  /*
  ret.reserve(qreg_size);
  for (auto &qop : qops) {
          if (std::get<ARGS>(qop)[0] > qreg_size) {
                  std::cout << "Qubit accessed outside register range\n";
                  exit(1);
          }
          ret[std::get<ARGS>(qop)[0]].push_back(std::get<QOP_NUM_GLOBAL>(qop));
  }
  */
  return ret;
};

std::vector<unsigned int>
qrane_mainprogram::get_next_grid_row(plinko_grid &P, std::vector<bool> &grouped,
                                     unsigned int qreg_size) {
  std::size_t i;

  // First ensure that the front has no elements that have been grouped already
  for (i = 0; i < P.size(); ++i) {
    if (!P[i].empty()) {
      while (grouped[P[i].front()]) {
        P[i].pop_front();
        if (P[i].empty()) {
          break;
        }
      }
    }
  }

  // Then we can grab a COPY of the entire bottom row
  std::vector<unsigned int> ret = std::vector<unsigned int>();
  ret.reserve(qreg_size);
  for (i = 0; i < P.size(); ++i) {
    if (!P[i].empty()) {
      ret.push_back(P[i].front());
    }
  }
  return ret;
}

/*

*/
stride_graph qrane_mainprogram::generate_stride_graph(
    const std::vector<unsigned int> &qop_ids, unsigned int qreg_size,
    unsigned int args) {
  stride_graph G;
  G.reserve(qreg_size);

  // This is for determining which index of 2Qubit gates to use.
  // If either argument is constant, the other argument is chosen.
  unsigned int index;
  if (std::get<ARGS>(qops_list[qop_ids[0]]).size() == 2 && qop_ids.size() > 1) {
    auto args_0 = std::get<ARGS>(qops_list[qop_ids[0]]);
    auto args_1 = std::get<ARGS>(qops_list[qop_ids[1]]);
    if (args_1[1] - args_0[1] != 0) {
      index = 1;
    } else if (args_1[0] - args_0[0] != 0) {
      index = 0;
    } else {
      index = 0;
    }
  } else {
    index = 0;
  }

  // For each qop
  for (std::size_t i = 0; i < qop_ids.size(); ++i) {
    // Prepare strides list and initialize qop i's adjacency_list
    G[qop_ids[i]] = std::vector<std::pair<unsigned int, int>>();

    // For each other qop
    for (std::size_t j = 0; j < qop_ids.size(); ++j) {
      int stride;
      int i_op = std::get<ARGS>(qops_list[qop_ids[i]])[index];
      int j_op = std::get<ARGS>(qops_list[qop_ids[j]])[index];
      stride = j_op - i_op;

      // Create the neighbor as (global_id, [strides]) and push to j's adjacency
      // list
      if (stride > 0) {
        auto v = std::pair<unsigned int, int>(qop_ids[j], stride);
        G[qop_ids[i]].push_back(v);
      }
    }
  }
  return G;
};

std::vector<unsigned int> qrane_mainprogram::longest_valid_path_search(
    stride_graph G, std::vector<unsigned int> ordering) {
  std::vector<std::vector<unsigned int>> paths;

  // While we can still pick a source vertex
  while (!ordering.empty()) {

    // Grab the first zero in-degree vertex in the topological ordering
    unsigned int src = ordering.front();

    // Initialize local stack for perform DFS from src and longest_path variable
    frame_stack stack = frame_stack();
    std::vector<unsigned int> longest_path = std::vector<unsigned int>();

    // Generate and push a start frame that only labels the src
    auto start_frame = std::make_tuple(src, 0, LEX_POS,
                                       std::unordered_map<unsigned int, bool>(),
                                       std::vector<unsigned int>());
    stack.push(start_frame);

    // Begin DFS
    while (!stack.empty()) {
      auto curr_frame = stack.top();
      auto curr_id = std::get<ID>(curr_frame);
      stack.pop();

      // Put the current global id into the visited and path vectors
      if (!std::get<VISITED>(curr_frame)[curr_id]) {
        std::get<PATH>(curr_frame).push_back(curr_id);
        std::get<VISITED>(curr_frame)[curr_id] = true;
      }

      // For each neighbor
      bool frame_pushed = false;
      for (auto i = G[curr_id].begin(); i != G[curr_id].end(); ++i) {

        // If the vertex is unvisited, we have two possibilities
        if (!std::get<VISITED>(curr_frame)[(*i).first]) {

          // If we are at the first branch from the search, then we have yet to
          // establish a stride Compute the stride and lexicographic order, then
          // build the new frame
          if (std::get<STRIDE>(curr_frame) == 0) {
            int diff = i->first - std::get<PATH>(curr_frame).back();
            lex_type lex;
            if (diff > 0) {
              lex = LEX_POS;
            } else if (diff < 0) {
              lex = LEX_NEG;
            }
            auto new_frame = std::make_tuple(i->first, i->second, lex,
                                             std::get<VISITED>(curr_frame),
                                             std::get<PATH>(curr_frame));
            stack.push(new_frame);
            frame_pushed = true;

            // Otherwise, we only push a new frame when the path stride (weight)
            // equals the established stride
          } else {
            int diff = i->first - std::get<PATH>(curr_frame).back();
            lex_type lex;
            if (diff > 0) {
              lex = LEX_POS;
            } else if (diff < 0) {
              lex = LEX_NEG;
            }

            if (i->second == std::get<STRIDE>(curr_frame) &&
                lex == std::get<LEX_TYPE>(curr_frame)) {
              auto new_frame = std::make_tuple((*i).first, (*i).second, lex,
                                               std::get<VISITED>(curr_frame),
                                               std::get<PATH>(curr_frame));
              stack.push(new_frame);
              frame_pushed = true;
            }
          }
        }
      }

      // If we frames were pushed at the current source, then we have completed
      // a path
      if (!frame_pushed) {

        // Store it if it the largest path so far.
        if (std::get<PATH>(curr_frame).size() >= longest_path.size()) {
          longest_path = std::get<PATH>(curr_frame);
        }
      }
    }

    for (auto val : longest_path) {
      // qrane_utils::adj_list_remove_vertex(G, val);
      ordering.erase(std::remove(ordering.begin(), ordering.end(), val),
                     ordering.end());
    }
    paths.push_back(longest_path);
  }
  std::vector<unsigned int> safety_path = {(*G.begin()).first};
  paths.push_back(safety_path);
  return get_longest_valid_path(paths);
};

std::vector<unsigned int> qrane_mainprogram::get_longest_valid_path(
    std::vector<std::vector<unsigned int>> paths) {
  std::vector<unsigned int> selected_path;
  // bool disrespects_dependences;
  // bool cycle_introduced;
  // bool lexico_negative;
  // bool cannot_carry;

  while (true) {
    if (paths.empty()) {
      return std::vector<unsigned int>();
    }

    auto max_path_it =
        std::max_element(paths.begin(), paths.end(), vec_size_compare);
    selected_path = *max_path_it;
    paths.erase(max_path_it);

    // for (auto val : selected_path) { std::cout << val << " "; } std::cout <<
    // std::endl; qrane_domain test = create_fresh_domain(ctx,
    // this->num_domains, selected_path);

    // cannot_carry = deps.path_violates_dependences(ctx, selected_path, test,
    // this->domain_map, this->num_domains, true); if (cannot_carry) { continue;
    // }

    // lexico_negative = deps.path_violates_lexico_positivity(ctx,
    // selected_path, this->domain_map, this->num_domains, this->num_qops,
    // true); if (lexico_negative) { continue; }

    // disrespects_dependences =
    // deps.path_disrespects_dependences(selected_path, num_qops); if
    // (disrespects_dependences) { continue; }

    // cycle_introduced = deps.path_introduces_dependence_cycle(selected_path,
    // num_qops); if (cycle_introduced) { continue; }

    return selected_path;
  }
};

ray_graph
qrane_mainprogram::generate_ray_graph(const std::vector<unsigned int> &level,
                                      unsigned int qreg_size) {
  ray_graph rg = ray_graph();

  // For each qop_identifier
  for (auto i = level.begin(); i != level.end(); ++i) {
    auto i_args = std::get<ARGS>(qops_list[*i]);
    auto key = std::pair<unsigned int, float>();
    key.first = std::get<QOP_NUM_GLOBAL>(qops_list[*i]);

    std::vector<std::vector<int>> point_dups = std::vector<std::vector<int>>();

    // Look at all subsequent identifiers
    for (auto j = i + 1; j != level.end(); ++j) {
      auto j_args = std::get<ARGS>(qops_list[*j]);

      if (std::find(point_dups.begin(), point_dups.end(), j_args) !=
          point_dups.end()) {
        continue;
      }

      float rise = static_cast<float>(j_args[1] - i_args[1]);
      float run = static_cast<float>(j_args[0] - i_args[0]);

      // if (run == 0) { continue; }
      if (run == 0) {
        key.second = std::numeric_limits<float>::infinity();
      } else {
        key.second = rise / run;
      }
      // if (key.second == 0) { continue; }

      if (rg[key].size() <= qreg_size) {
        rg[key].push_back(std::get<QOP_NUM_GLOBAL>(qops_list[*j]));
      }
      point_dups.push_back(j_args);
    }

    // For each i, we also add a singleton entry to ensure all points can be
    // covered.
    key.second = 0;
    if (rg.count(key) == 0) {
      rg[key] = std::deque<unsigned int>();
    }
  }

  for (auto &entry : rg) {
    entry.second.push_front(entry.first.first);
  }
  return rg;
};

std::array<unsigned int, 2> qrane_mainprogram::look_ahead(plinko_grid circuit,
                                                          unsigned int depth) {
  std::array<unsigned int, 2> counts = {0, 0};

  // For each lane in the circuit
  for (unsigned int i = 0; i < circuit.size(); ++i) {

    // If the lane size is 1, then there are no more elements to look ahead at
    if (circuit[i].size() == 1) {
      continue;
    }

    // Otherwise, skip the first element (the row from which we are looking
    // ahead) and track argument count until empty
    for (unsigned int j = 1; j <= depth && j < circuit[i].size(); ++j) {
      std::size_t args = std::get<ARGS>(qops_list[circuit[i][j]]).size();
      counts[args - 1] += 1;
    }
  }
  return counts;
};

/*
        Convert qrane_statement objects into qop_identifier list
*/
void qrane_mainprogram::convert_stmtlist_to_vector_form() {
  std::vector<qrane_statement *> stmts = stmtlist->get_qops();
  qrane_qop *qop;

  // First do the dependence graph construction
  for (std::size_t i = 0; i < stmts.size(); ++i) {
    qop = (qrane_qop *)stmts[i];
    if (qop->get_arglist()->size() > 2) {
      std::cout
          << "Gates with more than three arguments must first be decomposed.\n";
      exit(1);
    }
    add_dependence_vertex(qop);
  }

  std::unordered_map<std::string, unsigned long> gate_type_ctr;
  for (std::size_t i = 0; i < stmts.size(); ++i) {
    qop = (qrane_qop *)stmts[i];
    std::string gate_id = qop->get_id();
    if (gate_type_ctr.count(gate_id) == 0) {
      gate_type_ctr[gate_id] = 0;
    }
    qop_identifier id = generate_qop_identifier(qop, gate_type_ctr[gate_id]);
    gate_type_ctr[gate_id] += 1;
    this->qops_list[std::get<QOP_NUM_GLOBAL>(id)] = id;
  }

  // Separate the qops into their respective gate types
  // for (std::size_t i = 0; i < qops_list.size(); ++i) {
  //	this->qops[std::get<GATE_TYPE>(qops_list[i])].push_back(qops_list[i]);
  //}
}

/*
<arg(0), ..., arg(n-1), in_degree, out_degree, qop_num_type, qop_num_global>
Reserve(num_args + 4);
*/
qop_identifier
qrane_mainprogram::generate_qop_identifier(qrane_qop *qop,
                                           std::size_t qop_num_type) {
  qop_identifier id;

  std::vector<int> qop_args;
  for (std::size_t i = 0; i < qop->num_args(); ++i) { // args
    qop_args.push_back(qop->at(i));
  }

  unsigned int in_degree = 0;  // deps.qop_in_degree(qop);
  unsigned int out_degree = 0; // deps.qop_out_degree(qop);
  std::string gate_type = qop->get_id();
  unsigned int qop_num_global = qop->get_dim1_qop_num();

  id = std::make_tuple(qop_args, in_degree, out_degree, gate_type, qop_num_type,
                       qop_num_global);
  return id;
}

void qrane_mainprogram::gate_map_store_domain(qrane_domain dom) {
  gate_domain_map[dom.gate_id].push_back(dom);
};

void qrane_mainprogram::add_dependence_vertex(qrane_qop *qop) {
  char type;
  for (unsigned int j = 0; j < qop->num_args(); ++j) {
    num_qubit_exprs += 1;
    if (opt->write_all) {
      type = 'w';
    } else {
      if (j < qop->num_args() - 1) {
        type = 'r';
      } else {
        type = 'w';
      }
    }
    deps.add_vertex(qop->get_dim1_qop_num(), qop->at(j), type, qop->get_id());
    deps.add_write_all_vertex(qop->get_dim1_qop_num(), qop->at(j), 'w',
                              qop->get_id());
  }
};

// bool is_mergee(const qrane_domain& dom) { return dom.is_mergee; }

bool domain_match_by_num(const qrane_domain &dom,
                         const unsigned int &search_num) {
  return dom.domain_num == search_num;
}

bool comparator_access_graph_domain_size(
    const std::pair<const std::vector<int>,
                    std::pair<lex_type, std::deque<unsigned int>>> &i,
    const std::pair<const std::vector<int>,
                    std::pair<lex_type, std::deque<unsigned int>>> &j,
    domain_map_t &dmp) {
  unsigned int i_size = 0;
  unsigned int j_size = 0;

  for (auto val : i.second.second) {
    i_size += dmp[val].component_qops.size();
  }
  for (auto val : j.second.second) {
    j_size += dmp[val].component_qops.size();
  }
  return i_size < j_size;
};

bool comparator_candidate_list_domain_size(
    const std::pair<lex_type, std::vector<unsigned int>> &lhs,
    const std::pair<lex_type, std::vector<unsigned int>> &rhs,
    domain_map_t &dmp) {
  unsigned int i_size = 0;
  unsigned int j_size = 0;

  for (auto val : lhs.second) {
    i_size += dmp[val].component_qops.size();
  }
  for (auto val : rhs.second) {
    j_size += dmp[val].component_qops.size();
  }
  return i_size < j_size;
};

/*
This is the big search one. Doesn't seem to do as well.

void qrane_mainprogram::combine_domains() {
        unsigned int current_dim = 2;

        while (!this->domain_map.empty()) {
                std::vector<std::pair<lex_type, std::vector<unsigned int>>>
all_combinations; all_combinations.reserve(this->domain_map.size());

                // For each domain in the set
                for (domain_map_t::iterator i = std::begin(this->domain_map); i
!= std::end(this->domain_map); i++) {

                        // Store all potential higher-dimensional domains that
could be constructed std::vector<std::pair<lex_type, std::vector<unsigned int>>>
my_combinations; unsigned int args = i->second.args;

                        // This block sets the search limit as an iterator
                        domain_map_t::iterator lim_it;
                        auto remaining = std::distance(i,
std::end(this->domain_map)); if (remaining < opt->search_limit) { lim_it =
std::next(i, remaining); } else { lim_it = std::next(i, opt->search_limit); }

                        // For search_limit other domains in the set
                        for (domain_map_t::iterator j = std::next(i, 1); j !=
std::end(this->domain_map) && j != lim_it; ++j) {

                                unsigned int limit;
                                if (opt->search_limit == 0) { limit =
opt->search_limit + 1; } else { limit = 0; } for (auto& pair : my_combinations)
{ if (limit == opt->search_limit) { break; }

                                        if (j->first == pair.second.back()) {
continue; }

                                        // Disqualified if domains have
differing gate types if (domains_have_different_gate_type(j->first,
pair.second.back())) { continue; }

                                        // Disqualified if domains have
different lex type if (j->second.lex != domain_map[pair.second.back()].lex) {
continue; }

                                        // Disqualified if established lex order
is disobeyed
                                        // Think of lhs as "established" and rhs
as "mergee" if (domains_lex_order(pair.second.back(), j->first) != pair.first) {
continue; }

                                        bool res;
                                        res =
extended_domain_inconsistent(j->first, pair.second, current_dim); if (res) {
continue; }

                                        pair.second.push_back(j->first);
                                        ++limit;
                                }
                                // Disqualified if domains have differing gate
types if (domains_have_different_gate_type(i->first, j->first)) { continue; }

                                // Disqualified if domains have different lex
type if (domains_lex_mismatch(i->first, j->first)) { continue; }

                                // Disqualified if domains are inconsistent
                                bool res;
                                res = extended_domain_inconsistent(i->first,
j->first, current_dim); if (res) { continue; }

                                lex_type lex = domains_lex_order(i->first,
j->first); if (lex == LEX_SUBSET) { continue; }

                                std::vector<unsigned int> new_path = {i->first,
j->first}; my_combinations.push_back(std::make_pair(lex, new_path));
                        }
                        all_combinations.insert(all_combinations.end(),
my_combinations.begin(), my_combinations.end());
                }

                domain_map_t new_domain_map =
greedy_domain_selection(all_combinations, current_dim);

                // Erase chosen domains
                for (auto& pair : new_domain_map) {
                        for (auto key : pair.second.subdomains) {
                                this->domain_map.erase(key);
                        }
                }

                // Move all domains not promoted in new_domain_map to the
unchanged domains list for (auto& pair : this->domain_map) {
                        this->unchanged_domains.push_back(pair.second);
                }

                this->domain_map = new_domain_map;
                current_dim += 1;
        }
}
*/

/*
        You know what you could do.
        Construct an isl_mat* matrix within each thread, and pass that pointer
        to extended_domain_inconsistent
*/
void qrane_mainprogram::combine_domains() {
  unsigned int current_dim = 2;

  while (!this->domain_map.empty()) {
    std::vector<std::pair<lex_type, std::vector<unsigned int>>>
        all_combinations;
    all_combinations.reserve(2 * this->domain_map.size());

    for (domain_map_t::iterator i = std::begin(this->domain_map);
         i != std::end(this->domain_map); i++) {

      std::vector<std::pair<lex_type, std::vector<unsigned int>>>
          my_combinations;

#if 0
			// First look through all_combinations to see if we can extend the domain path
            //if (opt->search_limit > 0) { std::shuffle(all_combinations.begin(), all_combinations.end(), std::default_random_engine()); }
			
			unsigned int limit;
			if (opt->search_limit == 0) {
				limit = opt->search_limit + 1;
			} else {
				limit = 0;
			}
			for (auto& pair : my_combinations) {
				if (limit == opt->search_limit) { break; }

				if (i->first == pair.second.back()) { continue; }

				// Disqualified if domains have differing gate types
				if (domains_have_different_gate_type(i->first, pair.second.back())) { continue; }

				// Disqualified if domains have different lex type
				if (i->second.lex != domain_map[pair.second.back()].lex) { continue; }

				// Disqualified if established lex order is disobeyed 
				// Think of lhs as "established" and rhs as "mergee"
				if (domains_lex_order(pair.second.back(), i->first) != pair.first) { continue; }

				bool res;
//#pragma omp critical
				res = extended_domain_inconsistent(i->first, pair.second, current_dim);
				if (res) { continue; }

				pair.second.push_back(i->first);
				++limit;
			}
#endif

      // Then we can look through the rest of the domains and make a two-domain
      // path
      domain_map_t::iterator lim_it;
      auto remaining = std::distance(i, std::end(this->domain_map));
      if (remaining < opt->search_limit) {
        lim_it = std::next(i, remaining);
      } else {
        lim_it = std::next(i, opt->search_limit);
      }
      for (auto j = std::next(i, 1);
           j != std::end(this->domain_map) && j != lim_it; ++j) {

        // Disqualified if domains have differing gate types
        if (domains_have_different_gate_type(i->first, j->first)) {
          continue;
        }

        // Disqualified if domains have different lex type
        if (domains_lex_mismatch(i->first, j->first)) {
          continue;
        }

        // Disqualified if domains are inconsistent
        bool res;
        res = extended_domain_inconsistent(i->first, j->first, current_dim);
        if (res) {
          continue;
        }

        lex_type lex = domains_lex_order(i->first, j->first);
        if (lex == LEX_SUBSET) {
          continue;
        }

        std::vector<unsigned int> new_path = {i->first, j->first};
        my_combinations.push_back(std::make_pair(lex, new_path));
      }

      all_combinations.insert(all_combinations.end(), my_combinations.begin(),
                              my_combinations.end());
    }

    /*
                    std::cout << "---\n";
                    for (auto& elem : all_combinations) {
                            for(auto key : elem.second) {
                                    std::cout << key << " ";
                            }
                            std::cout << std::endl;
                    }
    */

    domain_map_t new_domain_map =
        greedy_domain_selection(all_combinations, current_dim);

    // Erase chosen domains
    for (auto &pair : new_domain_map) {
      for (auto key : pair.second.subdomains) {
        this->domain_map.erase(key);
      }
    }

    // Move all domains not promoted in new_domain_map to the unchanged domains
    // list
    for (auto &pair : this->domain_map) {
      this->unchanged_domains.push_back(pair.second);
    }

    this->domain_map = new_domain_map;
    current_dim += 1;
  }
}

bool qrane_mainprogram::domains_have_different_gate_type(unsigned int lhs,
                                                         unsigned int rhs) {
  return this->domain_map[lhs].gate_id != this->domain_map[rhs].gate_id;
};

bool qrane_mainprogram::domains_lex_mismatch(unsigned int lhs,
                                             unsigned int rhs) {
  qrane_domain i = domain_map[lhs];
  qrane_domain j = domain_map[rhs];

  if (i.lex == j.lex) {
    return false;
  } else {
    if (i.lex == LEX_SINGLE || j.lex == LEX_SINGLE) {
      return false;
    } else {
      return true;
    } // true LEX_POS vs LEX_NEG mismatch
  }
};

lex_type qrane_mainprogram::domains_lex_order(unsigned int lhs,
                                              unsigned int rhs) {
  qrane_domain i = this->domain_map[lhs];
  qrane_domain j = this->domain_map[rhs];

  // This stays in no matter what
  if ((i.get_time_min() > j.get_time_min() &&
       i.get_time_max() < j.get_time_max()) ||
      (j.get_time_min() > i.get_time_min() &&
       j.get_time_max() < i.get_time_max())) {
    return LEX_SUBSET;
  }

  /* This is the partial overlap version
  // This version fails BIGD 20qbt_7d1_1d2_9.qasm
  if (i.stmt_count == 1 && j.stmt_count > 1) {
          if (i.get_time_max() < j.get_time_min()) {
                  return LEX_POS;
          } else if (i.get_time_min() > j.get_time_min()) {
                  return LEX_NEG;
          } else {
                  return LEX_SUBSET;
          }

  } else if (i.stmt_count > 1 && j.stmt_count == 1) {
          if (i.get_time_min() < j.get_time_min()) {
                  return LEX_POS;
          } else if (i.get_time_min() > j.get_time_max()) {
                  return LEX_NEG;
          } else {
                  return LEX_SUBSET;
          }

  } else {
          if ((i.get_time_min() < j.get_time_min() && i.get_time_max() <
  j.get_time_min()) || (i.get_time_min() < j.get_time_min() && j.get_time_max()
  < j.get_time_max() && i.get_time_min() > j.get_time_min())) { return LEX_POS;
          }
          else if ((i.get_time_min() > j.get_time_max() && i.get_time_max() >
  j.get_time_max()) || (i.get_time_min() > j.get_time_min() && i.get_time_min()
  < j.get_time_max() && j.get_time_max() < i.get_time_max())) { return LEX_NEG;
          } else {
                      return LEX_SUBSET;
          }
  }
  */

  if (i.stmt_count == 1 && j.stmt_count > 1) {
    if (i.get_time_max() < j.get_time_min()) {
      return LEX_POS;
    } else if (i.get_time_min() > j.get_time_min()) {
      return LEX_NEG;
    } else {
      return LEX_SUBSET;
    }

  } else if (i.stmt_count > 1 && j.stmt_count == 1) {
    if (i.get_time_min() < j.get_time_min()) {
      return LEX_POS;
    } else if (i.get_time_min() > j.get_time_max()) {
      return LEX_NEG;
    } else {
      return LEX_SUBSET;
    }

  } else if (i.stmt_count == 1 && j.stmt_count == 1) {
    if (i.get_time_min() < j.get_time_min()) {
      return LEX_POS;
    } else if (i.get_time_min() > j.get_time_min()) {
      return LEX_NEG;
    } else {
      return LEX_SUBSET;
    }

    // Both domains have at least two points
  } else {
    if (i.lex == LEX_POS) {
      if ( (i.get_time_max() < j.get_time_min()) //||
		             /*(i.get_time_min() < j.get_time_min() && j.get_time_min() < i.get_time_max() && i.get_time_max() < j.get_time_max())*/) {
        return LEX_POS;
      } else {
        return LEX_SUBSET;
      }
    } else if (i.lex == LEX_NEG) {
      if ( (j.get_time_max() < i.get_time_min()) //||
			     /*(j.get_time_min() < i.get_time_min() && i.get_time_min() < j.get_time_max() && j.get_time_max() < i.get_time_max())*/) {
        return LEX_NEG;
      } else {
        return LEX_SUBSET;
      }
    }
  }
  return LEX_SUBSET;
};

bool qrane_mainprogram::extended_domain_inconsistent(
    unsigned int new_dom, std::vector<unsigned int> path,
    unsigned int current_dim) {
  std::vector<unsigned int> combined = path;
  path.push_back(new_dom);
  isl_mat *system = combine_access_matrices(combined, current_dim);
  // system = compute_access_relations(isl_mat_copy(system));
  system = compute_access_relations(system);
  bool result =
      check_consistency(system, current_dim, domain_map[new_dom].args);
  isl_mat_free(system);
  if (result) {
    return false;
  } // If consistent, return false
  else {
    return true;
  } // Otherwise, return true
};

bool qrane_mainprogram::extended_domain_inconsistent(unsigned int lhs,
                                                     unsigned int rhs,
                                                     unsigned int current_dim) {
  std::vector<unsigned int> combined = {lhs, rhs};
  isl_mat *my_system = combine_access_matrices(combined, current_dim);
  // system = compute_access_relations(isl_mat_copy(system));
  my_system = compute_access_relations(my_system);
  bool result = check_consistency(my_system, current_dim, domain_map[lhs].args);
  isl_mat_free(my_system);
  if (result) {
    return false;
  } // If consistent, return false
  else {
    return true;
  } // Otherwise, return true
};

domain_map_t
qrane_mainprogram::greedy_domain_selection(candidate_list candidates,
                                           unsigned int current_dim) {
  domain_map_t new_domain_map;
  // new_domain_map.reserve(candidates.size() * 0.5);
  bool invalid_matrix;
  // bool disrespects_dependences;

  while (!candidates.empty()) {
    auto max_it = std::max_element(
        candidates.begin(), candidates.end(),
        std::bind(comparator_candidate_list_domain_size, std::placeholders::_1,
                  std::placeholders::_2, this->domain_map));

    std::vector<unsigned int> path = max_it->second;

    // Disqualified if it is inconsistent
    invalid_matrix = inconsistent_or_rational_matrix(path, current_dim);
    if (invalid_matrix) {
      candidates.erase(max_it);
      continue;
    }

    qrane_domain new_dom = merge_domains(path, max_it->first, current_dim);
    new_domain_map[path.front()] = new_dom;

    candidates.erase(max_it);
    for (auto &pair : candidates) {
      for (auto val : pair.second) {
        if (std::find(path.begin(), path.end(), val) != path.end()) {
          pair.first = LEX_REMOVE;
          break;
        }
      }
    }
    candidates.erase(
        std::remove_if(candidates.begin(), candidates.end(),
                       [](std::pair<lex_type, std::vector<unsigned int>> &it) {
                         return it.first == LEX_REMOVE;
                       }),
        candidates.end());
  }
  return new_domain_map;
}

/*
        Notes: We cannot just keep choosing domains until we've chosen them all,
        because some domains may not be promoted to 2D. Instead, loop until
        G is empty. Back in combine_domains, any domains that are left uncovered
        are unchanged will be offloaded the unchanged domains list.
*/
domain_map_t
qrane_mainprogram::greedy_domain_selection(access_graph &G,
                                           unsigned int current_dim) {
  domain_map_t new_domain_map;
  // new_domain_map.reserve(G.size() * 0.5);
  bool invalid_matrix;

  while (!G.empty()) {
    auto max_it = std::max_element(
        G.begin(), G.end(),
        std::bind(comparator_access_graph_domain_size, std::placeholders::_1,
                  std::placeholders::_2, this->domain_map));
    std::vector<unsigned int> collection;
    std::copy((*max_it).second.second.begin(), (*max_it).second.second.end(),
              std::back_inserter(collection));

    // disrespects_dependences = deps.path_disrespects_dependences(collection,
    // num_qops); if (disrespects_dependences) { G.erase(max_it); continue; }

    // cycle_introduced = deps.path_introduces_dependence_cycle(collection,
    // num_qops); if (cycle_introduced) { G.erase(max_it); continue; }

    invalid_matrix = inconsistent_or_rational_matrix(collection, current_dim);
    if (invalid_matrix) {
      G.erase(max_it);
      continue;
    }

    // for (auto val : collection) { std::cout << val << " "; } std::cout <<
    // std::endl;

    qrane_domain new_dom =
        merge_domains(collection, max_it->second.first, current_dim);

    // cannot_carry = deps.path_violates_dependences(ctx, collection, new_dom,
    // this->domain_map, this->num_domains, false); if (cannot_carry) {
    // G.erase(max_it); continue; }

    new_domain_map[collection.front()] = new_dom;
    // this->deps.update_working_domain(ctx, collection, domain_map, new_dom,
    // false);

    // then do the deletion routine
    G.erase(max_it);

    auto to_remove = std::vector<access_graph::iterator>();
    for (auto it = G.begin(); it != G.end(); ++it) {
      for (auto val : it->second.second) {
        if (std::find(collection.begin(), collection.end(), val) !=
            collection.end()) {
          to_remove.push_back(it);
          break;
        }
      }
    }
    for (auto &it : to_remove) {
      G.erase(it);
    }
  }
  return new_domain_map;
};

bool qrane_mainprogram::inconsistent_or_rational_matrix(
    const std::vector<unsigned int> &domains, unsigned int current_dim) {
  isl_mat *mat = combine_access_matrices(domains, current_dim);
  mat = compute_access_relations(mat);

  if (!check_consistency(mat, current_dim, domain_map[domains.front()].args)) {
    // printf("Inconsistent\n");
    // printf("----------------\n");
    isl_mat_free(mat);
    return true;
  }

  if (!integral_matrix(mat, current_dim, domain_map[domains.front()].args)) {
    // printf("Rational\n");
    // printf("----------------\n");
    isl_mat_free(mat);
    return true;
  }
  // printf("Clear\n");
  // printf("----------------\n");
  isl_mat_free(mat);
  return false;
};

qrane_domain
qrane_mainprogram::merge_domains(const std::vector<unsigned int> &domains,
                                 lex_type lex, unsigned int current_dim) {
  deps.update_membership_graph_ND_phase(domains, this->domain_map);

  qrane_domain new_domain = qrane_domain();
  new_domain.lex = lex;
  new_domain.gate_id = domain_map[domains.front()].gate_id;
  new_domain.args = domain_map[domains.front()].args;
  new_domain.domain_num =
      domains.front(); // new_domain takes id of the first domain in the list
  new_domain.dimensionality =
      current_dim; // new_domain has dimension equal to current_dim
  new_domain.subdomains = domains; // subdomains is reflexive as well
  new_domain.set_local_domain(combine_isl_local_domains(domains, current_dim));
  new_domain.set_access_mat(combine_access_matrices(domains, current_dim));

  for (auto id : domains) {
    new_domain.add_component_qops(domain_map[id].component_qops);
  }
  new_domain.stmt_count = new_domain.component_qops.size();
  return new_domain;
};

__isl_give isl_set *qrane_mainprogram::combine_isl_local_domains(
    const std::vector<unsigned int> &domains, unsigned int current_dim) {
  isl_set *ret_set = isl_set_empty(isl_space_set_alloc(ctx, 0, current_dim));
  isl_set *mergee_set;

  for (std::size_t i = 0; i < domains.size(); ++i) {
    mergee_set = this->domain_map[domains[i]].get_local_domain_copy();
    mergee_set = isl_set_insert_dims(mergee_set, isl_dim_set, 0, 1);
    mergee_set = isl_set_fix_dim_si(mergee_set, 0, i);
    mergee_set = isl_set_reset_tuple_id(mergee_set);
    ret_set = isl_set_union(ret_set, mergee_set);
  }

  std::string domain_name = "S" + std::to_string(domains.front());
  isl_id *id = isl_id_alloc(ctx, domain_name.c_str(), nullptr);
  ret_set = isl_set_set_tuple_id(ret_set, id);
  ret_set = isl_set_coalesce(ret_set);
  return ret_set;
};

__isl_give isl_mat *qrane_mainprogram::combine_access_matrices(
    const std::vector<unsigned int> &domains, unsigned int current_dim) {
  isl_mat *ret_mat = domain_map[domains.front()].get_access_mat_copy();
  // isl_mat_dump(ret_mat);
  ret_mat = append_column_with_val(ret_mat, 0);

  isl_mat *temp_mat;
  for (std::size_t i = 1; i < domains.size(); ++i) {
    temp_mat =
        append_column_with_val(domain_map[domains[i]].get_access_mat_copy(), i);
    ret_mat = isl_mat_concat(temp_mat, ret_mat); // (top, bottom)
  }
  return ret_mat;
};

bool dom_compare(const qrane_domain &a, const qrane_domain &b) {
  return a.component_qops.size() < b.component_qops.size();
};

bool is_overlapping(const qrane_domain &a,
                    const std::vector<unsigned int> &subdomains) {
  for (const auto elem : subdomains) {
    if (std::find(a.subdomains.begin(), a.subdomains.end(), elem) !=
        a.subdomains.end()) {
      return true;
    }
  }
  return false;
};

std::list<qrane_domain> qrane_mainprogram::greedy_nd_domain_selection(
    std::list<qrane_domain> candidates) {
  std::list<qrane_domain> ret = std::list<qrane_domain>();
  while (!candidates.empty()) {
    std::list<qrane_domain>::iterator max_it =
        std::max_element(candidates.begin(), candidates.end(), dom_compare);
    qrane_domain max_dom = *max_it;

    std::vector<unsigned int> subdomains = max_dom.subdomains;
    candidates.erase(max_it);
    ret.push_back(max_dom);
    candidates.remove_if(
        std::bind(is_overlapping, std::placeholders::_1, subdomains));
  }
  return ret;
};

/*
  Notes:
    Naming is probably not necessary until after merging is complete
    Make a compilation flag for debugging vs production
*/
__isl_give isl_set *qrane_mainprogram::build_ND_domain_from_sets(
    std::vector<qrane_domain> &mergees) {
  isl_set *ret_set = isl_set_empty(
      isl_space_set_alloc(ctx, 0, mergees.front().dimensionality));
  isl_set *mergee_set;

  for (std::size_t i = 0; i < mergees.size(); ++i) {
    mergee_set = mergees[i].get_local_domain_copy();
    mergee_set = isl_set_insert_dims(mergee_set, isl_dim_set, 0, 1);
    mergee_set = isl_set_fix_dim_si(mergee_set, 0, i);
    mergee_set = isl_set_reset_tuple_id(mergee_set);
    ret_set = isl_set_union(ret_set, mergee_set);
  };

  std::string domain_name = "S" + std::to_string(mergees.front().domain_num);
  isl_id *id = isl_id_alloc(ctx, domain_name.c_str(), nullptr);
  ret_set = isl_set_set_tuple_id(ret_set, id);
  ret_set = isl_set_coalesce(ret_set);
  return ret_set;
};

/*
        Due to isl's reverse Gaussian elimination, we have to
        build the access matrix backwards:

        mergees[n-1] n-1
        mergees[n-2] n-2
        ...
        mergees[0] 0
*/
__isl_give isl_mat *qrane_mainprogram::compute_access_relations(isl_mat *mat) {

  // std::cout << "Access Mat:" << std::endl << std::flush;
  // isl_mat_dump(mat);
  mat = isl_mat_row_basis(mat);
  // std::cout << "Reduced:" << std::endl << std::flush;
  // isl_mat_dump(mat);

  return mat;
};

__isl_give isl_mat *
qrane_mainprogram::concat_matrices_dimwise(std::vector<qrane_domain> &mergees) {
  isl_mat *merger_mat;
  isl_mat *mergee_mat;

  // Start with the last mergee
  merger_mat = mergees.back().get_access_mat_copy();
  merger_mat = isl_mat_add_zero_cols(merger_mat, 1);
  for (int row = 0; row < isl_mat_rows(merger_mat); ++row) {
    // merger_mat = isl_mat_set_element_si(merger_mat, row,
    // isl_mat_cols(merger_mat)-1, mergees.front().consumed + 1);
  }

  // Then append an initial merger.consumed column to the mergee access_mat
  for (std::size_t i = mergees.size() - 1; i-- > 0;) {
    mergee_mat = mergees[i].get_access_mat_copy();
    // if (mergees[i].consumed == 0) {
    mergee_mat = isl_mat_add_zero_cols(mergee_mat, 1);

    for (int row = 0; row < isl_mat_rows(mergee_mat); ++row) {
      mergee_mat = isl_mat_set_element_si(mergee_mat, row,
                                          isl_mat_cols(mergee_mat) - 1, i);
    }
    //}

    merger_mat = isl_mat_concat(merger_mat, mergee_mat);
  }
  return merger_mat;
};

/*
        EXPECTS mat TO BE IN REF
*/
bool qrane_mainprogram::integral_matrix(isl_mat *mat, std::size_t dim,
                                        std::size_t args) {
  isl_mat *solved = isl_mat_copy(mat);
  solved = qrane_utils::back_substitute_isl_mat(ctx, solved, args, dim);

  isl_size rows = isl_mat_rows(solved);
  isl_size cols = isl_mat_cols(solved);
  isl_val *val;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      val = isl_mat_get_element_val(solved, i, j);
      int den = isl_val_get_den_si(val);
      if (den != 1) {
        isl_val_free(val);
        isl_mat_free(solved);
        return false;
      }
    }
  }
  isl_mat_free(solved);
  return true;
};

/*
        This is weird. The output isl_mat_row_basis is going to be
        the normal rref version of the matrix but upside down, i.e.:
        [[d1 1 b1 1 1 1]
         [c1 1 a1 1 0 1]
         [d0 1 b0 1 1 0]
         [c0 1 a0 1 0 0]]

        EXPECTS mat TO BE IN REF
*/
__isl_keep bool qrane_mainprogram::check_consistency(isl_mat *mat,
                                                     std::size_t dim,
                                                     std::size_t args) {
  isl_size cols = isl_mat_cols(mat);
  isl_val *right_val;
  isl_val *left_val;

  // First check that the last dim columns of the first row are zero
  for (std::size_t i = 0; i < dim; ++i) {
    right_val = isl_mat_get_element_val(mat, 0, (cols - 1) - i);
    if (!isl_val_is_zero(right_val)) {
      // std::cout << "Consistent" << std::endl << std::flush;
      return true;
    }
    isl_val_free(right_val);
  }

  // Then, go left two columns at a time and check right is zero and left is
  // non-zero
  for (std::size_t i = args; i-- > 0;) {
    int right_val_index = 2 * i + 1;
    int left_val_index = 2 * i;
    right_val = isl_mat_get_element_val(mat, 0, right_val_index);
    left_val = isl_mat_get_element_val(mat, 0, left_val_index);
    if (isl_val_is_zero(right_val) && !isl_val_is_zero(left_val)) {
      // std::cout << "Inconsistent" << std::endl << std::flush;
      return false;
    }
    isl_val_free(right_val);
    isl_val_free(left_val);
  }
  // std::cout << "Consistent" << std::endl << std::flush;
  return true;
};

__isl_give isl_mat *
qrane_mainprogram::append_column_with_val(__isl_take isl_mat *mat, int val) {
  isl_mat *ret = isl_mat_copy(mat);
  isl_size cols = isl_mat_cols(ret);
  isl_size rows = isl_mat_rows(ret);

  ret = isl_mat_insert_cols(ret, cols, 1);
  for (int row = 0; row < rows; ++row) {
    ret = isl_mat_set_element_si(ret, row, cols, val);
  }
  isl_mat_free(mat);
  return ret;
}

/*
    With the assertion that all domains have been constructed
  from the input file, we initialize this object's isl sets
  and maps that correspond to the domain, read, write, and
  schedule with strings built from information contained in the
  qrane_domain objects.
    The SCHEDULE_MODE flag is checked here to determine whether to
  construct the schedule from the Default Schedule string or the
  Recovered Schedule string.

  Params:
    none
  Return:
    none
*/
void qrane_mainprogram::build_isl_domain_read_write_schedule() {
  assert(!unchanged_domains.empty());
  scop->final_domain_list = unchanged_domains;
  scop->domain = initialize_domain();
  scop->read = initialize_read_relations();

  if (opt->write_all) {
    scop->write = initialize_read_relations();
  } else {
    scop->write = initialize_write_relations();
  }

  scop->call = initialize_call_relations();

  scop->dependence = deps.generate_validity_map(ctx);

  scop->arguments = initialize_arguments_map();
  scop->membership = deps.get_membership();
  scop->qubit_access_profile = deps.get_qubit_access_profile_map();

  if (opt->schedule_mode == SCHEDULE_IMPLICIT) {
    if (!opt->quiet) {
      std::cout << "Scheduling ... " << std::flush;
    }
    scop->schedule = initialize_recovered_schedule();
    if (!opt->quiet) {
      std::cout << "Done.\n" << std::flush;
    }
  }

  // isl_union_map* write_all_dependence =
  // deps.generate_write_all_dependences(ctx); isl_union_map* computed_deps =
  // isl_union_flow_get_must_dependence(compute_dependences());

  // isl_bool subset = isl_union_map_is_subset(scop->dependence, computed_deps);
  // isl_bool subset = isl_union_map_is_subset(computed_deps, scop->dependence);
  // isl_bool subset = isl_map_is_subset(isl_map_read_from_str(ctx, "{[1]}"),
  // isl_map_read_from_str(ctx, "{[1];[2];}"));
  // std::cout << "SUBSET: " << subset << std::endl;
};

isl_union_map *qrane_mainprogram::get_dependences() {
  return deps.generate_validity_map(ctx);
};

/*
        TODO: Consider freeing local domains here.
*/
__isl_give isl_union_set *qrane_mainprogram::initialize_domain() {
  isl_union_set *result = isl_union_set_empty_ctx(ctx);
  for (auto i = unchanged_domains.begin(); i != unchanged_domains.end(); ++i) {
    result = isl_union_set_add_set(result, i->get_local_domain_copy());
  }
  result = isl_union_set_coalesce(result);
  return result;
};

__isl_give isl_union_map *qrane_mainprogram::initialize_recovered_schedule() {
  isl_union_map *default_schedule =
      deps.build_implicit_schedule(ctx, this->subcircuit_num);
  return default_schedule;
};

__isl_give isl_union_map *qrane_mainprogram::initialize_read_relations() {
  isl_union_map *ret =
      isl_union_map_read_from_str(ctx, build_union_read_str().c_str());
  ret = isl_union_map_intersect_domain(ret, isl_union_set_copy(scop->domain));
  return isl_union_map_coalesce(ret);
};

__isl_give isl_union_map *qrane_mainprogram::initialize_write_relations() {
  isl_union_map *ret =
      isl_union_map_read_from_str(ctx, build_union_write_str().c_str());
  ret = isl_union_map_intersect_domain(ret, isl_union_set_copy(scop->domain));
  return isl_union_map_coalesce(ret);
};

__isl_give isl_union_map *qrane_mainprogram::initialize_call_relations() {
  isl_union_map *ret =
      isl_union_map_read_from_str(ctx, build_union_call_str().c_str());
  ret = isl_union_map_intersect_domain(ret, isl_union_set_copy(scop->domain));
  return isl_union_map_coalesce(ret);
};

__isl_give isl_union_map *qrane_mainprogram::initialize_arguments_map() {
  isl_union_map *ret = isl_union_map_empty_ctx(ctx);
  for (const auto &qrane_dom : this->unchanged_domains) {
    isl_point *pnt = isl_point_zero(isl_space_set_alloc(ctx, 0, 1));
    isl_val *val = isl_val_zero(ctx);
    val = isl_val_set_si(val, qrane_dom.args);
    pnt = isl_point_set_coordinate_val(pnt, isl_dim_set, 0, val);
    isl_set *domain = qrane_dom.get_local_domain_copy();
    isl_set *range = isl_set_from_point(pnt);
    isl_map *map = isl_map_from_domain_and_range(domain, range);
    ret = isl_union_map_add_map(ret, map);
  }
  return ret;
};

/*
        ALL arguments are considered "read" arguments.
*/
std::string qrane_mainprogram::build_union_read_str() {
  std::ostringstream strm;

  strm << "{";
  for (auto dom : unchanged_domains) {

    // For each argument
    for (int arg = 0; arg < dom.args; ++arg) {

      // Generate the "in" side of the relation
      strm << " S" << dom.domain_num;
      strm << "[";
      for (std::size_t dim = 0; dim < dom.dimensionality; ++dim) {
        strm << "i" << dim;
        if (dim != dom.dimensionality - 1) {
          strm << ",";
        }
      }
      strm << "]";

      // Generate the "out" side of the relation
      strm << "-> q[";
      for (std::size_t dim = 0; dim <= dom.dimensionality; ++dim) {
        std::string coeff = std::to_string(dom.get_coefficient(arg, dim));
        if (dim != dom.dimensionality) {
          strm << coeff << "*" << "i" << dim << " + ";
        } else {
          strm << coeff;
        }
      }
      strm << "];";
    }
  }
  strm << "};";
  return strm.str();
};

/*
        This only differs from build_union_read_str() in that
        only the last argument is affected.
*/
std::string qrane_mainprogram::build_union_write_str() {
  std::ostringstream strm;

  strm << "{";
  for (auto dom : unchanged_domains) {

    // Generate the "in" side of the relation
    strm << "S" << dom.domain_num;
    strm << "[";
    for (std::size_t dim = 0; dim < dom.dimensionality; ++dim) {
      strm << "i" << dim;
      if (dim != dom.dimensionality - 1) {
        strm << ",";
      }
    }
    strm << "]";

    // Generate the "out" side of the relation
    strm << "-> q[";
    for (std::size_t dim = 0; dim <= dom.dimensionality; ++dim) {
      std::string coeff =
          std::to_string(dom.get_coefficient(dom.args - 1, dim));
      if (dim != dom.dimensionality) {
        strm << coeff << "*" << "i" << dim << " + ";
      } else {
        strm << coeff;
      }
    }
    strm << "];";
  }
  strm << "};";
  return strm.str();
};

std::string qrane_mainprogram::build_union_call_str() {
  std::ostringstream strm;

  strm << "{";
  for (auto dom : unchanged_domains) {

    // Generate the "in" side of the relation
    strm << " S" << dom.domain_num;
    strm << "[";
    for (std::size_t dim = 0; dim < dom.dimensionality; ++dim) {
      strm << "i" << dim;
      if (dim != dom.dimensionality - 1) {
        strm << ",";
      }
    }
    strm << "]";
    // strm << "-> " << dom.gate_id << "[";
    strm << "-> [";

    // For each argument
    for (int arg = 0; arg < dom.args; ++arg) {

      // Generate the "out" side of the relation
      for (std::size_t dim = 0; dim <= dom.dimensionality; ++dim) {
        std::string coeff = std::to_string(dom.get_coefficient(arg, dim));
        if (dim != dom.dimensionality) {
          strm << coeff << "*" << "i" << dim << " + ";
        } else {
          strm << coeff;
        }
      }
      if (arg != dom.args - 1) {
        strm << ", ";
      }
    }
    strm << "];";
  }
  strm << "};";
  return strm.str();
};

void qrane_mainprogram::print_isl_domain_read_write_schedule() {
  std::cout << "Domain := "
            << isl_union_set_to_str(isl_union_set_copy(scop->domain))
            << std::endl
            << std::endl;
  std::cout << "Read := "
            << isl_union_map_to_str(isl_union_map_copy(scop->read)) << std::endl
            << std::endl;
  std::cout << "Write := "
            << isl_union_map_to_str(isl_union_map_copy(scop->write))
            << std::endl
            << std::endl;
  std::cout << "Call := "
            << isl_union_map_to_str(isl_union_map_copy(scop->call)) << std::endl
            << std::endl;
  if (opt->check || opt->schedule_mode != SCHEDULE_IMPLICIT) {
    std::cout << "DataDependencies := "
              << isl_union_map_to_str(isl_union_map_copy(scop->dependence))
              << std::endl
              << std::endl;
  }
  std::cout << "RecoveredSchedule := "
            << isl_union_map_to_str(isl_union_map_copy(scop->schedule))
            << std::endl
            << std::endl;
};

std::string qrane_mainprogram::get_domain_list_str() {
  assert(!scop->final_domain_list.empty());
  std::ostringstream strm;
  for (const auto &dom : scop->final_domain_list) {
    strm << isl_set_to_str(dom.get_local_domain_copy()) << std::endl;
  }
  return strm.str();
};

std::string qrane_mainprogram::generate_codegen_c_str() {
  std::string ret;
  char *str;

  // Set the print options
  isl_options_set_ast_always_print_block(ctx, 1);
  isl_ast_print_options *options = isl_ast_print_options_alloc(ctx);
  options = isl_ast_print_options_set_print_user(
      options, &qrane_codegen::qrane_stmt_print_user_fprintf_qasm,
      (void *)(this));

  // Allocate the ast build
  isl_ast_build *build = isl_ast_build_alloc(ctx);

  // Set function hook at each domain
  t_qrane_scop *my_scop = scop;
  build = isl_ast_build_set_at_each_domain(
      build, &qrane_codegen::qrane_at_each_domain, (void *)(my_scop));

  // Build the schedule
  isl_ast_node *node = isl_ast_build_node_from_schedule_map(
      build, isl_union_map_copy(my_scop->schedule));

  // Print
  printer = isl_printer_to_str(ctx);
  printer = isl_printer_set_output_format(printer, ISL_FORMAT_C);
  printer = isl_ast_node_print(node, printer, options);
  str = isl_printer_get_str(printer);
  ret = std::string(str);
  this->codegen_c_str = ret;
  isl_ast_print_options_free(options);
  return ret;
};

bool is_lexico_positive(__isl_keep isl_set *set) {
  int nn = isl_set_dim(set, isl_dim_set);
  int ii;
  bool ret = true;
  int first_pos = -1;
  int first_neg = -1;
  for (ii = 0; ii < nn; ii++) {
    isl_val *val = isl_set_plain_get_val_if_fixed(set, isl_dim_set, ii);
    // isl_bool dimOK = isl_val_is_nonneg (val);
    // ret = ret and dimOK == isl_bool_true;
    if (first_pos < 0 and isl_val_is_pos(val))
      first_pos = ii;
    if (first_neg < 0 and isl_val_is_neg(val))
      first_neg = ii;
    isl_val_free(val);
  }
  // The single point in the set is lexico positive if it doesn't have
  // any negative component, or if it has one, but we have a strictly
  // positive component before it.
  ret = (first_neg == -1) or (first_neg >= 0 and first_pos < first_neg);
  return ret;
}

bool qrane_mainprogram::check_recovered_respects_dependencies() {
  bool ret = false;
  if (opt->check) {

    // Create a copy of dependencies, default schedule, and recovered schedule
    isl_union_map *deps = isl_union_map_copy(scop->dependence);
    if (isl_union_map_is_empty(deps)) {
      return true;
    }
    isl_union_map *rec = isl_union_map_copy(scop->schedule);

    // depInTime := (schedule^-1 . deps) . deps
    isl_union_map *rec_inv = isl_union_map_reverse(isl_union_map_copy(rec));
    isl_union_map *depInTime = isl_union_map_apply_range(rec_inv, deps);
    depInTime = isl_union_map_apply_range(depInTime, isl_union_map_copy(rec));

    // deltas(depInTime)
    // isl_union_map * deltasWithMap = isl_union_map_deltas_map
    // (isl_union_map_copy (depInTime));
    isl_set *justDeltas =
        isl_set_from_union_set(isl_union_map_deltas(depInTime));
    isl_set *themin = isl_set_lexmin(justDeltas);

    ret = is_lexico_positive(themin);

    // std::cout << "Minimum delta: " << isl_set_to_str (themin) << std::endl;
    isl_set_free(themin);
  }
  return ret;
};

__isl_give isl_union_flow *qrane_mainprogram::compute_dependences() {
  isl_union_map *all = isl_union_map_union(isl_union_map_copy(scop->write),
                                           isl_union_map_copy(scop->read));
  isl_union_access_info *accinfo =
      isl_union_access_info_from_sink(isl_union_map_copy(all));
  accinfo = isl_union_access_info_set_must_source(accinfo, all);
  accinfo = isl_union_access_info_set_schedule_map(
      accinfo, isl_union_map_copy(scop->schedule));
  isl_union_flow *ret = isl_union_access_info_compute_flow(accinfo);
  return ret;
}

void qrane_mainprogram::compute_transformation() {
  assert(isl_options_set_schedule_max_constant_term(ctx, 0) == isl_stat_ok);
  assert(isl_options_set_schedule_max_coefficient(ctx, 2) == isl_stat_ok);
  switch (opt->schedule_mode) {
  case SCHEDULE_IMPLICIT:
    assert(false);
  case SCHEDULE_ISL:
    assert(isl_options_set_schedule_algorithm(
               ctx, ISL_SCHEDULE_ALGORITHM_ISL) == isl_stat_ok);
    if (!opt->quiet) {
      std::cout << "isl default scheduler chosen.\n";
    }
    break;
  case SCHEDULE_MINFUSE:
    assert(isl_options_set_schedule_algorithm(
               ctx, ISL_SCHEDULE_ALGORITHM_ISL) == isl_stat_ok);
    isl_options_set_schedule_serialize_sccs(ctx, 1);
    if (!opt->quiet) {
      std::cout << "Pluto Minfuse chosen.\n";
    }
    break;
  case SCHEDULE_MAXFUSE:
    assert(isl_options_set_schedule_algorithm(
               ctx, ISL_SCHEDULE_ALGORITHM_ISL) == isl_stat_ok);
    isl_options_set_schedule_whole_component(ctx, 1);
    isl_options_set_schedule_maximize_band_depth(ctx, 1);
    if (!opt->quiet) {
      std::cout << "Pluto Maxfuse chosen.\n";
    }
    break;
  case SCHEDULE_FEAUTRIER:
    assert(isl_options_set_schedule_algorithm(
               ctx, ISL_SCHEDULE_ALGORITHM_FEAUTRIER) == isl_stat_ok);
    // isl_options_set_schedule_split_scaled (m_ctx, 1);
    if (!opt->quiet) {
      std::cout << "Feautrier chosen.\n";
    }
    break;
  }

  isl_schedule_constraints *cons =
      isl_schedule_constraints_on_domain(isl_union_set_copy(scop->domain));
  cons = isl_schedule_constraints_set_validity(
      cons, isl_union_map_copy(scop->dependence));

  if (!opt->quiet) {
    std::cout << "computing schedule ..." << std::flush;
  }
  isl_schedule *sched = isl_schedule_constraints_compute_schedule(cons);
  if (!opt->quiet) {
    std::cout << "Done.\n" << std::flush;
  }

  isl_union_map *sched_map = isl_schedule_get_map(sched);
  sched_map = isl_union_map_intersect_domain(sched_map, this->scop->domain);
  this->scop->schedule = sched_map;
};

qrane_output_scop *qrane_mainprogram::get_output_scop() {
  qrane_output_scop *ret = new qrane_output_scop();
  ret->domain = isl_union_set_copy(scop->domain);
  ret->read = isl_union_map_copy(scop->read);
  ret->write = isl_union_map_copy(scop->write);
  ret->schedule = isl_union_map_copy(scop->schedule);
  ret->arguments = isl_union_map_copy(scop->arguments);
  return ret;
};

// -----------------------------
// Printing and String Retrieval
// -----------------------------

std::string qrane_mainprogram::get_registers() {
  std::ostringstream qreg_decls;
  std::vector<qrane_statement *> qregs = stmtlist->get_qregs();

  for (std::size_t i = 0; i < qregs.size(); ++i) {
    qrane_qreg *qreg = (qrane_qreg *)qregs[i];
    qreg_decls << "qreg " << qreg->get_id() << "["
               << std::to_string(qreg->get_size()) << "];\\n";
  }
  return qreg_decls.str();
};

std::string qrane_mainprogram::get_domain_profile_str() {
  assert(!scop->final_domain_list.empty());
  std::ostringstream strm;

  // Map: dimension -> (count, total number of points)
  std::map<std::size_t, std::pair<std::size_t, std::size_t>> dims_info;

  for (std::size_t i = 0; i < scop->final_domain_list.size(); ++i) {
    long dom_card = scop->final_domain_list[i].stmt_count;
    dims_info[scop->final_domain_list[i].dimensionality].first += 1;
    dims_info[scop->final_domain_list[i].dimensionality].second += dom_card;
  }

  for (auto &entry : dims_info) {
    strm << entry.first << "D: " << entry.second.first << " domains, "
         << entry.second.second << " points.\n";
  }
  return strm.str();
}

std::string qrane_mainprogram::get_domain_size_histogram_str() {
  assert(!scop->final_domain_list.empty());
  return print_domain_size_histogram(scop->final_domain_list);
}

std::string qrane_mainprogram::get_reconstruction_histogram_str() {
  assert(!scop->final_domain_list.empty());
  return print_reconstruction_histogram(scop->final_domain_list);
}

std::string qrane_mainprogram::get_networkx_edge_list_str() {
  // return deps.get_networkx_edge_list_str();
  return deps.get_gates_networkx_edge_list_str(stmtlist->get_qops());
};

std::string qrane_mainprogram::get_qubit_access_profile_str() {
  return deps.get_qubit_access_profile_str();
}

void qrane_mainprogram::print_membership_graph() { deps.print_membership(); };

std::string qrane_mainprogram::get_aquma_scop_str() {
  std::ostringstream strm;
  strm << isl_union_set_to_str(scop->domain) << std::endl;
  strm << isl_union_map_to_str(scop->read) << std::endl;
  strm << isl_union_map_to_str(scop->write) << std::endl;
  strm << isl_union_map_to_str(scop->schedule);
  return strm.str();
}

std::string qrane_mainprogram::print_reconstruction_histogram(
    std::vector<qrane_domain> dom_list) {
  // domain dimension -> { cardinality -> { occurrences } }
  std::map<unsigned int, std::map<unsigned int, unsigned int>> hist;
  std::ostringstream strm;

  for (const auto &dom : dom_list) {
    unsigned int dim = dom.dimensionality;
    unsigned int card = dom.stmt_count;
    hist[dim][card] += 1;
  }
  strm << "--- Reconstruction Profile ---" << std::endl;
  strm << "Dimension -> {Cardinality:Count}" << std::endl;
  for (auto dim : hist) {
    strm << dim.first << " -> {";
    for (auto pair : dim.second) {
      strm << pair.first << ":" << pair.second << ",";
    }
    strm << "}\n";
  }
  strm << "------------------------------" << std::endl;
  return strm.str();
}

std::string qrane_mainprogram::print_domain_size_histogram(
    std::vector<qrane_domain> dom_list) {
  std::map<unsigned int, unsigned int> hist;
  for (auto dom : dom_list) {
    hist[dom.stmt_count] += 1;
  }

  std::ostringstream strm;
  strm << "--- Domain Size Breakdown ---" << std::endl;
  strm << "Domain Size : Domain Count" << std::endl;
  for (auto bucket : hist) {
    strm << bucket.first << " : " << bucket.second << std::endl;
  }
  strm << "-----------------------------" << std::endl;
  return strm.str();
}
