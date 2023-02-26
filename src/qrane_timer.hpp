#ifndef QRANE_TIMER_HPP
#define QRANE_TIMER_HPP

#include <chrono>

namespace qrane {

struct global_timer_s {
	std::chrono::high_resolution_clock::time_point global_start;
	std::chrono::high_resolution_clock::time_point reconstruction_complete;
	std::chrono::high_resolution_clock::time_point scheduling_complete;
	std::chrono::high_resolution_clock::time_point checking_start;
	std::chrono::high_resolution_clock::time_point checking_end;
	std::chrono::high_resolution_clock::time_point global_end;
};
typedef struct global_timer_s global_timer;

}
#endif