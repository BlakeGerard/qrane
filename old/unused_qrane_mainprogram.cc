
/*
void qrane_mainprogram::parse_ND_domains_cover(unsigned int current_dim) {
	isl_mat* result;
	isl_mat* concat;
	std::vector<qrane_domain> domains;
  	std::vector<qrane_domain> mergees;
  	std::vector<qrane_domain> updated_domains;

	//std::list<std::pair<qrane_domain, std::vector<unsigned int>>> candidates;
	std::vector<qrane_domain> candidates;
  
	unsigned int update_count = 0;

	// Do this for each gate type
  	for (auto& gate_type : gate_domain_map) {
    	domains = gate_type.second;

		// For each 1D domain, dom_i
    	for (std::size_t i = 0; i < domains.size(); ++i) {
		//	auto doms_at_i = std::list<std::pair<qrane_domain, std::vector<unsigned int>>>();
			auto doms_at_i = std::vector<qrane_domain>();
			qrane_domain dom_i = domains[i];

			// For each subsequent domain, dom_j
      		for (std::size_t j = i + 1; j < domains.size(); ++j) {
				qrane_domain dom_j = domains[j];

				// First check if dom_j is consistent with any of the doms_at_i
				for (std::size_t k = 0; k < doms_at_i.size(); ++k) {
					isl_mat* dom_j_appended = append_column_with_val(dom_j.get_access_mat_copy(), doms_at_i[k].subdomains);
					
					concat = isl_mat_concat(dom_j_appended, doms_at_i[k].get_access_mat_copy());
					isl_mat_dump(concat);
					result = compute_access_relations(isl_mat_copy(concat));
					if (check_consistency(result, current_dim, doms_at_i[k].args)) {
						doms_at_i[k].add_component_qops(dom_j.component_qops);
						doms_at_i[k].set_access_mat(isl_mat_copy(concat));
						doms_at_i[k].subdomains += 1;
					}
					
					isl_mat* dom_j_appended = append_column_with_val(dom_j.get_access_mat_copy(), elem.first.subdomains);
					
					concat = isl_mat_concat(dom_j_appended, elem.first.get_access_mat_copy());
					isl_mat_dump(concat);
					result = compute_access_relations(isl_mat_copy(concat));
					if (check_consistency(result, current_dim, elem.first.args)) {
						elem.first.add_component_qops(dom_j.component_qops);
						elem.first.set_access_mat(isl_mat_copy(concat));
						elem.first.subdomains += 1;
						elem.second.push_back(dom_j.domain_num);
					}
					
					isl_mat_free(concat);
					isl_mat_free(result);
				}

				// When that is done, just try to make a domain between i and j
				isl_mat* dom_i_appended = append_column_with_val(dom_i.get_access_mat_copy(), 0);
				isl_mat* dom_j_appended = append_column_with_val(dom_j.get_access_mat_copy(), 1);
				concat = isl_mat_concat(dom_j_appended, dom_i_appended);
				result = compute_access_relations(isl_mat_copy(concat));
				if (check_consistency(result, current_dim, dom_i.args)) {
					qrane_domain new_nd_placeholder = qrane_domain();
					new_nd_placeholder.add_component_qops(dom_i.component_qops);
					new_nd_placeholder.add_component_qops(dom_j.component_qops);
					new_nd_placeholder.set_access_mat(isl_mat_copy(concat));
					new_nd_placeholder.subdomains = 2;
					std::vector<unsigned int> subdomains({dom_i.domain_num, dom_j.domain_num});
					doms_at_i.push_back(new_nd_placeholder);
					//doms_at_i.push_back(std::pair<qrane_domain, std::vector<unsigned int>>(new_nd_placeholder, subdomains));
				}
				isl_mat_free(concat);
				isl_mat_free(result);
      		}
			candidates.insert(candidates.end(), doms_at_i.begin(), doms_at_i.end());
    	}
	}
	std::cout << "made it" << std::endl;
	//candidates = greedy_nd_domain_selection(candidates);
};

bool dom_compare(const std::pair<qrane_domain, std::vector<unsigned int>>& a, 
                 const std::pair<qrane_domain, std::vector<unsigned int>>& b) {
    return a.first.subdomains < b.first.subdomains;
};

std::list<std::pair<qrane_domain, std::vector<unsigned int>>> qrane_mainprogram::greedy_nd_domain_selection(
									std::list<std::pair<qrane_domain, std::vector<unsigned int>>> candidates) {

	std::list<std::pair<qrane_domain, std::vector<unsigned int>>> ret;
	while (!candidates.empty()) {
		auto max_it = std::max_element(candidates.begin(), candidates.end(), dom_compare);
		std::vector<unsigned int> subdomains = max_it->second;

		candidates.erase(max_it);
		ret.push_back(*max_it);

		std::vector<std::list<std::pair<qrane_domain, std::vector<unsigned int>>>::iterator> to_remove;
		for (auto cand = candidates.begin(); cand != candidates.end(); ++cand) {

			for (auto& dom_num : subdomains) {
				if (std::find(cand->second.begin(), cand->second.end(), dom_num) != cand->second.end()) {
					to_remove.push_back(cand);
					break;
				}
			}
		}
		for (auto cand : to_remove) {
			candidates.erase(cand);
		}
	}
	return ret;
};
*/


/*
void qrane_mainprogram::parse_with_bipartition_cover() {
	qops = qasm_ops_by_gate();
	convert_stmtlist_to_vector_form();
	bool continue_flag = false;
	bool dep_found = false;
	unsigned int global_domain_count = 0;
	
	// Do this for each gate type
	for (auto& gate_type : qops) {
		std::string gate_id = gate_type.first;
		
		// Get the number of arguments for this gate type
		unsigned int num_args = std::get<ARGS>(gate_type.second.front()).size();
		function_adjacency_list adj_list_per_arg = function_adjacency_list();

			// For each point in the qops list
			// This is sorted lexicograpically with dependence constraints
			for (std::size_t i = 0; i < gate_type.second.size(); ++i) {
				dep_found = false;
				unsigned long op_num_global = std::get<QOP_NUM_GLOBAL>(gate_type.second[i]);

				// Initialize an adjacency_list for the functions passing through the current point
				function_adjacency_list participants = function_adjacency_list();

				// Now we construct (x, y) pairs for each argument, where
				// x = position in the qops list = i
				// y = arg_val
				std::vector<std::pair<float, float>> floats_per_argument_zero;
				floats_per_argument_zero.reserve(num_args);

				float x0;
				if (COVER_MODE > 0) { x0 = i; }
				//else if (COVER_MODE == 2) { x0 = std::find(qops_list.begin(), qops_list.end(), gate_type.second[i]) - qops_list.begin(); }
				for (std::size_t j = 0; j < num_args; ++j) {
					float y0_j = std::get<ARGS>(gate_type.second[i])[j];
					floats_per_argument_zero.push_back(std::pair<float, float>({x0, y0_j}));
				}

				// Add a "default" function containing just the point with slopes of zero
				std::vector<std::pair<unsigned int, int>> key;
				key.reserve(num_args);
				for (std::size_t k = 0; k < num_args; ++k) {
					key.push_back(std::pair<unsigned int, int>({op_num_global, 0}));
				}
				participants[key].insert(op_num_global);

				// For all following points in the qops list
				for (std::size_t j = i+1; j < gate_type.second.size(); ++j) {
					unsigned long j_op_num_global = std::get<QOP_NUM_GLOBAL>(gate_type.second[j]);
					continue_flag = false;

					// Construct the (x, y) pairs for each argument of this point, where
					// x = position in the qops list = j
					// y = arg_val
					std::vector<std::pair<float, float>> floats_per_argument_one;
					floats_per_argument_one.reserve(num_args);
					
					float x1;
					if (COVER_MODE > 0) { x1 = j; }
					//else if (COVER_MODE == 2) { x1 = std::find(qops_list.begin(), qops_list.end(), gate_type.second[j]) - qops_list.begin(); }
					for (std::size_t k = 0; k < num_args; ++k) {

						if (SEND_IT == 0) {
							if (std::get<ARGS>(gate_type.second[i])[k] == std::get<ARGS>(gate_type.second[j])[k]) {
								dep_found = true;
								break;
							}
						}
					
						float y1_k = std::get<ARGS>(gate_type.second[j])[k];
						floats_per_argument_one.push_back(std::pair<float, float>({x1, y1_k}));
					}
					if (dep_found) {break;}

					// Now compute the slopes between all arguments
					std::vector<float> slopes;
					slopes.reserve(num_args);
					for (std::size_t k = 0; k < num_args; ++k) {
						float rise = floats_per_argument_one[k].second - floats_per_argument_zero[k].second;
						float run = floats_per_argument_one[k].first - floats_per_argument_zero[k].first;

						if (run != 0) {
							slopes.push_back(rise / run);
						} else {
							continue_flag = true;
							break;
						}
					}
					if (continue_flag) {continue;}
					
					// Check if all slopes are integers
					bool all_integers = true;
					for (std::size_t k = 0; k < num_args; ++k) {
						if (!is_integer(slopes[k])) {
							all_integers = false;
						}
					}

					// Make the key
					std::vector<std::pair<unsigned int, int>> key;
					key.reserve(num_args);
					if (all_integers) {
						for (std::size_t k = 0; k < num_args; ++k) {
							key.push_back(std::pair<unsigned int, int>({op_num_global, slopes[k]}));
						}
						participants[key].insert(op_num_global);
						participants[key].insert(j_op_num_global);
					}
				}

				// Put the i'th qop into the participants list of each function that starts with
				// the i'th qop
				for (auto &elem : participants) {
					elem.second.insert(op_num_global);
				}
				adj_list_per_arg.insert(participants.begin(), participants.end());
			}

		adj_list_per_arg = greedy_covering_policy(adj_list_per_arg);

		std::cout << gate_type.first << " := {\n";
		for (auto const pair : adj_list_per_arg) {
			
			std::cout << "{";
			for (auto const elem : pair.first) {
				std::cout << "(" << elem.first << "," << elem.second << ") ";
			}
			std::cout << "} -> [";

			for (auto const elem : pair.second) {
				std::cout << elem << ",";
			}
			std::cout << "];\n";
		}
		std::cout << "};" << std::endl;

		// Now build the domains
		std::vector<std::pair<unsigned int, unsigned int>> points;
		for (const auto funct : adj_list_per_arg) {
			qrane_domain domain = qrane_domain(ctx, global_domain_count, gate_id, num_args, funct.first, funct.second, this->qops_list);
			gate_map_store_domain(domain);
			points = domain.generate_1D_points();
			for (const auto point : points) {
        		deps.set_membership(point.first, point.second, global_domain_count);
      		}
			global_domain_count += 1;
		}
	}
}
*/

// Basically enumerates all paths in a complete graph, of which there are n!
/*
	for (auto elem : G) {
		std::cout << "\nPaths from " << elem.first << std::endl;
		frame_stack stack = frame_stack();
		
		// Start value
		auto start_frame = std::make_tuple(elem.first, std::vector<bool>(num_v, false),
							std::vector<int>(), std::vector<unsigned int>());
		stack.push(start_frame);

		while (!stack.empty() && stack.size() < 150) {
			auto curr_frame = stack.top();
			auto curr_id = std::get<ID>(curr_frame);
			stack.pop();

			// Put the current global id into the visited and path vectors
			if (!std::get<VISITED>(curr_frame)[curr_id]) {
				std::get<PATH>(curr_frame).push_back(curr_id);
				std::get<VISITED>(curr_frame)[curr_id] = true;
			}

			// For each neighbor
			bool frame_pushed = false;
			for (auto i = G[curr_id].begin(); i != G[curr_id].end(); ++i) {
				
				// If the vertex is unvisited
				if (!std::get<VISITED>(curr_frame)[(*i).first]) {

					// If the strides list is empty, then we are at the first branch and we use
					// the strides paired with the neighbor
					if (std::get<STRIDES>(curr_frame).empty()) {
						auto new_frame = std::make_tuple((*i).first, std::get<VISITED>(curr_frame),
									   					(*i).second, std::get<PATH>(curr_frame));
						stack.push(new_frame);
						frame_pushed = true;
					} else {
						if ((*i).second == std::get<STRIDES>(curr_frame)) {
							auto new_frame = std::make_tuple((*i).first, std::get<VISITED>(curr_frame),
									   					    (*i).second, std::get<PATH>(curr_frame));
							stack.push(new_frame);
							frame_pushed = true;
						}
					}
				}
			}
			if (!frame_pushed) {
				
				for (auto val : std::get<PATH>(curr_frame)) {
					std::cout << val  << " ";
				}
				std::cout << std::endl;
				
			} 
		}
	}
*/

/*
    After this object recieves a stmtlist populated with qops,
  we construct a vector of qrane_domains. Each qrane_domain 
  contains information that defines distinct groups of qubits.
  For each qop in the file, we check if it belongs in an existing
  qrane_domain by a reverse search through the domain list (e.g. 
  the qop likely belongs in the most recent group of the same name 
  and control linearity). If a qualifying domain is found, the domain
  information is updated internally.
    This function is a prerequisite for ALL isl specific functions,
  thus, it is called right after a valid stmtlist is provided to
  this object.

  Params:
    none
  Return:
    none

void qrane_mainprogram::parse_1D_domains() {
  std::vector<qrane_statement*> qops = stmtlist->get_qops();
  qrane_qop* qop;
  std::string id;
  int domain_num = 0;
  bool existing_stmt_found = false;

  qop = (qrane_qop*) qops[0];
  qrane_domain new_dom = qrane_domain(domain_num, qop);
  gate_map_store_domain(new_dom);
  add_dependence_vertex(qop);

  for (std::size_t i = 1; i < qops.size(); ++i) {

    // Retrieve the qop
    qop = (qrane_qop*) qops[i];
    id = qop->get_id();

	if (gate_domain_map.count(id)) {
		// Reverse loop through the domains in the vector to see 
    	// if it belongs to a currently existing domain.
		unsigned int count = 0;
    	for (auto dom = gate_domain_map.at(id).end() - 1; dom >= gate_domain_map.at(id).begin() && count < DISTANCE_LIMIT; --dom) {
		//for (auto dom = gate_domain_map.at(id).begin(); dom != gate_domain_map.at(id).end() && count < DISTANCE_LIMIT; ++dom) {

      		if (dom->check_qop_belongs_in_domain(qop)) {
        		existing_stmt_found = true;
        		add_dependence_vertex(qop);
        		break;
      		}
			++count;
    	}
	}

    

    // Either no polyhedral statement with same gate type, 
    // OR does not fall in linearity range of another statement, make a new one.
    if (!existing_stmt_found) {
      domain_num += 1;
      qrane_domain new_dom = qrane_domain(domain_num, qop);
      gate_map_store_domain(new_dom);
      add_dependence_vertex(qop);
    }
    existing_stmt_found = false;
  }

  std::vector<std::pair<unsigned int, unsigned int>> points;
  for (auto &gate_type : gate_domain_map) {
    for (auto dom = gate_type.second.begin(); dom != gate_type.second.end(); ++dom) {
      dom->build_local_domain(ctx);
      points = dom->generate_1D_points();

      for (const auto &point : points) {
        deps.set_membership(point.first, point.second, dom->domain_num);
      }
    }
  }
}
*/

/*
void qrane_mainprogram::parse_with_bipartition_cover() {
	convert_stmtlist_to_vector_form();
	bool continue_flag;
	bool dep_found;
	bool all_integers;
	unsigned int global_domain_count = 0;
	function_adjacency_list adj_list = function_adjacency_list();

	std::cout << "Computing candidate 1D domains ... ";

	// For each point in the qops list
	for (std::size_t i = 0; i < qops_list.size(); ++i) {
		qop_identifier qop_i = qops_list[i];

		// Get relevant information about qop_i
		unsigned int num_args_i = std::get<ARGS>(qop_i).size();
		unsigned long op_num_global_i = std::get<QOP_NUM_GLOBAL>(qop_i);
		std::string gate_id_i = std::get<GATE_TYPE>(qop_i);
	
		// Initialize an adjacency_list for the functions passing through the current point
		function_adjacency_list funcs_at_i = function_adjacency_list();

		// Now we construct (x, y_i) pairs for each argument, where
		// x = dependens on COVER_MODE
		// y_i = arg_val
		std::vector<std::pair<float, float>> floats_per_argument_zero;
		floats_per_argument_zero.reserve(num_args_i);
		float x0 = 0;
		//if (COVER_MODE == 1) { x0 = std::get<QOP_NUM_TYPE>(qop_i); }
		//else if (COVER_MODE == 2) { x0 = i; }
		for (std::size_t j = 0; j < num_args_i; ++j) {
			float y0_j = std::get<ARGS>(qop_i)[j];
			floats_per_argument_zero.push_back(std::pair<float, float>({x0, y0_j}));
		}

		// Add a "default" function containing just the point with slopes of zero
		
		std::vector<std::pair<unsigned int, int>> key;
		key.reserve(num_args_i);
		for (std::size_t k = 0; k < num_args_i; ++k) {
			key.push_back(std::pair<unsigned int, int>({op_num_global_i, 0}));
		}
		funcs_at_i[key].insert(op_num_global_i);
		

		// For all following points in the qops list
		for (std::size_t j = i+1; j < qops_list.size(); ++j) {
			dep_found = false;
			continue_flag = false;
			all_integers = true;
			qop_identifier qop_j = qops_list[j];

			// Get relevant information about qop_j
			unsigned long op_num_global_j = std::get<QOP_NUM_GLOBAL>(qop_j);
			std::string gate_id_j = std::get<GATE_TYPE>(qop_j);

			// Now if we are checking for dependencies during the reconstruction, we may
			// have to exit the search on qop_i at this point.
			if (SEND_IT == 0) {
				auto args_i = std::get<ARGS>(qop_i);
				auto args_j = std::get<ARGS>(qop_j);
				for (const unsigned long arg : args_i) {
					if (std::find(args_j.begin(), args_j.end(), arg) != args_j.end()) {
						dep_found = true;
						break;
					}
				}
				if (dep_found) {
					break;
				}
			}

			// If there are no dependencies, we first check if the qops have the same gate type
			if (gate_id_i != gate_id_j) { continue; }

			for (const auto &func : funcs_at_i) {
				continue_flag = false;
				// x1 is equal to the size of the participants list
				std::vector<std::pair<float, float>> floats_per_argument_one;
				floats_per_argument_one.reserve(num_args_i);
				float x1 = func.second.size();
				for (std::size_t k = 0; k < num_args_i; ++k) {
					float y1_k = std::get<ARGS>(qop_j)[k];
					floats_per_argument_one.push_back(std::pair<float, float>({x1, y1_k}));
				}

				for (std::size_t k = 0; k < num_args_i; ++k) {
					if (func.first[k].second * x1 + std::get<ARGS>(qop_i)[k] != floats_per_argument_one[k].second) {
						continue_flag = true;
						break;
					}
				}
				if (continue_flag) { continue ;}
				funcs_at_i[func.first].insert(op_num_global_j);
			}
			continue_flag = false;

			// Construct the (x, y_j) pairs for each argument of this point, where
			// x = depends on COVER_MODE
			// y_j = arg_val
			std::vector<std::pair<float, float>> floats_per_argument_one;
			floats_per_argument_one.reserve(num_args_i);
			float x1 = 1;
			//if (COVER_MODE == 1) { x1 = std::get<QOP_NUM_TYPE>(qop_j); }
			//else if (COVER_MODE == 2) { x1 = j; }
			for (std::size_t k = 0; k < num_args_i; ++k) {
				float y1_k = std::get<ARGS>(qop_j)[k];
				floats_per_argument_one.push_back(std::pair<float, float>({x1, y1_k}));
			}

			// Now compute the slopes between all arguments
			std::vector<float> slopes;
			slopes.reserve(num_args_i);
			for (std::size_t k = 0; k < num_args_i; ++k) {
				float rise = floats_per_argument_one[k].second - floats_per_argument_zero[k].second;
				float run = floats_per_argument_one[k].first - floats_per_argument_zero[k].first;

				if (run != 0) {
					slopes.push_back(rise / run);
				} else {
					continue_flag = true;
					break;
				}
			}
			// For an undefined slope, continue on to the next qop_j
			if (continue_flag) { continue; }
					
			// Check if all slopes are integers
			for (std::size_t k = 0; k < num_args_i; ++k) {
				if (!qrane_utils::is_integer(slopes[k])) {
					all_integers = false;
				}
			}
			// If one argument is not governed by an integer line, continue on to the next qop_j
			if (!all_integers) { continue; }

			// Make the key
			std::vector<std::pair<unsigned int, int>> key;
			key.reserve(num_args_i);
			for (std::size_t k = 0; k < num_args_i; ++k) {
				key.push_back(std::pair<unsigned int, int>({op_num_global_i, slopes[k]}));
			}

			// Insert the global identifiers at the computed key
			if (funcs_at_i.count(key) == 0) {
				funcs_at_i[key].insert(op_num_global_i);
				funcs_at_i[key].insert(op_num_global_j);
			}
		}

		// Insert all funcs_at_i into the global adj_list
		adj_list.insert(funcs_at_i.begin(), funcs_at_i.end());
	}
	
	std::cout << "Done." << std::endl << std::flush;

	// Select the domains according to the greedy-maximum covering policy
	std::cout << "Selecting 1D domains ... " << std::flush;
	adj_list = greedy_covering_policy(adj_list);
	print_adjacency_list(adj_list);
	std::cout << "Done." << std::endl << std::flush;

	std::map<unsigned int, unsigned int> hist;
	
	// Now build the domains
	auto find_lambda = [](const qop_identifier& id, unsigned int global) { return std::get<QOP_NUM_GLOBAL>(id) == global; };
	std::vector<std::pair<unsigned int, unsigned int>> points;
	for (const auto &funct : adj_list) {
		qop_identifier starting_point = *(std::find_if(qops_list.begin(), qops_list.end(), std::bind(find_lambda, std::placeholders::_1, funct.first[0].first)));
		std::string gate_id = std::get<GATE_TYPE>(starting_point);
		unsigned int num_args = funct.first.size();
		qrane_domain domain = qrane_domain(ctx, global_domain_count, gate_id, num_args, funct.first, funct.second, this->qops_list);
		gate_map_store_domain(domain);
		original_domains.push_back(domain);
		points = domain.generate_1D_points();
		for (const auto &point : points) {
        	deps.set_membership(point.first, point.second, global_domain_count);
      	}
		global_domain_count += 1;

		hist[domain.get_card()] += 1;
	}

	std::cout << "--------------------" << std::endl;
	std::cout << "Size : Domains of this size" << std::endl;
	for (auto bucket : hist) {
		std::cout << bucket.first << " : " << bucket.second << std::endl;
	} 
	std::cout << "--------------------" << std::endl;
}
*/

/*
	Return true if a should come before b
bool qrane_mainprogram::dependence_constrained_lex_order(const qop_identifier& a, const qop_identifier& b) {
	std::vector<int> _a = std::get<ARGS>(a);
	std::vector<int> _b = std::get<ARGS>(b);
	return std::lexicographical_compare(_a.begin(), _a.end(), _b.begin(), _b.end());
	std::cout << std::get<QOP_NUM_GLOBAL>(a) << ", " << std::get<QOP_NUM_GLOBAL>(b) << std::endl;
	bool intermediate;
	if (deps.dependence_exists(std::get<QOP_NUM_GLOBAL>(b), std::get<QOP_NUM_GLOBAL>(a))) {
		std::cout << "dependence_exists\n";
		return false;
	} else {

		auto first_a = a_args.begin();
		auto last_a = a_args.end();
		auto first_b = b_args.begin();
		auto last_b = b_args.end();

		while (a_args.size() < b_args.size()) {
			a_args.push_back(std::numeric_limits<int>::max());
		}
		while (b_args.size() < a_args.size()) {
			b_args.push_back(std::numeric_limits<int>::max());
		}

		intermediate = std::lexicographical_compare(first_a, last_a, first_b, last_b);
		if (intermediate) { return true; }
		else {return false;}

		// Compare in degrees
		unsigned int a_comp = std::get<IN_DEGREE>(a);
		unsigned int b_comp = std::get<IN_DEGREE>(b);
		if (a_comp < b_comp) {return true;}
		else if (a_comp > b_comp) {return false;}

		// Compare out degrees
		a_comp = std::get<OUT_DEGREE>(a);
		b_comp = std::get<OUT_DEGREE>(b);
		if (a_comp < b_comp) {return true;}
		else if (a_comp > b_comp) {return false;}

		// Compare gate types
		std::string a_gate = std::get<GATE_TYPE>(a);
		std::string b_gate = std::get<GATE_TYPE>(b);
		if (a_gate < b_gate) {return true;}
		else if (a_gate > b_gate) {return false;}

		// Compare qop_num_type
		a_comp = std::get<QOP_NUM_TYPE>(a);
		b_comp = std::get<QOP_NUM_TYPE>(b);
		if (a_comp < b_comp) {return true;}
		else if (a_comp > b_comp) {return false;}

		// Compare qop_num_global
		a_comp = std::get<QOP_NUM_GLOBAL>(a);
		b_comp = std::get<QOP_NUM_GLOBAL>(b);
		if (a_comp < b_comp) {return true;}
		else if (a_comp > b_comp) {return false;}
	}
	// If we get here, the tuples are equal (which will never happen because global identifier)
	return true;
};
*/

/*
__isl_give isl_mat* qrane_mainprogram::create_access_mat_from_candidate_function(function_identifier f_id, function_neighbors neighbors, qasm_ops_list qops) {
	unsigned int dimensionality = 1;
	unsigned int args = f_id.size();
	std::size_t rows = neighbors.size();
    std::size_t cols = dimensionality + 2*(args); // 1 column for i and 2 columns per arg(1 offset and 1 value)

    isl_mat* access_mat = isl_mat_alloc(this->ctx, rows, cols);
	unsigned int row = 0;
	unsigned int iter = 0;
	for (unsigned int neighbor : neighbors) {
		row = (rows-1) - iter;
		access_mat = isl_mat_set_element_si(access_mat, row, cols-1, iter);

		for (std::size_t ctr = 0; ctr < args; ++ctr) {
			int index = (2*args-2) - 2*ctr;
			access_mat = isl_mat_set_element_si(access_mat, row, index+1, 1);
			access_mat = isl_mat_set_element_si(access_mat, row, index, std::get<ARGS>(qops[neighbor])[ctr]);
		}	
		++iter;
	}
	return access_mat;
};
*/

/*
function_adjacency_list qrane_mainprogram::greedy_covering_policy(function_adjacency_list adj) {
	function_neighbors satisfied;
	function_adjacency_list new_adj;

	while (satisfied.size() != num_qops) {

		// First find the maximum size list on the rhs and get all of its neighbors
		auto max_it = std::max_element(adj.begin(), adj.end(), vec_compare);
		function_neighbors max_neighbors = max_it->second;

		// Insert the max_it entry into the new_adj list
		new_adj.insert(*max_it);
		satisfied.insert(max_neighbors.begin(), max_neighbors.end());
		adj.erase(max_it);
	
		// Now we need to do remove all of max_it's neighbors from the graph
		std::vector<function_identifier> to_remove;
		for (auto& pair : adj) {
			// Check if the current function references any of max_it's neighbors
			for (auto& elem : pair.second) {
				if (std::find(max_neighbors.begin(), max_neighbors.end(), elem) != max_neighbors.end()) {
					to_remove.push_back(pair.first);
					break;
				}
			}
		}
		for (auto elem : to_remove) {
			adj.erase(elem);
		}
	}
	return new_adj;
};
*/

/*
void qrane_mainprogram::sort_favor_linearity(qasm_ops_list& ops_list) {
	std::stable_sort(ops_list.begin(), ops_list.end(), 
	std::bind(&qrane_mainprogram::dependence_constrained_lex_order, this, std::placeholders::_1, std::placeholders::_2));
}
*/

/*
Old one qubit gate reconstruction
void qrane_mainprogram::one_qubit_gate_reconstruction() {
	for (auto gate_partition : qops) {
		std::vector<bool> seen = std::vector<bool>(qreg_size, false);
		unsigned int args = std::get<ARGS>(gate_partition.second[0]).size();
		if (args > 1) { continue; }

		std::vector<std::vector<unsigned int>> paths;
		
		// Generate the plinko grid for the gate partition
		plinko_grid P = generate_plinko_grid(gate_partition.second, qreg_size);
		std::size_t max_depth = std::max_element(std::begin(P), std::end(P), qrane_utils::queue_size_predicate)->size();

		// Compute domain(s) at each level of the plinko grid
		for (std::size_t i = 0; i < max_depth; ++i) {
			std::vector<unsigned int> level = get_next_grid_row(P, seen, qreg_size);
			stride_graph G = generate_stride_graph(level, qreg_size, args);
			std::vector<unsigned int> ordering = qrane_utils::adj_list_topological_ordering(G);
			std::vector<std::vector<unsigned int>> level_paths = path_search(G, ordering);
			paths.reserve(paths.size() + level_paths.size());
			paths.insert(paths.end(), level_paths.begin(), level_paths.end());
		}

		
		for (auto& path : paths) {
			for (auto val : path) {
				std::cout << val << " ";
			}
			std::cout << std::endl;
		}

		// Now we form the domains
		for (auto& path : paths) {
			qrane_domain dom = qrane_domain(ctx, num_domains, gate_partition.first, args, this->qops_list, path);
			gate_map_store_domain(dom);
			original_domains.push_back(dom);
			auto points = dom.generate_1D_points();
			for (const auto &point : points) { deps.set_membership(point.first, point.second, num_domains); }
			num_domains += 1;
		}
	}
}
*/

/*
Old two-qubit gate reconstruction

	The process for constructing 1D domains for 2-qubit gates
	is similar to that of 1-qubit gates. Instead of using the plinko
	method for finding "rows" of gates to consider, we do the "net-casting"
	n^2 traversal method and build the following map:

	(starting_point, slope) -> [global ids following the starting_point with the same slope (including duplicates)]
	
	Then we use the maximum selection policy to pick which "row" we use to run the 
	path-finding algorithm. 
void qrane_mainprogram::two_qubit_gate_reconstruction() {
	for (auto gate_partition : qops) {

		unsigned int num_args = std::get<ARGS>(gate_partition.second[0]).size();
		if (num_args != 2) { continue; }		

		ray_graph rg = generate_ray_graph(gate_partition.second, qreg_size);
		std::vector<std::vector<unsigned int>> paths;

		while (!rg.empty()) {
			// Find the largest list
			auto max_it = std::max_element(rg.begin(), rg.end(), rg_compare);

			// Pull a level from the max list
			auto level = std::vector<unsigned int>(); level.reserve(max_it->second.size());
			std::copy(max_it->second.begin(), max_it->second.end(), std::back_inserter(level));

			// Generate stride graph from the level
			stride_graph G = generate_stride_graph(level, qreg_size, num_args);

			std::vector<unsigned int> ordering = qrane_utils::adj_list_topological_ordering(G);
			std::vector<std::vector<unsigned int>> level_paths = path_search(G, ordering);

			// Get the largest path
			auto max_path = std::max_element(level_paths.begin(), level_paths.end(), vec_size_compare);
			paths.push_back(*max_path);

			// Now we need to do remove all of max_it's neighbors from the graph
			std::vector<std::pair<unsigned int, float>> to_remove;
			for (auto& pair : rg) {
				
				for (auto& elem : pair.second) {

					if (std::find(max_path->begin(), max_path->end(), elem) != max_path->end()) {
						to_remove.push_back(pair.first);
						break;
					}
				}
			}
			for (auto elem : to_remove) {
				rg.erase(elem);
			}
		}

		for (auto& qop : gate_partition.second) {
			paths.push_back(std::vector<unsigned int>{std::get<QOP_NUM_GLOBAL>(qop)});
		}
		
		for (auto& path : paths) {
			for (auto val : path) {
				std::cout << val << " ";
			}
			std::cout << std::endl;
		}

		// Now we form the domains
		for (auto& path : paths) {
			qrane_domain dom = qrane_domain(ctx, num_domains, gate_partition.first, num_args, this->qops_list, path);
			gate_map_store_domain(dom);
			original_domains.push_back(dom);
			auto points = dom.generate_1D_points();
			for (const auto &point : points) { deps.set_membership(point.first, point.second, num_domains); }
			num_domains += 1;
		}
	}
}
*/

/*
Old Path search variant that finds all longest paths from a level

std::vector<std::vector<unsigned int>> qrane_mainprogram::path_search(stride_graph G, std::vector<unsigned int> ordering) {
	std::vector<std::vector<unsigned int>> paths;

	// While we can still pick a source vertex
	while (!ordering.empty()) {

		// Grab the first zero in-degree vertex in the topological ordering
		unsigned int src = ordering.front();

		// Initialize local stack for perform DFS from src and longest_path variable
		frame_stack stack = frame_stack();
		std::vector<unsigned int> longest_path = std::vector<unsigned int>();
		
		// Generate and push a start frame that only labels the src
		auto start_frame = std::make_tuple(src, 0,
										   std::unordered_map<unsigned int, bool>(), std::vector<unsigned int>());
		stack.push(start_frame);

		// Begin DFS
		while (!stack.empty()) {
			auto curr_frame = stack.top();
			auto curr_id = std::get<ID>(curr_frame);
			stack.pop();

			// Put the current global id into the visited and path vectors
			if (!std::get<VISITED>(curr_frame)[curr_id]) {
				std::get<PATH>(curr_frame).push_back(curr_id);
				std::get<VISITED>(curr_frame)[curr_id] = true;
			}

			// For each neighbor
			bool frame_pushed = false;
			for (auto i = G[curr_id].begin(); i != G[curr_id].end(); ++i) {
				
				// If the vertex is unvisited, we have two possibilities
				if (!std::get<VISITED>(curr_frame)[(*i).first]) {

					// If we are at the first branch from the search, then we have yet to establish a stride
					// Compute the stride and build a frame.
					if (std::get<STRIDE>(curr_frame) == 0) {
						auto new_frame = std::make_tuple((*i).first, (*i).second, 
							                             std::get<VISITED>(curr_frame), std::get<PATH>(curr_frame));
						stack.push(new_frame);
						frame_pushed = true;

					// Otherwise, we only push a new frame when the path stride (weight) equals the established stride
					} else {
						if ((*i).second == std::get<STRIDE>(curr_frame)) {
							auto new_frame = std::make_tuple((*i).first, (*i).second, 
							                                 std::get<VISITED>(curr_frame), std::get<PATH>(curr_frame));
							stack.push(new_frame);
							frame_pushed = true;
						}
					}
				}
			}

			// If we frames were pushed at the current source, then we have completed a path
			if (!frame_pushed) {
				
				// Store it if it the largest path so far.
				if (std::get<PATH>(curr_frame).size() >= longest_path.size()) {
					longest_path = std::get<PATH>(curr_frame);
				}
			} 
		}

		for (auto val : longest_path) {
			qrane_utils::adj_list_remove_vertex(G, val);
			ordering.erase(std::remove(ordering.begin(), ordering.end(), val), ordering.end());
		}
		paths.push_back(longest_path);
	}
	return paths;
};
*/

/*
	This is just for testing purposes
bool qrane_deps::merge_all_paths(std::vector<std::vector<unsigned int>> all_paths, unsigned int num_qops) {
	for (auto& path : all_paths) {
		unsigned int leader = path[0];

		// First, remove any self references
		std::vector<unsigned int> no_self_refs;
		for (auto it = ddg[leader].begin(); it != ddg[leader].end(); ++it) {
			if (std::find(path.begin(), path.end(), *it) == path.end()) {
				no_self_refs.push_back(*it);
			}
		}
		ddg[leader] = no_self_refs;

		// Then, collect the neighbors of all other elements in the path
		for (std::size_t i = 1; i < path.size(); ++i) {
			auto neighbors = ddg[path[i]];

			for (auto n : neighbors) {
				if (std::find(ddg[leader].begin(), ddg[leader].end(), n) == ddg[leader].end()) {
					ddg[leader].push_back(n);
				}
			}
			ddg.erase(path[i]);
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
	}
	
	return detect_time_dependence_cycle(num_qops);
};
*/


/*
	This will not be the main recursive part.
	This function begins the recursive algorithm for each
	gate type. 
void qrane_mainprogram::parse_domains_divide_and_conquer() {

	for (int i = 0; i < ROUNDS; ++i) {
		for (auto& gate_type : gate_domain_map) {
			std::vector<qrane_domain> domains = gate_type.second;
			std::vector<qrane_domain> resultant = std::vector<qrane_domain>();
			attempt_merge(resultant, domains);
			std::sort(resultant.begin(), resultant.end());
			gate_type.second = resultant;
		}
	};
	
	for (auto& gate_type : gate_domain_map) {
		unchanged_domains.insert(unchanged_domains.end(), gate_type.second.begin(), gate_type.second.end() );
	}
};

void qrane_mainprogram::attempt_merge(std::vector<qrane_domain>& resultant, std::vector<qrane_domain> domains) {
	if (domains.size() == 1) {
		resultant.push_back(domains.front());
		return;
	}

	bool success = compute_access_relations(domains);

	if (success) {
		//qrane_domain merger = merge_domains(domains);
		//merger.set_local_domain(build_ND_domain_from_sets(domains));
		resultant.push_back(merger);
		return;
	} else {
		std::vector<qrane_domain> left(domains.begin(), domains.begin() + domains.size() / 2);
    	std::vector<qrane_domain> right(domains.begin() + domains.size() / 2, domains.end());
		attempt_merge(resultant, left);
		attempt_merge(resultant, right);
	}
};
*/

/*
std::vector<unsigned int> qrane_mainprogram::longest_path_search(stride_graph& G, std::vector<unsigned int> ordering) {
	// Grab the first zero in-degree vertex in the topological ordering
	unsigned int src = ordering.front();

	// Initialize local stack for perform DFS from src and longest_path variable
	frame_stack stack = frame_stack();
	std::vector<unsigned int> longest_path = std::vector<unsigned int>();
	longest_path.reserve(qreg_size);
		
	// Generate and push a start frame that only labels the src
	auto start_frame = std::make_tuple(src, 0,
									   std::unordered_map<unsigned int, bool>(), std::vector<unsigned int>());
	stack.push(start_frame);

	// Begin DFS
	while (!stack.empty()) {
		auto curr_frame = stack.top();
		auto curr_id = std::get<ID>(curr_frame);
		stack.pop();

		// Put the current global id into the visited and path vectors
		if (!std::get<VISITED>(curr_frame)[curr_id]) {
			std::get<PATH>(curr_frame).push_back(curr_id);
			std::get<VISITED>(curr_frame)[curr_id] = true;
		}

		// For each neighbor
		bool frame_pushed = false;
		for (auto i = G[curr_id].begin(); i != G[curr_id].end(); ++i) {
				
			// If the vertex is unvisited, we have two possibilities
			if (!std::get<VISITED>(curr_frame)[(*i).first]) {

				// If we are at the first branch from the search, then we have yet to establish a stride
				// Compute the stride and build a frame.
				if (std::get<STRIDE>(curr_frame) == 0) {
					auto new_frame = std::make_tuple((*i).first, (*i).second, 
							                        std::get<VISITED>(curr_frame), std::get<PATH>(curr_frame));
					stack.push(new_frame);
					frame_pushed = true;

				// Otherwise, we only push a new frame when the path stride (weight) equals the established stride
				} else {
					if ((*i).second == std::get<STRIDE>(curr_frame)) {
						auto new_frame = std::make_tuple((*i).first, (*i).second, 
						                                 std::get<VISITED>(curr_frame), std::get<PATH>(curr_frame));
						stack.push(new_frame);
						frame_pushed = true;
					}
				}
			}
		}

		// If no frames were pushed at the current source, then we have completed a path
		if (!frame_pushed) {
				
			// Store it if it the largest path so far.
			if (std::get<PATH>(curr_frame).size() >= longest_path.size()) {
				longest_path = std::get<PATH>(curr_frame);
			}
		} 
	}
	return longest_path;
};
*/


/*
	NOTE: We check for gate_id equivalence BEFORE updating the 
	distane limite count, so the count only applies for domains
	of the same type.

void qrane_mainprogram::parse_ND_domains_cover(unsigned int current_dim) {
	isl_mat* result;
	isl_mat* concat;
	std::vector<qrane_domain> wrk = original_domains;
	
	// For each 1D domain, dom_i
	while (!wrk.empty()) {
		std::cout << "Working on level: " << current_dim << std::endl;
		std::list<qrane_domain> candidates = std::list<qrane_domain>();
		std::vector<qrane_domain> updated_domains = std::vector<qrane_domain>();

		for (std::size_t i = 0; i < wrk.size(); ++i) {
			auto doms_at_i = std::list<qrane_domain>();
			unsigned int count = 0;

			// For each subsequent domain, dom_j
      		//for (std::size_t j = i + 1; j < i + 2 && j < wrk.size() && count < DISTANCE_LIMIT; ++j) {
			for (std::size_t j = i + 1; j < wrk.size() && count < DISTANCE_LIMIT; ++j) {

				if (wrk[i].gate_id != wrk[j].gate_id) { continue; }
				//if (wrk[i].get_time_max() > wrk[j].get_time_min()) { 
					//break; 
				//}
				if (((wrk[j].get_time_min() > wrk[i].get_time_min()) && (wrk[j].get_time_max() < wrk[i].get_time_max()))) {
					continue;
				}

				
				// First check if dom_j is consistent with any of the doms_at_i
				for (auto& cand : doms_at_i) {
					if (((wrk[j].get_time_min() > cand.get_time_min()) && (wrk[j].get_time_max() < cand.get_time_max()))) {
						continue;
					}
					isl_mat* dom_j_appended = append_column_with_val(wrk[j].get_access_mat_copy(), cand.subdomains.size());
					
					concat = isl_mat_concat(dom_j_appended, cand.get_access_mat_copy());
					result = compute_access_relations(isl_mat_copy(concat));
					if (check_consistency(result, current_dim, cand.args)) {
						cand.add_component_qops(wrk[j].component_qops);
						cand.set_access_mat(isl_mat_copy(concat));
						cand.subdomains.push_back(wrk[j].domain_num);
					}
					isl_mat_free(concat);
					isl_mat_free(result);
				}
				
				

				// When that is done, just try to make a domain between i and j
				isl_mat* dom_i_appended = append_column_with_val(wrk[i].get_access_mat_copy(), 0);
				isl_mat* dom_j_appended = append_column_with_val(wrk[j].get_access_mat_copy(), 1);
				concat = isl_mat_concat(dom_j_appended, dom_i_appended);
				result = compute_access_relations(isl_mat_copy(concat));
				if (check_consistency(result, current_dim, wrk[i].args)) {
					qrane_domain new_nd_placeholder = qrane_domain();
					new_nd_placeholder.args = wrk[i].args;
					new_nd_placeholder.add_component_qops(wrk[i].component_qops);
					new_nd_placeholder.add_component_qops(wrk[j].component_qops);
					new_nd_placeholder.subdomains.push_back(wrk[i].domain_num);
					new_nd_placeholder.subdomains.push_back(wrk[j].domain_num);
					new_nd_placeholder.set_access_mat(isl_mat_copy(concat));
					doms_at_i.push_back(new_nd_placeholder);
				}
				isl_mat_free(concat);
				isl_mat_free(result);
				++count;
      		}
			candidates.insert(candidates.end(), doms_at_i.begin(), doms_at_i.end());
    	}

		// Perform domain selection based on the chosen policy
		candidates = greedy_nd_domain_selection(candidates); 

		// Merge the domains together and append to the updated_domains list.
		for (auto& dom : candidates) {
			std::vector<qrane_domain> mergees;

			// Build mergee list out of subdomains
			for (auto& sub_num : dom.subdomains) {
				auto mergee_it = std::find_if(wrk.begin(), wrk.end(), std::bind(domain_match_by_num, std::placeholders::_1, sub_num));
				//mergee_it->is_mergee = true;
				mergees.push_back(*mergee_it);
			}

			// Do the domain merge
			deps.update_membership(mergees);
    		mergees.front().component_qops = dom.component_qops;
			//mergees.front().subdomains = dom.subdomains;
			mergees.front().subdomains.clear();
    		mergees.front().dimensionality = current_dim;
			//mergees.front().is_mergee = false;
        	mergees.front().set_local_domain(build_ND_domain_from_sets(mergees));
			mergees.front().set_access_mat(dom.get_access_mat_copy());

			// Remove all mergees from the domains list
			wrk.erase(std::remove_if(wrk.begin(), wrk.end(), is_mergee), wrk.end());

			// Add the updated domain to the updated_domains list
			updated_domains.push_back(mergees.front());
		}

		// What's left in domains are the 1D domains that weren't a
		// component of any 2D domain in the selection process
		for (auto dom : wrk) {
			unchanged_domains.push_back(dom);
		}

		wrk = updated_domains;
		//sort_lexico_by_time_components(wrk);
		++current_dim;
	}
	std::cout << "Finished at level: " << current_dim-1 << std::endl;
};
*/

/*
void qrane_mainprogram::parse_ND_domains() {
	isl_mat* result;
	isl_mat* concat;
	std::vector<qrane_domain> domains;
  	std::vector<qrane_domain> mergees;
  	std::vector<qrane_domain> updated_domains;
  
	unsigned int update_count = 0;

  	for (auto& gate_type : gate_domain_map) {
    	updated_domains.clear();
    	domains = gate_type.second;

    	for (std::size_t i = 0; i < domains.size();) {
      		mergees.clear();

      		// First we put i in mergees, expecting i to be a mergee
      		mergees.push_back(domains[i]);
			//domains[i].is_mergee = true;
	  		//mergees.front().is_mergee = true;
    
      		// Then we iterate through all remaining domains to see if they can be merged with i.
      		// "Merger" is the last element of mergees, and mergees are all prior elements
			unsigned int count = 0;
      		for (std::size_t j = i + 1; j < domains.size() && count < DISTANCE_LIMIT; ++j) {
				std::vector<qrane_domain> yeet = {mergees.front(), domains[j]};

				if (!((yeet[1].get_time_min() > yeet[0].get_time_min()) && (yeet[1].get_time_max() < yeet[0].get_time_max()))) {
				//if (false) {
					//if (yeet[0].strides[yeet[0].base] == yeet[1].strides[yeet[1].base] || (yeet[0].stmt_count == 1 || yeet[1].stmt_count == 1)) {
					concat = concat_matrices_dimwise(yeet);
					result = compute_access_relations(isl_mat_copy(concat));
					if (check_consistency(result, domains[i].dimensionality+1, domains[i].args)) {
						mergees.front().set_access_mat(concat);
						//mergees.front().consumed += 1;
						//domains[j].is_mergee = true;
						mergees.push_back(domains[j]); 
					}
					++count;
				}
      		}

      		if (mergees.size() > 1) {
    			deps.update_membership(mergees);
    			// For all mergees but the last element (the merger)
    			for (std::size_t i = 1; i < mergees.size(); ++i) {
      				mergees.front().add_component_qops(mergees[i].component_qops);
    			}
				//mergees.front().is_mergee = false;
    			mergees.front().dimensionality += 1; 
        		mergees.front().set_local_domain(build_ND_domain_from_sets(mergees));
        		updated_domains.push_back(mergees.front());
				update_count += 1;
				domains.erase(std::remove_if(domains.begin(), domains.end(), is_mergee), domains.end());
      
        		// Reset i to the beginning of the list
        		i = 0;
      		} else {
				mergees.front().set_access_mat(isl_mat_row_basis(mergees.front().access_mat));
        		unchanged_domains.push_back(mergees.front());
				domains.erase(std::remove_if(domains.begin(), domains.end(), is_mergee), domains.end());
				i = 0;
      		}
    	}
    	gate_type.second = updated_domains;
	}

  	// Remove empty keys
  	for (auto it = gate_domain_map.begin(); it != gate_domain_map.end(); ) {
    	if (it->second.empty()) {
      		it = gate_domain_map.erase(it);
    	} else {
			for (auto &dom : it->second) {
				//dom.consumed = 0;
			}
      		++it;
    	}
  	}

	if (PRINT_MEMBERSHIP) {deps.print_membership();}
	if (update_count > 0) {
		if (OUTPUT_MODE < 3) {std::cout << "Going up one level!" << std::endl;}
    	parse_ND_domains();
	}
};
*/

/*
bool qrane_mainprogram::check_recovered_respects_default_old () {
  bool ret = false;
  if (CHECK_MODE > 0) {
    std::cout << "Verifying recovered schedule respects default schedule..." << std::endl;

    // Create a copy of dependencies, default schedule, and recovered schedule
    isl_union_map* deps = isl_union_map_copy(validity);
    isl_union_map* def = isl_union_map_copy(default_schedule);
    isl_union_map* rec = isl_union_map_copy(recovered_schedule);

    // allgoodcombos := def^-1 . deps . def;
    isl_union_map* def_inv = isl_union_map_reverse(isl_union_map_copy(def));
    isl_union_map* allgoodcombos = isl_union_map_apply_range(def_inv, isl_union_map_copy(deps));
    allgoodcombos = isl_union_map_apply_range(allgoodcombos, isl_union_map_copy(def));
	//std::cout << "allgoodcombos :=  " << isl_union_map_to_str(allgoodcombos) << std::endl;

    // goodlessthan := allgoodcombos << allgoodcombos;
    isl_union_map* goodlessthan = isl_union_map_lex_le_union_map(isl_union_map_copy(allgoodcombos), allgoodcombos);
    //std::cout << "goodlessthan :=  " << isl_union_map_to_str(goodlessthan) << std::endl;

    // allbadcombos := rec^-1 . read . rec;
    isl_union_map* rec_inv = isl_union_map_reverse(isl_union_map_copy(rec));
    isl_union_map* allbadcombos = isl_union_map_apply_range(rec_inv, deps);
    allbadcombos = isl_union_map_apply_range(allbadcombos, isl_union_map_copy(rec));
    //std::cout << "allbadcombos :=  " << isl_union_map_to_str(allbadcombos) << std::endl;

    // badlessthan := allbadcombinations << allbadcombinations
    isl_union_map* badlessthan = isl_union_map_lex_le_union_map(isl_union_map_copy(allbadcombos), allbadcombos);
    //std::cout << "badlessthan :=  " << isl_union_map_to_str(badlessthan) << std::endl;

    // good := def . goodlessthan . def^-1
    def_inv = isl_union_map_reverse(isl_union_map_copy(def));
    isl_union_map* good = isl_union_map_apply_range(def, goodlessthan);
    good = isl_union_map_apply_range(good, def_inv);
    //std::cout << "good :=  " << isl_union_map_to_str(good) << std::endl;

    // bad := recovered . badlessthan . recovered^-1
    rec_inv = isl_union_map_reverse(isl_union_map_copy(rec));
    isl_union_map* bad = isl_union_map_apply_range(rec, badlessthan);
    bad = isl_union_map_apply_range(bad, rec_inv);
    //std::cout << "bad :=  " << isl_union_map_to_str(bad) << std::endl;

    // diff := good - bad;
    isl_union_map* diff = isl_union_map_subtract(good, bad);
    isl_bool res = isl_union_map_is_empty(diff);
	if (!res) {std::cout << "diff :=  " << isl_union_map_to_str(diff) << std::endl;}
	else {std::cout << "diff :=  {}" << std::endl;}
    
    ret = res > 0;
  }
  return ret;
};
*/