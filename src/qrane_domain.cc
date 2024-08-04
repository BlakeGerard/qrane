/*
Qrane
Filename: qrane_domain.cc
Creation date: July 18, 2020
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

#include "qrane_domain.hh"
#include "barvinok/isl.h"
#include "isl/aff.h"

#include <algorithm>
#include <cmath>
#include <functional>

qrane_domain::qrane_domain() {
  local_domain = nullptr;
  access_mat = nullptr;
};

qrane_domain::~qrane_domain() {}

qrane_domain::qrane_domain(qrane_domain const &rhs) {
  domain_num = rhs.domain_num;
  gate_id = rhs.gate_id;
  stmt_count = rhs.stmt_count;
  args = rhs.args;
  dimensionality = rhs.dimensionality;
  subdomains = rhs.subdomains;
  affine_list = rhs.affine_list;
  component_qops = rhs.component_qops;
  lex = rhs.lex;
  access_mat = isl_mat_copy(rhs.access_mat);
  // isl_mat_free(rhs.access_mat);
  local_domain = isl_set_copy(rhs.local_domain);
  // isl_set_free(rhs.local_domain);
  // local_schedule = isl_map_copy(rhs.local_schedule);
};

qrane_domain &qrane_domain::operator=(qrane_domain const &rhs) {
  domain_num = rhs.domain_num;
  gate_id = rhs.gate_id;
  stmt_count = rhs.stmt_count;
  args = rhs.args;
  dimensionality = rhs.dimensionality;
  subdomains = rhs.subdomains;
  affine_list = rhs.affine_list;
  component_qops = rhs.component_qops;
  lex = rhs.lex;
  access_mat = isl_mat_copy(rhs.access_mat);
  // isl_mat_free(rhs.access_mat);
  local_domain = isl_set_copy(rhs.local_domain);
  // isl_set_free(rhs.local_domain);
  // local_schedule = isl_map_copy(rhs.local_schedule);
  return *this;
};

/*
        This is the main one
*/
qrane_domain::qrane_domain(isl_ctx *ctx, unsigned int domain_num,
                           std::string gate_id, unsigned int num_args,
                           qasm_ops_list &qops_list,
                           std::vector<unsigned int> qop_ids) {
  local_domain = nullptr;
  access_mat = nullptr;
  this->domain_num = domain_num;
  this->gate_id = gate_id;
  this->args = num_args;
  this->dimensionality = 1;
  this->stmt_count = qop_ids.size();
  this->component_qops.insert(component_qops.end(), qop_ids.begin(),
                              qop_ids.end());

  if (component_qops.size() == 1) {
    this->lex = LEX_SINGLE;
  } else if (component_qops[1] - component_qops[0] > 0) {
    this->lex = LEX_POS;
  } else if (component_qops[1] - component_qops[0] < 0) {
    this->lex = LEX_NEG;
  } else {
    assert(false);
  }

  build_affine_list_from_qop_ids(qops_list, qop_ids);
  build_local_domain(ctx);
}

/*
        This is the main one
*/
void qrane_domain::build_affine_list_from_qop_ids(
    qasm_ops_list &qops_list, std::vector<unsigned int> &qop_ids) {
  if (stmt_count == 1) {
    std::vector<int> op_0_args = std::get<ARGS>(qops_list[qop_ids[0]]);
    for (int i = 0; i < args; ++i) {
      affine_list.push_back(std::make_pair(0, op_0_args[i]));
    }
  } else {
    std::vector<int> op_0_args = std::get<ARGS>(qops_list[qop_ids[0]]);
    std::vector<int> op_1_args = std::get<ARGS>(qops_list[qop_ids[1]]);

    int x1 = 0;
    int x2 = 1; // I think this is correct
    int y1, y2;
    float m, b;

    for (int i = 0; i < args; ++i) {
      y1 = op_0_args[i];
      y2 = op_1_args[i];
      m = (y2 - y1) / (x2 - x1);
      b = y1 - m * x1;
      affine_list.push_back(std::pair<int, int>(m, b));
    }
  }
};

void qrane_domain::set_dimensionality(unsigned int dim) {
  this->dimensionality = dim;
};

void qrane_domain::set_local_domain(isl_set *new_domain) {
  // isl_set_free(local_domain);
  local_domain = new_domain;
};

void qrane_domain::set_access_mat(isl_mat *mat) {
  // isl_mat_free(access_mat);
  access_mat = mat;
};

void qrane_domain::add_component_qops(
    std::vector<unsigned int> component_qops) {
  this->component_qops.insert(this->component_qops.end(),
                              component_qops.begin(), component_qops.end());
};

void qrane_domain::one_dim_domain_print() {
  std::ostringstream strm;
  strm << "S" << this->domain_num << " := {\n";
  for (std::size_t i = 0; i < this->stmt_count; ++i) {
    strm << "\t" << component_qops[i] << ": ";
    for (auto access : affine_list) {
      strm << access.first * i + access.second << " ";
    }
    strm << "\n";
  }
  strm << "};";
  std::cout << strm.str() << std::endl;
};

/*
    This is only used to initialize local_domain for the
    one-dimensional case.
*/
__isl_keep void qrane_domain::build_local_domain(isl_ctx *ctx) {
  isl_val *v;
  isl_id *id;
  isl_multi_aff *ma;
  isl_aff *var, *cst;
  isl_basic_set *bset;
  isl_space *spc = isl_space_unit(ctx);

  std::string id_string = std::string("S");
  id_string.append(std::to_string(this->domain_num));
  id = isl_id_alloc(ctx, id_string.c_str(), nullptr);
  spc = isl_space_add_named_tuple_id_ui(spc, id, 1);
  ma = isl_multi_aff_identity_on_domain_space(isl_space_copy(spc));
  var = isl_multi_aff_get_at(ma, 0);
  v = isl_val_int_from_ui(ctx, 0);
  cst = isl_aff_val_on_domain_space(isl_space_copy(spc), v);
  bset = isl_aff_ge_basic_set(isl_aff_copy(var), cst);

  v = isl_val_int_from_ui(ctx, stmt_count - 1);
  cst = isl_aff_val_on_domain_space(spc, v);
  bset = isl_basic_set_intersect(bset, isl_aff_le_basic_set(var, cst));
  bset = isl_basic_set_preimage_multi_aff(bset, ma);
  this->local_domain = isl_set_from_basic_set(bset);

  std::size_t rows = stmt_count;
  std::size_t cols =
      dimensionality +
      2 * (args); // 1 column for i and 2 columns per arg(1 offset and 1 value)

  access_mat = isl_mat_alloc(ctx, rows, cols);
  for (std::size_t row = rows; row-- > 0;) {
    int val = -1 * row + (rows - 1); // This just means the last row has point
                                     // 0, second to last has point 1, etc.
    access_mat = isl_mat_set_element_si(access_mat, row, cols - 1, val);
    for (std::size_t ctr = args; ctr-- > 0;) {
      int index = 2 * ctr;
      int fnct = -1 * ctr + (args - 1);
      access_mat = isl_mat_set_element_si(access_mat, row, index + 1, 1);
      access_mat = isl_mat_set_element_si(access_mat, row, index,
                                          affine_list[fnct].first * val +
                                              affine_list[fnct].second);
    }
  }
};

/*
    Generate points of the form: (line_num, index)
*/
std::vector<std::pair<unsigned int, unsigned int>>
qrane_domain::generate_1D_points() {
  std::vector<std::pair<unsigned int, unsigned int>> ret;

  for (unsigned int i = 0; i < stmt_count; ++i) {
    auto pair = std::pair<unsigned int, unsigned int>(component_qops[i], i);
    ret.push_back(pair);
  };
  return ret;
};

std::string qrane_domain::get_domain_str() {
  std::string ret = std::string(isl_set_to_str(isl_set_copy(local_domain)));
  return ret;
};

__isl_give isl_set *qrane_domain::get_lexmin() const {
  return isl_set_lexmin(isl_set_copy(local_domain));
};

__isl_give isl_set *qrane_domain::get_lexmax() const {
  return isl_set_lexmax(isl_set_copy(local_domain));
};

__isl_give isl_set *qrane_domain::get_local_domain_copy() const {
  return isl_set_copy(local_domain);
};

__isl_give isl_mat *qrane_domain::get_access_mat_copy() const {
  return isl_mat_copy(access_mat);
};

int qrane_domain::get_coefficient(unsigned int arg, unsigned int dim) {
  isl_val *val = isl_mat_get_element_val(access_mat, arg, dim);
  return isl_val_get_num_si(val);
}

long qrane_domain::get_card() const {
  isl_set *cpy = get_local_domain_copy();
  isl_pw_qpolynomial *pwq = isl_set_card(cpy);
  isl_val *val = isl_pw_qpolynomial_max(pwq);
  long ret = isl_val_get_num_si(val);
  return ret;
}

__isl_give isl_mat *zero_matrix(isl_ctx *ctx, isl_size rows, isl_size cols) {
  isl_mat *ret = isl_mat_alloc(ctx, rows, cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      ret = isl_mat_set_element_si(ret, i, j, 0);
    }
  }
  return ret;
}

std::vector<int> find_zero_cols(__isl_keep isl_mat *mat, int col_lb,
                                int col_ub) {
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

__isl_give isl_mat *drop_zero_cols(__isl_take isl_mat *mat,
                                   std::vector<int> cols_to_drop) {
  isl_mat *ret_mat = isl_mat_copy(mat);

  for (std::size_t i = 0; i < cols_to_drop.size(); ++i) {
    ret_mat = isl_mat_drop_cols(ret_mat, cols_to_drop[i], 1);
  }
  isl_mat_free(mat);
  return ret_mat;
};

/*
        isl uses reverse gauss-jordan elimination to compute
        row basis, so backwards substitution goes from top
        left to bottom right.

        Problem case:  This matrix is consistent, but the results
        are rational numbers. Need to account for this.
        [[5,0,2,0,0,0]
     [-19,1,0,1,0,0]
     [-23,0,0,0,2,0]
     [0,0,0,0,0,1]]
*/

void qrane_domain::back_substitution(isl_ctx *ctx) {
  access_mat = isl_mat_row_basis(access_mat);
  isl_mat *access_mat_copy = isl_mat_copy(access_mat);
  // std::cout << "row basis access_mat:" << std::endl << std::flush;
  // isl_mat_dump(access_mat);
  int access_rows = isl_mat_rows(access_mat);

  // First find any dim columns that are zero and record them.
  int dim_cols_lb = 2 * args;
  int dim_cols_ub = isl_mat_cols(access_mat);
  std::vector<int> zero_cols =
      find_zero_cols(access_mat, dim_cols_lb, dim_cols_ub);
  int num_zero_cols = zero_cols.size();

  // Unless there are zero cols, the rows of coeff_mat is equal to args
  // and the cols of coeff_mat is equal to dim + 1 (offset column)
  isl_size coeff_rows = this->args;
  isl_size coeff_cols = this->dimensionality + 1;

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
      // std::cout << "/" << std::flush;
      // isl_val_dump(wrk2);
      // std::cout << "\n";
      wrk1 = isl_val_div(wrk1, wrk2);
      coeff_mat = isl_mat_set_element_val(coeff_mat, arg, coeff_col, wrk1);
    }
  }

  for (int i = 0; i < num_zero_cols; ++i) {
    int col_to_insert = (dim_cols_ub - 1) - 1 * zero_cols[i];
    coeff_mat = isl_mat_insert_zero_cols(coeff_mat, col_to_insert, 1);
  }

  // std::cout << "Results: " << std::endl << std::flush;
  // isl_mat_dump(coeff_mat);
  access_mat = coeff_mat;
};

unsigned int qrane_domain::get_time_min() const {
  return *std::min_element(component_qops.begin(), component_qops.end());
  // return component_qops.front();
};

unsigned int qrane_domain::get_time_max() const {
  return *std::max_element(component_qops.begin(), component_qops.end());
  // return component_qops.back();
};

/*
__isl_keep void qrane_domain::build_local_schedule(__isl_keep isl_ctx* ctx) {
        isl_map* map = isl_map_from_domain(isl_set_copy(local_domain));
        map = isl_map_add_dims(map, isl_dim_out, 1);
        map = isl_map_equate(map, isl_dim_in, 0, isl_dim_out, 0);
        local_schedule = map;
};

void qrane_domain::add_scalar_dim_to_local_schedule(unsigned int pos, int val) {
        local_schedule = isl_map_insert_dims(local_schedule, isl_dim_out, pos,
1); isl_space* spc = isl_map_get_space(local_schedule); isl_local_space* lspc =
isl_local_space_from_space(spc); isl_constraint* constraint =
isl_constraint_alloc_equality(lspc); constraint =
isl_constraint_set_coefficient_si(constraint, isl_dim_out, pos, 1); constraint =
isl_constraint_set_constant_si(constraint, -1 * val); local_schedule =
isl_map_add_constraint(local_schedule, constraint);
};
*/
