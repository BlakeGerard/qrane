#ifndef QRANE_hpp
#define QRANE_hpp

#include "include/qrane_host.hpp"

void qrane_options_init(qrane_options *opt);

int qrane_options_check(qrane_options *opt);

void qrane_options_free(qrane_options *opt);

void print_qrane_options(qrane_options *opt);

int qrane_check_isomorphism(int argc, char *argv[], qrane_options *opt);

qrane_output_scop *qrane_driver(int argc, char *argv[], qrane_options *opt);

#endif
