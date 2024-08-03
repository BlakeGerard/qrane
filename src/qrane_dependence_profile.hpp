/*
Qrane
Filename: qrane_deps.hpp
Creation date: December 26, 2020
Copyright (C) 2020

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QRANE_DEPENDENCE_PROFILE_HPP
#define QRANE_DEPENDENCE_PROFILE_HPP

#include <array>
#include <map>
#include <queue>
#include <string>

#include "isl/map.h"
#include "isl/union_map.h"

#include "qrane_graph.hpp"
#include "qrane_options.hpp"
#include "qrane_qop.hpp"
#include "qrane_shared.hpp"

namespace qrane {

enum access_type_e { READ, WRITE };

class DependenceProfile {

public:
  DependenceProfile(const std::map<qop_id, std::shared_ptr<Qop>> &qops,
                    const qrane_options *opt);

  // Frontier processing methods for the 1D recovery phase.
  adjacency_t<qop_id> get_dependence_frontier();
  void remove_frontier_subset(const adjacency_t<qop_id> &vertices);
  std::array<unsigned int, 2>
  lookahead_breadth(unsigned int breadth, std::vector<qop_id> &frontier,
                    std::map<qop_id, std::shared_ptr<Qop>> &qops);
  std::array<unsigned int, 2>
  lookahead_depth(unsigned int depth, std::vector<qop_id> &frontier,
                  std::map<qop_id, std::shared_ptr<Qop>> &qops);

  // isl functionality
  isl_union_map *build_implicit_schedule(isl_ctx *ctx,
                                         const membership_map_t &membership);

  // Printing and string formatting
  std::string get_networkx_edge_list_str();
  std::string get_gates_networkx_edge_list_str(
      const std::map<qop_id, std::shared_ptr<Qop>> &qops);
  void print_dependencies();

private:
  Graph<qop_id> G_static_;
  Graph<qop_id> G_dynamic_;
  std::map<qop_id, std::queue<std::pair<qop_id, access_type_e>>> latest_access_;

  void
  construct_dependence_graph(const std::map<qop_id, std::shared_ptr<Qop>> &qops,
                             const qrane_options *opt);
  void add_dependence(const qop_id accessor, const qubit_id accessed,
                      const access_type_e type);

  void lookahead_depth_main(unsigned int depth, qop_id src,
                            std::array<unsigned int, 2> &count,
                            std::map<qop_id, std::shared_ptr<Qop>> &qops);
};
} // namespace qrane
#endif