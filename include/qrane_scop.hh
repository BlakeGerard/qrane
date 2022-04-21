#ifndef QRANE_SCOP_H
#define QRANE_SCOP_H

#include <vector>

#include "isl/union_set.h"
#include "isl/union_map.h"
#include "isl/ast_build.h"

#include "qrane_domain.hh"
#include "qrane_deps.hh"

namespace qrane {

	/*
			This struct is mainly used to package multiple analysis results
		of a particular analyst unit.

		Members:
			domain: Iteration domain
			read: Read relations
			call: Artifact of old codegen process
			write: Write relations
			schedule: Schedule on domain
			dependencies: Dependencies between elements of domain
			arguments: Map from domain point to qop argument count
			membership_map: Map of domain point to qop_id
			qubit_access_profile: ...
			final_domain_list: Final list of domain objects from qrane.
							   Only used in the compilation host.

	*/
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

	
	/*		This struct contains only isl structures that Martin requested,
		and is intended to be an output scop for other tools.

		Members:
			domain: Iteration domain
			read: Read relations
			write: Write relations
			schedule: Schedule on domain
			arguments: Map from domain point to qop argument count.
	*/
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
}

qrane::output_scop_s a;

struct s_qrane_ast_info_t {
	isl_ast_expr_list* ast_exl;
  	isl_ast_build* build;
};
typedef struct s_qrane_ast_info_t t_qrane_ast_info;

#endif