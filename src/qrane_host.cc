#include "qrane_host.hh"

// Global domain counting variable from qrane_ctr.hh
unsigned int num_domains = 0;
extern int optind;

unsigned int max_substr_size = std::numeric_limits<unsigned int>::min();
unsigned int avg_substr_size = 0;
unsigned int avg_substr_occ = 0;
unsigned int substr_count = 0;

qrane_host::qrane_host(qrane_options* opt, qrane_timer* timer) {
	this->opt = opt;
	this->timer = timer;
	this->main_processor = new qrane_mainprogram(opt);
};

qrane_host::~qrane_host() {
	delete main_processor;
}

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

	std::vector<qrane_mainprogram> gates_2Q = circuit_decomposition(ag, circ);
	std::vector<qrane_mainprogram> gates_1Q = 
		generate_qrane_mainprogram_list_from_chunked_statements(
		main_processor->get_1Q_gates(), gates_2Q.size());

	gates_2Q.insert(gates_2Q.end(), gates_1Q.begin(), gates_1Q.end());

	parallel_process(gates_2Q);
	timer->reconstruction_complete = std::chrono::high_resolution_clock::now();

	if (opt->schedule_mode != SCHEDULE_IMPLICIT) { main_processor->compute_transformation(); }
	timer->scheduling_complete = std::chrono::high_resolution_clock::now();

	delete(circ);
	delete(parser);
	delete(ag);
	return 0;
}

std::vector<qrane_mainprogram> qrane_host::circuit_decomposition(aquma_graph* ag, aquma_circuit* circ) {
    std::set<int> pending;
	unsigned int subcircuit_count = 0;

	std::vector<qrane_statement*> qrane_stmts = main_processor->get_2Q_gates();
	std::vector<qrane_mainprogram> all;

	// Aquma initialization
	ag->initialize_pending_qubits(pending, circ);

	// Continue until the 2Q gates list is exhausted
	while (!ag->m_qsubstr.empty()) {

	  	std::cout << "Recursing on the longest substr." << std::endl;

		// Perform the recursion and pick a substr
		qrane_substr_info selected = substr_recursion(ag);

		// If the chosen substr is below the bound, all other substrs will be that small.
		// The pool of remaining gates is chunked like normal
		if (selected.first.size() <= DECOMP_SUBSTR_SIZE_BOUND) {
			std::vector<qrane_mainprogram> mps = 
				generate_qrane_mainprogram_list_from_chunked_statements(qrane_stmts, subcircuit_count);
			all.insert(all.end(), mps.begin(), mps.end());
			break;
		}

		// Convert the chosen substr into corresponding qrane_statement* values.
		qrane_mainprogram new_mp = generate_qrane_mainprogram_from_aquma_substr(
			selected, qrane_stmts, subcircuit_count);
		store_substrs_in_qrane_mainprogram(new_mp, selected, qrane_stmts);
		all.push_back(new_mp);

		substr_count += 1;
		avg_substr_size += selected.first.size();
		avg_substr_occ += selected.second.size();
		if (selected.first.size() > max_substr_size) { max_substr_size = selected.first.size(); }

		// Now remove the substrings from the m_qsubstr and qrane_stmts lists
		ag->splice_substr(selected.second, selected.first.size());
		qrane_utils::splice_stmtlist(qrane_stmts, selected.second, selected.first.size());
		subcircuit_count += 1;
	}
	avg_substr_size /= substr_count;
	avg_substr_occ /= substr_count;
	return all;
}

qrane_substr_info qrane_host::substr_recursion(aquma_graph* ag) {
	std::vector<int> prev;
	std::vector<unsigned int> prev_locs;
	std::vector<int> curr;
	std::vector<unsigned int> curr_locs;
	unsigned int depth = 0;

	// Call copy constructor on ag
	aquma_graph ag_prime = *ag;
	ag_prime.m_qsubstr = std::vector<int>(ag->m_qsubstr);

	while (depth <= RECURSION_DEPTH_BOUND) {

		ag_prime.extract_longest_repeated_non_overlapping_substr(curr);

		if (curr.empty()) {
			return qrane_substr_info(ag_prime.m_qsubstr, std::vector<unsigned int>()); 
		}

		ag_prime.count_substr_repetitions(ag_prime.m_qsubstr, curr, curr_locs);

		if (curr_locs.size() < RECURSION_SUBSTR_OCCURRENCE_BOUND) {
			if (!prev.empty()) { return qrane_substr_info(prev, prev_locs); }
			else { return qrane_substr_info(curr, curr_locs);}
		}

		if (curr.size() <= RECURSION_SUBSTR_SIZE_BOUND) {
			if (!prev.empty()) { return qrane_substr_info(prev, prev_locs); }
			else { return qrane_substr_info(curr, curr_locs);}
		}

		prev = curr;
		prev_locs = curr_locs;
		ag_prime.m_qsubstr = curr;
		depth += 1;
	}
	return qrane_substr_info(prev, prev_locs);
};

std::vector<qrane_mainprogram> qrane_host::generate_qrane_mainprogram_list_from_chunked_statements(
	std::vector<qrane_statement*> stmts_to_chunk, unsigned int subcircuit_count) {
	if (stmts_to_chunk.empty()) { return std::vector<qrane_mainprogram>(); }
	std::vector<std::vector<qrane_statement*>> chunked = 
		qrane_utils::split_into_n_components(stmts_to_chunk, opt->chunk);

	std::vector<qrane_mainprogram> mps; mps.reserve(chunked.size());
	for (auto& chunk : chunked) {
		mps.push_back(create_fresh_qrane_mainprogram(chunk, subcircuit_count));
		subcircuit_count += 1;
	}	
	return mps;
}

qrane_mainprogram qrane_host::generate_qrane_mainprogram_from_aquma_substr(
	qrane_substr_info& info, std::vector<qrane_statement*>& stmts_2Q, unsigned int subcircuit_num) {
	std::vector<qrane_statement*>::const_iterator first = stmts_2Q.begin() + info.second[0];
	std::vector<qrane_statement*>::const_iterator last = stmts_2Q.begin() + info.second[0] + info.first.size();
	std::vector<qrane_statement*> stmts(first, last);
	return create_fresh_qrane_mainprogram(stmts, subcircuit_num);
};

qrane_mainprogram qrane_host::create_fresh_qrane_mainprogram(
	std::vector<qrane_statement*> stmts, unsigned int subcircuit_num) {
	qrane_stmtlist* stmtlist = new qrane_stmtlist();
	stmtlist->set_stmts(stmts);
	qrane_mainprogram new_mp = qrane_mainprogram(opt);
	new_mp.set_subcircuit_num(subcircuit_num);
	new_mp.add_stmtlist(stmtlist);
	new_mp.set_num_qops(stmts.size());
	new_mp.qreg_size = main_processor->qreg_size;
	return new_mp;
}

void qrane_host::store_substrs_in_qrane_mainprogram(qrane_mainprogram& mp, 
	qrane_substr_info& info, std::vector<qrane_statement*> stmts_2Q) {
	std::vector<qrane_stmtlist*> substrs; substrs.reserve(info.second.size() - 1);

	for (std::size_t i = 1; i < info.second.size(); ++i) {
		std::vector<qrane_statement*>::const_iterator first = stmts_2Q.begin() + info.second[i];
		std::vector<qrane_statement*>::const_iterator last = stmts_2Q.begin() + info.second[i] + info.first.size();
		std::vector<qrane_statement*> stmts(first, last);
		qrane_stmtlist* stmtlist = new qrane_stmtlist();
		stmtlist->set_stmts(stmts);
		substrs.push_back(stmtlist);
	}
	mp.set_substrs(substrs);
};

std::vector<qrane_mainprogram> qrane_host::generate_qrane_mainprogram_substrs(qrane_mainprogram& mp) {
	std::vector<qrane_mainprogram> new_mps; new_mps.reserve(mp.substrs.size());
	
	// For each substr of the given mainprogram
	for (const auto& stmts : mp.substrs) {

		// 2. map1 = originalDomainNum -> newDomainNum
		// 3. map2 = originalLineNum -> [substr1LineNum, substr2LineNum, ...]
		qrane_mainprogram substr_mp = create_fresh_qrane_mainprogram(stmts->get_2Q_gates(), 9999);
		substr_new_id_map domains = create_old_to_new_domain_map(mp);
		substr_new_id_map qops = create_old_to_new_qop_map(mp, stmts);

		// 4. For each domain in unchanged_domains:
		//		- Update the domain nums
		//		- Replace the id in the local domain
		std::vector<qrane_domain> new_doms = mp.get_scop()->final_domain_list;
		for (auto& dom : new_doms) {
			unsigned int old_id = domains[dom.domain_num];
			dom.domain_num = old_id;
			isl_set* local_domain = dom.get_local_domain_copy();
			std::string new_id = "S" + std::to_string(old_id);
			local_domain = isl_set_set_tuple_name(local_domain, new_id.c_str());
			isl_set_free(dom.local_domain);
			dom.set_local_domain(local_domain);
		}
		substr_mp.set_unchanged_domains(new_doms);

		for (const auto& dom : new_doms) {
			std::cout << dom.domain_num << ": \n";
			isl_set_dump(dom.get_local_domain_copy());
		}

		// 5. For each relation in ddg:
		substr_mp.set_deps(mp.get_deps());
		time_dependence_graph new_ddg;
		for (const auto& relation : substr_mp.get_deps().ddg) {
			for (const auto& n : relation.second) {
					new_ddg[qops[relation.first]].push_back(qops[n]);
			}
		}
		substr_mp.set_ddg(new_ddg);

		// 6. For each relation in membership:
		//		- use map1 and map2 to edit both the lhs and rhs
		membership_map new_membership;
		for (const auto& relation : substr_mp.get_deps().membership) {
			new_membership[qops[relation.first]] = relation.second;
			new_membership[qops[relation.first]].first = domains[relation.second.first];
		}
		substr_mp.set_membership(new_membership);

		substr_mp.build_isl_domain_read_write_schedule();
		std::cout << "-----\n";
		isl_union_set_dump(substr_mp.get_scop()->domain);
		isl_union_map_dump(substr_mp.get_scop()->read);
		new_mps.push_back(substr_mp);
	}
	return new_mps;
};

std::vector<unsigned int> qrane_host::get_new_domain_ids_list(unsigned int cnt) {
	num_domains += 1;
	std::vector<unsigned int> ret; ret.reserve(cnt);
	for (unsigned int i = num_domains; i < num_domains + cnt; ++i) {
		ret.push_back(i);
	}
	num_domains += cnt;
	return ret;
};

substr_new_id_map qrane_host::create_old_to_new_domain_map(qrane_mainprogram& mp) {
	std::vector<unsigned int> new_domain_ids;
	new_domain_ids = get_new_domain_ids_list(mp.get_num_domains());

	std::vector<qrane_domain>& old_domains = mp.get_scop()->final_domain_list;

	substr_new_id_map ret; ret.reserve(new_domain_ids.size());
	for (std::size_t i = 0; i < mp.get_scop()->final_domain_list.size(); ++i) {
		ret[old_domains[i].domain_num] = new_domain_ids[i];
	}
	return ret;
}

substr_new_id_map qrane_host::create_old_to_new_qop_map(qrane_mainprogram& mp, qrane_stmtlist* stmts) {
	std::vector<qrane_statement*> old_qop_ids = mp.get_stmtlist()->get_2Q_gates();
	std::vector<qrane_statement*> new_qop_ids = stmts->get_2Q_gates();
	assert(old_qop_ids.size() == new_qop_ids.size());

	substr_new_id_map ret; ret.reserve(old_qop_ids.size());
	for (std::size_t i = 0; i < old_qop_ids.size(); ++i) {
		ret[((qrane_qop*) old_qop_ids[i])->get_dim1_qop_num()] = ((qrane_qop*) new_qop_ids[i])->get_dim1_qop_num();
	}
	return ret;
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
	if (this->opt->device_file == NULL) {
		std::cout << "You must provide a device_file to utilize Aquma facilities.\n";
		return 1;
	}

	aopt->scop_file = this->opt->qasm_file;
	aopt->device_file = this->opt->device_file;
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
		auto stmts = main_processor->get_stmtlist()->get_qops();
		auto mps = generate_qrane_mainprogram_list_from_chunked_statements(stmts, 0);
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
	main_processor->build_isl_domain_read_write_schedule();
};

bool sort_mps_in_time(const qrane_mainprogram& a, const qrane_mainprogram& b) {
	return a.get_time_max() < b.get_time_min();
};

void codegen_for_all_subcircuits(std::vector<qrane_mainprogram> mps) {
	std::sort(mps.begin(), mps.end(), sort_mps_in_time);

	unsigned int ctr = 0;
	for (auto& mp : mps) {
		std::string codegen_c_str = mp.generate_codegen_c_str();
		std::string codegen_file  = std::string("sabretest/gen_" + std::to_string(ctr) + ".qasm");
		std::string base_name;
		std::string c_name;
		std::string qasm_name;
		std::string executable_name;
		std::string compile;
		std::string execute;
		std::string cleanup;

		base_name = codegen_file.substr(0, codegen_file.find_last_of("."));
		c_name = base_name + ".c";
		qasm_name = base_name + ".qasm";
		executable_name = "temp.exe";

		compile = "gcc -std=c11 " + c_name + " -o " + executable_name;
		execute = "./" + executable_name;
		cleanup = "rm " + c_name + " " + executable_name;

    	int res = qrane_utils::generate_c_test_file(c_name, qasm_name, codegen_c_str, mp.get_registers());
		if (res) {
			std::cout << "Failed to open codegen file ... returning error code 1.\n";
			exit(1);
		}
		// Use std::system to compile the codegen_c_str.c file and execute it
		if (std::system(compile.c_str())) {
			std::cout << "Could not compile codegen file.\n";
			exit(1);
		}
		if (std::system(execute.c_str())) {
			std::cout << "Could not execute check program.\n";
			exit(1);
		}
		if (std::system(cleanup.c_str())) {
			std::cout << "Error doing cleanup.\n";
			exit(1);
		}
		++ctr;
	}
};

void qrane_host::parallel_process(std::vector<qrane_mainprogram> mps) {
	main_processor->build_dependence_graph();
	unsigned int qreg_size = main_processor->qreg_size;
	std::vector<t_qrane_scop*> all_scops = std::vector<t_qrane_scop*>(mps.size());

#pragma omp parallel for schedule(dynamic)
		for (std::size_t i = 0; i < mps.size(); ++i) {
			mps[i].parse_domains();
			mps[i].build_isl_domain_read_write_schedule();
			all_scops[i] = mps[i].get_scop();
		}

		if (opt->substr) {
			for (std::size_t i = 0; i < mps.size(); ++i) {
				if (!mps[i].substrs.empty()) {
					for (auto& mp : generate_qrane_mainprogram_substrs(mps[i])) {
						mps.push_back(mp);
						all_scops.push_back(mp.get_scop());
					}
				}
			}
		}

		codegen_for_all_subcircuits(mps);
		exit(1);

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
		main_processor->set_scop(full_scop);
		if (!opt->quiet) { std::cout << "Done.\n";}
};

void qrane_host::merge_qubit_access_profiles(qubit_profile_map& a, qubit_profile_map& b) {
	for (const auto& qubit : b) {
		//if (a.count(qubit.first) == 0) {
		//	std::cout << "Qubit not registered\n";
		//	a.insert(qubit);
		//	continue;
		//}
		for (const auto& gate : qubit.second) {
			//if (a[qubit.first].count(gate.first) == 0) {
			//	std::cout << "Gate not registered\n";
			//	a[qubit.first].insert(gate);
			//	continue;
			//}

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


	if (!opt->quiet) { std::cout << "Checking that control-read dependences are subset of control-write dependence ... " << std::flush; }
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

	std::string c_name = "check.c";
	std::string qasm_name = "check.qasm";
	std::string exec_name = "check.exe";
	std::string compile = "gcc -std=c11 check.c -o check.exe";
	std::string execute = "./" + exec_name;
	std::string clean = "rm -f " + c_name + " " + qasm_name + " " + exec_name;

    qrane_utils::generate_c_test_file(c_name, qasm_name, codegen_c_str, main_processor->get_registers());

	// Use std::system to compile the codegen_c_str.c file and execute it
	if (std::system(compile.c_str())) {
		std::cout << "Could not compile check file";
		return false;
	}
	if (std::system(execute.c_str())) {
		std::cout << "Could not execute check program\n";
		return false;
	}

	check_processor = new qrane_mainprogram(opt);
	
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

	// We need to do this so that checkpg->get_qubit_profile_map() has something to create
	check_processor->build_dependence_graph();

	std::string mainmap = main_processor->get_qubit_access_profile_str();
	std::string checkmap = check_processor->get_qubit_access_profile_str();

	//if (std::system(clean.c_str())) {
	//	std::cout << "Error during qubit access profile check cleanup.\n";
	//	return false;
	//}

	std::cout << mainmap;
	std::cout << checkmap;

	// Do not delete check_processor here. It is used in isomorphism check
	return mainmap == checkmap; // 0 if they are equal
};

/*
bool qrane_host::check_dependence_subset() {
	if (opt->write_all) {

	} else {
		return true;
	}
}
*/

int qrane_host::check_input_output_isomorphism() {
	this->main_processor = new qrane_mainprogram(opt);
	this->check_processor = new qrane_mainprogram(opt);

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

	this->main_processor->build_dependence_graph();
	this->check_processor->build_dependence_graph();

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

	delete check_processor;

	if (result_str == "true") { return true; } 
	else { return false; }
};

void qrane_host::print_scop() {
	if (!opt->quiet) { main_processor->print_isl_domain_read_write_schedule(); }
	if (!opt->quiet && opt->membership) { main_processor->print_membership_graph(); }
};

void qrane_host::print_stats() {
  	std::cout << "--- Stats ---" << std::endl;
	if (opt->chunk > 1 || opt->substr) { std::cout << "Qops: " << main_processor->get_num_qops() + 1 << std::endl; }
	else { std::cout << "Qops: " << main_processor->get_num_qops() << std::endl; }
	std::cout << "Lookahead Breadth Limit: " << opt->breadth_limit << std::endl;
	std::cout << "Search Limit: " << opt->search_limit << std::endl;
  	std::cout << "Domains: \n";
  	std::cout << main_processor->get_domain_profile_str();
  	std::cout << "Total: " << main_processor->get_num_domains() << " domains, "<< main_processor->get_num_points() << " points." <<  std::endl;
	std::cout << "-------------" << std::endl;

	std::cout << "--- Substr ---" << std::endl;
	std::cout << "Num substr             : " << substr_count << std::endl;
	std::cout << "Max substr size        : " << max_substr_size << std::endl;
	std::cout << "Avg substr size        : " << avg_substr_size << std::endl;
	std::cout << "Avg substr occurrences : " << avg_substr_occ << std::endl;
	std::cout << "--------------" << std::endl;

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
		std::string qasm_name;
		std::string executable_name;
		std::string compile;
		std::string execute;
		std::string cleanup;

		base_name = codegen_file.substr(0, codegen_file.find_last_of("."));
		c_name = base_name + ".c";
		qasm_name = base_name + ".qasm";
		executable_name = "temp.exe";

		compile = "gcc -std=c11 " + c_name + " -o " + executable_name;
		execute = "./" + executable_name;
		cleanup = "rm " + c_name + " " + executable_name;

    	int res = qrane_utils::generate_c_test_file(c_name, qasm_name, codegen_c_str, main_processor->get_registers());
		if (res) {
			std::cout << "Failed to open codegen file ... returning error code 1.\n";
			return 1;
		}
		// Use std::system to compile the codegen_c_str.c file and execute it
		if (std::system(compile.c_str())) {
			std::cout << "Could not compile codegen file.\n";
			return 1;
		}
		if (std::system(execute.c_str())) {
			std::cout << "Could not execute check program.\n";
			return 1;
		}
		if (std::system(cleanup.c_str())) {
			std::cout << "Error doing cleanup.\n";
			return 1;
		}
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
			{"circuit", no_argument, 0, 13},
			{"device_file", required_argument, 0, 14},
			{"substr", no_argument, 0, 15},
			{"help", no_argument, 0, 16},
			{"check_qasm", required_argument, 0, 17},
			{"write_all", no_argument, 0, 18},
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
				opt->device_file = optarg;
			} else {
				std::cout << "Must provide a device file.\n";
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

      	case '?':
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
	strm << "--write_all                     Consider all qubit accesses as write-only." << std::endl;
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
