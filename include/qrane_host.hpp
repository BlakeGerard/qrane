#ifndef QRANE_HOST_H
#define QRANE_HOST_H

#include <memory>
#include <iostream>
#include <fstream>
#include <cstring>
#include <Python.h>
#include "unistd.h"
#include "getopt.h"
#include "omp.h"

#include "qrane-parser.h"
#include "qrane_ctr.hpp"
#include "qrane_options.hpp"
#include "qrane_timer.hpp"
#include "qrane_program.hpp"
#include "qrane_scop.hpp"
#include "qrane_routing.hpp"
#include "aquma.hpp"

#define RECURSION_DEPTH_BOUND 4
#define RECURSION_SUBSTR_SIZE_BOUND 50
#define RECURSION_SUBSTR_OCCURRENCE_BOUND 2
#define DECOMP_SUBSTR_SIZE_BOUND 50

typedef std::pair<std::vector<int>, std::vector<unsigned int>> qrane_substr_result;
typedef std::vector<qrane_substr_result> qrane_circuit_decomp;
typedef std::map<circuit_id, std::vector<circuit_id>> qrane_subcircuit_map;

class qrane_host {

	private:
		qrane_options* opt;
		qrane_timer* timer;
		std::shared_ptr<qrane_program> main_processor;
		std::shared_ptr<qrane_program> check_processor;

		qrane_subcircuit_map subcircuit_map;
		circuit_id circuit_count;

		std::vector<qrane_program> circuit_decomposition(aquma_graph* ag, aquma_circuit* circ);
		qrane_substr_result substr_recursion(aquma_graph* ag);

		std::vector<qrane_program> generate_qrane_program_list_from_chunked_statements(
			qrane_statementlist stmts_to_chunk);

		qrane_program create_fresh_qrane_program(
			qrane_statementlist stmts);

		std::vector<qrane_program> generate_qrane_program_substrs(qrane_program& mp);

		void merge_qubit_access_profiles(qubit_profile_map& a, qubit_profile_map& b);

		int set_fixed_aquma_options(aquma_options* aopt);
		aquma_circuit* read_aquma_circuit_from_qasm();

		bool check_isomorphism();
		bool check_qubit_access_profile_equivalence();
		void parallel_process(std::vector<qrane_program>& chunked);
		void sequential_process();
		std::string help_message();

		void modify_subcircuits(std::vector<std::vector<qrane_program>::iterator> its);
		std::vector<qrane_program> qrane_programs_from_substr_result(qrane_substr_result& result,
			qrane_statementlist& statements_2Q);
		qrane_statementlist collect_unpartitioned_statements(std::vector<qrane_program>& subcircuits);
		void sort_mainprograms(std::vector<qrane_program>& mps);
		void testing(std::vector<qrane_program> mps);

	public:
		qrane_host(qrane_options* opt, qrane_timer* timer);

		// These are the functions to fully drive qrane's functionality.
		int parse_options(int argc, char* argv[]);
		int check_input_output_isomorphism();

		int parse_circuit();
		int process_circuit();
		int run_checks();
		void print_scop();
		void print_stats();
		int output_to_files();
		qrane_output_scop* get_scop();

		// Incorporating AQUMA for recursive decomposition
		int process_circuit_via_substring_decomposition();
};

#endif
