#include "qrane.h"

void qrane_options_init(qrane_options* opt) {
	opt->qrane_home = std::getenv("QRANE_HOME");
	opt->qasm_file = NULL;
	opt->device_file = NULL;
	opt->codegen_file = NULL;
	opt->aquma_file = NULL;
	opt->check_qasm = NULL;
	opt->check = false;
	opt->quiet = false;
	opt->membership = false;
	opt->substr = false;
	opt->write_all = false;
	opt->chunk = 1; 			// Treat the file as one circuit
	opt->breadth_limit = 2;		// Impose no limit
	opt->search_limit = 0;		// Impose no limit
	opt->process_mode = PROCESS_DDG;
	opt->schedule_mode = SCHEDULE_IMPLICIT;
}

int qrane_options_check(qrane_options* opt) {
	if (opt->qrane_home == nullptr) { 
		std::cout << "Please set $QRANE_HOME to your qrane installation directory ... returning error code 1\n";
		return 1; 
	}
	if (opt->qasm_file == NULL) { 
		std::cout << "You must provide an OpenQASM file ... returning error code 1\n";
		return 1; 
	}

	FILE* check;

	// Verify the qasm file if supplied
	if (opt->qasm_file) {
		if ((check = fopen(opt->qasm_file, "r"))) {
			fclose(check);
		} else {
			printf("OpenQASM file %s not found ... returning error code 1\n", opt->qasm_file);
			return 1;
		}
	}

	// Verify the codegen file if supplied
	if (opt->codegen_file) {
		if ((check = fopen(opt->codegen_file, "w"))) {
			fclose(check);
		} else {
			printf("Failed to create or open codegen file %s ... returning error code 1\n", opt->codegen_file);
			return 1;
		}
	}

	// Verify the aquma output file if supplied
	if (opt->aquma_file) {
		if ((check = fopen(opt->codegen_file, "w"))) {
			fclose(check);
		} else {
			printf("Failed to create or open aquma output file %s .. returning error code 1\n", opt->aquma_file);
			return 1;
		}
	}

	// Everything checks out
	return 0;
}

void qrane_options_free(qrane_options* opt) {

}

void print_qrane_options(qrane_options* opt) {
	printf ("Collected Qrane options: \n");
  	printf ("\tQRANE_HOME              : %s\n", opt->qrane_home);
  	printf ("\tQasm Input              : %s\n", opt->qasm_file);
 	printf ("\tCheck                   : %s\n", opt->check ? "True" : "False");
  	printf ("\tQuiet                   : %s\n", opt->quiet ? "True" : "False");
  	printf ("\tMembership              : %s\n", opt->membership ? "True" : "False");
	printf ("\tSubstr                  : %s\n", opt->membership ? "True" : "False");
  	printf ("\tSubcircuit Size         : %d\n", opt->chunk);
	printf ("\tLookahead Breadth Limit : %d\n", opt->breadth_limit);
	printf ("\tSearch Limit            : %d\n", opt->search_limit);
	printf ("\tCircuit Processing Mode : %d\n", opt->process_mode);
	printf ("\tSchedule Mode           : %d\n", opt->schedule_mode);
  	printf ("\n\n");
}

int qrane_check_isomorphism(int argc, char* argv[], qrane_options* opt) {
	qrane_timer timer = qrane_timer();
	qrane_host host = qrane_host(opt, &timer);
	host.parse_options(argc, argv);
	int res = host.check_input_output_isomorphism();
	return res;
}

qrane_output_scop* qrane_driver(int argc, char* argv[],
								    qrane_options* opt) {
	int res;
	qrane_timer timer = qrane_timer();
	qrane_output_scop* scop = new qrane_output_scop();
	qrane_host host = qrane_host(opt, &timer);

	timer.global_start = std::chrono::high_resolution_clock::now();

	res = host.parse_options(argc, argv);
	if (res) {
		std::cout << "Failed to parse qrane_options. Returning empty scop.\n";
		return scop;
	}

	res = host.parse_circuit();
	if (res) {
		std::cout << "Something went wrong in the parser. Returning empty scop.\n";
		return scop;
	}

	if (!opt->substr) { res = host.process_circuit(); }
	//else { res = host.process_circuit_via_substring_decomposition(); }
	if (res) {
		std::cout << "Something went wrong during reconstruction. Returning empty scop.\n";
		return scop;
	}
	
	if (opt->check) { res = host.run_checks(); }
	if (res) {
		std::cout << "One of the checks failed. Returning empty scop.\n";
		return scop;
	}

	timer.global_end = std::chrono::high_resolution_clock::now();

	if (!opt->quiet) { host.print_scop(); }
	if (!opt->quiet) { host.print_stats(); }

	res = host.output_to_files();
	if (res) {
		std::cout << "Failed to write to aquma_file or codegen_file. Returning empty scop.\n";
		return scop;
	}

	return host.get_scop();
}
