// /*
// Qrane
// Filename: qrane_mainprogram.hh
// Creation date: June 28, 2020
// Copyright (C) 2020

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// */

// #ifndef QRANE_MAINPROGRAM
// #define QRANE_MAINPROGRAM

// #include <array>
// #include <vector>
// #include <queue>
// #include <string>
// #include <stdlib.h>
// #include <iostream>
// #include <utility>
// #include <map>
// #include <set>
// #include <list>
// #include <stack>
// #include <chrono>
// #include "isl/ctx.h"
// #include "isl/space.h"
// #include "isl/id.h"
// #include "isl/set.h"
// #include "isl/map.h"
// #include "isl/union_set.h"
// #include "isl/union_map.h"
// #include "isl/schedule.h"
// #include "isl/ast.h"
// #include "isl/flow.h"
// #include "isl/ast_build.h"
// #include "isl/constraint.h"
// #include "qrane_stmtlist.hh"
// #include "qrane_domain.hh"
// #include "qrane_deps.hh"
// #include "qrane_statement.hh"
// #include "qrane_qop.hh"
// #include "qrane_decl.hh"
// #include "qrane_shared.hh"
// #include "qrane_flags.hh"
// #include "qrane_shared.hh"
// #include "qrane_scop.hh"
// #include "qrane_utils.hh"
// #include "qrane_options.hh"

// struct VectorOfIntsHasher
// {
// 	std::size_t operator()(const std::vector<int> &V) const {
// 		std::size_t val = 0;
// 		std::hash<int> hasher;
//     	for (const auto n : V) {
//         	val ^= hasher(n) + 0x9e3779b9 + (val << 6) + (val >> 2);
//     	}
//     	return val;
// 	}
// };

// typedef std::map<unsigned int, qrane_domain> domain_map_t;

// typedef std::vector<std::pair<lex_type, std::vector<unsigned int>>> candidate_list;

// typedef std::unordered_map<std::vector<int>, std::pair<lex_type, std::deque<unsigned int>>, VectorOfIntsHasher> access_graph;

// enum frame_element {
// 	ID = 0,
// 	STRIDE,
// 	LEX_TYPE,
// 	VISITED,
// 	PATH
// };
// typedef std::stack<std::tuple<unsigned int, int, lex_type, std::unordered_map<unsigned int, bool>, std::vector<unsigned int>>> frame_stack;


// class qrane_mainprogram {

//   private:
// 	const qrane_options* opt;
//     qrane_stmtlist *stmtlist;                         // openQASM statements parsed by Bison
//     qrane_deps deps;
//     std::string codegen_c_str;                        // String to store codegen output with ISL_FORMAT_C flag enabled
//     unsigned int num_qops;                            // Number of qops in the file
// 	unsigned long long num_points;
// 	unsigned long long num_qubit_exprs;

//     unsigned int subcircuit_num;

//     qasm_ops_list qops_list;
// 	plinko_grid circuit;
//     std::unordered_map<std::string, std::vector<qrane_domain>> gate_domain_map; // Group domains by gate type
// 	std::vector<qrane_domain> original_domains;
//     std::vector<qrane_domain> unchanged_domains;

// 	domain_map_t domain_map;

//     // ISL Specific Objects
//     isl_ctx *ctx;                                     // context for this program
//     isl_union_map* default_schedule;                  // default schedule for this program
//     isl_printer* printer;                             // printer for displaying objects
//     t_qrane_scop* scop;

//     // ISL interaction for 1D sets and maps
//     __isl_give isl_union_set* initialize_domain();
// 	__isl_give isl_union_map* initialize_read_relations();
// 	__isl_give isl_union_map* initialize_write_relations();
// 	__isl_give isl_union_map* initialize_call_relations();
// 	__isl_give isl_union_map* initialize_recovered_schedule(SCHEDULE_ALGORITHM SCHEDULE_MODE);

//     // ISL interaction for 2D sets and maps
//     __isl_give isl_set* build_ND_domain_from_sets(std::vector<qrane_domain>& mergees);
//     __isl_give isl_mat* compute_access_relations(isl_mat* mat);
// 	__isl_give isl_mat* concat_matrices_dimwise(std::vector<qrane_domain>& mergees);
// 	void attempt_merge(std::vector<qrane_domain>& resultant, std::vector<qrane_domain> domains);
//     __isl_keep bool check_consistency(isl_mat* mat, std::size_t dim, std::size_t args);
// 	bool integral_matrix(isl_mat* mat, std::size_t dim, std::size_t args);
// 	__isl_give isl_mat* append_column_with_val(__isl_take isl_mat* mat, int val);
	
// 	std::list<qrane_domain> greedy_nd_domain_selection(std::list<qrane_domain> candidates);

// 	// Circuit processing
// 	void convert_vector_form_to_plinko_grid();
// 	void process_ddg();
// 	void process_circuit();
// 	std::vector<unsigned int> get_ones_from_level(std::vector<unsigned int>& level);
// 	std::vector<unsigned int> get_twos_from_level(std::vector<unsigned int>& level);
// 	std::vector<unsigned int> find_longest_ones_path(std::vector<unsigned int>& ones, std::size_t qreg_size);
// 	std::vector<unsigned int> find_longest_twos_path(std::vector<unsigned int>& twos, std::size_t qreg_size);
// 	std::vector<unsigned int> get_most_frequent_gate_type(const std::vector<unsigned int>& level);
// 	std::vector<unsigned int> one_qubit_clearing_policy(std::vector<unsigned int>& level);
// 	std::vector<unsigned int> look_ahead_policy(std::vector<unsigned int>& level, unsigned int depth);
// 	std::array<unsigned int, 2> dependence_graph_lookahead(std::vector<unsigned int>& path, unsigned int depth);

// 	// Data structure interaction during circuit processing
// 	plinko_grid generate_plinko_grid(qasm_ops_list& qops, unsigned int qreg_size);
// 	stride_graph generate_stride_graph(const std::vector<unsigned int>& level, unsigned int qreg_size, unsigned int args);
// 	ray_graph generate_ray_graph(const std::vector<unsigned int>& level, unsigned int qreg_size);
// 	std::vector<unsigned int> get_next_grid_row(plinko_grid& P, std::vector<bool>& seen, unsigned int qreg_size);
// 	std::vector<unsigned int> longest_path_search(stride_graph& G, std::vector<unsigned int> ordering);
// 	std::vector<unsigned int> longest_valid_path_search(stride_graph G, std::vector<unsigned int> ordering);
// 	std::vector<unsigned int> get_longest_valid_path(std::vector<std::vector<unsigned int>> paths);
// 	std::array<unsigned int, 2> look_ahead(plinko_grid circuit, unsigned int depth);

// 	void combine_domains();
// 	bool domains_time_space_subset(const qrane_domain& i, const qrane_domain& j);
// 	bool domains_have_different_gate_type(unsigned int lhs, unsigned int rhs);
// 	bool domains_lex_mismatch(unsigned int lhs, unsigned int rhs);
// 	lex_type domains_lex_order(unsigned int i, unsigned int j);
// 	domain_map_t greedy_domain_selection(access_graph& G, unsigned int current_dim);
// 	qrane_domain merge_domains(const std::vector<unsigned int>& domains, lex_type lex, unsigned int current_dim);
// 	__isl_give isl_set* combine_isl_local_domains(const std::vector<unsigned int>& domains, unsigned int current_dim);
// 	__isl_give isl_mat* combine_access_matrices(const std::vector<unsigned int>& domains, unsigned int current_dim);
// 	bool inconsistent_or_rational_matrix(const std::vector<unsigned int>& domains, unsigned int current_dim);
// 	bool extended_domain_inconsistent(unsigned int new_dom, std::vector<unsigned int> path, unsigned int current_dim);
// 	bool extended_domain_inconsistent(unsigned int lhs, unsigned int rhs, unsigned int current_dim);
// 	domain_map_t greedy_domain_selection(candidate_list candidates, unsigned int current_dim);

// 	//qrane_domain create_fresh_domain(isl_ctx* ctx, unsigned int num_domains, std::vector<unsigned int>& path);
// 	void create_fresh_domain(isl_ctx* ctx, std::vector<unsigned int>& path);


//     // Parsing-specific functions
//     void parse_1D_domains();
//     void parse_ND_domains();
// 	void parse_ND_domains_cover(unsigned int current_dim); 
// 	void parse_domains_divide_and_conquer();
	
//     void gate_map_store_domain(qrane_domain dom);
// 	void add_dependence_vertex(qrane_qop* qop);
// 	__isl_give isl_union_map* initialize_arguments_map();
//    	std::string build_union_read_str();
//     std::string build_union_write_str();
// 	std::string build_union_call_str();

// 	// Functions for doing the graph version 1D domains
// 	void parse_with_bipartition_cover();
// 	void convert_stmtlist_to_vector_form();
// 	qop_identifier generate_qop_identifier(qrane_qop* qop, std::size_t qop_num_type);
// 	void sort_favor_linearity(qasm_ops_list& ops_list);
// 	bool dependence_constrained_lex_order(const qop_identifier& a, const qop_identifier& b);

// 	void sort_domains(std::vector<qrane_domain>& domains);
// 	bool time_constrained_lex_order(const qrane_domain& a, const qrane_domain& b);
// 	bool domain_num_order(const qrane_domain& a, const qrane_domain& b);
// 	std::string print_domain_size_histogram(std::vector<qrane_domain> dom_list);


//   public:
//   	qrane_mainprogram();
//     qrane_mainprogram(const qrane_options* opt);
//     ~qrane_mainprogram();
// 	bool qreg_seen;
// 	std::size_t qreg_size;

// 	void set_dependences();
// 	void full_stack_transformation();

// 	__isl_give isl_union_flow* compute_dependences();
// 	void compute_transformation();

//     // Functions for parser interaction
//     void parse_domains();
// 	void generate_ddg_only();
// 	void build_dependence_graph();
//     void add_stmtlist(qrane_stmtlist *stmtlist);
//     qrane_stmtlist* get_stmtlist();
//     std::string get_registers(); 

// 	void set_scop(t_qrane_scop* new_scop);
// 	void set_subcircuit_num(unsigned int num);
// 	unsigned int get_num_domains();
// 	unsigned long long get_num_points();
// 	std::string get_domain_profile_str();
// 	std::string get_graphml_str();
// 	std::string get_networkx_edge_list_str();
// 	void increment_num_qops();
// 	unsigned int get_num_qops();
// 	void set_num_qops(unsigned int num_qops);
// 	unsigned long long get_num_qubit_exprs();

// 	t_qrane_scop* get_scop();
// 	qrane_output_scop* get_output_scop();
	
//     // Accessing ISL functionality
//     void build_isl_domain_read_write_schedule(SCHEDULE_ALGORITHM SCHEDULE_MODE);
//     void print_isl_domain_read_write_schedule();
// 	void print_membership_graph();

//     std::string generate_codegen_c_str();
// 	bool check_all_qops_accounted();
//     bool check_recovered_respects_dependencies();
// 	std::string get_domain_list_str();
// 	std::string get_qubit_profile_str();
// 	std::string get_aquma_scop_str();
// 	std::string get_qubit_access_profile_str();
// 	std::string get_domain_size_histogram_str();
// 	std::string get_reconstruction_histogram_str();
// 	std::string print_reconstruction_histogram(std::vector<qrane_domain> dom_list);
// };

// #endif
