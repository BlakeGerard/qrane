#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <chrono>
#include <regex>
#include <limits>
#include <time.h>
#include <cstdlib>
#include <Python.h>
#include "unistd.h"
#include "getopt.h"
#include "qrane_utils.hh"
#include "qrane_mainprogram.hh"
#include "include/qrane_flags.hh"
#include "qrane-parser.h"
#include "omp.h"

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
std::string PROCESS_NUM = "-1";
SCHEDULE_ALGORITHM SCHEDULE_MODE = DEFAULT;

char* pwd;
char* qrane_home;
char qasm_file[2056];
char codegen_file[1024];
char aquma_file[1024];
std::string qasm_file_name;
qrane_mainprogram* checkpg;

// I should move the timing stuff to a struct
std::chrono::high_resolution_clock::time_point global_start;
std::chrono::high_resolution_clock::time_point done_parsing;
std::chrono::high_resolution_clock::time_point done_building;
std::chrono::high_resolution_clock::time_point checking_start;
std::chrono::high_resolution_clock::time_point checking_end;
std::chrono::high_resolution_clock::time_point global_end;

void parse_command_line(int argc, char **argv);
bool run_checks(qrane_mainprogram* mainpg);
bool check_isomorphism(qrane_mainprogram* mainpg);
bool check_qubit_profile_equivalence(qrane_mainprogram* mainpg);
std::string get_qasm_file_name(char* filename);
std::string help_message();
void print_stats(qrane_mainprogram* mainpg);

extern yy::qrane_parser::symbol_type yylex();
extern FILE *yyin;
isl_stat isl_res;

qrane_output_scop* qrane_driver(int argc, char **argv)
{
	pwd = std::getenv("PWD");
	qrane_home = std::getenv("QRANE_HOME");
	if (qrane_home == nullptr) {
		std::cout << "Please set $QRANE_HOME environment variable." << std::endl;
		exit(1);
	}
  	parse_command_line(argc, argv);

    FILE *qasm = fopen(qasm_file, "r");
  	if (!qasm) { std::cout << "Failed to open openQASM file." << std::endl; exit(1);}

	qasm_file_name = get_qasm_file_name(qasm_file);
  	yyin = qasm;
  	qrane_mainprogram* mainpg = new qrane_mainprogram();  
	yy::qrane_parser main_parser(mainpg);
	int result = main_parser();
	fclose(yyin);

  	if (result) {
		std::cout << "Failed the grammar check." << std::endl;
		exit(1);
  	}

  	global_start = std::chrono::high_resolution_clock::now();

	if (DIVIDE > 1) {
		mainpg->build_dependence_graph();
		std::vector<qrane_statement*> stmts = mainpg->get_stmtlist()->get_qops();

		std::vector<std::vector<qrane_statement*>> divided = qrane_utils::split_into_n_components(stmts, DIVIDE);
		unsigned int qreg_size = mainpg->qreg_size;
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
			new_mp.build_isl_domain_read_write_schedule(SCHEDULE_MODE);

//			unsigned int my_total = new_mp.get_num_domains();
//			#pragma omp atomic
//			total += my_total;

			//std::cout << new_mp.get_reconstruction_histogram_str();
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
		full_scop->arguments = isl_union_map_empty_ctx(ctx);
        full_scop->membership = membership_map();
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
			std::move(all_scops[i]->final_domain_list.begin(), all_scops[i]->final_domain_list.end(),
				std::back_inserter(full_scop->final_domain_list));
        }

		mainpg->set_scop(full_scop);

		if (SCHEDULE_MODE != DEFAULT) { mainpg->compute_transformation(); }
  		done_building = std::chrono::high_resolution_clock::now();
	} else {
		mainpg->parse_domains();
  		done_parsing = std::chrono::high_resolution_clock::now();
		mainpg->build_isl_domain_read_write_schedule(SCHEDULE_MODE);
		if (SCHEDULE_MODE != DEFAULT) { mainpg->compute_transformation(); }
  		done_building = std::chrono::high_resolution_clock::now();
	}

	if (!QUIET_MODE) { mainpg->print_isl_domain_read_write_schedule(); }
	if (!QUIET_MODE && MEMBERSHIP_MODE) { mainpg->print_membership_graph(); }

	if (OUTPUT_AQUMA) {
		std::string str = mainpg->get_aquma_scop_str();
		std::ofstream aquma_out;
		aquma_out.open(aquma_file);
		aquma_out << str;
		aquma_out.close();
	}

	if (OUTPUT_CODEGEN) {
		std::string codegen_c_str = mainpg->generate_codegen_c_str();
		std::string cg = std::string(codegen_file);
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
		int res = std::system(cleanup.c_str());
    	// MK: Check
    	assert (!res && "Error doing cleanup.");
	}

	if (CHECK_MODE) {
		checking_start = std::chrono::high_resolution_clock::now();
		run_checks(mainpg);
		checking_end = std::chrono::high_resolution_clock::now();
	}

  	global_end = std::chrono::high_resolution_clock::now();

	if (!QUIET_MODE) { print_stats(mainpg); }

	qrane_output_scop* ret = mainpg->get_output_scop();
  	return ret;
}

void print_stats(qrane_mainprogram* mainpg) {
  	std::cout << "--- Stats ---" << std::endl;
  	std::cout << "Qops: " << mainpg->get_num_qops() << std::endl;
	std::cout << "Look-ahead Depth: " << LOOKAHEAD_DEPTH << std::endl;
	std::cout << "Search Limit: " << SEARCH_LIMIT << std::endl;
  	std::cout << "Domains: \n";
  	std::cout << mainpg->get_domain_profile_str();
  	std::cout << "Total: " << mainpg->get_num_domains() << " domains, "<< mainpg->get_num_points() << " points." <<  std::endl;
	std::cout << "-------------" << std::endl;

	std::cout << mainpg->get_domain_size_histogram_str();
	std::cout << mainpg->get_reconstruction_histogram_str();

	std::cout << "--- Timing ---" << std::endl;
  	std::cout << "Time reconstructing domains: " << std::chrono::duration_cast<std::chrono::milliseconds>(done_parsing-global_start).count() << "ms" << std::endl;
  	std::cout << "Time scheduling: " << std::chrono::duration_cast<std::chrono::milliseconds>(done_building-done_parsing).count() << "ms" << std::endl;
  	if (CHECK_MODE) {std::cout << "Time checking correctness: " << std::chrono::duration_cast<std::chrono::milliseconds>(checking_end-checking_start).count() << "ms" << std::endl;}
  	std::cout << "Total execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(global_end-global_start).count() << "ms" << std::endl;
  	std::cout << "-------------" << std::endl;
}

bool run_checks(qrane_mainprogram* mainpg) {
	bool check;

	if (!QUIET_MODE) { std::cout << "Checking that all qops have been accounted for ... " << std::flush; }
	check = mainpg->check_all_qops_accounted();
	if (!check) { 
		if (!QUIET_MODE) { std::cout << "False\n" << std::flush; }
		return false; 
	}
	if (!QUIET_MODE) { std::cout << "True\n" << std::flush; }

	if (!QUIET_MODE) { std::cout << "Checking that recovered schedule respects dependences ... " << std::flush; }
	check = mainpg->check_recovered_respects_dependencies();
	if (!check) { 
		if (!QUIET_MODE) { std::cout << "False\n" << std::flush; }
		return false; 
	}
	if (!QUIET_MODE) { std::cout << "True\n" << std::flush; }

	if (!QUIET_MODE) { std::cout << "Checking that all qubits have the same number of accesses ... " << std::flush; }
	check = check_qubit_profile_equivalence(mainpg);
	if (!check) { 
		if (!QUIET_MODE) { std::cout << "False\n" << std::flush; }
		return false; 
	}
	if (!QUIET_MODE) { std::cout << "True\n" << std::flush; }

	if (!QUIET_MODE) { std::cout << "Checking for isomorphism between original and recovered dependence graphs ... " << std::flush; }
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

	if (PROCESS_NUM != "-1") {
		graph_path = "checkgraph_p" + PROCESS_NUM + ".txt";
	} else {
		graph_path = "checkgraph.txt";
	}
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
	if (PROCESS_NUM != "-1") {
		std::string c_name = "check_p" + PROCESS_NUM + ".c";
		std::string qasm_name = "check_p" + PROCESS_NUM + ".qasm";
		std::string exec_name = "check_p" + PROCESS_NUM + ".exe";
		clean = "rm -f " + c_name + " " + qasm_name + " " + exec_name + " " + graph_path + " maingraph.txt";
	} else {
		clean = "rm -f check.c check.exe check.qasm checkgraph.txt maingraph.txt";
	}

	int res = std::system(clean.c_str());
  assert (!res && "Error doing cleaup.");
  // MK: Should return some return value from Python, not just always 'true'
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
	if (PROCESS_NUM != "-1") {
		c_name = "check_p" + PROCESS_NUM + ".c";
		qasm_name = "check_p" + PROCESS_NUM + ".qasm";
		exec_name = "check_p" + PROCESS_NUM + ".exe";
		compile = "gcc -std=c11 " + c_name + " -o " + exec_name;
		execute = "./" + exec_name;
	} else {
		c_name = "check.c";
		qasm_name = "check.qasm";
		exec_name = "check.exe";
		compile = "gcc -std=c11 check.c -o check.exe";
		execute = "./" + exec_name;
	}

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

	// We need to do this so that checkpg->get_qubit_profile_map() has something to create
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
	strm << "--q:qasm= \t REQUIRED: Path to qasm input file." << std::endl;
	strm << "--q:chunk= \t Set the size of each subcircuit to process." << std::endl;
	strm << "--q:check \t Check mode. Run all three verification checks." << std::endl;
    strm << "--q:depth= \t Look-ahead depth for the look-ahead policy." << std::endl;
	strm << "--q:search= \t Search limit in nD phase." << std::endl;
	strm << "--q:quiet \t Quiet mode. Only send domain size histogram, checks, and stats to stdout." << std::endl;
	strm << "--q:member \t Print the time space -> domain space map." << std::endl;
	strm << "--q:isl \t Use isl's default scheduling algorithm." << std::endl;
	strm << "--q:minfuse \t Use Pluto minfuse scheduling algorithm." << std::endl;
	strm << "--q:maxfuse \t Use Pluto maxfuse scheduling algorithm." << std::endl;
	strm << "--q:feautrier \t Use Feautrier's scheduling algorithm." << std::endl;
	strm << "--q:aquma_out = path/to/output/file \t Generate .aquma file with iteration domain and access relations." << std::endl;
	strm << "--q:codegen_out = path/to/output/file \t Generate compilable C file containing isl codegen output at filepath." << std::endl;
	strm << "--q:circuit \t Process the plinko grid instead of dependence graph." << std::endl;
	strm << "--q:help \t Print this help message." << std::endl;
	strm << "---------------" << std::endl;
	return strm.str();
}

void parse_command_line(int argc, char **argv) {
	int gopt;

	char prog[] = "./skip";
	int new_argc = argc + 1;
	char* new_argv_temp[new_argc];
	char** new_argv = (char**) malloc(sizeof(char*) * new_argc);
	new_argv_temp[0] = prog;

	int i;
	for (i = 0; i < argc; ++i) {
		new_argv_temp[i+1] = argv[i]+1;
	}
	for (i = 0; i < new_argc; ++i) {
		new_argv[i] = strdup(new_argv_temp[i]);
	}
	
	while (1) {
		static struct option long_options[] = {
			{"q:qasm", required_argument, 0, 0},
			{"q:chunk", required_argument, 0, 1},
			{"q:check", no_argument, 0, 2},
			{"q:depth", required_argument, 0, 3},
			{"q:search", required_argument, 0, 4},
			{"q:quiet", no_argument, 0, 5},
			{"q:member", no_argument, 0, 6},
	  		{"q:isl", no_argument, 0, 7},
	  		{"q:minfuse", no_argument, 0, 8},
	  		{"q:maxfuse", no_argument, 0, 9},
			{"q:feautrier", no_argument, 0, 10},
			{"q:aquma_out", optional_argument, 0, 11},
      		{"q:codegen_out", optional_argument, 0, 12},
			{"q:circuit", no_argument, 0, 13},
			{"q:help", no_argument, 0, 14},
     		{0, 0, 0, 0}
    };

    int option_index;
    gopt = getopt_long(new_argc, new_argv, "", long_options, &option_index);
	std::cout << "gopt: " << gopt << std::endl;

    if (gopt == -1) {
		break;
	}

    switch (gopt) {
	
		// Qasm
		case 0:
			if (optarg) { 
				//strcpy(qasm_file, pwd);
				//strcpy(qasm_file+strlen(pwd), "/");
				//strcpy(qasm_file+strlen(pwd)+1, optarg); 
				strcpy(qasm_file, optarg);
				std::cout << qasm_file << std::endl;
			} else {
				std::cout << "Please provide input qasm file.\n";
				exit(1); 
			} 
			break;

		// Chunk
		case 1:
			DIVIDE = std::stoul(std::string(optarg));
			break;

		// Check
      	case 2:
        	CHECK_MODE = true;
        	break;

        // Lookahead depth
        case 3:
            LOOKAHEAD_DEPTH = std::atoi(optarg);
        	break;

		// Search limit
        case 4:
        	SEARCH_LIMIT = std::stoul(std::string(optarg));
        	break;

		// Quiet mode
      	case 5:
        	QUIET_MODE = true;
			break;

		// Membership print
		case 6:
			MEMBERSHIP_MODE = true;
			break;

		// isl schedule mode
		case 7:
			SCHEDULE_MODE = ISL;
			break;

		// minfuse schedule mode
		case 8:
			SCHEDULE_MODE = PLUTO_MINFUSE;
			break;

		// maxfuse schedule mode
		case 9:
			SCHEDULE_MODE = PLUTO_MAXFUSE;
			break;

		// feautrier schedule mode
		case 10:
			SCHEDULE_MODE = FEAUTRIER;
			break;

		// to aquma
		case 11:
			OUTPUT_AQUMA = true;
			if (optarg) { strcpy(aquma_file, optarg); } 
			else { strcpy(aquma_file, "scop.aquma"); }
			break;
		
		// to C
		case 12:
			OUTPUT_CODEGEN = true;
        	if (optarg) { strcpy(codegen_file, optarg); } 
			else { strcpy(codegen_file, "codegen.c"); }
        	break;

		// circuit
		case 13:
			ONED_MODE = CIRCUIT;
			break;

		// help
		case 14:
			std::cout << help_message();
			exit(1);
			break;

      	case '?':
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
