#include "qrane.h"

int main(int argc, char** argv) {
	qrane_options opt;
	qrane_options_init(&opt);
	int res = qrane_check_isomorphism(argc, argv, &opt);
	std::cout << res << std::endl;
	//qrane_output_scop* scop = qrane_driver(argc, argv, &opt);
	qrane_options_free(&opt);
	return 0;
}
