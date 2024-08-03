#ifndef QRANE_UTILS_HPP
#define QRANE_UTILS_HPP

#include <iostream>
#include <memory>
#include <stack>
#include <string>

#include "qrane_dependence_profile.hpp"
#include "qrane_qop.hpp"
#include "qrane_shared.hpp"
#include "isl/mat.h"
#include "isl/val.h"

namespace qrane {

namespace Utils {

struct StrideGraph {
  Graph<qop_id> G;
  edge_properties_t<qop_id, int> W;
};

std::vector<qop_id> stride_graph_long_path_search(
    DependenceProfile &dependence_profile,
    const std::map<qop_id, std::shared_ptr<Qop>> &all_qops);
} // namespace Utils
} // namespace qrane

#endif

////////// OLD //////////

// template<typename A, typename B>
// std::initializer_list<A> get_map_keys_as_initializer_list(const std::map<A,
// B>& m);

// // qrane_statement splicing
// std::vector<std::shared_ptr<Element>>
// splice_stmtlist(std::vector<std::shared_ptr<Element>> stmts,
// 	std::vector<unsigned int>& locs, unsigned int len);
// std::vector<std::vector<std::shared_ptr<Element>>>
// split_into_n_components(std::vector<std::shared_ptr<Element>> stmts, unsigned
// int chunks);

// // For generating compileable C file to produce OpenQASM
// int generate_c_test_file(std::string c_name, std::string qasm_name,
// std::string codegen_c_str, std::string qreg_decls, std::string rv_map);

// std::vector<int> read_qop_id_sequence(std::string filename);

// // legacy stride_graph still in use
// // Need to convert to qrane_graph
// void adj_list_remove_vertex(stride_graph& G, qop_id v);
// std::vector<qop_id> adj_list_topological_ordering(stride_graph G);
// void adj_list_topological_ordering_util(qop_id start, stride_graph& G,
// std::unordered_map<qop_id, bool>& visited, std::stack<qop_id>& ordering);

// // Some misc helpers
// bool queue_size_predicate(const std::deque<unsigned int>& lhs, const
// std::deque<unsigned int>& rhs); bool is_integer(const float m);

// // Matrix methods
// std::vector<int> vectorize_isl_mat(__isl_keep isl_mat* mat);
// isl_mat* back_substitute_isl_mat(isl_ctx* ctx, __isl_keep isl_mat* mat, int
// args, int dim);
// __isl_give isl_mat* get_zero_matrix(isl_ctx* ctx, isl_size rows, isl_size
// cols); std::vector<int> find_zero_cols(__isl_keep isl_mat* mat, int col_lb,
// int col_ub);
// __isl_give isl_mat* drop_zero_cols(__isl_take isl_mat* mat, std::vector<int>
// cols_to_drop); void print_isl_mat(isl_mat* mat);
