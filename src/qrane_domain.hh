/*
Qrane
Filename: qrane_domain.hh
Creation date: June 30, 2020
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

#ifndef QRANE_DOMAIN
#define QRANE_DOMAIN

#include "qrane_qop.hh"
#include "qrane_shared.hh"
#include "qrane_stmtlist.hh"
#include "isl/ctx.h"
#include "isl/id.h"
#include "isl/map.h"
#include "isl/mat.h"
#include "isl/set.h"
#include "isl/space.h"
#include "isl/union_set.h"
#include "isl/val.h"
#include "isl/vec.h"
#include <assert.h>
#include <cstdlib>
#include <map>
#include <sstream>
#include <string>
// #include "qrane_flags.hh"

typedef std::map<unsigned int, qop_identifier> qasm_ops_list;

enum lex_type { LEX_POS = 0, LEX_NEG, LEX_SUBSET, LEX_REMOVE, LEX_SINGLE };

class qrane_domain {

public:
  unsigned int domain_num;
  std::string gate_id;
  int args;
  unsigned int dimensionality;
  unsigned int stmt_count;
  lex_type lex;

  std::vector<std::pair<int, int>> affine_list;
  std::vector<unsigned int>
      subdomains; // Tracks all domain_nums within this domain
  std::vector<unsigned int>
      component_qops; // Tracks all global_ids within this domain

  isl_set *local_domain;

  isl_mat *access_mat;

  qrane_domain();

  // Main one
  qrane_domain(isl_ctx *ctx, unsigned int domain_num, std::string gate_id,
               unsigned int num_args, qasm_ops_list &qops_list,
               std::vector<unsigned int> qop_ids);

  ~qrane_domain();

  qrane_domain(qrane_domain const &rhs);            // copy constructor
  qrane_domain &operator=(qrane_domain const &rhs); // copy assignment

  void add_component_qops(std::vector<unsigned int> component_qops);
  bool check_qop_belongs_in_domain(qrane_qop *qop);
  void set_dimensionality(unsigned int dim);
  void set_local_domain(isl_set *new_domain);
  void set_access_mat(isl_mat *mat);
  std::string get_domain_str();
  std::vector<std::pair<unsigned int, unsigned int>> generate_1D_points();
  void back_substitution(isl_ctx *ctx);
  int get_coefficient(unsigned int arg, unsigned int dim);

  void compute_access_relations();

  /////////////////////////
  __isl_give isl_set *get_lexmin() const;
  __isl_give isl_set *get_lexmax() const;
  __isl_give isl_set *get_local_domain_copy() const;
  __isl_give isl_mat *get_access_mat_copy() const;
  //__isl_give isl_map* get_local_schedule_copy() const;
  __isl_keep void build_local_domain(__isl_keep isl_ctx *ctx);
  __isl_keep void build_local_schedule(__isl_keep isl_ctx *ctx);
  long get_card() const;
  unsigned int get_time_min() const;
  unsigned int get_time_max() const;

  void add_scalar_dim_to_local_schedule(unsigned int pos, int val);

  void one_dim_domain_print();

private:
  void build_singleton_affine_list(qrane_qop *qop);
  void build_affine_list_from_qop_ids(qasm_ops_list &qops_list,
                                      std::vector<unsigned int> &qop_ids);
};

#endif