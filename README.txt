The Qrane mini-api has been modified to closely model the aquma api.
The changes mostly reside on the qrane side (the drivers are much cleaner now),
so the library invocation in your custom driver should remain largely the same.

--------
Mini-API
--------
The only include file you need is "qrane.h", which is found the main qrane directory.
The API now has the functions:

	void qrane_options_init(qrane_options* opt);
	int qrane_options_check(qrane_options* opt);
	void qrane_options_free(qrane_options* opt);
	void print_qrane_options(qrane_options* opt);
	qrane_output_scop* qrane_driver(int argc, char* argv[],
									qrane_options* opt);

Each function serves the exact same purpose as their corresponding
aquma versions. However, qrane_driver both extracts the command line
arguments and encapsulates all of qrane's processing, which is modified
by the arguments. So the qrane invocation should be something like:

	qrane_options opt;
	qrane_options_init(&opt);
	if (qrane_options_check(&opt)) { <do what you want with options error> }
	qrane_output_scop* qrane_scop;
	qrane_scop = qrane_driver(argc, argv, &opt);

If there is an error at any point within qrane_driver,
an empty qrane_output_scop* will be returned.

At the moment, Qrane is configured to add in the program name
to the argv list so that getopt will work as expected.
This means you will still need to do the manual options
procedure with sprintf. It would be a simple code comment in
qrane if we wanted to make qrane_driver parse the argc and argv 
parameters for main directly, like aquma_options_extract.

------------------
Command Line Flags
------------------
The "q:" prefix has been removed from all command line flags,
and both the binary and library versions of Qrane utilize the same
command line parsing function.

	--qasm=<path/to/*.qasm>    REQUIRED: Path to qasm input file.
	--chunk=<ui>               Set the size of each subcircuit to process.
	--check                    Check mode. Run all three verification checks.
    --depth=<ui>               Look-ahead depth for the look-ahead policy.
	--search=<ui>              Search limit in nD phase.
	--quiet                    Quiet mode. Print nothing to the console.
	--member 				   Print the time space -> domain space map.
	--circuit                  Process the plinko grid instead of dependence graph.
	--isl 					   Use isl's default scheduling algorithm.
	--minfuse                  Use PLuTo minfuse scheduling algorithm.
	--maxfuse                  Use PLuTo maxfuse scheduling algorithm.
	--feautrier                Use Feautrier's scheduling algorithm.
	--aquma_out=<filepath>     Generate .aquma file with iteration domain and access relations.
	--codegen_out=<filepath>   Generate .qasm file from circuit schedule.
	--help                     Print this help message.