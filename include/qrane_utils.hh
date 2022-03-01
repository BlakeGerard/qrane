#ifndef QRANE_UTILS_H
#define QRANE_UTILS_H

#include <string>
#include <iostream>
#include <stack>
#include "isl/mat.h"
#include "isl/val.h"
#include "qrane_shared.hh"
#include "aquma.hh"

namespace qrane_utils {
	void splice_stmtlist(std::vector<qrane_statement*>& stmts, 
		std::vector<unsigned int>& locs, unsigned int len);
	std::vector<std::vector<qrane_statement*>> split_into_n_components(std::vector<qrane_statement*> stmts, unsigned int chunks);
	int generate_c_test_file(std::string c_name, std::string qasm_name, std::string codegen_c_str, std::string qreg_decls);
	void adj_list_remove_vertex(stride_graph& G, unsigned int v);
	std::vector<unsigned int> adj_list_topological_ordering(stride_graph G);
	void adj_list_topological_ordering_util(unsigned int start, stride_graph& G, std::unordered_map<unsigned int, bool>& visited, std::stack<unsigned int>& ordering);
	void adj_list_print(stride_graph& G);
	void plinko_grid_print(plinko_grid& P, qasm_ops_list& qops_list);
	void ray_graph_print(ray_graph& G);
	

	bool queue_size_predicate(const std::deque<unsigned int>& lhs, const std::deque<unsigned int>& rhs);

	bool is_integer(const float m);

	// Matrix methods
	std::vector<int> vectorize_isl_mat(__isl_keep isl_mat* mat);
	isl_mat* back_substitute_isl_mat(isl_ctx* ctx, __isl_keep isl_mat* mat, unsigned int args, unsigned int dim);
	__isl_give isl_mat* zero_matrix(isl_ctx* ctx, isl_size rows, isl_size cols);
	std::vector<int> find_zero_cols(__isl_keep isl_mat* mat, int col_lb, int col_ub);
	__isl_give isl_mat* drop_zero_cols(__isl_take isl_mat* mat, std::vector<int> cols_to_drop);
	void print_isl_mat(isl_mat* mat);

	// Templated Functions
	template<typename T, typename A>
	void vector_print(const std::vector<T, A>& vect) {
		std::cout << "{ ";
		for (auto& val : vect) { std::cout << val << " "; }
		std::cout << "}\n";
	}
};

#endif
