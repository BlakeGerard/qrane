#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <chrono>
#include <regex>
#include <limits>
#include <time.h>
#include <Python.h>
#include "unistd.h"
#include "getopt.h"
#include "qrane_utils.hh"
#include "qrane_mainprogram.hh"
#include "include/qrane_flags.hh"
#include "qrane-parser.h"
#include "omp.h"
#include "qrane_options.hh"
#include "qrane_timer.hh"

/*
PROCESS_MODE ONED_MODE = DDG; 
unsigned int DIVIDE = 1;
bool CHECK_MODE = false;     
bool MEMBERSHIP_MODE = false;
bool QUIET_MODE = false;
int LOOKAHEAD_DEPTH = 2;
unsigned int SEARCH_LIMIT = 0;
bool OUTPUT_AQUMA = false;
bool OUTPUT_CODEGEN = false;
unsigned int num_domains = 0;
//unsigned int num_domains = 0;
std::string PROCESS_NUM = "-1";
SCHEDULE_ALGORITHM SCHEDULE_MODE = DEFAULT;

char codegen_file[1024];
char aquma_file[1024];
*/
std::string qasm_file_name;
qrane_mainprogram* checkpg;

void parse_command_line(int argc, char **argv);
bool run_checks(qrane_mainprogram* mainpg);
bool check_isomorphism(qrane_mainprogram* mainpg);
bool check_qubit_profile_equivalence(qrane_mainprogram* mainpg);
std::string get_qasm_file_name(char* filename);
std::string help_message();

extern yy::qrane_parser::symbol_type yylex();
extern FILE *yyin;
isl_stat isl_res;

void qrane_options_init(qrane_options* opt) {
	opt->qrane_home = std::getenv("QRANE_HOME");
	opt->qasm_file = NULL;
	opt->codegen_file = NULL;
	opt->aquma_file = NULL;
	opt->check = true;
	opt->quiet = false;
	opt->membership = false;
	opt->chunk = 1; 			// Treat the file as one circuit
	opt->breadth_limit = 2;		// Impose no limit
	opt->search_limit = 0;		// Impose no limit
	opt->process_mode = PROCESS_DDG;
	opt->schedule_mode = SCHEDULE_IMPLICIT;
}

int qrane_options_check(qrane_options* opt) {
	if (!opt->qrane_home) { return 0; }
	if (!opt->qasm_file) { return 0; }

	FILE* check;

	// Verify the qasm file if supplied
	if (opt->qasm_file) {
		if ((check = fopen(opt->qasm_file, "r"))) {
			fclose(check);
		} else {
			printf("OpenQASM file %s not found ... Aborting.", opt->qasm_file);
			return 0;
		}
	}

	// Verify the codegen file if supplied
	if (opt->codegen_file) {
		if ((check = fopen(opt->codegen_file, "w"))) {
			fclose(check);
		} else {
			printf("Failed to create or open codegen file %s ... Aborting.", opt->codegen_file);
			return 0;
		}
	}

	// Verify the aquma output file if supplied
	if (opt->aquma_file) {
		if ((check = fopen(opt->codegen_file, "w"))) {
			fclose(check);
		} else {
			printf("Failed to create or open aquma output file %s ... Aborting.", opt->aquma_file);
			return 0;
		}
	}

	// Everything checks out
	return 1;
}

int main (int argc, char **argv)
{
	qrane_options opt = qrane_options();
	qrane_timer timer = qrane_timer();
	qrane_options_init(&opt);
	qrane_options_check(&opt);

  	FILE *qasm = nullptr;
  	parse_command_line(argc, argv);

  	if (optind < argc && std::strcmp(argv[optind], "help") != 0) {
    	qasm = fopen(argv[optind], "r");
  	} else {
	  	std::cout << help_message() << std::endl;
	  	exit(1);
  	}
  
  	if (!qasm) { std::cout << "Failed to open openQASM file." << std::endl; exit(1);}

	qasm_file_name = get_qasm_file_name(argv[optind]);
  	yyin = qasm;
  	qrane_mainprogram* mainpg = new qrane_mainprogram();  
	yy::qrane_parser main_parser(mainpg);
	int result = main_parser();
	fclose(yyin);

  	if (result) {
		std::cout << "Failed the grammar check." << std::endl;
		exit(1);
  	}


	std::chrono::high_resolution_clock::time_point global_start;
	std::chrono::high_resolution_clock::time_point done_parsing;
	std::chrono::high_resolution_clock::time_point done_building;
	std::chrono::high_resolution_clock::time_point checking_start;
	std::chrono::high_resolution_clock::time_point checking_end;
	std::chrono::high_resolution_clock::time_point global_end;

  	global_start = std::chrono::high_resolution_clock::now();

	// If we are doing subcircuits
	if (opt.chunk > 1) {
		mainpg->build_dependence_graph();
		std::vector<qrane_statement*> stmts = mainpg->get_stmtlist()->get_qops();

		std::vector<std::vector<qrane_statement*>> divided = qrane_utils::split_into_n_components(stmts, opt.chunk);
		unsigned int qreg_size = mainpg->qreg_size;

		// Parallel circuit reconstruction
		std::vector<t_qrane_scop*> all_scops = std::vector<t_qrane_scop*>(divided.size());
#pragma omp parallel for
		for (std::size_t i = 0; i < divided.size(); ++i) {
			qrane_stmtlist* new_stmts = new qrane_stmtlist();
			new_stmts->set_stmts(divided[i]);
			qrane_mainprogram new_mp = qrane_mainprogram(); 
			new_mp.set_subcircuit_num(i);
			new_mp.add_stmtlist(new_stmts);
			new_mp.set_num_qops(divided[i].size());
			new_mp.qreg_size = qreg_size;
			new_mp.parse_domains();
			new_mp.build_isl_domain_read_write_schedule();
			all_scops[i] = new_mp.get_scop();
		}
  		done_parsing = std::chrono::high_resolution_clock::now();

		isl_ctx* ctx = isl_ctx_alloc();
        t_qrane_scop* full_scop = new t_qrane_scop();
        full_scop->domain = isl_union_set_empty_ctx(ctx);
        full_scop->read = isl_union_map_empty_ctx(ctx);
        full_scop->write = isl_union_map_empty_ctx(ctx);
        full_scop->call = isl_union_map_empty_ctx(ctx);
        full_scop->schedule = isl_union_map_empty_ctx(ctx);
		full_scop->dependence = isl_union_map_empty_ctx(ctx);
        full_scop->membership = membership_map();
		full_scop->final_domain_list = std::vector<qrane_domain>();
        for (std::size_t i = 0; i < all_scops.size(); ++i) {
            full_scop->domain = isl_union_set_union(full_scop->domain, all_scops[i]->domain);
            full_scop->read = isl_union_map_union(full_scop->read, all_scops[i]->read);
            full_scop->write = isl_union_map_union(full_scop->write, all_scops[i]->write);
            full_scop->call = isl_union_map_union(full_scop->call, all_scops[i]->call);
            full_scop->schedule = isl_union_map_union(full_scop->schedule, all_scops[i]->schedule);
			full_scop->dependence = isl_union_map_union(full_scop->dependence, all_scops[i]->dependence);
			full_scop->membership.insert(all_scops[i]->membership.begin(), all_scops[i]->membership.end());
			std::move(all_scops[i]->final_domain_list.begin(), all_scops[i]->final_domain_list.end(),
				std::back_inserter(full_scop->final_domain_list));
        }

		mainpg->set_scop(full_scop);
		if (opt.schedule_mode != SCHEDULE_IMPLICIT) { mainpg->compute_transformation(); }
  		done_building = std::chrono::high_resolution_clock::now();
	} else {
		mainpg->parse_domains();
  		done_parsing = std::chrono::high_resolution_clock::now();
		mainpg->build_isl_domain_read_write_schedule();
		if (opt.schedule_mode != SCHEDULE_IMPLICIT) { mainpg->compute_transformation(); }
  		done_building = std::chrono::high_resolution_clock::now();
	}

	if (!opt.quiet) { mainpg->print_isl_domain_read_write_schedule(); }
	if (!opt.quiet && opt.membership) { mainpg->print_membership_graph(); }

	if (opt.aquma_file) {
		std::string str = mainpg->get_aquma_scop_str();
		std::ofstream aquma_out;
		aquma_out.open(opt.aquma_file);
		aquma_out << str;
		aquma_out.close();
	}

	if (opt.codegen_file) {
		std::string codegen_c_str = mainpg->generate_codegen_c_str();
		std::string cg = std::string(opt.codegen_file);
		std::string c_name;
		std::string qasm_name;
		std::string compile;
		std::string execute;
		c_name = cg + ".c";
		qasm_name = cg + ".qasm";
		compile = "gcc -std=c11 " + c_name + " -o " + cg;
		execute = cg;

    		qrane_utils::generate_c_test_file(c_name, qasm_name, codegen_c_str, mainpg->get_registers());

		// Use std::system to compile the codegen_c_str.c file and execute it
		if (std::system(compile.c_str())) {
			std::cout << "Could not compile check file";
			exit(1);
		}
		if (std::system(execute.c_str())) {
			std::cout << "Could not execute check program\n";
			exit(2);
		}
		std::string cleanup = "rm " + c_name + " " + execute;
		std::system(cleanup.c_str());
	}

	if (opt.check) {
		checking_start = std::chrono::high_resolution_clock::now();
		run_checks(mainpg, &opt);
		checking_end = std::chrono::high_resolution_clock::now();
	}

  	global_end = std::chrono::high_resolution_clock::now();

  	// Print execution statistics
  	std::cout << "--- Stats ---" << std::endl;
  	std::cout << "Qops: " << mainpg->get_num_qops() << std::endl;
	std::cout << "Look-ahead Depth: " << opt.breadth_limit << std::endl;
	std::cout << "Search Limit: " << opt.search_limit << std::endl;
  	std::cout << "Domains: \n";
  	std::cout << mainpg->get_domain_profile_str();
  	std::cout << "Total: " << mainpg->get_num_domains() << " domains, "<< mainpg->get_num_points() << " points." <<  std::endl;
	std::cout << "-------------" << std::endl;

	std::cout << mainpg->get_domain_size_histogram_str();
	std::cout << mainpg->get_reconstruction_histogram_str();

	std::cout << "--- Timing ---" << std::endl;
  	std::cout << "Time reconstructing domains: " << std::chrono::duration_cast<std::chrono::milliseconds>(done_parsing-global_start).count() << "ms" << std::endl;
  	std::cout << "Time scheduling: " << std::chrono::duration_cast<std::chrono::milliseconds>(done_building-done_parsing).count() << "ms" << std::endl;
  	if (opt.check) {std::cout << "Time checking correctness: " << std::chrono::duration_cast<std::chrono::milliseconds>(checking_end-checking_start).count() << "ms" << std::endl;}
  	std::cout << "Total execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(global_end-global_start).count() << "ms" << std::endl;
  	std::cout << "-------------" << std::endl;
  	return 0;
}

bool run_checks(qrane_mainprogram* mainpg, qrane_options* opt) {
	bool check;

	if (!opt->quiet) { std::cout << "Checking that all qops have been accounted for ... " << std::flush; }
	check = mainpg->check_all_qops_accounted();
	if (!check) { 
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return false; 
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	if (!opt->quiet) { std::cout << "Checking that recovered schedule respects dependences ... " << std::flush; }
	check = mainpg->check_recovered_respects_dependencies();
	if (!check) { 
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return false; 
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	if (!opt->quiet) { std::cout << "Checking that all qubits have the same number of accesses ... " << std::flush; }
	check = check_qubit_profile_equivalence(mainpg);
	if (!check) { 
		if (!opt->quiet) { std::cout << "False\n" << std::flush; }
		return false; 
	}
	if (!opt->quiet) { std::cout << "True\n" << std::flush; }

	if (!opt->quiet) { std::cout << "Checking for isomorphism between original and recovered dependence graphs ... " << std::flush; }
	check_isomorphism(mainpg);

	return true;
}

bool check_isomorphism(qrane_mainprogram* mainpg) {
	std::string maingraph_str = mainpg->get_networkx_edge_list_str();
	std::string checkgraph_str = checkpg->get_networkx_edge_list_str();

	std::string graph_path("maingraph.txt");
	std::ofstream graph_out;
  	graph_out.open(graph_path);
	graph_out << maingraph_str;
  	graph_out.close();

	graph_path = "checkgraph.txt";
	graph_out.open(graph_path);
	graph_out << checkgraph_str;
  	graph_out.close();

	std::ostringstream strm;
	strm << "from networkx import DiGraph, read_edgelist, is_isomorphic\n";
	strm << "G1 = read_edgelist('maingraph.txt', create_using=DiGraph())\n";
	strm << "G2 = read_edgelist(\'" << graph_path << "\', create_using=DiGraph())\n";
	strm << "res = is_isomorphic(G1, G2)\n";
	strm << "print(res)";

	Py_Initialize();
	PyRun_SimpleString(strm.str().c_str());
	Py_Finalize();

    std::string clean;
	clean = "rm -f check.c check.exe check.qasm checkgraph.txt maingraph.txt";

	std::system(clean.c_str());
	return true;
};

bool check_qubit_profile_equivalence(qrane_mainprogram* mainpg) {

	// Write the mainpg codegen to a C file, compile, and generate check qasm file.
	std::string codegen_c_str = mainpg->generate_codegen_c_str();

	std::string c_name;
	std::string qasm_name;
	std::string exec_name;
	std::string compile;
	std::string execute;
	c_name = "check.c";
	qasm_name = "check.qasm";
	exec_name = "check.exe";
	compile = "gcc -std=c11 check.c -o check.exe";
	execute = "./" + exec_name;

    qrane_utils::generate_c_test_file(c_name, qasm_name, codegen_c_str, mainpg->get_registers());

	// Use std::system to compile the codegen_c_str.c file and execute it
	if (std::system(compile.c_str())) {
		std::cout << "Could not compile check file";
		exit(1);
	}
	if (std::system(execute.c_str())) {
		std::cout << "Could not execute check program\n";
		exit(2);
	}

	checkpg = new qrane_mainprogram();
	
	// Read the qasm through the bison parser to get a new stmtlist
	FILE *qasm = nullptr;
	qasm = fopen(qasm_name.c_str(), "r");
	yyin = qasm;
	yy::qrane_parser check_parser(checkpg);
	int result = check_parser();
	fclose(yyin);

	if (result) {
		std::cout << "Check file has invalid grammar structure." << std::endl;
		exit(3);
  	}
	checkpg->build_dependence_graph();

	std::string mainmap = mainpg->get_qubit_access_profile_str();
	std::string checkmap = checkpg->get_qubit_access_profile_str();

	//std::cout << "Original qubit profile map := {" << std::endl << std::flush;
	//std::cout << mainpg->get_qubit_profile_str();
	//std::cout << "}" << std::endl << std::flush;
	//std::cout << "Checkfile qubit profile map := {" << std::endl << std::flush;
	//std::cout << checkpg->get_qubit_profile_str();
	//std::cout << "}" << std::endl << std::flush;

	return mainmap == checkmap;
};


std::string help_message() {
	std::ostringstream strm;
	strm << "--- Options ---" << std::endl;
	strm << "-c \t Check mode. Run all three verification checks." << std::endl;
    strm << "-d \t Look-ahead depth for the look-ahead policy." << std::endl;
	strm << "-s \t Search limit in nD phase." << std::endl;
	strm << "-q \t Quiet mode. Only send domain size histogram, checks, and stats to stdout." << std::endl;
	strm << "-m \t Print the time space -> domain space map." << std::endl;
	strm << "--isl \t Use isl's default scheduling algorithm." << std::endl;
	strm << "--minfuse \t Use Pluto minfuse scheduling algorithm." << std::endl;
	strm << "--maxfuse \t Use Pluto maxfuse scheduling algorithm." << std::endl;
	strm << "--feautrier \t Use Feautrier's scheduling algorithm." << std::endl;
	strm << "--aquma_out = path/to/output/file \t Generate .aquma file with iteration domain and access relations." << std::endl;
	strm << "--codegen_out = path/to/output/file \t Generate .qasm file from chosen circuit schedule." << std::endl;
	strm << "---------------" << std::endl;
	return strm.str();
}


void parse_command_line(int argc, char **argv, qrane_options* opt) {
	int gopt;

	while (1) {
		static struct option long_options[] = {
	  		{"isl", optional_argument, 0, 'a'},
	  		{"minfuse", optional_argument, 0, 'b'},
	  		{"maxfuse", optional_argument, 0, 'z'},
			{"feautrier", optional_argument, 0, 'x'},
			{"aquma_out", optional_argument, 0, 'e'},
      		{"codegen_out", optional_argument, 0, 'f'},
			{"process", optional_argument, 0, 'v'},
     		{0, 0, 0, 0}
    };

    int option_index = 0;
    gopt = getopt_long(argc, argv, "gcqmd:s:p:", long_options, &option_index);

    if (gopt == -1)
      break;

    switch (gopt) {
		case 'g':
			ONED_MODE = CIRCUIT;
			break; 

		// Check mode
      	case 'c':
        	CHECK_MODE = true;
        	break;

        // Lookahead depth
        case 'd':
                LOOKAHEAD_DEPTH = std::atoi(optarg);
                break;

		// Quiet mode
      	case 'q':
        	QUIET_MODE = true;
			break;

        case 's':
                SEARCH_LIMIT = std::stoul(std::string(optarg));
                break;

		case 'p':
				DIVIDE = std::stoul(std::string(optarg));
				break;

		// Membership print
		case 'm':
			MEMBERSHIP_MODE = true;
			break;
		case 'v':
			PROCESS_NUM = std::string(optarg);
			break;

		// isl schedule mode
		case 'a':
			SCHEDULE_MODE = ISL;
			break;

		// minfuse schedule mode
		case 'b':
			SCHEDULE_MODE = PLUTO_MINFUSE;
			break;

		// maxfuse schedule mode
		case 'z':
			SCHEDULE_MODE = PLUTO_MAXFUSE;
			break;

		// feautrier schedule mode
		case 'x':
			SCHEDULE_MODE = FEAUTRIER;
			break;

		// to aquma
		case 'e':
			OUTPUT_AQUMA = true;
			if (optarg) {
				strcpy(aquma_file, optarg);
			} else {
				strcpy(aquma_file, "scop.aquma");
			}

			break;
		
		// to C
		case 'f':
			OUTPUT_CODEGEN = true;
        	if (optarg) {
          		strcpy(codegen_file, optarg);
        	} else {
          		strcpy(codegen_file, "codegen.c");
        	}
        	break;

      	case '?':
        	std::cout << "Type \"help\" for more information." << std::endl;
        	exit(1);
        	break;
		
      
      	default:
        	abort();
    }
  }
};

std::string get_qasm_file_name(char* filename) {
	std::string ret;
	std::string file = std::string(filename);
	ret = file.substr(file.find_last_of("/")+1);
	return ret;
}
