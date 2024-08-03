#ifndef QRANE_SCOP_H
#define QRANE_SCOP_H

#include <vector>

#include "qrane_dependence_profile.hpp"
#include "isl/ast_build.h"
#include "isl/union_map.h"
#include "isl/union_set.h"

namespace qrane {

class Statement;

struct full_scop_s {
  isl_union_set *domain;
  isl_union_map *read;
  isl_union_map *write;
  isl_union_map *call;
  isl_union_map *schedule;
  isl_union_map *dependencies;
  isl_union_map *arguments;
  membership_map_t membership;
  qubit_profile_map qubit_access_profile;
  std::vector<Statement> final_domain_list;

  ~full_scop_s() {
    isl_union_set_free(domain);
    isl_union_map_free(read);
    isl_union_map_free(write);
    isl_union_map_free(call);
    isl_union_map_free(schedule);
    isl_union_map_free(dependencies);
    isl_union_map_free(arguments);
  }
};
typedef full_scop_s full_scop;

struct output_scop_s {
  isl_union_set *domain;
  isl_union_map *read;
  isl_union_map *write;
  isl_union_map *schedule;
  isl_union_map *arguments;

  output_scop_s(isl_ctx *ctx) {
    domain = isl_union_set_empty_ctx(ctx);
    read = isl_union_map_empty_ctx(ctx);
    write = isl_union_map_empty_ctx(ctx);
    schedule = isl_union_map_empty_ctx(ctx);
    arguments = isl_union_map_empty_ctx(ctx);
  }

  ~output_scop_s() {
    isl_union_set_free(domain);
    isl_union_map_free(read);
    isl_union_map_free(write);
    isl_union_map_free(schedule);
    isl_union_map_free(arguments);
  }
};
typedef output_scop_s output_scop;
} // namespace qrane

struct s_qrane_ast_info_t {
  isl_ast_expr_list *ast_exl;
  isl_ast_build *build;
};
typedef struct s_qrane_ast_info_t t_qrane_ast_info;

#endif

/*
namespace qrane {

struct full_scop_s {
  isl_union_set* domain;
  isl_union_map* read;
  isl_union_map* write;
  isl_union_map* call;
  isl_union_map* schedule;
  isl_union_map* dependencies;
  isl_union_map* arguments;
  membership_map_t membership;
  qubit_profile_map qubit_access_profile;
  std::vector<Statement> final_domain_list;

  ~full_scop_s() {
    isl_union_set_free(domain);
    isl_union_map_free(read);
    isl_union_map_free(write);
    isl_union_map_free(call);
    isl_union_map_free(schedule);
    isl_union_map_free(dependencies);
    isl_union_map_free(arguments);
  }
};

struct output_scop_s {
  isl_union_set* domain;
  isl_union_map* read;
  isl_union_map* write;
  isl_union_map* schedule;
  isl_union_map* arguments;

  ~output_scop_s() {
    isl_union_set_free(domain);
    isl_union_map_free(read);
    isl_union_map_free(write);
    isl_union_map_free(schedule);
    isl_union_map_free(arguments);
  }
};
}  // namespace qrane

struct s_qrane_ast_info_t {
  isl_ast_expr_list* ast_exl;
  isl_ast_build* build;
};
typedef struct s_qrane_ast_info_t t_qrane_ast_info;

#endif
*/
