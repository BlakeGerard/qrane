
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>

#include "include/qrane_deps.hpp"
#include "qrane_utils.hpp"

// -------------------------------
// Constructors and Initialization
// -------------------------------

namespace qrane {

DependenceProfile::DependenceProfile(
    const std::map<qop_id, std::shared_ptr<Qop>> &qops,
    const qrane_options *opt) {
  auto V =
      utils::get_map_keys_as_initializer_list<qop_id, std::shared_ptr<Qop>>(
          qops);
  G_static_ = Graph<qop_id>(V, true);
  G_dynamic_ = Graph<qop_id>(V, true);
  latest_access_ =
      std::map<qop_id, std::queue<std::pair<qop_id, access_type_e>>>();
  construct_dependence_graph(qops, opt);
};

/*
        Membership is normally initialized here. It should
        probably be in Program directly.
*/
void DependenceProfile::construct_dependence_graph(
    const std::map<qop_id, std::shared_ptr<Qop>> &qops,
    const qrane_options *opt) {

  // Add dependencies to the graph argument by argument
  for (const auto &element : qops) {
    access_type_e type;
    unsigned int num_args = element.second->num_args();
    for (unsigned int i = 0; i < num_args; ++i) {
      // If all access are considered as writes, override the type
      if (opt->write_all)
        type = WRITE;

      // Otherwise, only the last argument is a write
      else {
        if (i < num_args - 1)
          type = READ;
        else
          type = WRITE;
      }
      add_dependence(element.second->id(), element.second->arg(i)->index(),
                     type);
    }
  }
}

void DependenceProfile::add_dependence(const qop_id accessor,
                                       const qubit_id accessed,
                                       const access_type_e type) {

  // If the index is already being tracked
  if (latest_access_.count(accessed)) {

    // If the queue is not empty
    if (latest_access_[accessed].size() > 0) {

      // If the current access is a read
      if (type == READ) {

        // and the latest access is a write (WAR)
        auto &latest = latest_access_[accessed].front();
        if (latest.second == WRITE) {

          // Generate a dependence only. The access gets pushed onto the queue
          if (latest.first == accessor) {
            return;
          }
          G_static_.add_edge(latest.first, accessor);
          G_dynamic_.add_edge(latest.first, accessor);

          // and the latest access is a read (RAR)
        } else if (latest.second == READ) {
          // Don't generate a dependence, just push the access to the queue
        }

        // If the current access is a write (RAW or WAW)
      } else if (type == WRITE) {

        // Generate dependence for each item and remove it from the queue
        while (!latest_access_[accessed].empty()) {
          auto latest = latest_access_[accessed].front();
          latest_access_[accessed].pop();
          if (latest.first == accessor) {
            continue;
          }
          G_static_.add_edge(latest.first, accessor);
          G_dynamic_.add_edge(latest.first, accessor);
        }
      }
    }
  }
  latest_access_[accessed].push(std::make_pair(accessor, type));
}

adjacency_t<qop_id> DependenceProfile::get_dependence_frontier() {
  return G_dynamic_.get_frontier();
}

void DependenceProfile::remove_frontier_subset(
    const adjacency_t<qop_id> &vertices) {
  G_dynamic_.remove_vertices(vertices);
}

std::array<unsigned int, 2> DependenceProfile::lookahead_breadth(
    unsigned int breadth, std::vector<qop_id> &frontier,
    std::map<qop_id, std::shared_ptr<Qop>> &qops) {

  std::array<unsigned int, 2> all_counts = {0, 0};
  std::size_t frontier_size = frontier.size();
  for (const auto &f : frontier) {
    const auto &neighbors = G_dynamic_.get_neighbors(f);

    // No nodes to look ahead
    if (neighbors.size() == 0) {
      continue;
    }

    std::size_t args_count;
    for (const auto &n : neighbors) {
      args_count = qops[n]->num_args();
      all_counts[args_count - 1] += 1;
    }
  }
  return all_counts;
}

std::array<unsigned int, 2> DependenceProfile::lookahead_depth(
    unsigned int depth, std::vector<qop_id> &frontier,
    std::map<qop_id, std::shared_ptr<Qop>> &qops) {

  std::array<unsigned int, 2> count = {0, 0};
  for (const auto &f : frontier) {
    std::size_t args = qops[f]->num_args();
    count[args - 1] += 1;
    lookahead_depth_main(depth, f, count, qops);
  }
  return count;
};

void DependenceProfile::lookahead_depth_main(
    unsigned int depth, qop_id src, std::array<unsigned int, 2> &count,
    std::map<qop_id, std::shared_ptr<Qop>> &qops) {

  auto traversal = std::stack<std::pair<qop_id, unsigned int>>();
  auto completed = std::map<qop_id, bool>();
  for (const auto &element : qops)
    completed.insert(std::make_pair(element.first, false));

  traversal.push(std::make_pair(src, 1));
  unsigned int v;
  unsigned int d;
  while (!traversal.empty()) {
    auto frame = traversal.top();
    v = frame.first;
    d = frame.second;
    traversal.pop();

    // If the vertex has not been counted, count it and mark it as counted
    if (!completed[v]) {
      completed[v] = true;
      std::size_t args = qops[v]->num_args();
      count[args - 1] += 1;
    }

    if (d < depth) {
      for (const auto &n : G_dynamic_.get_neighbors(v)) {
        traversal.push(std::make_pair(n, d + 1));
      }
    }
  }
}

/*
                This function builds a string representation of the
   point-to-point dependencies in ISL format. Each qop_id in G_static_ is
   converted to its associated point of an iteration domain, e.g.: qop_id 4 ->
   S2[0,1]

*/
isl_union_map *
DependenceProfile::build_implicit_schedule(isl_ctx *ctx,
                                           const membership_map_t &membership) {
  isl_union_map *schedule = isl_union_map_empty_ctx(ctx);

  std::ostringstream strm;
  unsigned int node_count = 0;
  for (const auto &node : G_static_) {
    auto node_info = membership.at(node.first);
    strm << "{S" << std::to_string(node_info.first) << "[";
    for (std::vector<unsigned int>::reverse_iterator dim =
             node_info.second.rbegin();
         dim != (node_info.second.rend() - 1); ++dim) {
      strm << std::to_string(*dim) << ",";
    }
    strm << std::to_string(node_info.second[0]) << "] -> ";
    strm << "[" << node.first << "]}";

    isl_map *node_map = isl_map_read_from_str(ctx, strm.str().c_str());
    schedule = isl_union_map_add_map(schedule, node_map);
    strm.str(std::string());
    ++node_count;
  }
  return isl_union_map_coalesce(schedule);
}

std::string DependenceProfile::get_networkx_edge_list_str() {
  std::ostringstream strm;
  for (const auto &entry : G_static_) {
    for (const auto neighbor : entry.second) {
      strm << entry.first << " " << neighbor << std::endl;
    }
  }
  return strm.str();
}

std::string DependenceProfile::get_gates_networkx_edge_list_str(
    const std::map<qop_id, std::shared_ptr<Qop>> &qops) {
  std::ostringstream strm;
  std::string lhs_id;
  std::string rhs_id;
  for (const auto &entry : G_static_) {
    lhs_id = qops.at(entry.first)->to_string();
    lhs_id.erase(std::remove(lhs_id.begin(), lhs_id.end(), ' '), lhs_id.end());
    for (const auto &neighbor : entry.second) {
      rhs_id = qops.at(neighbor)->to_string();
      rhs_id.erase(std::remove(rhs_id.begin(), rhs_id.end(), ' '),
                   rhs_id.end());
      strm << lhs_id << " " << rhs_id << std::endl;
    }
  }
  return strm.str();
}

void DependenceProfile::print_dependencies() {
  std::ostringstream strm;
  strm << "{\n";
  for (const auto &pair : G_static_) {
    strm << "\t" << pair.first << " -> [ ";
    for (auto val : pair.second) {
      strm << val << " ";
    }
    strm << "];\n";
  }
  strm << "};";
  std::cout << strm.str() << std::endl;
}
} // namespace qrane