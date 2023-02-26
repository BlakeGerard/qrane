#include <map>
#include <deque>
#include <vector>
#include <string>
#include <unordered_map>

#ifndef QRANE_SHARED_HPP
#define QRANE_SHARED_HPP

typedef int qop_id;
typedef int qubit_id;
typedef int statement_id;
typedef int program_id;

struct PairHasher
{
	std::size_t operator()(const std::pair<unsigned int, float>& id) const {
		std::size_t val = 0;
		std::hash<unsigned int> ui_hasher;
		std::hash<float> fl_hasher;

		val ^= ui_hasher(id.first) + 0x9e3779b9 + (val << 6) + (val >> 2);
		val ^= fl_hasher(id.second) + 0x9e3779b9 + (val << 6) + (val >> 2);
		return val;
	};
};

// Map: line_num -> (domain_num, [i, j, ...])
typedef std::map<qop_id, std::pair<unsigned int, std::vector<unsigned int>>> membership_map_t;
typedef std::map<std::string, qop_id> membership_map_reverse;

typedef std::unordered_map<qop_id, std::vector<std::pair<qop_id, int>>> stride_graph;

typedef std::unordered_map<std::pair<qop_id, float>, std::deque<qop_id>, PairHasher> ray_graph;

typedef std::map<unsigned int, std::map<std::string, unsigned int>> qubit_profile_map;

#endif