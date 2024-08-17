#include "qrane_utils.hh"
#include "assert.h"
#include <cmath>
#include <fstream>
#include <functional>
#include <regex>

void qrane_utils::splice_stmtlist(std::vector<qrane_statement *> &stmts,
                                  std::vector<unsigned int> &locs,
                                  unsigned int len) {

  unsigned int ss, tt;
  std::vector<qrane_statement *> temp;
  temp.resize(stmts.size() - len * locs.size());
  unsigned int segment;
  for (tt = 0, ss = 0, segment = 0;
       segment < locs.size() and ss < stmts.size();) {
    if (ss < locs[segment])
      temp[tt++] = stmts[ss++];
    else {
      std::cout << "Reached position " << locs[segment] << ", advancing ..."
                << std::endl;
      segment++;
      ss += len;
    }
  }
  for (; ss < stmts.size(); ss++, tt++) {
    temp[tt] = stmts[ss];
  }

  stmts.clear();
  stmts.resize(temp.size());
  stmts = temp;
}

std::vector<std::vector<qrane_statement *>>
qrane_utils::split_into_n_components(std::vector<qrane_statement *> stmts,
                                     unsigned int chunks) {
  int size = (stmts.size() - 1) / chunks + 1;

  // create an array of vectors to store the sub-vectors
  auto vec = std::vector<std::vector<qrane_statement *>>(size);

  // each iteration of this loop process the next set of `n` elements
  // and store it in a vector at k'th index in `vec`
  for (int k = 0; k < size; ++k) {
    // get range for the next set of `n` elements
    auto start_itr = std::next(stmts.cbegin(), k * chunks);
    auto end_itr = std::next(stmts.cbegin(), k * chunks + chunks);

    // allocate memory for the sub-vector
    vec[k].resize(chunks);

    // code to handle the last sub-vector as it might
    // contain fewer elements
    if (k * chunks + chunks > stmts.size()) {
      end_itr = stmts.cend();
      vec[k].resize(stmts.size() - k * chunks);
    }

    // copy elements from the input range to the sub-vector
    std::copy(start_itr, end_itr, vec[k].begin());
  }
  return vec;
};

bool is_target_vertex(const std::pair<unsigned int, int> &a, unsigned int v) {
  return a.first == v;
}

void qrane_utils::adj_list_remove_vertex(stride_graph &G, unsigned int v) {
  for (auto &elem : G) {
    auto &un = G[elem.first];
    un.erase(
        std::remove_if(un.begin(), un.end(),
                       std::bind(is_target_vertex, std::placeholders::_1, v)),
        un.end());
  }
  G.erase(v);
};

std::vector<unsigned int>
qrane_utils::adj_list_topological_ordering(stride_graph G) {
  std::size_t num_v = G.size();
  std::unordered_map<unsigned int, bool> visited(num_v);
  for (auto elem : G) {
    visited[elem.first] = false;
  }
  std::stack<unsigned int> ordering = std::stack<unsigned int>();

  for (auto elem : G) {
    if (!visited[elem.first]) {
      adj_list_topological_ordering_util(elem.first, G, visited, ordering);
    }
  }

  std::vector<unsigned int> result;
  std::size_t ordering_size = ordering.size();
  for (std::size_t i = 0; i < ordering_size; ++i) {
    result.push_back(ordering.top());
    ordering.pop();
  }
  return result;
}

void qrane_utils::adj_list_topological_ordering_util(
    unsigned int start, stride_graph &G,
    std::unordered_map<unsigned int, bool> &visited,
    std::stack<unsigned int> &ordering) {
  visited[start] = true;
  for (std::size_t i = 0; i < G[start].size(); ++i) {
    unsigned int neighbor = G[start][i].first;
    if (!visited[neighbor]) {
      adj_list_topological_ordering_util(neighbor, G, visited, ordering);
    }
  }
  ordering.push(start);
}

void qrane_utils::adj_list_print(stride_graph &G) {
  for (auto elem : G) {
    std::cout << elem.first << " -> [";

    for (auto op : elem.second) {
      std::cout << "(" << op.first << ", " << op.second << ") ";
    }
    std::cout << "]" << std::endl;
  }
};

void qrane_utils::plinko_grid_print(plinko_grid &P, qasm_ops_list &qops_list) {
  std::size_t m = 0;
  for (auto queue : P) {
    std::cout << m << ": [";
    while (!queue.empty()) {
      std::cout << queue.front();
      if (std::get<ARGS>(qops_list[queue.front()]).size() == 2) {
        std::cout << "*";
      }
      std::cout << " ";
      queue.pop_front();
    }
    std::cout << "]\n";
    ++m;
  }
};

void qrane_utils::ray_graph_print(ray_graph &G) {
  for (auto &entry : G) {
    std::cout << "(" << entry.first.first << ", " << entry.first.second
              << ") -> [";
    for (auto val : entry.second) {
      std::cout << val << " ";
    }
    std::cout << "]\n";
  }
};

bool qrane_utils::queue_size_predicate(const std::deque<unsigned int> &lhs,
                                       const std::deque<unsigned int> &rhs) {
  return lhs.size() < rhs.size();
}

bool qrane_utils::is_integer(const float m) {
  if (std::abs(std::roundf(m) - m) <= 0.00000f) {
    return true;
  } else {
    return false;
  }
};

int qrane_utils::generate_c_test_file(std::string c_name, std::string qasm_name,
                                      std::string codegen_c_str,
                                      std::string qreg_decls) {
  std::ofstream ofile;
  std::string ofile_name(c_name);
  std::cout << "opening file: " << ofile_name << std::endl;
  ofile.open(ofile_name);
  if (!ofile.is_open()) {
    return 1;
  }

  const char *macros =
      "#ifdef ceild\n"
      "#undef ceild\n"
      "#endif\n"
      "#ifdef floord\n"
      "#undef floord\n"
      "#endif\n"
      "#ifdef max\n"
      "#undef max\n"
      "#endif\n"
      "#ifdef min\n"
      "#undef min\n"
      "#endif\n"
      "#define ceild(n,d)  (((n) < 0)? -((-(n))/(d)) : ((n)+(d)-1)/(d))\n"
      "#define floord(x,y) (((x) < 0)? -((-(x)+(y)-1)/(y)) : (x)/(y))\n"
      "#define max(x,y)    ((x) > (y)? (x) : (y))\n"
      "#define min(x,y)    ((x) < (y)? (x) : (y))\n";

  // qasm output file from C test file
  std::string qfile(qasm_name);
  std::string qelib("\\\"qelib1.inc\\\"");

  ofile << "#include \"stdio.h\"" << std::endl << std::endl;
  ofile << macros;
  ofile << std::endl << "int main() {" << std::endl;
  ofile << "FILE *f = fopen(\"" << qfile << "\", \"w\");" << std::endl;
  ofile << "fprintf(f, \"OPENQASM 2.0;\\ninclude " << qelib << ";\\n"
        << qreg_decls << "\");" << std::endl;
  ofile << codegen_c_str;
  ofile << "fclose(f);\nreturn 0;" << std::endl << "}";
  ofile.close();
  return 0;
};

std::vector<int> qrane_utils::vectorize_isl_mat(__isl_keep isl_mat *mat) {
  assert(mat != NULL);
  int cols = isl_mat_cols(mat);
  int rows = isl_mat_rows(mat);
  std::vector<int> ret;
  ret.reserve(rows * cols);

  isl_val *val = NULL;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      val = isl_mat_get_element_val(mat, i, j);
      ret.push_back(isl_val_get_num_si(val));
    }
  }
  if (val)
    isl_val_free(val);
  isl_mat_free(mat);
  return ret;
}

isl_mat *qrane_utils::zero_matrix(isl_ctx *ctx, isl_size rows, isl_size cols) {
  isl_mat *ret = isl_mat_alloc(ctx, rows, cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      ret = isl_mat_set_element_si(ret, i, j, 0);
    }
  }
  return ret;
}

std::vector<int> qrane_utils::find_zero_cols(__isl_keep isl_mat *mat,
                                             int col_lb, int col_ub) {
  std::vector<int> ret_cols;
  isl_size rows = isl_mat_rows(mat);
  isl_val *tmp;
  bool found_nonzero;

  for (int col = col_lb; col < col_ub; ++col) {
    found_nonzero = false;
    for (int row = 0; row < rows; ++row) {
      tmp = isl_mat_get_element_val(mat, row, col);
      if (!isl_val_is_zero(tmp)) {
        found_nonzero = true;
        break;
      }
    }
    if (!found_nonzero) {
      ret_cols.push_back(col);
    }
  }
  return ret_cols;
}

__isl_give isl_mat *qrane_utils::drop_zero_cols(__isl_take isl_mat *mat,
                                                std::vector<int> cols_to_drop) {
  isl_mat *ret_mat = isl_mat_copy(mat);

  for (std::size_t i = 0; i < cols_to_drop.size(); ++i) {
    ret_mat = isl_mat_drop_cols(ret_mat, cols_to_drop[i], 1);
  }
  isl_mat_free(mat);
  return ret_mat;
};

/*
        EXPECTS mat TO BE IN REF
*/
isl_mat *qrane_utils::back_substitute_isl_mat(isl_ctx *ctx,
                                              __isl_keep isl_mat *mat,
                                              unsigned int args,
                                              unsigned int dim) {
  isl_mat *access_mat_copy = isl_mat_copy(mat);
  int access_rows = isl_mat_rows(mat);

  // First find any dim columns that are zero and record them.
  int dim_cols_lb = 2 * args;
  int dim_cols_ub = isl_mat_cols(mat);
  std::vector<int> zero_cols = find_zero_cols(mat, dim_cols_lb, dim_cols_ub);
  int num_zero_cols = zero_cols.size();

  // Unless there are zero cols, the rows of coeff_mat is equal to args
  // and the cols of coeff_mat is equal to dim + 1 (offset column)
  isl_size coeff_rows = args;
  isl_size coeff_cols = dim + 1;

  // Then drop those columns from the access_mat and update
  // the number of columns of necessary
  isl_mat *w_access_mat;
  if (num_zero_cols > 0) {
    w_access_mat = drop_zero_cols(access_mat_copy, zero_cols);
    coeff_cols -= num_zero_cols;
  } else {
    w_access_mat = access_mat_copy;
  }
  // std::cout << "After drops access_mat:" << std::endl << std::flush;
  // isl_mat_dump(w_access_mat);

  // Initialize the coeff_mat
  isl_mat *coeff_mat = zero_matrix(ctx, coeff_rows, coeff_cols);
  isl_val *wrk1;
  isl_val *wrk2;
  isl_val *wrk3;

  // Need to do back substitution for each argument
  for (std::size_t arg = args; arg-- > 0;) {
    // std::cout << "arg: " << arg << std::endl << std::flush;

    for (int row = 0; row < access_rows; ++row) {
      // x[i] = a(i,n)
      // We compute coefficients starting with the offset going to highest dim
      // Thus, we start on the right-most side of the coeff_mat and work
      // leftwards
      int coeff_col = -1 * row + (coeff_cols - 1);

      // arg_col is the column of access_mat that arg refers to,
      // i.e. for ccx: arg0->col4, arg1->col2, arg0->col0
      int arg_col = -2 * arg + (2 * args - 2);
      wrk1 = isl_mat_get_element_val(w_access_mat, row, arg_col);
      coeff_mat = isl_mat_set_element_val(coeff_mat, arg, coeff_col, wrk1);

      // ub was here too
      for (int index = 0; index < row; ++index) {
        unsigned int arg_col;
        if (index == 0) {
          arg_col = (2 * args - 1) - 2 * arg;
        } else {
          arg_col = 2 * args + (index - 1);
        }
        wrk1 = isl_mat_get_element_val(coeff_mat, arg, coeff_col);  // x[i]
        wrk2 = isl_mat_get_element_val(w_access_mat, row, arg_col); // a(i,j)
        wrk3 = isl_mat_get_element_val(coeff_mat, arg,
                                       -1 * index + (coeff_cols - 1)); // x[j]

        /*
        isl_val_dump(wrk1);
        std::cout << "-=" << std::flush;
        isl_val_dump(wrk2);
        std::cout << "*" << std::flush;
        isl_val_dump(wrk3);
        */

        wrk2 = isl_val_mul(wrk2, wrk3); // a(i,j) * x[j]
        wrk1 = isl_val_sub(wrk1, wrk2); // x[i] - (a(i,j) * x[j])
        coeff_mat = isl_mat_set_element_val(coeff_mat, arg, coeff_col, wrk1);
      }

      wrk1 = isl_mat_get_element_val(coeff_mat, arg, coeff_col); // x[i]
      unsigned int target;
      if (row == 0) {
        target = (2 * args - 1) - 2 * arg;
        wrk2 = isl_mat_get_element_val(w_access_mat, row, target);
      } else {
        target = 1 * row + (2 * args - 1);
        wrk2 = isl_mat_get_element_val(w_access_mat, row, target);
      }

      // isl_val_dump(wrk1);
      // std::cout << "/\n" << std::flush;
      // isl_val_dump(wrk2);
      // std::cout << "\n";
      // std::cout << "=" << std::flush;
      // wrk1 = isl_val_div(wrk1, wrk2);
      // isl_val_dump(wrk1);
      coeff_mat = isl_mat_set_element_val(coeff_mat, arg, coeff_col, wrk1);
    }
  }

  for (int i = 0; i < num_zero_cols; ++i) {
    int col_to_insert = (dim_cols_ub - 1) - 1 * zero_cols[i];
    coeff_mat = isl_mat_insert_zero_cols(coeff_mat, col_to_insert, 1);
  }

  // std::cout << "Results: " << std::endl << std::flush;
  // isl_mat_dump(coeff_mat);
  return coeff_mat;
};

void qrane_utils::print_isl_mat(isl_mat *mat) {
  isl_size rows = isl_mat_rows(mat);
  isl_size cols = isl_mat_cols(mat);
  std::ostringstream strm;

  strm << "[";
  for (int i = 0; i < rows; ++i) {
    strm << "[";
    for (int j = 0; j < cols; ++j) {
      isl_val *val = isl_mat_get_element_val(mat, i, j);
      strm << isl_val_get_num_si(val) << " ";
    }
    strm << "]\n";
  }
  strm << " ]\n";

  std::cout << strm.str();
}
