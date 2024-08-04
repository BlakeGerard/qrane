#include "qrane_domain.hh"
#include "qrane_qop.hh"
#include <deque>
#include <map>
#include <unordered_map>
#include <vector>

#ifndef QRANE_SHARED_HH
#define QRANE_SHARED_HH

struct PairHasher {
  std::size_t operator()(const std::pair<unsigned int, float> &id) const {
    std::size_t val = 0;
    std::hash<unsigned int> ui_hasher;
    std::hash<float> fl_hasher;

    val ^= ui_hasher(id.first) + 0x9e3779b9 + (val << 6) + (val >> 2);
    val ^= fl_hasher(id.second) + 0x9e3779b9 + (val << 6) + (val >> 2);
    return val;
  };
};

enum qop_component {
  ARGS = 0,
  IN_DEGREE,
  OUT_DEGREE,
  GATE_TYPE,
  QOP_NUM_TYPE,
  QOP_NUM_GLOBAL
};

// THIS MUST BE A MAP
typedef std::map<unsigned int, std::vector<unsigned int>> time_dependence_graph;

// Map: line_num -> (domain_num, [i, j, ...])
typedef std::map<unsigned int,
                 std::pair<unsigned int, std::vector<unsigned int>>>
    membership_map;

typedef std::tuple<std::vector<int>, unsigned int, unsigned int, std::string,
                   unsigned int, unsigned int>
    qop_identifier;

typedef std::map<unsigned int, qop_identifier> qasm_ops_list;

typedef std::unordered_map<unsigned int,
                           std::vector<std::pair<unsigned int, int>>>
    stride_graph;

typedef std::vector<std::deque<unsigned int>> plinko_grid;

typedef std::unordered_map<std::pair<unsigned int, float>,
                           std::deque<unsigned int>, PairHasher>
    ray_graph;

typedef std::map<unsigned int, std::map<std::string, unsigned int>>
    qubit_profile_map;

typedef std::vector<std::deque<unsigned int>> plinko_grid;

typedef std::unordered_map<std::pair<unsigned int, float>,
                           std::deque<unsigned int>, PairHasher>
    ray_graph;

#endif