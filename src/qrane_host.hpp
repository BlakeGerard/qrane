#ifndef QRANE_HOST_H
#define QRANE_HOST_H

#include "getopt.h"
#include "omp.h"
#include "unistd.h"
#include <Python.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>

#include "qrane_id.hpp"
#include "qrane_options.hpp"
#include "qrane_parser.h"
#include "qrane_program.hpp"
// #include "qrane_routing.hpp"
#include "qrane_scop.hpp"
#include "qrane_timer.hpp"

#ifdef QRANE_USE_AQUMA
#include "aquma.hpp"
#endif

#define RECURSION_DEPTH_BOUND 4
#define RECURSION_SUBSTR_SIZE_BOUND 50
#define RECURSION_SUBSTR_OCCURRENCE_BOUND 2
#define DECOMP_SUBSTR_SIZE_BOUND 50

namespace qrane {

typedef std::pair<std::vector<int>, std::vector<unsigned int>>
    qrane_substr_result;
typedef std::vector<qrane_substr_result> qrane_circuit_decomp;
typedef std::map<int, std::vector<int>> qrane_subcircuit_map;

class Host {

public:
  Host(qrane_options *opt, global_timer *timer);

  // These are the functions to fully drive qrane's functionality.
  int parse_options(int argc, char *argv[]);
  int check_input_output_isomorphism();

  int parse_circuit();
  int process_circuit();
  int run_checks();
  void print_scop();
  void print_stats();
  int output_to_files();
  output_scop_s *get_scop();

#ifdef QRANE_USE_AQUMA
  // Incorporating AQUMA for recursive decomposition
  int process_circuit_via_substring_decomposition();
#endif

private:
  qrane_options *opt;
  global_timer *timer;
  std::shared_ptr<Program> main_processor;
  std::shared_ptr<Program> check_processor;

  qrane_subcircuit_map subcircuit_map;
  int circuit_count;

#ifdef QRANE_USE_AQUMA
  std::vector<qrane_program> circuit_decomposition(aquma_graph *ag,
                                                   aquma_circuit *circ);
  qrane_substr_result substr_recursion(aquma_graph *ag);
  int set_fixed_aquma_options(aquma_options *aopt);
  aquma_circuit *read_aquma_circuit_from_qasm();
#endif

  std::vector<Program> generate_qrane_program_list_from_chunked_statements(
      std::vector<Statement> stmts_to_chunk);

  Program create_fresh_qrane_program(std::vector<Statement> stmts);

  std::vector<Program> generate_qrane_program_substrs(Program &mp);

  void merge_qubit_access_profiles(qubit_profile_map &a, qubit_profile_map &b);

  bool check_isomorphism();
  bool check_qubit_access_profile_equivalence();
  void parallel_process(std::vector<Program> &chunked);
  void sequential_process();
  std::string help_message();

  void modify_subcircuits(std::vector<std::vector<Program>::iterator> its);
  std::vector<Program>
  qrane_programs_from_substr_result(qrane_substr_result &result,
                                    std::vector<Statement> &statements_2Q);
  std::vector<Statement>
  collect_unpartitioned_statements(std::vector<Program> &subcircuits);
  void sort_mainprograms(std::vector<Program> &mps);
  void testing(std::vector<Program> mps);
};
} // namespace qrane
#endif
