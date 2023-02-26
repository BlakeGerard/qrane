#ifndef AQUMA_OPTIONS_H
#define AQUMA_OPTIONS_H

struct qrane_options_s {
	char* qrane_home;
	char* qasm_file;
	char* calibration_file;
	char* coupling_file;
	char* codegen_file;
	char* aquma_file;
	char* check_qasm;
	bool check;
	bool quiet;
	bool membership;
	bool substr;
	bool write_all;
	unsigned int chunk;
	unsigned int breadth_limit;
	long search_limit;
	unsigned int process_mode;
	unsigned int schedule_mode;
};
typedef struct qrane_options_s qrane_options;

#define PROCESS_DDG 0
#define PROCESS_GRID 1

#define SCHEDULE_IMPLICIT 0
#define SCHEDULE_ISL 1
#define SCHEDULE_MINFUSE 2
#define SCHEDULE_MAXFUSE 3
#define SCHEDULE_FEAUTRIER 4

#endif
