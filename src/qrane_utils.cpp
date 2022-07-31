#include "qrane_utils.hpp"

#include <cmath>
#include <fstream>
#include <functional>
#include <regex>

#include "assert.h"

namespace qrane {

namespace Utils {

std::vector<qop_id> stride_graph_long_path_search(
    DependenceProfile& dependence_profile const
        std::map<qop_id, std::shared_ptr<Qop>>& all_qops) {
  std::vector<qop_id> group;

  // Get the current frontier
  auto subset = dependence_profile.get_dependence_frontier();

  // Split the frontier into one- and two-qubit qops
  auto one_qubit_qops = get_one_qubit_qops(subset, all_qops);
  one_qubit_qops = get_qops_of_most_common_gate_type(one_qubit_qops, all_qops);
  auto two_qubit_qops = get_two_qubit_qops(subset, all_qops);
  two_qubit_qops = get_qops_of_most_common_gate_type(two_qubit_qops, all_qops);

  // Always clear out one-qubit qops if any were in the frontier
  if (one_qubit_qops.empty()) {
    group =
        stride_graph_longest_path_of_constant_weight(two_qubit_qops, all_qops);
  } else {
    group =
        stride_graph_longest_path_of_constant_weight(one_qubit_qops, all_qops);
  }

  // SIDE-EFFECT: Remove the subset from the frontier
  dependence_profile_.remove_frontier_subset(subset);

  return group;
}

// Anonymous namespace private to Utils namespace.
namespace {

std::vector<qop_id> get_one_qubit_qops(
    const std::vector<qop_id>& frontier,
    const std::map<qop_id, std::shared_ptr<Qop>>& all_qops) {
  std::vector<qop_id> one_qubit_qops;
  for (const auto& id : frontier) {
    if (all_qops.at(id)->is_1Q_gate()) {
      one_qubit_qops.push_back(id);
    }
  }
  return one_qubit_qops;
};

std::vector<qop_id> get_two_qubit_qops(
    const std::vector<qop_id>& frontier,
    const std::map<qop_id, std::shared_ptr<Qop>>& all_qops) {
  std::vector<qop_id> one_qubit_qops;
  for (const auto& id : frontier) {
    if (all_qops.at(id)->is_1Q_gate()) {
      one_qubit_qops.push_back(id);
    }
  }
  return one_qubit_qops;
};

std::vector<qop_id> get_qops_of_most_common_gate_type(
    const std::vector<qop_id>& subset,
    const std::map<qop_id, std::shared_ptr<Qop>>& all_qops) {
  std::map<std::string, std::vector<qop_id>> gate_types;

  // Collect qops of each gate type
  for (const auto& id : subset) {
    auto gate = all_qops.at(id)->name();
    gate_types[gate].push_back(id);
  }

  // Find the maximum count
  auto max = std::max_element(
      gate_types.begin(), gate_types.end(),
      [](const std::pair<std::string, std::vector<qop_id>>& a,
         const std::pair<std::string, std::vector<qop_id>>& b) {
        return a.second.size() < b.second.size();
      });
  return max->second;
};

std::vector<qop_id> stride_graph_longest_path_of_constant_weight(
    const std::vector<qop_id>& subset,
    const std::map<qop_id, std::shared_ptr<Qop>>& all_qops) {
  // Generate the stride_graph and edge_weights
  StrideGraph SG = generate_stride_graph(subset, all_qops);
}

StrideGraph generate_stride_graph(
    const std::vector<qop_id>& subset,
    const std::map<qop_id, std::shared_ptr<Qop>>& all_qops) {
  StrideGraph ret;
  ret.G = Graph<qop_id>();
  ret.W = edge_properties_t<qop_id, int>();

  for (const auto& u : subset) {
    for (const auto& v : subset) {
    }
  }
}

}  // namespace
}  // namespace Utils
}  // namespace qrane

//////// OLD /////////

// 		template<typename A, typename B>
// 		std::initializer_list<A> get_map_keys_as_initializer_list(const
// std::map<A, B>& m) { 			const std::size_t m_size = m.size();
// std::size_t i = 0; 			std::array<A, m_size> tmp; 			for (const auto& element : m) {
// 				tmp[i] = element.first;
// 				++i;
// 			}
// 			return std::initializer_list<A>(std::move(tmp));
// 		}

// 		std::vector<std::shared_ptr<Element>>
// splice_stmtlist(std::vector<std::shared_ptr<Element>> stmts,
// 			std::vector<unsigned int>& locs, unsigned int len) {

// 			std::vector<std::shared_ptr<Element>> ret =
// std::vector<std::shared_ptr<Element>>(); 			unsigned int
// len_countdown = 0;

// 			for (unsigned int i = 0; i < stmts.size(); ++i) {
// 				if (std::find(locs.begin(), locs.end(), i) !=
// locs.end())
// { 					len_countdown = len - 1; 				}
// else if (len_countdown > 0) { 					len_countdown
// -= 1; 				} else {
// ret.push_back(stmts.at(i));
// 				}
// 			}
// 			return ret;
// 		}

// 		std::vector<std::vector<std::shared_ptr<Element>>>
// split_into_n_components( 			std::vector<std::shared_ptr<Element>>
// stmts,
// unsigned int chunks) { 			int size = (stmts.size() - 1) / chunks
// + 1;

// 			// create an array of vectors to store the sub-vectors
// 			auto vec =
// std::vector<std::vector<std::shared_ptr<Element>>>(size);

// 			// each iteration of this loop process the next set of
// `n` elements
// 			// and store it in a vector at k'th index in `vec`
// 			for (int k = 0; k < size; ++k)
// 			{
// 				// get range for the next set of `n` elements
// 				std::vector<std::shared_ptr<Element>>::iterator
// start_itr = std::next(stmts.begin(), k*chunks);
// 				std::vector<std::shared_ptr<Element>>::iterator end_itr
// = std::next(stmts.begin(), k*chunks + chunks);

// 				// allocate memory for the sub-vector
// 				vec[k].resize(chunks);

// 				// code to handle the last sub-vector as it
// might
// 				// contain fewer elements
// 				if (k*chunks + chunks > stmts.size())
// 				{
// 					end_itr = stmts.end();
// 					vec[k].resize(stmts.size() - k*chunks);
// 				}

// 				// copy elements from the input range to the
// sub-vector 				std::copy(start_itr, end_itr,
// vec[k].begin());
// 			}
// 			return vec;
// 		};

// 		bool is_target_vertex(const std::pair<qop_id, int>& a, qop_id v)
// { 			return a.first == v;
// 		}

// 		void adj_list_remove_vertex(stride_graph& G, qop_id v) {
// 			for (auto& elem : G) {
// 				auto& un = G[elem.first];
// 				un.erase(std::remove_if(un.begin(), un.end(),
// 						std::bind(is_target_vertex,
// std::placeholders::_1, v)), un.end());
// 			}
// 			G.erase(v);
// 		};

// 		std::vector<qop_id> adj_list_topological_ordering(stride_graph
// G)
// { 			std::size_t num_v = G.size();
// std::unordered_map<qop_id, bool>
// visited(num_v); 			for (auto elem : G) { visited[elem.first] =
// false; } 			std::stack<qop_id> ordering = std::stack<qop_id>();

// 			for (auto elem : G) {
// 				if (!visited[elem.first]) {
// 					adj_list_topological_ordering_util(elem.first,
// G, visited, ordering);
// 				}
// 			}

// 			std::vector<qop_id> result;
// 			std::size_t ordering_size = ordering.size();
// 			for (std::size_t i = 0; i < ordering_size; ++i) {
// 				result.push_back(ordering.top());
// 				ordering.pop();
// 			}
// 			return result;
// 		}

// 		void adj_list_topological_ordering_util(qop_id start,
// stride_graph& G, std::unordered_map<qop_id, bool>& visited,
// std::stack<qop_id>& ordering) { 			visited[start] = true; 			for (std::size_t i =
// 0; i < G[start].size(); ++i) { 				unsigned int neighbor = G[start][i].first; 				if
// (!visited[neighbor]) { 					adj_list_topological_ordering_util(neighbor, G,
// visited, ordering);
// 				}
// 			}
// 			ordering.push(start);
// 		}

// 		bool queue_size_predicate(const std::deque<unsigned int>& lhs,
// const std::deque<unsigned int>& rhs) { 			return lhs.size() <
// rhs.size();
// 		}

// 		bool is_integer(const float m) {
// 			if (std::abs(std::roundf(m) - m) <= 0.00000f) {
// 				return true;
// 			} else {
// 				return false;
// 			}
// 		};

// 		int generate_c_test_file(std::string c_name, std::string
// qasm_name, std::string codegen_c_str, std::string qreg_decls, std::string
// rv_map) { 		std::ofstream ofile; 		std::string ofile_name(c_name);
// 		ofile.open(ofile_name);
// 		if (!ofile.is_open()) { return 1; }

// 		const char* macros =	"#ifdef ceild\n"
// 								"#undef ceild\n"
// 								"#endif\n"
// 								"#ifdef
// floord\n"
// 								"#undef
// floord\n"
// 								"#endif\n"
// 								"#ifdef max\n"
// 								"#undef max\n"
// 								"#endif\n"
// 								"#ifdef min\n"
// 								"#undef min\n"
// 								"#endif\n"
// 								"#define ceild(n,d)  (((n) <
// 0)?
// -((-(n))/(d)) : ((n)+(d)-1)/(d))\n"
// 								"#define floord(x,y) (((x) <
// 0)?
// -((-(x)+(y)-1)/(y)) : (x)/(y))\n"
// 								"#define max(x,y)    ((x) > (y)?
// (x) : (y))\n"
// 								"#define min(x,y)    ((x) < (y)?
// (x) : (y))\n";

// 			// qasm output file from C test file
// 			std::string qfile(qasm_name);
// 			std::string qelib("\\\"qelib1.inc\\\"");

// 			ofile << "#include \"stdio.h\"" << std::endl;
// 			ofile << "#include <vector>" << std::endl;
// 			ofile << "#include <map>" << std::endl;
// 			ofile << std::endl;
// 			ofile << macros << std::endl;
// 			ofile << "using namespace std;" << std::endl;
// 			ofile << rv_map << std::endl;
// 			ofile << std::endl << "int main() {" << std::endl;
// 			ofile << "FILE *f = fopen(\"" << qfile << "\", \"w\");"
// << std::endl;
// 			//ofile << "fprintf(f, \"OPENQASM 2.0;\\ninclude " << qelib
// <<
// ";\\n" << qreg_decls << "\");" << std::endl; 			ofile <<
// codegen_c_str; 			ofile << "fclose(f);\nreturn 0;" <<
// std::endl << "}"; 			ofile.close(); 			return
// 0;
// 		};

// 		std::vector<qop_id> read_qop_id_sequence(std::string filename) {
// 			fstream fstrm;
// 			fstrm.open(filename, ios::in);
// 			if (fstrm.is_open()) {
// 					std::vector<qop_id> ret;
// 					string temp;
// 					while(getline(fstrm, temp)) {
// 						ret.push_back(std::stoul(temp));
// 					}
// 					fstrm.close();
// 					return ret;
// 			} else {
// 				return std::vector<qop_id>();
// 			}
// 		};

// 		std::vector<int> vectorize_isl_mat(__isl_keep isl_mat* mat) {
// 			assert(mat != NULL);
// 			int cols = isl_mat_cols(mat);
// 			int rows = isl_mat_rows(mat);
// 			std::vector<int> ret;
// 			ret.reserve(rows*cols);

// 			isl_val* val = NULL;
// 			for (int i = 0; i < rows; ++i) {
// 				for (int j = 0; j < cols; ++j) {
// 					val = isl_mat_get_element_val(mat, i,
// j); 					ret.push_back(isl_val_get_num_si(val));
// 				}
// 			}
// 			if (val) {
// 				isl_val_free(val);
// 				isl_mat_free(mat);
// 			}
// 			return ret;
// 		}

// 		__isl_give isl_mat* get_zero_matrix(isl_ctx* ctx, isl_size rows,
// isl_size cols) { 			isl_mat* ret = isl_mat_alloc(ctx, rows,
// cols); 			for (int i =
// 0; i < rows; ++i) { 				for (int j = 0; j < cols; ++j) {
// ret = isl_mat_set_element_si(ret, i, j, 0);
// 				}
// 			}
// 			return ret;
// 		}

// 		std::vector<int> find_zero_cols(__isl_keep isl_mat* mat, int
// col_lb, int col_ub) { 			std::vector<int> ret_cols;
// isl_size rows = isl_mat_rows(mat); 			isl_val* tmp;
// bool found_nonzero;

// 			for (int col = col_lb; col < col_ub; ++col) {
// 				found_nonzero = false;
// 				for (int row = 0; row < rows; ++row) {
// 					tmp = isl_mat_get_element_val(mat, row,
// col); 					if (!isl_val_is_zero(tmp)) {
// found_nonzero = true; 						break;
// 					}
// 				}
// 				if (!found_nonzero) {
// 					ret_cols.push_back(col);
// 				}
// 			}
// 			return ret_cols;
// 		}

// 		__isl_give isl_mat* drop_zero_cols(__isl_take isl_mat* mat,
// std::vector<int> cols_to_drop) { 			isl_mat* ret_mat =
// isl_mat_copy(mat);

// 			for (std::size_t i = 0; i < cols_to_drop.size(); ++i) {
// 				ret_mat = isl_mat_drop_cols(ret_mat,
// cols_to_drop[i], 1);
// 			}
// 			isl_mat_free(mat);
// 			return ret_mat;
// 		};

// 		/*
// 			EXPECTS MATRIX TO BE IN REF

// 			isl uses reverse gauss-jordan elimination to compute
// 			row basis, so backwards substitution goes from top
// 			left to bottom right.

// 			Problem case:  This matrix is consistent, but the
// results 			are rational numbers. Need to account for this.
// 			[[5,0,2,0,0,0]
// 			[-19,1,0,1,0,0]
// 			[-23,0,0,0,2,0]
// 			[0,0,0,0,0,1]]
// 		*/
// 		isl_mat* back_substitute_isl_mat(isl_ctx* ctx, __isl_keep
// isl_mat*
// mat, int args, int dim) { 			isl_mat* access_mat_copy =
// isl_mat_copy(mat); 			int access_rows = isl_mat_rows(mat);

// 			// First find any dim columns that are zero and record
// them. 			int dim_cols_lb = 2*args; 			int dim_cols_ub
// = isl_mat_cols(mat); 			std::vector<int> zero_cols = find_zero_cols(mat,
// dim_cols_lb, dim_cols_ub); 			int num_zero_cols =
// zero_cols.size();

// 			// Unless there are zero cols, the rows of coeff_mat is
// equal to args
// 			// and the cols of coeff_mat is equal to dim + 1 (offset
// column) 			isl_size coeff_rows = args; 			isl_size
// coeff_cols = dim + 1;

// 			// Then drop those columns from the access_mat and
// update
// 			// the number of columns of necessary
// 			isl_mat* w_access_mat;
// 			if (num_zero_cols > 0) {
// 				w_access_mat = drop_zero_cols(access_mat_copy,
// zero_cols); 				coeff_cols -= num_zero_cols; 			}
// else { 				w_access_mat = access_mat_copy;
// 			}
// 			//std::cout << "After drops access_mat:" << std::endl <<
// std::flush;
// 			//isl_mat_dump(w_access_mat);

// 			// Initialize the coeff_mat
// 			isl_mat* coeff_mat = get_zero_matrix(ctx, coeff_rows,
// coeff_cols); 			isl_val* wrk1; 			isl_val* wrk2;
// isl_val* wrk3;

// 			// Need to do back substitution for each argument
// 			for(int arg = args; arg-- > 0;) {
// 				//std::cout << "arg: " << arg << std::endl <<
// std::flush;

// 				for (int row = 0; row < access_rows; ++row) {
// 					// x[i] = a(i,n)
// 					// We compute coefficients starting with the
// offset going to highest dim
// 					// Thus, we start on the right-most side of
// the
// coeff_mat and work leftwards 					int coeff_col =
// -1*row+(coeff_cols-1);

// 					// arg_col is the column of access_mat that
// arg refers to,
// 					// i.e. for ccx: arg0->col4, arg1->col2,
// arg0->col0 					int arg_col = -2*arg+(2*args-2);
// wrk1 = isl_mat_get_element_val(w_access_mat, row, arg_col);
// coeff_mat = isl_mat_set_element_val(coeff_mat, arg, coeff_col, wrk1);

// 					// ub was here too
// 					for (int index = 0; index < row;
// ++index)
// { 						int arg_col; 						if
// (index == 0) { 							arg_col = (2*args-1)-2*arg;
// } else { 							arg_col =
// 2*args+(index-1);
// 						}
// 						wrk1 = isl_mat_get_element_val(coeff_mat,
// arg, coeff_col); // x[i] 						wrk2 =
// isl_mat_get_element_val(w_access_mat, row, arg_col);  // a(i,j)
// wrk3 = isl_mat_get_element_val(coeff_mat, arg, -1*index+(coeff_cols-1)); //
// x[j] 						wrk2 = isl_val_mul(wrk2, wrk3); // a(i,j)
// *
// x[j] 						wrk1 = isl_val_sub(wrk1, wrk2); // x[i] -
// (a(i,j) * x[j]) 						coeff_mat =
// isl_mat_set_element_val(coeff_mat, arg, coeff_col, wrk1);
// 					}

// 					wrk1 = isl_mat_get_element_val(coeff_mat,
// arg, coeff_col); // x[i] 					int target;
// if (row == 0) { 						target =
// (2*args-1)-2*arg; 						wrk2 = isl_mat_get_element_val(w_access_mat, row, target);
// } else { 						target = 1*row+(2*args-1);
// wrk2 = isl_mat_get_element_val(w_access_mat, row, target);
// 					}

// 					//wrk1 = isl_val_div(wrk1, wrk2);
// 					coeff_mat = isl_mat_set_element_val(coeff_mat,
// arg, coeff_col, wrk1);
// 				}
// 			}

// 			for (int i = 0; i < num_zero_cols; ++i) {
// 				int col_to_insert =
// (dim_cols_ub-1)-1*zero_cols[i]; 				coeff_mat =
// isl_mat_insert_zero_cols(coeff_mat, col_to_insert, 1);
// 			}

// 			return coeff_mat;
// 		};

// 		void print_isl_mat(isl_mat* mat) {
// 			isl_size rows = isl_mat_rows(mat);
// 			isl_size cols = isl_mat_cols(mat);
// 			std::ostringstream strm;

// 			strm << "[";
// 			for (int i = 0; i < rows; ++i) {
// 				strm << "[";
// 				for (int j = 0; j < cols; ++j) {
// 					isl_val* val = isl_mat_get_element_val(mat,
// i,
// j); 					strm << isl_val_get_num_si(val) << " ";
// 				}
// 				strm << "]\n";
// 			}
// 			strm << " ]\n";

// 			std::cout << strm.str();
// 		}

// 	}
// }
