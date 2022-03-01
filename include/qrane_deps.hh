/*
Qrane
Filename: qrane_deps.hh
Creation date: December 26, 2020
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

#ifndef QRANE_DEPS
#define QRANE_DEPS

#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <array>
#include <stack>

#include "isl/map.h"
#include "isl/union_map.h"
#include "isl/union_set.h"
#include "isl/id.h"
#include "isl/options.h"
#include "isl/schedule.h"

#include "qrane_stmtlist.hh"
#include "qrane_shared.hh"


typedef std::unordered_map<unsigned int, int> time_dependence_graph_in_degrees;

// Map: qubit_index -> queue( pair(line_num, "access_type=r/w") ) 
typedef std::unordered_map<int, std::queue<std::pair<unsigned int, char>>> access_map;


typedef std::map<unsigned int, qrane_domain> domain_map_t;

class qrane_deps {

    public:
		time_dependence_graph ddg;
		time_dependence_graph ddg_write_all;
		time_dependence_graph_in_degrees ddg_ins;
		access_map latest_access;
		access_map latest_access_write_all;
		qubit_profile_map profile_map;
        membership_map membership;
		
		qrane_deps();
        qrane_deps(std::vector<qrane_statement*> stmts);
        ~qrane_deps();
        qrane_deps(qrane_deps const& rhs);
        qrane_deps& operator=(qrane_deps const& rhs);

		// Dependence Graph and Membership Map Construction
        void add_vertex(unsigned int line_num, int index_accessed, char type, std::string gate_id);
        void add_write_all_vertex(unsigned int line_num, int index_accessed, char type, std::string gate_id);
        void set_membership(unsigned int line_num, unsigned int index, unsigned int domain_num);
		void update_membership_graph_1D_phase(const std::vector<unsigned int>&path, unsigned int domain_num);
		void update_membership_graph_ND_phase(const std::vector<unsigned int>& domains, domain_map_t& domain_map);

		std::array<unsigned int, 2> dependence_graph_lookahead_breadth(std::vector<unsigned int>& frontier, unsigned int num_qops, unsigned int depth, qasm_ops_list& qops_list);
		std::array<unsigned int, 2> dependence_graph_lookahead_depth(std::vector<unsigned int>& frontier, unsigned int num_qops, unsigned int depth, qasm_ops_list& qops_list);
		void dependence_graph_lookahead_depth_main(unsigned int src, unsigned int num_qops, unsigned int depth, std::array<unsigned int, 2>& count, qasm_ops_list& qops_list);

		// Dependence graph frontier processing
		void initialize_frontier_processing();
		std::vector<unsigned int> get_dependence_frontier();
		void decrement_in_degrees_of_path_neighbors(std::vector<unsigned int>& path);

		isl_union_map* build_implicit_schedule(isl_ctx* ctx, unsigned int subcircuit_num);

		// For isl object construction
        __isl_keep isl_union_map* generate_validity_map(isl_ctx* ctx);
		isl_union_map* generate_write_all_dependences(isl_ctx* ctx);
		__isl_keep isl_union_map* generate_default_map(isl_ctx* ctx);
		isl_union_map* get_validity_map();
		qubit_profile_map get_qubit_access_profile_map();
        
		membership_map get_membership() const;
		
		void convert_time_ddg_to_str_ddg(qrane_stmtlist* stmtlist);
		qubit_profile_map get_qubit_profile_map();

		// Printing and string formatting
		std::string get_qubit_access_profile_str();
		std::string get_networkx_edge_list_str();
		std::string get_gates_networkx_edge_list_str(std::vector<qrane_statement*> qops_list);
		void print_membership();
		void print_membership_given(membership_map& given);
		void time_dependence_graph_print();
		void time_dependence_graph_print_given(time_dependence_graph& G);
};

#endif
