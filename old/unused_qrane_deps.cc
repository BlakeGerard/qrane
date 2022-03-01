/*
bool qrane_deps::path_violates_dependences(isl_ctx* ctx, std::vector<unsigned int>& path, qrane_domain test_domain,
                                           domain_map_t& domain_map, unsigned int domain_num, bool one_dim_phase) {

	//isl_union_set* test_dom = make_test_working_domain(ctx, path, test_domain);
	membership_map test_membership = make_test_membership_map(path, domain_map, domain_num, one_dim_phase);
	//print_membership_given(test_membership);
	time_dependence_graph test_ddg = ddg;
	isl_union_map* test_deps = generate_dependence_map_from_time_ddg(ctx, test_ddg, test_membership);

	isl_schedule_constraints* sc = isl_schedule_constraints_on_domain(test_dom);
    sc = isl_schedule_constraints_set_validity(sc, test_deps);
    isl_schedule* sched = isl_schedule_constraints_compute_schedule(sc);
	
	bool is_null = (sched == NULL);

	//if (!is_null) {
	//	//isl_schedule_dump(sched);
	//	printf("good schedule\n");
	//} else {
	//	printf("null schedule\n");
	//}

	// If it is null, then it was invalid
	return is_null;
};
*/

/*
bool qrane_deps::path_violates_lexico_positivity(isl_ctx* ctx, std::vector<unsigned int> path, domain_map_t& domain_map,
                                                 unsigned int domain_num, unsigned int num_qops, bool one_dim_phase) {
	time_dependence_graph test_merge = ddg; //merge_path_within_ddg(path);
	membership_map test_membership = make_test_membership_map(path, domain_map, domain_num, one_dim_phase);
	isl_union_map* temp_deps = generate_dependence_map_from_time_ddg(ctx, test_merge, test_membership);

	isl_union_set* deltas = isl_union_map_deltas(temp_deps);
	isl_bool result = isl_union_set_is_empty(deltas);

	isl_union_set_free(deltas);
	return !(result == 1);
};
*/

/*
bool qrane_deps::path_disrespects_dependences(std::vector<unsigned int> path, unsigned int num_qops) {
	if (path.size() == 1) { return false; }

    // dst  src
    //  a -> b -> d -> f -> c
	auto dst = path.begin();
	auto dst_end = path.end() - 1;
	auto src = path.begin() + 1;
	auto src_end = path.end();

	// For each a -> b pair in the path, 
	// check if a (dst) is reachable from b (src)
	for (; dst != dst_end && src != src_end; ++dst, ++src) {
		if (dfs_disrespects_dependences_main(*src, *dst, num_qops)) {
			return true;
		}
	}
	return false;
};

//https://medium.com/tebs-lab/breadth-first-search-and-depth-first-search-4310f3bf8416
bool qrane_deps::dfs_disrespects_dependences_main(unsigned int src, unsigned int dst, unsigned int num_qops) {
	auto traversal = std::stack<unsigned int>();
	auto completed = std::vector<bool>(num_qops, false);
	traversal.push(src);

	unsigned int v;
	while (!traversal.empty()) {
		v = traversal.top();
		traversal.pop();
		if (completed[v]) { continue; }
		if (v == dst) { return true; }

		for (auto n = ddg[v].begin(); n != ddg[v].end(); ++n) {
			traversal.push(*n);
		}
		completed[v] = true;
	}
	return false;
};
*/

/*
// Recursive Cycle Detection main
bool qrane_deps::path_introduces_dependence_cycle(std::vector<unsigned int> path, unsigned int num_qops) {
	if (path.size() == 1) { return false; }
	auto test_merge = merge_path_within_ddg(path);

	auto visited = std::vector<bool>(num_qops, false);
	auto recstack = std::vector<bool>(num_qops, false);
	for (auto it = working_ddg.begin(); it != working_ddg.end(); ++it) {
		visited[it->first] = false;
		recstack[it->first] = false;
	}
	
	for (auto it = test_merge.begin(); it != test_merge.end(); ++it) {
		if (dfs_dependence_cycle_util(it->first, test_merge, visited, recstack)) {
			return true;
		}
	}
	return false;
};
*/

/*
// Recursive Cycle Detection util
bool qrane_deps::dfs_dependence_cycle_util(unsigned int v, time_dependence_graph& G, std::vector<bool> visited, std::vector<bool>& recstack) {
	if (visited[v] == false) {
		visited[v] = true;
		recstack[v] = true;

		for (auto n = G[v].begin(); n != G[v].end(); ++n) {
			if (!visited[*n] && dfs_dependence_cycle_util(*n, G, visited, recstack))
				return true;
			else if (recstack[*n])
				return true;
		}
	}
	recstack[v] = false;
	return false;
}
*/

/*
time_dependence_graph qrane_deps::merge_path_within_ddg(std::vector<unsigned int> path) {
	time_dependence_graph test_merge = this->working_ddg;
	unsigned int leader = path[0];

	// First, remove any self references
	std::vector<unsigned int> no_self_refs;
	for (auto it = test_merge[leader].begin(); it != test_merge[leader].end(); ++it) {
		if (std::find(path.begin(), path.end(), *it) == path.end()) {
			no_self_refs.push_back(*it);
		}
	}
	test_merge[leader] = no_self_refs;

	// Then, collect the neighbors of all other elements in the path
	for (std::size_t i = 1; i < path.size(); ++i) {
		auto neighbors = test_merge[path[i]];

		for (auto n : neighbors) {
			if (std::find(ddg[leader].begin(), ddg[leader].end(), n) == ddg[leader].end()) {
				test_merge[leader].push_back(n);
			}
		}
		test_merge.erase(path[i]);
	}

	// Finally, convert all other references to any element in the path 
	// to the leader value
	for (auto& node : ddg) {
		std::vector<unsigned int> adjusted;
		if (std::find(node.second.begin(), node.second.end(), leader) != node.second.end()) {
			for (auto val : node.second) {
				if (std::find(path.begin(), path.end(), val) == path.end()) {
					adjusted.push_back(val);
				}
			}
			adjusted.push_back(leader);
			node.second = adjusted;
		}
	}
	return test_merge;
}
*/

/*
void qrane_deps::contract_path(std::vector<unsigned int> path) {
	time_dependence_graph test_merge = this->working_ddg;
	unsigned int leader = path[0];

	// First, remove any self references
	std::vector<unsigned int> no_self_refs;
	for (auto it = test_merge[leader].begin(); it != test_merge[leader].end(); ++it) {
		if (std::find(path.begin(), path.end(), *it) == path.end()) {
			no_self_refs.push_back(*it);
		}
	}
	test_merge[leader] = no_self_refs;

	// Then, collect the neighbors of all other elements in the path
	for (std::size_t i = 1; i < path.size(); ++i) {
		auto neighbors = test_merge[path[i]];

		for (auto n : neighbors) {
			if (std::find(ddg[leader].begin(), ddg[leader].end(), n) == ddg[leader].end()) {
				test_merge[leader].push_back(n);
			}
		}
		test_merge.erase(path[i]);
	}

	// Finally, convert all other references to any element in the path 
	// to the leader value
	for (auto& node : ddg) {
		std::vector<unsigned int> adjusted;
		if (std::find(node.second.begin(), node.second.end(), leader) != node.second.end()) {
			for (auto val : node.second) {
				if (std::find(path.begin(), path.end(), val) == path.end()) {
					adjusted.push_back(val);
				}
			}
			adjusted.push_back(leader);
			node.second = adjusted;
		}
	}
	this->working_ddg = test_merge;
};
*/

/*
membership_map qrane_deps::make_test_membership_map(std::vector<unsigned int>& path, domain_map_t& domain_map,
                                                    unsigned int domain_num, bool one_dim_phase) {
	membership_map ret = this->membership;
	if (one_dim_phase) {
		// path represents points in potential 1d domain

		unsigned int index = 0;
		for (const auto point : path) {
			ret[point].first = domain_num;
			ret[point].second.push_back(index);
			++index;
		}

	} else {
		// path represents domain ids

		unsigned int parent_num = path.front();
		std::vector<unsigned int> components = domain_map[parent_num].component_qops; // should this be subdomains?
	
		// Update the points of the parent domain with a zero value for outermost loop variable
		for (auto val : components) {
			ret[val].second.push_back(0);
		}

		// Do the same as above for each subsequent domain, but use mergee_counter instead of zero
		unsigned int mergee_counter = 1;
		for (std::size_t i = 1; i < path.size(); ++i) {
     	   components = domain_map[path[i]].component_qops;

    		for (auto val : components) {
				ret[val].first = parent_num;
    	     	ret[val].second.push_back(mergee_counter);
			}
    	    mergee_counter += 1;
    	}
	}
	return ret;
}
*/

/*
	This is taking up a lot of time.

std::vector<unsigned int> qrane_deps::get_dependence_frontier() {
	if (working_ddg.empty()) { return std::vector<unsigned int>(); }
	std::unordered_map<unsigned int, unsigned int> in_degree = std::unordered_map<unsigned int, unsigned int>(working_ddg.size());
	std::vector<unsigned int> frontier;

	// Initialize the in_degree map with zeroes
	for (const auto& pair : this->working_ddg) {
		in_degree[pair.first] = 0;
	}

	// Increment in_degree count when node is encountered in a list
	for (const auto& pair : this->working_ddg) {
		for (const auto val : pair.second) {
			in_degree[val]++;
		}
	}

	// Store all in-degree nodes
	for (const auto& pair : in_degree) {
		if (pair.second == 0) { frontier.push_back(pair.first); }
	}
	return frontier;
};
*/

/*
std::unordered_map<unsigned int, std::pair<unsigned int, unsigned int>> qrane_deps::get_time_degree_profile(unsigned int num_qops) {
	auto ret = std::unordered_map<unsigned int, std::pair<unsigned int, unsigned int>>();
	ret.reserve(num_qops);

	for (auto pair : this->ddg) {
		for (auto v : pair.second) {
			ret[v].first += 1;							// Increment in degree of each vertex in the adjacency list 
		}
		ret[pair.first].second = pair.second.size();	// Out degree equals size(list)
	}
	return ret;
};
*/


/*
	BFS to see if there is a dependence between a and b.
	BFS is necessary to find transitive dependencies.
bool qrane_deps::dependence_exists(unsigned int s, unsigned int d) {
	if (s == d) { return true; }
	std::size_t vertices = ddg.size();

	// Mark all vertices as not visited
	bool visited[vertices];
	for (std::size_t i = 0; i < vertices; ++i) {
		visited[i] = false;
	}

	std::queue<unsigned int> traversal;
	visited[s] = true;
	traversal.push(s);

	while (!traversal.empty()) {
		s = traversal.front();
		traversal.pop();

		for (auto i = ddg[s].begin(); i != ddg[s].end(); ++i) {
			if (*i == d) { return true; }

			if (!visited[*i]) {
				visited[*i] = true;
				traversal.push(*i);
			}
		}
	}
	return false;
}
*/

/*
std::size_t qrane_deps::qop_in_degree(qrane_qop* qop) {
	std::size_t in_degree = 0;
	for (const auto &elem : validity) {
		if (elem.second == qop->get_dim1_qop_num()) {
			in_degree += 1;
		}
	}
	return in_degree;
}
*/

/*
std::size_t qrane_deps::qop_out_degree(qrane_qop* qop) {
	std::size_t out_degree = 0;
	for (const auto &elem : validity) {
		if (elem.first == qop->get_dim1_qop_num()) {
			out_degree += 1;
		}
	}
	return out_degree;
}
*/