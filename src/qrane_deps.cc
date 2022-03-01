#include "include/qrane_deps.hh"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <functional>
#include "qrane_utils.hh"

	// -------------------------------
	// Constructors and Initialization
	// -------------------------------

qrane_deps::qrane_deps() {
};

qrane_deps::~qrane_deps() {
};

qrane_deps::qrane_deps(std::vector<qrane_statement*> stmts) {
	ddg = time_dependence_graph();
	ddg_write_all = time_dependence_graph();
   	latest_access = access_map();
	latest_access_write_all = access_map();
	profile_map = qubit_profile_map();
    membership = membership_map();

	// Subcircuits must initialize dependence graph and membership map
	// with Ids of their respective qops.
	for (auto val : stmts) {
		qrane_qop* qop = (qrane_qop*) val;
		ddg[qop->get_dim1_qop_num()] = std::vector<unsigned int>();
		ddg_write_all[qop->get_dim1_qop_num()] = std::vector<unsigned int>();
		membership[qop->get_dim1_qop_num()] = std::make_pair(qop->get_dim1_qop_num(), std::vector<unsigned int>());
	}
};

qrane_deps::qrane_deps(qrane_deps const& rhs) {
	ddg = rhs.ddg;
    latest_access = rhs.latest_access;
	profile_map = rhs.profile_map;
    membership = rhs.membership;
};

qrane_deps& qrane_deps::operator=(qrane_deps const& rhs) {
	ddg = rhs.ddg;
    latest_access = rhs.latest_access;
	profile_map = rhs.profile_map;
    membership = rhs.membership;
    return *this;
};

membership_map qrane_deps::get_membership() const {
	return this->membership;
}

	// ------------------------------------------------
	// Dependence Graph and Membership Map Construction
	// ------------------------------------------------

/*
	Add a single vertex to the dependence graph.
	Update the latest_access to reflect presence of new qop.
	Update the qubit access profile to reflect presence of new qop.
*/
void qrane_deps::add_vertex(unsigned int line_num, int index_accessed, char type, std::string gate_id) {
	auto current_access = std::pair<unsigned int, char>(line_num, type);
	std::pair<unsigned int, char> queue_member;

	// If the index is already being tracked
	if (latest_access.count(index_accessed)) {

		// If the queue is not empty
		if (latest_access[index_accessed].size() > 0) {

			// If the current access is a read
			if (current_access.second == 'r') {

				// and the latest access is a write (WAR)
				if (latest_access[index_accessed].front().second == 'w') {

					// Generate a dependence only. The access gets pushed onto the queue
					queue_member = latest_access[index_accessed].front();
					if (queue_member.first == current_access.first) { return; }
					ddg[queue_member.first].push_back(current_access.first);

				// and the latest access is a read (RAR)
				} else if (latest_access[index_accessed].front().second == 'r') {
					// Don't generate a dependence, just push the acess to the queue
				}

			// If the current access is a write (RAW or WAW)
			} else if (current_access.second == 'w') {

				// Generate dependence for each item and remove it from the queue
				while (!latest_access[index_accessed].empty()) {
    				queue_member = latest_access[index_accessed].front();
					latest_access[index_accessed].pop();
					if (queue_member.first == current_access.first) { continue; }
					ddg[queue_member.first].push_back(current_access.first);
  				}
			}
		}
	}
	(profile_map[index_accessed])[gate_id] += 1;
	latest_access[index_accessed].push(current_access);
};

void qrane_deps::add_write_all_vertex(unsigned int line_num, int index_accessed, char type, std::string gate_id) {
	auto current_access = std::pair<unsigned int, char>(line_num, type);
	std::pair<unsigned int, char> queue_member;

	// If the index is already being tracked
	if (latest_access_write_all.count(index_accessed)) {

		// If the queue is not empty
		if (latest_access_write_all[index_accessed].size() > 0) {

			// If the current access is a read
			if (current_access.second == 'r') {
				assert(false && "Added a read dependence to ddg_write_all");

				/*
				// and the latest access is a write (WAR)
				if (latest_access_write_all[index_accessed].front().second == 'w') {

					// Generate a dependence only. The access gets pushed onto the queue
					queue_member = latest_access_write_all[index_accessed].front();
					if (queue_member.first == current_access.first) { return; }
					ddg[queue_member.first].push_back(current_access.first);

				// and the latest access is a read (RAR)
				} else if (latest_access[index_accessed].front().second == 'r') {
					// Don't generate a dependence, just push the acess to the queue
				}
				*/

			// If the current access is a write (RAW or WAW)
			} else if (current_access.second == 'w') {

				// Generate dependence for each item and remove it from the queue
				while (!latest_access_write_all[index_accessed].empty()) {
    				queue_member = latest_access_write_all[index_accessed].front();
					latest_access_write_all[index_accessed].pop();
					if (queue_member.first == current_access.first) { continue; }
					ddg_write_all[queue_member.first].push_back(current_access.first);
  				}
			}
		}
	}
	latest_access_write_all[index_accessed].push(current_access);
};

/*
	TODO: Document
*/
void qrane_deps::set_membership(unsigned int line_num, unsigned int index, unsigned int domain_num) {
    auto rhs = std::pair<unsigned int, std::vector<unsigned int>>(domain_num, std::vector<unsigned int>{index});
    membership[line_num] = rhs;
};

/*
	This is only called AFTER the domain has been chosen
*/
void qrane_deps::update_membership_graph_1D_phase(const std::vector<unsigned int>& path, unsigned int domain_num) {
	unsigned int index = 0;
	for (const auto point : path) {
		this->membership[point].first = domain_num;
		this->membership[point].second.push_back(index);
		++index;
	}
}

/*
	This takes in domain_num identifiers, NOT inidividual points
*/
void qrane_deps::update_membership_graph_ND_phase(const std::vector<unsigned int>& domains, domain_map_t& domain_map) {
	unsigned int parent_num = domains.front();
	std::vector<unsigned int> components = domain_map[parent_num].component_qops;
	
	// Update the points of the parent domain with a zero value for outermost loop variable
	for (auto val : components) {
		membership[val].second.push_back(0);
	}

	// Do the same as above for each subsequent domain, but use mergee_counter instead of zero
	unsigned int mergee_counter = 1;
	for (std::size_t i = 1; i < domains.size(); ++i) {
        components = domain_map[domains[i]].component_qops;

    	for (auto val : components) {
			membership[val].first = parent_num;
         	membership[val].second.push_back(mergee_counter);
		}
        mergee_counter += 1;
    }
};

isl_union_map* qrane_deps::build_implicit_schedule(isl_ctx* ctx, unsigned int subcircuit_num) {
	isl_union_map* schedule = isl_union_map_empty_ctx(ctx);

	std::ostringstream strm;
	unsigned int node_count = 0;
	for (auto& node : this->ddg) {
		auto node_info = membership[node.first];

        strm << "{S" << std::to_string(node_info.first) << "[";
        for (std::vector<unsigned int>::reverse_iterator dim = node_info.second.rbegin(); dim != (node_info.second.rend() - 1); ++dim) {
            strm << std::to_string(*dim) << ",";
        }
        strm << std::to_string(node_info.second[0]) << "] -> ";
		//strm << "[" << subcircuit_num << ", " << node_count << "]}";
		strm << "[" << node.first << "]}";

		//std::cout << strm.str() << std::endl;

		isl_map* node_map = isl_map_read_from_str(ctx, strm.str().c_str());
		schedule = isl_union_map_add_map(schedule, node_map);
		strm.str(std::string());
		++node_count;
	}
	return isl_union_map_coalesce(schedule);
};

__isl_keep isl_union_map* qrane_deps::generate_validity_map(isl_ctx* ctx) {
    std::ostringstream strm;
    isl_union_map* ret_map = isl_union_map_empty_ctx(ctx);
    isl_map* single_map;

    for (const auto &vertex : ddg) {
		auto left_info = membership[vertex.first];
		for (const auto neighbor : vertex.second) {
			auto right_info = membership[neighbor];

       	 	strm << "{S" << std::to_string(left_info.first) << "[";
        	for (std::vector<unsigned int>::reverse_iterator dim = left_info.second.rbegin(); dim != (left_info.second.rend() - 1); ++dim) {
            	strm << std::to_string(*dim) << ",";
        	}
        	strm << std::to_string(left_info.second[0]) << "] -> ";

        	strm << "S" << std::to_string(right_info.first) << "[";
        	for (std::vector<unsigned int>::reverse_iterator dim = right_info.second.rbegin(); dim != (right_info.second.rend() - 1); ++dim) {
            	strm << std::to_string(*dim) << ",";
        	}
        	strm << std::to_string(right_info.second[0]) << "]};";

        	single_map = isl_map_read_from_str(ctx, strm.str().c_str());
        	ret_map = isl_union_map_coalesce(isl_union_map_add_map(ret_map, single_map));
        	strm.str(std::string());
		}
    }
	//isl_bool exact = isl_bool_false;
	//isl_bool* exact_ptr = &exact;
	//ret_map = isl_union_map_transitive_closure(ret_map, exact_ptr);
    return isl_union_map_coalesce(ret_map);
};


__isl_keep isl_union_map* qrane_deps::generate_write_all_dependences(isl_ctx* ctx) {
    std::ostringstream strm;
    isl_union_map* ret_map = isl_union_map_empty_ctx(ctx);
    isl_map* single_map;

    for (const auto &vertex : ddg_write_all) {
		auto left_info = membership[vertex.first];
		for (const auto neighbor : vertex.second) {
			auto right_info = membership[neighbor];

       	 	strm << "{S" << std::to_string(left_info.first) << "[";
        	for (std::vector<unsigned int>::reverse_iterator dim = left_info.second.rbegin(); dim != (left_info.second.rend() - 1); ++dim) {
            	strm << std::to_string(*dim) << ",";
        	}
        	strm << std::to_string(left_info.second[0]) << "] -> ";

        	strm << "S" << std::to_string(right_info.first) << "[";
        	for (std::vector<unsigned int>::reverse_iterator dim = right_info.second.rbegin(); dim != (right_info.second.rend() - 1); ++dim) {
            	strm << std::to_string(*dim) << ",";
        	}
        	strm << std::to_string(right_info.second[0]) << "]};";

        	single_map = isl_map_read_from_str(ctx, strm.str().c_str());
        	ret_map = isl_union_map_coalesce(isl_union_map_add_map(ret_map, single_map));
        	strm.str(std::string());
		}
    }
	//isl_bool exact = isl_bool_false;
	//isl_bool* exact_ptr = &exact;
	//ret_map = isl_union_map_transitive_closure(ret_map, exact_ptr);
    return isl_union_map_coalesce(ret_map);
};

	// ------------------------------------
	// Dependence Graph Frontier Processing
	// ------------------------------------

/*
	TODO: Document
*/
void qrane_deps::initialize_frontier_processing() {
	// Initialize the in_degree map with zeroes
	for (const auto& pair : this->ddg) {
		ddg_ins[pair.first] = 0;
	}

	// Increment in_degree count when node is encountered in a list
	for (const auto& pair : this->ddg) {
		for (const auto val : pair.second) {
			ddg_ins[val]++;
		}
	}
};

/*
	TODO: Document
*/
std::vector<unsigned int> qrane_deps::get_dependence_frontier() {
	if (this->ddg.empty()) { return std::vector<unsigned int>(); }
	std::vector<unsigned int> frontier;

	// Store all in-degree zero nodes
	for (const auto& pair : ddg_ins) {
 		if (pair.second == 0) { frontier.push_back(pair.first); }
	}
	return frontier;
};

/*
	TODO: Document
*/
void qrane_deps::decrement_in_degrees_of_path_neighbors(std::vector<unsigned int>& path) {
	for (const auto v : path) {
		for (unsigned int n : this->ddg[v]) {
			ddg_ins[n] -= 1;
		}
		ddg_ins[v] = -1;
	}
};

	// ------------------------
	// Look-ahead Functionality
	// ------------------------

/*
	TODO: Document
*/
std::array<unsigned int, 2> qrane_deps::dependence_graph_lookahead_breadth(
	std::vector<unsigned int>& frontier, unsigned int num_qops, 
	unsigned int depth, qasm_ops_list& qops_list) {

	std::array<unsigned int, 2> all_counts = {0,0};
	for (std::size_t i = 0; i < frontier.size(); ++i) {
		std::vector<unsigned int>& neighbors = this->ddg[frontier[i]];

        // No nodes to look ahead
		if (neighbors.size() == 0) { continue; }

		std::size_t args_count;
		for (std::size_t j = 0; j < depth && j < neighbors.size(); ++j) {
			args_count = std::get<ARGS>(qops_list[neighbors[j]]).size();
			all_counts[args_count - 1] += 1;
		}
	}
	return all_counts;
};

/*
	TODO: Document
*/
std::array<unsigned int, 2> qrane_deps::dependence_graph_lookahead_depth(
	std::vector<unsigned int>& frontier, unsigned int num_qops, unsigned int depth,
	qasm_ops_list& qops_list) {
	std::array<unsigned int, 2> count = {0, 0};

	for (auto i = frontier.begin(); i != frontier.end(); ++i) {
		std::size_t args = std::get<ARGS>(qops_list[*i]).size();
		count[args - 1] += 1;
		dependence_graph_lookahead_depth_main(*i, num_qops, depth, count, qops_list);
	}
	return count;
};

/*
	TODO: Document
*/
void qrane_deps::dependence_graph_lookahead_depth_main(unsigned int src, unsigned int num_qops, 
	unsigned int depth, std::array<unsigned int, 2>& count, qasm_ops_list& qops_list) {

	// The frame is <neighbor node, current_depth>
	auto traversal = std::stack<std::pair<unsigned int, unsigned int>>();
	auto completed = std::vector<bool>(num_qops, false);
	traversal.push(std::make_pair(src, 1));

	unsigned int v;
	unsigned int d;
	while (!traversal.empty()) {
		auto frame = traversal.top();
		v = frame.first;
		d = frame.second;
		traversal.pop();

		// If the vertex has not been counted, count it and mark it as counted
		if (!completed[v]) { 
			completed[v] = true;
			std::size_t args = std::get<ARGS>(qops_list[v]).size();
			count[args - 1] += 1;
		}

		if (d < depth) {
			for (auto n = ddg[v].begin(); n != ddg[v].end(); ++n) {
				traversal.push(std::make_pair(*n, d+1));
			}
		}
	}
};


	// -----------------------------
	// Printing and String Retrieval
	// -----------------------------

qubit_profile_map qrane_deps::get_qubit_access_profile_map() {
	return this->profile_map;
}

/*
	TODO: Document
*/
std::string qrane_deps::get_networkx_edge_list_str() {
	std::ostringstream strm;
	for (const auto& entry : ddg) {
		for (const auto neighbor : entry.second) {
			strm << entry.first << " " << neighbor << std::endl;
		}
	}
	return strm.str();
};

std::string qrane_deps::get_gates_networkx_edge_list_str(std::vector<qrane_statement*> stmts) {
	std::ostringstream strm;
	std::string lhs_id;
	std::string rhs_id;
	for (const auto& entry : ddg) {
		for (const auto neighbor : entry.second) {
			lhs_id = ((qrane_qop*)stmts[entry.first])->to_str();
			rhs_id = ((qrane_qop*)stmts[neighbor])->to_str();
			strm << lhs_id << " " << rhs_id << std::endl;
		}
	}
	return strm.str();
};

/*
	TODO: Document
*/
std::string qrane_deps::get_qubit_access_profile_str() {
	std::ostringstream strm;
	unsigned long long num_qubit_expr = 0;
	for (const auto &index_map : profile_map) {

		strm << index_map.first << ": {";
		for (const auto &gate_count_pair : index_map.second) {
			strm << " " << gate_count_pair.first << " (" << gate_count_pair.second << ")";
			num_qubit_expr += gate_count_pair.second;
		}
		strm << " }" << std::endl;
	}
	strm << "Index expression count: " << num_qubit_expr << std::endl;
	return strm.str();
};

/*
	TODO: Document
*/
void qrane_deps::time_dependence_graph_print() {
	std::ostringstream strm;
	strm << "{\n";
	for (auto& pair : ddg) {
		strm << "\t" << pair.first << " -> [ ";
		for (auto val : pair.second) {
			strm << val << " ";
		}
		strm << "];\n";
	}
	strm << "};";
	std::cout << strm.str() << std::endl;
};

/*
	TODO: Document
*/
void qrane_deps::time_dependence_graph_print_given(time_dependence_graph& G) {
	std::ostringstream strm;
	strm << "{\n";
	for (auto& pair : G) {
		strm << "\t" << pair.first << " -> [ ";
		for (auto val : pair.second) {
			strm << val << " ";
		}
		strm << "];\n";
	}
	strm << "};";
	std::cout << strm.str() << std::endl;
};

/*
	TODO: Document
*/
void qrane_deps::print_membership() {
    std::ostringstream stream;

    stream << "Membership: (line_num) -> (domain_num, [k, j, ...])" << std::endl;
    for (const auto &entry : membership) {
        stream << "(" << entry.first << ") -> ";
        stream << "(" << entry.second.first << ", [";

		for (auto r = entry.second.second.rbegin(); r != entry.second.second.rend(); ++r) {
			stream << *r << " ";
		}
        stream << "])" << std::endl;
    }
    std::cout << stream.str() << std::endl << std::flush;
};

/*
	TODO: Document
*/
void qrane_deps::print_membership_given(membership_map& given) {
	std::ostringstream stream;

    stream << "Membership: (line_num) -> (domain_num, [i, j, ...])" << std::endl;
    for (const auto &entry : given) {
        stream << "(" << entry.first << ") -> ";
        stream << "(" << entry.second.first << ", [";
        for (auto r = entry.second.second.rbegin(); r != entry.second.second.rend(); ++r) {
			stream << *r << " ";
		}
        stream << "])" << std::endl;
    }
    std::cout << stream.str() << std::endl;
}
