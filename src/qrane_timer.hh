#ifndef QRANE_TIMER_H
#define QRANE_TIMER_H

#include <chrono>

struct qrane_timer_s {
  std::chrono::high_resolution_clock::time_point global_start;
  std::chrono::high_resolution_clock::time_point reconstruction_complete;
  std::chrono::high_resolution_clock::time_point scheduling_complete;
  std::chrono::high_resolution_clock::time_point checking_start;
  std::chrono::high_resolution_clock::time_point checking_end;
  std::chrono::high_resolution_clock::time_point global_end;
};
typedef struct qrane_timer_s qrane_timer;

#endif