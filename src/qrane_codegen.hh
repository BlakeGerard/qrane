#ifndef QRANE_CODEGEN_H
#define QRANE_CODEGEN_H

#include "qrane_scop.hh"
#include "isl/aff.h"
#include "isl/ast.h"
#include "isl/ast_build.h"
#include "isl/ctx.h"
#include "isl/id.h"
#include "isl/map.h"
#include "isl/printer.h"
#include "isl/union_map.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

namespace qrane_codegen {

// fprintf_qasm
isl_stat qrane_build_gate_operation_fprintf_qasm(__isl_take isl_ast_expr *ae,
                                                 void *usr);
__isl_give isl_printer *
qrane_stmt_print_user_fprintf_qasm(__isl_take isl_printer *prt,
                                   __isl_take isl_ast_print_options *options,
                                   __isl_keep isl_ast_node *node, void *usr);

// Default
isl_stat qrane_build_gate_operation_default(__isl_take isl_ast_expr *ae,
                                            void *usr);
__isl_give isl_printer *
qrane_stmt_print_user_default(__isl_take isl_printer *prt,
                              __isl_take isl_ast_print_options *options,
                              __isl_keep isl_ast_node *node, void *usr);

isl_stat qrane_build_single_access_expression(__isl_take isl_map *acc,
                                              void *usr);

__isl_give isl_ast_expr_list *
qrane_build_access_at_domain(__isl_keep isl_ast_build *build,
                             __isl_keep isl_union_map *sched,
                             __isl_keep isl_union_map *call);

__isl_give isl_ast_node *qrane_at_each_domain(__isl_keep isl_ast_node *node,
                                              __isl_take isl_ast_build *build,
                                              void *user);

std::string find_domain_gate_id(const char *dom,
                                std::vector<qrane_domain> doms);
} // namespace qrane_codegen

#endif