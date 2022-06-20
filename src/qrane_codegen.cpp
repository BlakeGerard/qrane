#include "qrane_codegen.hpp"
#include "isl/aff.h"
#include "isl/id.h"
#include "isl/union_map.h"
#include "cstdlib"

int cnt;
int limit;

isl_stat qrane_codegen::qrane_build_domain_key(__isl_take isl_ast_expr * ae, void * usr) {
	std::string* key = (std::string*)(usr);
	std::string expr = std::string(isl_ast_expr_to_C_str(ae));
	expr.erase(remove(expr.begin(), expr.end(), '['), expr.end());
	expr.erase(remove(expr.begin(), expr.end(), ']'), expr.end());
	key->append(expr);
	key->append(", ");
	cnt += 1;
	return isl_stat_ok;
};

__isl_give isl_printer* qrane_codegen::qrane_stmt_print_user_fprintf_domain(__isl_take isl_printer* prt, 
																	      __isl_take isl_ast_print_options* options,
											  				              __isl_keep isl_ast_node* node, void* usr) {
  	isl_id* id = isl_ast_node_get_annotation (node);
  	isl_ast_expr_list* gate_call_expr_list = (isl_ast_expr_list*)(isl_id_get_user (id));

  	isl_size sz = isl_ast_expr_list_size(gate_call_expr_list);

  	prt = isl_printer_start_line(prt);
  	prt = isl_printer_print_str(prt, "fprintf(f, \"%d;\\n\", rv[std::make_pair(");
	prt = isl_printer_print_str(prt, isl_id_get_name(id));

	std::string* key = new std::string(", std::vector<int>({");
	isl_stat res = isl_ast_expr_list_foreach(gate_call_expr_list, &qrane_codegen::qrane_build_domain_key, (void*)(key));
	key->erase(key->end() - 2, key->end());
	key->append("}))])");
	prt = isl_printer_print_str(prt, key->c_str());

  	limit = isl_ast_expr_list_size(gate_call_expr_list);
	cnt = 0;
	  
	prt = isl_printer_print_str(prt, ";\n");
  	prt = isl_printer_end_line(prt);

  	isl_ast_expr_list_free (gate_call_expr_list);
  	return prt;
};

/*
	Use this format when codegen should be in fprintf_qasm mode.
	ex: fprintf(f, "cx q[%u], q[%u];", expr, expr);
*/
isl_stat qrane_codegen::qrane_build_gate_operation_fprintf_qasm(__isl_take isl_ast_expr * ae, void * usr) {
  	isl_printer* prt = (isl_printer*)(usr);
  	prt = isl_printer_print_str(prt, ", ");
	std::string expr = std::string(isl_ast_expr_to_C_str(ae));
	expr.erase(remove(expr.begin(), expr.end(), '['), expr.end());
	expr.erase(remove(expr.begin(), expr.end(), ']'), expr.end());
  	prt = isl_printer_print_str(prt, expr.c_str());
  	isl_ast_expr_free(ae);
  	cnt += 1;
  	return isl_stat_ok;
};

__isl_give isl_printer* qrane_codegen::qrane_stmt_print_user_fprintf_qasm(__isl_take isl_printer* prt, 
																	      __isl_take isl_ast_print_options* options,
											  				              __isl_keep isl_ast_node* node, void* usr) {
  	isl_id* id = isl_ast_node_get_annotation (node);
  	isl_ast_expr_list* gate_call_expr_list = (isl_ast_expr_list*)(isl_id_get_user (id));

  	isl_size sz = isl_ast_expr_list_size(gate_call_expr_list);

  	prt = isl_printer_start_line(prt);
  	prt = isl_printer_print_str(prt, "fprintf(f, \"");
  	prt = isl_printer_print_str(prt, isl_id_get_name(id));
  	prt = isl_printer_print_str(prt, " ");

	for (int i = 0; i < sz; ++i) {
		prt = isl_printer_print_str(prt, "q[%u]");
		if (i != sz-1) {prt = isl_printer_print_str(prt, ", ");}
	}
	prt = isl_printer_print_str(prt, ";\\n\"");
  

  	limit = isl_ast_expr_list_size(gate_call_expr_list);
	cnt = 0;
  	isl_stat res;
  	res = isl_ast_expr_list_foreach (gate_call_expr_list, &qrane_codegen::qrane_build_gate_operation_fprintf_qasm, (void*)(prt));
  	assert (res == isl_stat_ok);
	  
	prt = isl_printer_print_str(prt, ");");
  	prt = isl_printer_end_line(prt);

  	isl_ast_expr_list_free (gate_call_expr_list);
  	return prt;
};

/*
	Use this format when codegen should be default mode.
	ex: cx (q[expr], q[expr]);
*/
isl_stat qrane_codegen::qrane_build_gate_operation_default(__isl_take isl_ast_expr * ae, void * usr) {
  isl_printer* prt = (isl_printer*)(usr);
  prt = isl_printer_print_str(prt, "q");
  prt = isl_printer_print_ast_expr(prt, ae);
  if (cnt < limit-1) { prt = isl_printer_print_str(prt, ", ");}
  else {prt = isl_printer_print_str(prt, ");");}
  isl_ast_expr_free (ae);
  cnt += 1;
  return isl_stat_ok;
};

__isl_give isl_printer* qrane_codegen::qrane_stmt_print_user_default(__isl_take isl_printer* prt, __isl_take isl_ast_print_options* options,
											  __isl_keep isl_ast_node* node, void* usr) {
  isl_id* id = isl_ast_node_get_annotation (node);
  isl_ast_expr_list* gate_call_expr_list = (isl_ast_expr_list*)(isl_id_get_user (id));

  prt = isl_printer_start_line(prt);
  prt = isl_printer_print_str(prt, isl_id_get_name(id));
  prt = isl_printer_print_str(prt, " ");
  prt = isl_printer_print_str(prt, "(");

  	limit = isl_ast_expr_list_size(gate_call_expr_list);
	cnt = 0;
  isl_stat res;
  res = isl_ast_expr_list_foreach (gate_call_expr_list, &qrane_codegen::qrane_build_gate_operation_default, (void*)(prt));
  assert (res == isl_stat_ok);
  prt = isl_printer_end_line(prt);

  isl_ast_expr_list_free (gate_call_expr_list);
  return prt;
};

/*
	Third step in the codegen pipeline. This gets the isl_pw_aff
	from the access map and fills the expression list.
*/
isl_stat qrane_codegen::qrane_build_single_access_expression(__isl_take isl_map* acc, void* usr) {

  	t_qrane_ast_info* info = (t_qrane_ast_info*)(usr);
  	isl_pw_multi_aff* pma; 

	//isl_id* q = isl_id_alloc(isl_ast_build_get_ctx(isl_ast_build_copy(info->build)), "q", nullptr);
  	pma = isl_pw_multi_aff_from_map(acc);
  	
	int nd = isl_map_dim(acc, isl_dim_out);
	for (int i = 0; i < nd; ++i) {
		isl_pw_aff* pwa;
    	pwa = isl_pw_multi_aff_get_pw_aff(pma, i);
		isl_ast_expr* aexp;
		aexp = isl_ast_build_access_from_multi_pw_aff(info->build, isl_multi_pw_aff_from_pw_aff(pwa));
  		info->ast_exl = isl_ast_expr_list_add(info->ast_exl, aexp);
	}

	isl_pw_multi_aff_free(pma);
	//isl_id_free(q);
  	return isl_stat_ok;
};

/*
	Second point in the codegen pipeline. This composes the 
	reverse of the schedule map with the call map, in effect
	"converting" the access relation to work with the schedule
	parameters.
*/
__isl_give isl_ast_expr_list* qrane_codegen::qrane_build_access_at_domain(__isl_keep isl_ast_build * build, 
  														   __isl_keep isl_union_map * sched, 
  														   __isl_keep isl_union_map * call) 
{
	isl_union_map * sched_to_call;
  	//sched_to_call = isl_union_map_apply_range(
	//	  			isl_union_map_reverse(isl_union_map_copy(sched)), isl_union_map_copy (call));

	sched_to_call = isl_union_map_reverse(isl_union_map_copy(sched));
	isl_ctx * ctx = isl_union_map_get_ctx(sched);

	t_qrane_ast_info info;
	info.build = build;
	info.ast_exl = isl_ast_expr_list_alloc(ctx, 0);

  	isl_stat res;
	
  	res = isl_union_map_foreach_map (
    sched_to_call, &qrane_codegen::qrane_build_single_access_expression, (void*)(&info));
	assert(res == isl_stat_ok);

	isl_union_map_free(sched_to_call);
	return info.ast_exl;
}

/*
	Entry point for codegen editing. This is called at each domain.
*/
__isl_give isl_ast_node* qrane_codegen::qrane_at_each_domain(__isl_keep isl_ast_node* node,
											  __isl_take isl_ast_build* build, void* user) 									
{
	t_qrane_scop* scop = (t_qrane_scop*)(user);

	isl_ctx* ctx = isl_ast_node_get_ctx(node);
	isl_union_map* sched = isl_ast_build_get_schedule(build);
  	isl_map* map = isl_map_from_union_map(isl_union_map_copy(sched));

  	const char* dom_name = isl_map_get_tuple_name(map, isl_dim_in);
	std::string gate_id = qrane_codegen::find_domain_gate_id(dom_name, scop->final_domain_list);

	isl_ast_expr_list* acc_expr_list;
  	acc_expr_list = qrane_codegen::qrane_build_access_at_domain(build, sched, scop->call);

	isl_id * id;
  	id = isl_id_alloc(ctx, gate_id.c_str(), acc_expr_list);
  	node = isl_ast_node_set_annotation(node, id);
  	
	return node;
};

/*
	Just a utility to find the domain object for the current domain in the traversal
*/
std::string qrane_codegen::find_domain_gate_id(const char* dom, std::vector<qrane_domain> doms) {
	std::string ret("");
	std::string tmp = std::string(dom);
	tmp.erase(tmp.begin());
	for (const auto &domain : doms) {
		if (std::to_string(domain.domain_num).compare(tmp) == 0) {
			//ret = domain.gate_id;
			ret = std::to_string(domain.domain_num);
		}
	}
	return ret;
};
