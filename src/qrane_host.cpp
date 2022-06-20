#include "qrane_host.hpp"
#include "qrane_utils.hpp"

// Global domain counting variable from qrane_ctr.hpp
unsigned int num_domains = 0;
extern int optind;

qrane_host::qrane_host(qrane_options* opt, qrane_timer* timer) {
	this->opt = opt;
	this->timer = timer;
	this->main_processor = std::make_shared<qrane_program>(opt);
	this->circuit_count = 0;
};

int qrane_host::parse_circuit() {
	FILE* qasm = fopen(opt->qasm_file, "r");
	yyin = qasm;
	yy::qrane_parser main_parser(this->main_processor);
	int result = main_parser();
	fclose(yyin);
	return result;
};

	// ----------------------------
	// Aquma + Qrane Reconstruction
	// ----------------------------

int qrane_host::process_circuit_via_substring_decomposition() {

	// Aquma initialization
	aquma_options aopt;
	int res = set_fixed_aquma_options(&aopt);
	aquma_graph* ag = new aquma_graph(&aopt);
	ag->read_graph(aopt.device_file);
	aquma_qparser * parser;
 	parser = new aquma_qparser (aopt.scop_file, ag->get_size());
  	assert (!parser->parse());
  	parser->build_qubit_string(ag->get_substr_ref());
	aquma_circuit* circ = read_aquma_circuit_from_qasm();
	ag->initialize_layout();
	ag->init_qubit_reciprocals();

	// Qrane decomposition
	auto all = std::vector<qrane_program>();
	auto subcircuits = circuit_decomposition(ag, circ);
	auto remaining = 
		generate_qrane_program_list_from_chunked_statements(
		collect_unpartitioned_statements(subcircuits));
	
	all.insert(all.end(), subcircuits.begin(), subcircuits.end());
	all.insert(all.end(), remaining.begin(), remaining.end());

	parallel_process(all);
	timer->reconstruction_complete = std::chrono::high_resolution_clock::now();

	// Qrane scheduling
	if (opt->schedule_mode != SCHEDULE_IMPLICIT) { main_processor->compute_transformation(); }
	timer->scheduling_complete = std::chrono::high_resolution_clock::now();

	delete(circ);
	delete(parser);
	delete(ag);
	return 0;
}

qrane_statementlist qrane_host::collect_unpartitioned_statements(std::vector<qrane_program>& subcircuits) {
	auto all_statements = this->main_processor->get_statementlist();
	auto unpartitioned_statements = qrane_statementlist();

	std::shared_ptr<qrane_qop> qop;
	bool continue_flag;
	for (const auto& statement : all_statements) {
		if (statement->is_qop()) {
			continue_flag = false;
			qop = std::dynamic_pointer_cast<qrane_qop>(statement);

			// Skip any statements already in a subcircuit
			for (auto& circ : subcircuits) {
				bool c0 = qop->get_id() == circ.get_time_min();
				bool c1 = qop->get_id() == circ.get_time_max();
				bool c2 = qop->get_id() > circ.get_time_min() && qop->get_id() < circ.get_time_max();
				if (c0 || c1 || c2) {
					continue_flag = true;
					break;
				}
			}
			if (continue_flag) { continue; }
		
			// Otherwise, add it.
			unpartitioned_statements.append(statement);
		}
	}
	return unpartitioned_statements;
};

std::vector<qrane_program> qrane_host::circuit_decomposition(aquma_graph* ag, aquma_circuit* circ) {
	auto statements_2Q = main_processor->get_2Q_gates();
	auto all = std::vector<qrane_program>();
	this->subcircuit_map = qrane_subcircuit_map();

	// Aquma initialization
	std::set<int> pending;
	ag->initialize_pending_qubits(pending, circ);

	// Continue until the 2Q gates list is exhausted
	while (!ag->m_qsubstr.empty()) {

		// Perform the recursion and pick a substr
		qrane_substr_result result = substr_recursion(ag);

		// Check termination conditions
		bool c0 = result.first.size() <= DECOMP_SUBSTR_SIZE_BOUND;
		bool c1 = result.second.size() < RECURSION_SUBSTR_OCCURRENCE_BOUND;
		bool c2 = result.second.empty();
		if (c0 || c1 || c2) { break; }

		// Generate mainprograms from subcircuit result
		std::vector<qrane_program> subcircuits = 
			qrane_programs_from_substr_result(result, statements_2Q);
		all.insert(all.end(), subcircuits.begin(), subcircuits.end());

		// Now remove the substrings from the m_qsubstr and qrane_stmts lists
		ag->splice_substr(result.second, result.first.size());
		statements_2Q = qrane_utils::splice_stmtlist(
			statements_2Q, result.second, result.first.size());
	}
	return all;
}

qrane_substr_result qrane_host::substr_recursion(aquma_graph* ag) {
	std::vector<int> prev;
	std::vector<unsigned int> prev_locs;
	std::vector<int> curr;
	std::vector<unsigned int> curr_locs;
	unsigned int depth = 0;

	// Call copy constructor on ag
	aquma_graph ag_prime = *ag;
	ag_prime.m_qsubstr = std::vector<int>(ag->m_qsubstr);

	while (depth <= RECURSION_DEPTH_BOUND) {
		curr.clear();
		curr_locs.clear();

		ag_prime.extract_longest_repeated_non_overlapping_substr(curr);

		if (curr.empty()) {
			return qrane_substr_result(ag_prime.m_qsubstr, std::vector<unsigned int>()); 
		}

		ag_prime.count_substr_repetitions(ag_prime.m_qsubstr, curr, curr_locs);

		if (curr_locs.size() < RECURSION_SUBSTR_OCCURRENCE_BOUND) {
			if (!prev.empty()) {
				std::cout << "Met occr bound, returning prev\n"; 
				return qrane_substr_result(prev, prev_locs); 
			} else { 
				std::cout << "Met occr bound, returning curr\n"; 
				return qrane_substr_result(curr, curr_locs);
			}
		}

		if (curr.size() <= RECURSION_SUBSTR_SIZE_BOUND) {
			if (!prev.empty()) { 
				std::cout << "Met size bound, returning prev\n"; 
				return qrane_substr_result(prev, prev_locs); 
			}else { 
				std::cout << "Met size bound, returning curr\n"; 
				return qrane_substr_result(curr, curr_locs);
			}
		}

		prev.clear();
		prev_locs.clear();
		prev = curr;
		prev_locs = curr_locs;
		ag_prime.m_qsubstr = curr;
		depth += 1;
	}
	return qrane_substr_result(prev, prev_locs);
};

std::vector<qrane_program> qrane_host::qrane_programs_from_substr_result(
	qrane_substr_result& result,
	qrane_statementlist& statements_2Q) {
	
	std::vector<qrane_program> ret;
	ret.reserve(result.second.size());
	circuit_id leader;

	// For each index in statements_2Q
	for (std::size_t i = 0; i < result.second.size(); ++i) {
		auto first = statements_2Q.begin() + result.second[i];
		auto last = statements_2Q.begin() + result.second[i] + result.first.size();
		auto first_qop = std::dynamic_pointer_cast<qrane_qop>(*first);
		auto last_qop = std::dynamic_pointer_cast<qrane_qop>(*last);
		auto in_range = qrane_statementlist();
		bool range = false;

		// Collect all qops in the range [first, last]
		std::shared_ptr<qrane_qop> qop;
		for (const auto& statement : this->main_processor->get_qops()) {
			qop = dynamic_pointer_cast<qrane_qop>(statement);

			if (qop->get_id() == first_qop->get_id())
				range = true;
			else if (qop->get_id() == last_qop->get_id())
				range = false;
			
			if (range)
				in_range.append(statement);
		}

		// Generate and store the mainprogram
		qrane_program mp = create_fresh_qrane_program(in_range);
		if (i == 0) { 
			leader = mp.get_id();
			this->subcircuit_map.insert(std::make_pair(leader, std::vector<circuit_id>()));
		} else {
			mp.mark_as_substr_repetition();
			this->subcircuit_map[leader].push_back(mp.get_id()); 
		}
		ret.push_back(mp);
	}
	return ret;
};

std::vector<qrane_program> qrane_host::generate_qrane_program_list_from_chunked_statements(
	qrane_statementlist stmts_to_chunk) {
	if (stmts_to_chunk.empty()) { return std::vector<qrane_program>(); }
	std::vector<qrane_statementlist> chunked = 
		qrane_utils::split_into_n_components(stmts_to_chunk, opt->chunk);

	std::vector<qrane_program> mps; mps.reserve(chunked.size());
	for (auto& chunk : chunked) {
		mps.push_back(create_fresh_qrane_program(chunk));
	}	
	return mps;
}

/*
	NOTE: This function increments this->circuit_count
*/
qrane_program qrane_host::create_fresh_qrane_program(
	qrane_statementlist statements) {
	qrane_program new_mp = qrane_program(opt, this->circuit_count);
	new_mp.initialize(statements, main_processor->qreg_size);
	this->circuit_count += 1;
	return new_mp;
}

aquma_circuit* qrane_host::read_aquma_circuit_from_qasm() {
	int retval;
    char cmdstr[1000];
    const char * rawcirc = "raw-circuit.txt";
    sprintf (cmdstr, "python ${AQUMA_HOME}/extract-circuit-properties.py %s > %s", 
      (char*)opt->qasm_file, (char*)rawcirc); 
    retval = system(cmdstr);
    assert (!retval && "Circuit property extraction failed.");
    int nopts;
    FILE * ff = fopen(rawcirc, "r");
    assert (ff && "Error opening raw-circuit file. Aborting ...\n");
    retval = fscanf(ff, "%d", &nopts);

	aquma_circuit* circ = new aquma_circuit(main_processor->qreg_size, nopts);
    circ->read_qasm (ff);
    circ->compute_qubit_source_incidence();
    circ->show_qubit_histograms();
    if (ff) fclose (ff);
	return circ;
}

int qrane_host::set_fixed_aquma_options(aquma_options* aopt) {
	if (this->opt->calibration_file == NULL) {
		std::cout << "You must provide a device_file to utilize Aquma facilities.\n";
		return 1;
	}
	aopt->scop_file = this->opt->qasm_file;
	aopt->device_file = this->opt->calibration_file;
	aopt->input_format = FORMAT_QASM;
	aopt->slice_mode = SLICE_NORMAL;
	aopt->solver = SOLVER_ISL;
	aopt->algorithm = ALGO_SUBSTR_QD;
	aopt->substrqd = 1;
	aopt->debug = 0;
	return 0;
};


	// ----------------------------
	// Default Qrane Reconstruction
	// ----------------------------

int qrane_host::process_circuit() {
	if (opt->chunk > 1) { 
		auto qops = main_processor->get_statementlist().get_qops();
		auto mps = generate_qrane_program_list_from_chunked_statements(qops);
		parallel_process(mps); 
	} 
	else { sequential_process(); }
	timer->reconstruction_complete = std::chrono::high_resolution_clock::now();

	if (opt->schedule_mode != SCHEDULE_IMPLICIT) { main_processor->compute_transformation(); }
	timer->scheduling_complete = std::chrono::high_resolution_clock::now();

	return 0;
};

void qrane_host::sequential_process() {
	main_processor->parse_domains();
	if (!opt->quiet) { std::cout << "Merging affine abstractions ... " << std::flush;}
	main_processor->build_isl_domain_read_write_schedule();
};

bool comparator_mainprogram(qrane_program& a, qrane_program& b) {
	return a.get_time_max() < b.get_time_min();
};

void qrane_host::sort_mainprograms(std::vector<qrane_program>& mps) {
	std::sort(mps.begin(), mps.end(), comparator_mainprogram);
};

void qrane_host::testing(std::vector<qrane_program> mps) {
	// Sort mainprograms so they are in correct order
	sort_mainprograms(mps);

	// Initialize qrane_routing
	qrane_routing router = qrane_routing(
		mps[0].get_dependence_graph(),
		opt->coupling_file
	);

	// Collect external routing results for each subcircuit
	Py_Initialize();
	std::vector<qrane_routing_result> results;
	for (const auto& mp : mps) {
		std::cout << "Externally routing subcircuit: " << mp.get_id() << " ... ";
		results.push_back(router.export_to_tket(std::make_shared<qrane_program>(mp), opt));
		std::cout << "done." << std::endl;
	}
	Py_Finalize();
	
	auto all = qrane_statementlist();

	if (results.size() == 1) {
		all = results[0].first->get_qops();
	} else {
		for (std::size_t i = 0; i < results.size() - 1; ++i) {
			for (const auto& statement : results[i].first->get_qops()) {
				all.append(statement);
			}

			// Reconcile final mapping of it with initial mapping of it+1
			std::cout << "Reconciling " << i << " and " << i+1 << " ... \n" << std::flush;
			auto swaps = router.reconcile_mappings(results[i].second.second, results[i+1].second.first);
			std::cout << "done\n";

			for (const auto& statement : swaps) {
				all.append(statement);
			}
		}
	}
	

	qrane_program full = qrane_program(opt);
	full.initialize(all, mps[0].qreg_size);

	std::cout << std::boolalpha << router.simulate_circuit_execution(all, results[0].second.first) << std::endl;
};

void qrane_host::modify_subcircuits(std::vector<std::vector<qrane_program>::iterator> its) {
	auto leader = its.begin();

	// For each substr of the given mainprogram
	for (auto i = its.begin() + 1; i < its.end(); ++i) {

		substr_new_id_map old_to_new_domains = (*leader)->create_old_to_new_domain_map();
		substr_new_id_map old_to_new_qops = (*leader)->create_old_to_new_qop_map((*i)->get_qops());


		// 4. For each domain in unchanged_domains:
		//		- Update the domain nums
		//		- Replace the id in the local domain
		std::vector<qrane_domain> new_doms = (*leader)->get_scop()->final_domain_list;
		for (auto& dom : new_doms) {
			unsigned int new_id = old_to_new_domains[dom.domain_num];
			dom.domain_num = new_id;
			std::string new_id_str = "S" + std::to_string(new_id);

			isl_set* local_domain = dom.get_local_domain_copy();
			isl_set_free(dom.local_domain);
			local_domain = isl_set_set_tuple_name(local_domain, new_id_str.c_str());
			dom.set_local_domain(local_domain);
		}
		(*i)->set_unchanged_domains(new_doms);

		// 6. For each relation in membership:
		//		- use map1 and map2 to edit both the lhs and rhs
		membership_map new_membership;
		for (const auto& relation : (*leader)->get_scop()->membership) {
			new_membership[old_to_new_qops[relation.first]] = relation.second;
			new_membership[old_to_new_qops[relation.first]].first = old_to_new_domains[relation.second.first];
		}
		(*i)->set_membership(new_membership);

		(*i)->build_isl_domain_read_write_schedule();
	}
};

void qrane_host::parallel_process(std::vector<qrane_program>& mps) {
	unsigned int qreg_size = main_processor->qreg_size;
	std::vector<t_qrane_scop*> all_scops = std::vector<t_qrane_scop*>(mps.size());

#pragma omp parallel for schedule(dynamic)
		for (int i = 0; i < mps.size(); ++i) {
			if (!mps[i].is_substr_repetition()) {
				mps[i].parse_domains();
				mps[i].build_isl_domain_read_write_schedule();
				all_scops[i] = mps[i].get_scop();
			}
		}

		//testing(mps);
		//exit(1);

		for (const auto& entry : this->subcircuit_map) {
			std::vector<std::vector<qrane_program>::iterator> temp;
			for (auto mp = mps.begin(); mp != mps.end(); ++mp) {
				if (mp->get_id() == entry.first) {
					temp.push_back(mp);
					break;
				}
			}
			for (auto mp = mps.begin(); mp != mps.end(); ++mp) {
				if (std::find(entry.second.begin(), entry.second.end(), mp->get_id()) != entry.second.end()) {
					temp.push_back(mp);
				}
			}
			modify_subcircuits(temp);
		}

		if (!opt->quiet) { std::cout << "Merging subcircuit scops ... " << std::flush;}
		isl_ctx* ctx = isl_ctx_alloc();
        t_qrane_scop* full_scop = new t_qrane_scop();
        full_scop->domain = isl_union_set_empty_ctx(ctx);
        full_scop->read = isl_union_map_empty_ctx(ctx);
        full_scop->write = isl_union_map_empty_ctx(ctx);
        full_scop->call = isl_union_map_empty_ctx(ctx);
        full_scop->schedule = isl_union_map_empty_ctx(ctx);
		full_scop->dependence = isl_union_map_empty_ctx(ctx);
		full_scop->arguments = isl_union_map_empty_ctx(ctx);
        full_scop->membership = membership_map();
		full_scop->qubit_access_profile = qubit_profile_map();
		full_scop->final_domain_list = std::vector<qrane_domain>();
        for (std::size_t i = 0; i < all_scops.size(); ++i) {
            full_scop->domain = isl_union_set_union(full_scop->domain, all_scops[i]->domain);
            full_scop->read = isl_union_map_union(full_scop->read, all_scops[i]->read);
            full_scop->write = isl_union_map_union(full_scop->write, all_scops[i]->write);
            full_scop->call = isl_union_map_union(full_scop->call, all_scops[i]->call);
            full_scop->schedule = isl_union_map_union(full_scop->schedule, all_scops[i]->schedule);
			full_scop->dependence = isl_union_map_union(full_scop->dependence, all_scops[i]->dependence);
			full_scop->arguments = isl_union_map_union(full_scop->arguments, all_scops[i]->arguments);
			full_scop->membership.insert(all_scops[i]->membership.begin(), all_scops[i]->membership.end());
			merge_qubit_access_profiles(full_scop->qubit_access_profile, all_scops[i]->qubit_access_profile);
			std::move(all_scops[i]->final_domain_list.begin(), all_scops[i]->final_domain_list.end(),
				std::back_inserter(full_scop->final_domain_list));
        }
		//full_scop->dependence = main_processor->get_dependences();
		main_processor->set_scop(full_scop);
		if (!opt->quiet) { std::cout << "Done.\n";}
};

void qrane_host::merge_qubit_access_profiles(qubit_profile_map& a, qubit_profile_map& b) {
	for (const auto& qubit : b) {
		for (const auto& gate : qubit.second) {
			a[qubit.first][gate.first] += gate.second;
		}
	}
}

	// -------------------------------
	// Common Administrative Functions
	// -------------------------------

int qrane_host::run_checks() {
	timer->checking_start = std::chrono::high_resolution_clock::now();
	bool check_res;

	if (!opt->quiet) { std::cout << "Checking that all qops have been accounted for ... " << std::flush; }
	check_res = main_processor->check_all_qops_accounted();
	if (check_res == false) {
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return 1;
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	if (!opt->quiet) { std::cout << "Checking that recovered schedule respects dependences ... " << std::flush; }
	check_res = main_processor->check_recovered_respects_dependencies();
	if (check_res == false) {
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return 1;
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	if (!opt->quiet) { std::cout << "Checking that all qubits have the same number of accesses ... " << std::flush; }
	check_res = check_qubit_access_profile_equivalence();
	if (check_res == false) { 
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return 1; 
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	if (!opt->quiet) { std::cout << "Checking for isomorphism between original and recovered dependence graphs ... " << std::flush; }
	check_res = check_isomorphism();
	if (check_res == false) { 
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return 1; 
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	timer->checking_end = std::chrono::high_resolution_clock::now();
	return 0;
}

bool qrane_host::check_qubit_access_profile_equivalence() {

	// Write the mainpg codegen to a C file, compile, and generate check qasm file.
	std::string codegen_c_str = main_processor->generate_codegen_c_str();

	std::string c_name = "check.cc";
	std::string qasm_name = "check.qasm";
	std::string exec_name = "check.exe";
	std::string compile = "g++ -std=c++11 check.c -o check.exe";
	std::string execute = "./" + exec_name;
	std::string clean = "rm -f " + c_name + " " + qasm_name + " " + exec_name;

    qrane_utils::generate_c_test_file(c_name, qasm_name, codegen_c_str, main_processor->get_registers(), main_processor->get_membership_map_reverse_str());

	// Use std::system to compile the codegen_c_str.c file and execute it
	if (std::system(compile.c_str())) {
		std::cout << "Could not compile check file";
		return false;
	}
	if (std::system(execute.c_str())) {
		std::cout << "Could not execute check program\n";
		return false;
	}

	this->check_processor = std::make_shared<qrane_program>(opt);
	
	
	// Read the qasm through the bison parser to get a new stmtlist
	FILE *qasm = nullptr;
	qasm = fopen(qasm_name.c_str(), "r");
	yyin = qasm;
	yy::qrane_parser check_parser(check_processor);
	int result = check_parser();
	fclose(yyin);

	if (result) {
		std::cout << "Check file has invalid grammar structure." << std::endl;
		return false;
  	}

	std::string mainmap = main_processor->get_qubit_access_profile_str();
	std::string checkmap = check_processor->get_qubit_access_profile_str();

	//if (std::system(clean.c_str())) {
	//	std::cout << "Error during qubit access profile check cleanup.\n";
	//	return false;
	//}

	//std::cout << mainmap;
	//std::cout << checkmap;

	return mainmap == checkmap;
};

int qrane_host::check_input_output_isomorphism() {
	this->main_processor = std::make_shared<qrane_program>(opt);
	this->check_processor = std::make_shared<qrane_program>(opt);

	FILE* qasm = fopen(opt->qasm_file, "r");
	yyin = qasm;
	yy::qrane_parser main_parser(this->main_processor);
	int result = main_parser();
	fclose(yyin);

	FILE* check = fopen(opt->check_qasm, "r");
	yyin = check;
	yy::qrane_parser check_parser(this->check_processor);
	result = check_parser();
	fclose(yyin);

	bool res = check_isomorphism();
	return res;
}

bool qrane_host::check_isomorphism() {
	std::string maingraph_str = main_processor->get_networkx_edge_list_str();
	std::string checkgraph_str = check_processor->get_networkx_edge_list_str();
	std::ofstream graph_out;
	std::ifstream result_in;
	std::string result_str;
	std::string main_graph_path("maingraph.txt");
	std::string check_graph_path("checkgraph.txt");
	std::string result_path("result.txt");
	std::string clean = "rm -f " + main_graph_path + " " + check_graph_path + " " + result_path;

	// Write the main circuit dependence graph to a file
  	graph_out.open(main_graph_path);
	if (graph_out.is_open()) {
		graph_out << maingraph_str;
  		graph_out.close();
	} else {
		std::cout << "Failed to open main circuit NetworkX input file." << std::endl;
		return false;
	}
	
	// Write the check circuit dependence graph to a file
	graph_out.open(check_graph_path);
	if (graph_out.is_open()) {
		graph_out << checkgraph_str;
  		graph_out.close();
	} else {
		std::cout << "Failed to open check circuit NetworkX input file." << std::endl;
		return false;
	}
	
	// Check for isomorphism with NetworkX is_isomorphic()
	std::ostringstream command;
	command << "from networkx import DiGraph, read_edgelist, is_isomorphic"                     << std::endl;
	command << "def node_match(n1, n2):"                                                        << std::endl;
	command << "\t return n1 == n2"                                                                    << std::endl;
	command << "G1 = read_edgelist(\'" << main_graph_path << "\', create_using=DiGraph())"      << std::endl;
	command << "G2 = read_edgelist(\'" << check_graph_path << "\', create_using=DiGraph())"     << std::endl;
	command << "res = is_isomorphic(G1, G2, node_match=node_match)"                             << std::endl;
	command << "with open(\"" << result_path << "\", \"w\") as fh:"                             << std::endl;
	command << "\tfh.write((str(res)).lower())";

	Py_Initialize();
	PyRun_SimpleString(command.str().c_str());
	Py_Finalize();

	result_in.open(result_path);
	if (result_in.is_open()) {
		result_in >> result_str;
  		result_in.close();
	} else {
		std::cout << "Failed to read NetworkX output to result file." << std::endl;
		return false;
	}

	//if (std::system(clean.c_str())) {
	//	std::cout << "Error during isomorphism check cleanup.\n";
	//	return false;
	//}

	if (result_str == "true") { return true; } 
	else { return false; }
};

void qrane_host::print_scop() {
	if (!opt->quiet) { main_processor->print_isl_domain_read_write_schedule(); }
	if (!opt->quiet && opt->membership) { main_processor->print_membership_graph(); }
};

void qrane_host::print_stats() {
  	std::cout << "--- Stats ---" << std::endl;
	std::cout << "Qops: " << main_processor->get_num_qops() << std::endl;
	std::cout << "Lookahead Breadth Limit: " << opt->breadth_limit << std::endl;
	std::cout << "Search Limit: " << opt->search_limit << std::endl;
  	std::cout << "Domains: \n";
  	std::cout << main_processor->get_domain_profile_str();
  	std::cout << "Total: " << main_processor->get_num_domains() << " domains, "<< main_processor->get_num_points() << " points." <<  std::endl;
	std::cout << "-------------" << std::endl;

	std::cout << main_processor->get_domain_size_histogram_str();
	std::cout << main_processor->get_reconstruction_histogram_str();

	std::cout << "--- Timing ---" << std::endl;
  	std::cout << "Reconstruction: " << std::chrono::duration_cast<std::chrono::milliseconds>(timer->reconstruction_complete - timer->global_start).count() << "ms" << std::endl;
  	std::cout << "Scheduling: " << std::chrono::duration_cast<std::chrono::milliseconds>(timer->scheduling_complete - timer->reconstruction_complete).count() << "ms" << std::endl;
  	if (opt->check) {std::cout << "Verification: " << std::chrono::duration_cast<std::chrono::milliseconds>(timer->checking_end - timer->checking_start).count() << "ms" << std::endl;}
  	std::cout << "Total execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(timer->global_end - timer->global_start).count() << "ms" << std::endl;
  	std::cout << "-------------" << std::endl;
}

qrane_output_scop* qrane_host::get_scop() {
	return main_processor->get_output_scop();
};

int qrane_host::output_to_files() {
	if (opt->aquma_file) {
		std::string str = main_processor->get_aquma_scop_str();
		std::ofstream aquma_out;
		aquma_out.open(opt->aquma_file);
		if (aquma_out.is_open()) {
			aquma_out << str;
			aquma_out.close();
		} else {
			std::cout << "Failed to open aquma_file." << std::endl;
			return 1;
		}
	}

	if (opt->codegen_file) {
		std::string codegen_c_str = main_processor->generate_codegen_c_str();
		std::string codegen_file  = std::string(opt->codegen_file);
		std::string base_name;
		std::string c_name;
		std::string qops_name;
		std::string qasm_name;
		std::string executable_name;
		std::string compile;
		std::string execute;
		std::string cleanup;

		base_name = codegen_file.substr(0, codegen_file.find_last_of("."));
		c_name = base_name + ".cc";
		qops_name = base_name + ".qops";
		qasm_name = base_name + ".qasm";
		executable_name = "temp.exe";

		compile = "g++ -std=c++11 " + c_name + " -o " + executable_name;
		execute = "./" + executable_name;
		cleanup = "rm " + c_name + " " + executable_name;

    	int res = qrane_utils::generate_c_test_file(c_name, qops_name, codegen_c_str, main_processor->get_registers(), main_processor->get_membership_map_reverse_str());
		if (res) {
			std::cout << "Failed to open codegen file ... returning error code 1.\n";
			return 1;
		}
		if (std::system(compile.c_str())) {
			std::cout << "Could not compile codegen file.\n";
			return 1;
		}
		if (std::system(execute.c_str())) {
			std::cout << "Could not execute check program.\n";
			return 1;
		}

		std::vector<qop_id> ordering = qrane_utils::read_qop_id_sequence(qops_name);
		std::string reordered_qasm_str = main_processor->get_qasm_string(ordering);

		std::ofstream qasm_out;
		qasm_out.open(qasm_name);
		if (qasm_out.is_open()) {
			qasm_out << reordered_qasm_str;
			qasm_out.close();
		} else {
			std::cout << "Failed to open qasm file." << std::endl;
			return 1;
		}
		//if (std::system(cleanup.c_str())) {
		//	std::cout << "Error doing cleanup.\n";
		//	return 1;
		//}
	}
	return 0;
}

int qrane_host::parse_options(int argc, char* argv[]) {
	int gopt;

	char name[] = "./name";
	int new_argc = argc + 1;
	char* new_argv_temp[new_argc];
	char** new_argv = (char**) malloc(sizeof(char*) * new_argc);
	new_argv_temp[0] = name;

	int i;
	for (i = 0; i < argc; i++) {
		new_argv_temp[i+1] = argv[i];
	}
	for (i = 0; i < new_argc; i++) {
		new_argv[i] = strdup(new_argv_temp[i]);
	}

	while (1) {
		static struct option long_options[] = {
			{"qasm", required_argument, 0, 0},
			{"chunk", required_argument, 0, 1},
			{"check", no_argument, 0, 2},
			{"depth", required_argument, 0, 3},
			{"search", required_argument, 0, 4},
			{"quiet", no_argument, 0, 5},
			{"member", no_argument, 0, 6},
	  		{"isl", no_argument, 0, 7},
	  		{"minfuse", no_argument, 0, 8},
	  		{"maxfuse", no_argument, 0, 9},
			{"feautrier", no_argument, 0, 10},
			{"aquma", optional_argument, 0, 11},
      		{"codegen", optional_argument, 0, 12},
			{"grid", no_argument, 0, 13},
			{"calibration", required_argument, 0, 14},
			{"substr", no_argument, 0, 15},
			{"help", no_argument, 0, 16},
			{"check_qasm", required_argument, 0, 17},
			{"write_all", no_argument, 0, 18},
			{"coupling", required_argument, 0, 19},
     		{0, 0, 0, 0}
    };

    int option_index;
    gopt = getopt_long(new_argc, new_argv, "", long_options, &option_index);

    if (gopt == -1) {
		return 0;
	}

    switch (gopt) {
	
		// Qasm
		case 0:
			if (optarg) { 
				opt->qasm_file = optarg;
			} else {
				std::cout << "Please provide input qasm file.\n";
				return 1;
			} 
			break;

		// Chunk
		case 1:
			try {
				opt->chunk = std::stoul(std::string(optarg));
			} catch (const std::invalid_argument& e) {
				std::cout << "Invalid argument for --chunk=" << std::endl;
				return 1;
			}

			break;

		// Check
      	case 2:
		  	opt->check = true;
        	break;

        // Lookahead depth
        case 3:
			try {
				opt->breadth_limit = std::stoul(std::string(optarg));
			} catch (const std::invalid_argument& e) {
				std::cout << "Invalid argument for --breadth_limit=" << std::endl;
				return 1;
			}
        	break;

		// Search limit
        case 4:
			try {
				opt->search_limit = std::stoul(std::string(optarg));
			} catch (const std::invalid_argument& e) {
				std::cout << "Invalid argument for --search_limit=" << std::endl;
				return 1;
			}
        	break;

		// Quiet mode
      	case 5:
		  	opt->quiet = true;
			break;

		// Membership print
		case 6:
			opt->membership = true;
			break;

		// isl schedule mode
		case 7:
			opt->schedule_mode = SCHEDULE_ISL;
			break;

		// minfuse schedule mode
		case 8:
			opt->schedule_mode = SCHEDULE_MINFUSE;
			break;

		// maxfuse schedule mode
		case 9:
			opt->schedule_mode = SCHEDULE_MAXFUSE;
			break;

		// feautrier schedule mode
		case 10:
			opt->schedule_mode = SCHEDULE_FEAUTRIER;
			break;

		// to aquma
		case 11:
			if (optarg) { opt->aquma_file = optarg; }
			else { assert(false); }
			break;
		
		// to C
		case 12:
        	if (optarg) { opt->codegen_file = optarg; } 
			else { assert(false); }
        	break;

		// grid mode
		case 13:
			opt->process_mode = PROCESS_GRID;
			break;

		case 14:
			if (optarg) { 
				opt->calibration_file = optarg;
			} else {
				std::cout << "Please provide a .csv calibration file.\n";
				return 1;
			} 
			break;

		case 15:
			opt->substr = true;
			break;

		// help
		case 16:
			std::cout << help_message();
			break;

		// Check qasm file
		case 17:
			if (optarg) { 
				opt->check_qasm = optarg;
			} else {
				std::cout << "Please provide check qasm file.\n";
				return 1;
			} 
			break;

		case 18:
			opt->write_all = true;
			break;

		case 19:
			if (optarg) { 
				opt->coupling_file = optarg;
			} else {
				std::cout << "Must provide an edge-list formatted coupling graph .txt file.\n";
				return 1;
			} 
			break;

      	case '?':
		  	return 1;
        	break;
		
      	default:
		  	std::cout << help_message();
        	return 1;
			break;
    }
  }
	
  	for (i = 0; i < new_argc; i++) {
    	free (new_argv[i]);
  	}
  	free(new_argv);
	
  return 0;
};

std::string qrane_host::help_message() {
	std::ostringstream strm;
	strm << "----------- Options -----------" << std::endl;
	strm << "--qasm=<path/to/*.qasm>          REQUIRED: Path to qasm input file." << std::endl;
	strm << "--chunk=<ui>                     Set the size of each subcircuit to process." << std::endl;
	strm << "--check                          Check mode. Run all three verification checks." << std::endl;
    strm << "--depth=<ui>                     Look-ahead depth for the look-ahead policy." << std::endl;
	strm << "--search=<ui>                    Search limit in nD phase." << std::endl;
	strm << "--quiet                          Quiet mode. Only send domain size histogram, checks, and stats to stdout." << std::endl;
	strm << "--member                         Print the time space -> domain space map." << std::endl;
	strm << "--substr                         Use aquma-substring based circuit decomposition tactic." << std::endl;
	strm << "--write_all                      Consider all qubit accesses as write-only." << std::endl;
	strm << "--isl                            Use isl's default scheduling algorithm." << std::endl;
	strm << "--minfuse                        Use Pluto minfuse scheduling algorithm." << std::endl;
	strm << "--maxfuse                        Use Pluto maxfuse scheduling algorithm." << std::endl;
	strm << "--feautrier                      Use Feautrier's scheduling algorithm." << std::endl;
	strm << "--aquma=<path/to/output/file>    Generate .aquma file with iteration domain and access relations." << std::endl;
	strm << "--codegen=<path/to/output/file>  Generate compilable C file containing isl codegen output at filepath." << std::endl;
	strm << "--circuit                        Process the plinko grid instead of dependence graph." << std::endl;
	strm << "--help                           Print this help message." << std::endl;
	strm << "-------------------------------" << std::endl;
	return strm.str();
}
