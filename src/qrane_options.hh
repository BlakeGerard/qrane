#ifndef AQUMA_OPTIONS_H
#define AQUMA_OPTIONS_H

#include <string>

struct qrane_options_s {
  std::string qrane_home;
  std::string qasm_file;
  std::string device_file;
  std::string codegen_file;
  std::string aquma_file;
  std::string check_qasm;
  bool check;
  bool quiet;
  bool membership;
  bool substr;
  bool write_all;
  unsigned int chunk;
  unsigned int breadth_limit;
  unsigned int search_limit;
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
