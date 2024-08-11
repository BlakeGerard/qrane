#ifndef QRANE_HOST_H
#define QRANE_HOST_H

#include "getopt.h"
#include "omp.h"
#include "unistd.h"
#include <Python.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "qrane_ctr.hh"
#include "qrane_mainprogram.hh"
#include "qrane_options.hh"
#include "qrane_parser.h"
#include "qrane_scop.hh"
#include "qrane_timer.hh"

#ifdef QRANE_USE_AQUMA
#include "aquma.hh"
#endif

#define RECURSION_DEPTH_BOUND 4
#define RECURSION_SUBSTR_SIZE_BOUND 50
#define RECURSION_SUBSTR_OCCURRENCE_BOUND 2
#define DECOMP_SUBSTR_SIZE_BOUND 20

extern yy::qrane_parser::symbol_type yylex();
extern FILE *yyin;

typedef std::pair<std::vector<int>, std::vector<unsigned int>>
    qrane_substr_info;
typedef std::vector<qrane_substr_info> qrane_circuit_decomp;

typedef std::unordered_map<unsigned int, unsigned int> substr_new_id_map;

class qrane_host {

private:
  qrane_options *opt;
  qrane_timer *timer;
  qrane_mainprogram *main_processor;
  qrane_mainprogram *check_processor;

#ifdef QRANE_USE_AQUMA
  int set_fixed_aquma_options(aquma_options *aopt);
  aquma_circuit *read_aquma_circuit_from_qasm();
  std::vector<qrane_mainprogram> circuit_decomposition(aquma_graph *ag,
                                                       aquma_circuit *circ);
  qrane_substr_info substr_recursion(aquma_graph *ag);
  qrane_mainprogram generate_qrane_mainprogram_from_aquma_substr(
      qrane_substr_info &info, std::vector<qrane_statement *> &stmts,
      unsigned int subcircuit_num);
#endif

  std::vector<qrane_mainprogram>
  generate_qrane_mainprogram_list_from_chunked_statements(
      std::vector<qrane_statement *> stmts_to_chunk,
      unsigned int subcircuit_count);
  qrane_mainprogram
  create_fresh_qrane_mainprogram(std::vector<qrane_statement *> stmts,
                                 unsigned int subcircuit_num);

  void
  store_substrs_in_qrane_mainprogram(qrane_mainprogram &mp,
                                     qrane_substr_info &info,
                                     std::vector<qrane_statement *> stmts_2Q);
  std::vector<unsigned int> get_new_domain_ids_list(unsigned int cnt);
  std::vector<qrane_mainprogram>
  generate_qrane_mainprogram_substrs(qrane_mainprogram &mp);
  substr_new_id_map create_old_to_new_domain_map(qrane_mainprogram &mp);
  substr_new_id_map create_old_to_new_qop_map(qrane_mainprogram &mp,
                                              qrane_stmtlist *stmts);
  void merge_qubit_access_profiles(qubit_profile_map &a, qubit_profile_map &b);

  bool check_isomorphism();
  bool check_qubit_access_profile_equivalence();
  void parallel_process(std::vector<qrane_mainprogram> chunked);
  void sequential_process();
  std::string help_message();

  int validate_options() const;

public:
  qrane_host(qrane_options *opt, qrane_timer *timer);
  ~qrane_host();

  // These are the functions to fully drive qrane's functionality.
  int parse_options(int argc, char *argv[]);
  int check_input_output_isomorphism();

  int parse_circuit();
  int process_circuit();
  int run_checks();
  void print_scop();
  void print_stats();
  int output_to_files();
  qrane_output_scop *get_scop();

#ifdef QRANE_USE_AQUMA
  // Incorporating AQUMA for recursive decomposition
  int process_circuit_via_substring_decomposition();
#endif
};

#endif
