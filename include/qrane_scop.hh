#ifndef QRANE_SCOP_H
#define QRANE_SCOP_H

#include <vector>

#include "isl/union_set.h"
#include "isl/union_map.h"
#include "isl/ast_build.h"

#include "qrane_domain.hh"
#include "qrane_deps.hh"

struct s_qrane_scop_t {
  	isl_union_set* domain;
  	isl_union_map* read;
  	isl_union_map* write;
	isl_union_map* call;
  	isl_union_map* schedule;
  	isl_union_map* dependence;
	isl_union_map* arguments;
	membership_map membership;
	qubit_profile_map qubit_access_profile;
	std::vector<qrane_domain> final_domain_list;

	~s_qrane_scop_t() {
		isl_union_set_free(domain);
		isl_union_map_free(read);
		isl_union_map_free(write);
		isl_union_map_free(call);
		isl_union_map_free(schedule);
		isl_union_map_free(dependence);
		isl_union_map_free(arguments);
	}
};

typedef struct s_qrane_scop_t t_qrane_scop;

struct qrane_output_scop {
  	isl_union_set* domain;
  	isl_union_map* read;
  	isl_union_map* write;
  	isl_union_map* schedule;
	isl_union_map* arguments;

	~qrane_output_scop() {
		isl_union_set_free(domain);
		isl_union_map_free(read);
		isl_union_map_free(write);
		isl_union_map_free(schedule);
		isl_union_map_free(arguments);
	}
};

struct s_qrane_ast_info_t {
	isl_ast_expr_list* ast_exl;
  	isl_ast_build* build;
};

typedef struct s_qrane_ast_info_t t_qrane_ast_info;

#endif
