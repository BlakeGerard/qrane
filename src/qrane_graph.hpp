/*
Qrane
Filename: qrane_graph.hpp
Creation date: December 26, 2020
Copyright (C) 2020
*/

#ifndef QRANE_GRAPH_H
#define QRANE_GRAPH_H

#include <algorithm>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <vector>

namespace qrane {

template <typename T> using adjacency_t = std::vector<T>;

template <typename T> using graph_t = std::map<T, adjacency_t<T>>;

template <typename T, typename W> using vertex_properties_t = std::map<T, W>;

template <typename T, typename W>
using edge_properties_t = std::map<std::pair<T, T>, W>;

template <typename T> class Graph {

public:
  Graph();
  Graph(bool directed);
  Graph(std::vector<T> &V, bool directed);
  Graph(std::initializer_list<T> &V, bool directed);
  static Graph<T> read_from_edge_list_file(std::string path, bool directed);

  void add_vertex(T v);
  void add_edge(T v, T u);
  void remove_vertex(T v);
  void remove_edge(T v, T u);
  void remove_vertices(const adjacency_t<T> &v);

  adjacency_t<T> get_vertex_set() const;
  adjacency_t<T> get_frontier() const;
  adjacency_t<T> get_neighbors(T v) const;

  bool empty() const;
  bool contains_vertex(T v) const;
  bool contains_edge(T v, T u) const;
  unsigned int num_vertices() const;
  unsigned int num_edges() const;

  std::string to_string() const;
  std::string in_degrees_to_string() const;
  std::string to_python_tuple_list() const;

  // Algorithms
  unsigned int unweighted_shortest_path_length(T src, T dst) const;
  std::vector<T> topological_ordering() const;
  unsigned int longest_path() const;

  // Iterators
  typename std::map<T, std::vector<T>>::const_iterator cbegin() const;
  typename std::map<T, std::vector<T>>::const_iterator cend() const;
  typename std::map<T, std::vector<T>>::iterator begin();
  typename std::map<T, std::vector<T>>::iterator end();

private:
  graph_t<T> G_;
  std::map<T, unsigned int> in_degree_;
  bool directed_;

  // Helpers
  std::map<T, unsigned int> initialize_distance_map(T src) const;
};

/*
    Default constructor.
*/
template <typename T> Graph<T>::Graph() {
  directed_ = true;
  G_ = graph_t<T>();
  in_degree_ = std::map<T, unsigned int>();
};

/*
    Constructor with directed_ boolean.
*/
template <typename T> Graph<T>::Graph(bool directed) {
  directed_ = directed;
  G_ = graph_t<T>();
  in_degree_ = std::map<T, unsigned int>();
}

/*
    Add all vertices in vertex_set to the graph
    with in-degree zero.
*/
template <typename T>
Graph<T>::Graph(std::vector<T> &vertex_set, bool directed) {
  directed_ = directed;
  G_ = graph_t<T>();
  in_degree_ = std::map<T, unsigned int>();
  for (const T &v : vertex_set) {
    add_vertex(v);
  }
}

/*
    Constructor with initializer list.
*/
template <typename T>
Graph<T>::Graph(std::initializer_list<T> &vertex_set, bool directed) {
  directed_ = directed;
  G_ = graph_t<T>();
  in_degree_ = std::map<T, unsigned int>();
  for (const T &v : vertex_set) {
    add_vertex(v);
  }
}

/*
    Add vertex v to the graph with in-degree zero,
        if it does not already exist.
*/
template <typename T> void Graph<T>::add_vertex(T v) {
  if (contains_vertex(v)) {
    return;
  }
  G_.insert(std::make_pair(v, adjacency_t<T>()));
  in_degree_.insert(std::make_pair(v, 0));
}

/*
    Add the edge (v, u) to the graph. The vertices
        are added to the graph if not already present.
*/
template <typename T> void Graph<T>::add_edge(T v, T u) {
  if (contains_edge(v, u)) {
    return;
  }
  if (!contains_vertex(v)) {
    add_vertex(v);
  }
  if (!contains_vertex(u)) {
    add_vertex(u);
  }

  G_[v].push_back(u);
  in_degree_[u] += 1;

  // If undirected, make v a neighbor of u as well
  if (!directed_) {
    G_[u].push_back(v);
    in_degree_[v] += 1;
  }
}

/*
    Remove vertex v from the graph, if it exists.
*/
template <typename T> void Graph<T>::remove_vertex(T v) {
  if (!contains_vertex(v)) {
    return;
  }

  // Decrement in_degree_ of all neighbors of vertex v
  // Operation is identical for directed_ and undirected_ graphs
  for (const T &n : get_neighbors(v)) {
    in_degree_[n] -= 1;
  }

  // Remove any reference to v in all adjacency list
  for (auto &[vertex, neighbors] : G_) {
    neighbors.erase(std::remove_if(neighbors.begin(), neighbors.end(),
                                   [&](const auto &n) { return n == v; }));
  }

  // Remove v from the graph and in_degree_ map
  G_.erase(v);
  in_degree_.erase(v);
}

/*
    Apply remove_vertex to each vertex in the provided adjacency container.
*/
template <typename T>
void Graph<T>::remove_vertices(const adjacency_t<T> &vertices) {
  for (const auto &v : vertices) {
    remove_vertex(v);
  }
}

/*
    Remove edge (v, u) from the graph, if it exists.
*/
template <typename T> void Graph<T>::remove_edge(T v, T u) {
  if (!contains_edge(v, u)) {
    return;
  }

  G_[v].erase(u);
  in_degree_[u] -= 1;

  // If undirected, remove v from neighbors of u as well.
  if (!directed_) {
    G_[u].erase(v);
    in_degree_[v] -= 1;
  }
}

/*
    Get a copy of the vertex set of the graph.
*/
template <typename T> adjacency_t<T> Graph<T>::get_vertex_set() const {
  adjacency_t<T> vertex_set;
  for (const auto &[vertex, _] : G_) {
    vertex_set.push_back(vertex);
  }
  return vertex_set;
}

/*
    Get a copy of the neighboring vertices of
    vertex v. Return an empty adjacency_t
    if v is not present in the graph.
*/
template <typename T> adjacency_t<T> Graph<T>::get_neighbors(T v) const {
  if (contains_vertex(v)) {
    return G_.at(v);
  }
  return adjacency_t<T>();
}

/*
   Get the frontier of the graph, that is, the set
   of vertices of zero in-degree.
*/
template <typename T> adjacency_t<T> Graph<T>::get_frontier() const {
  auto frontier = adjacency_t<T>();
  if (empty()) {
    return frontier;
  }
  for (const auto &entry : in_degree_) {
    if (entry.second == 0) {
      frontier.push_back(entry.first);
    }
  }
  return frontier;
}

/*
        Get the number of vertices.
*/
template <typename T> unsigned int Graph<T>::num_vertices() const {
  return G_.size();
}

/*
        Count the edges in the graph. Since mutator
        functions take into account whether the graph
        is directed or undirected, the procedure is identical
        for both types.
*/
template <typename T> unsigned int Graph<T>::num_edges() const {
  unsigned int count =
      std::accumulate(G_.begin(), G_.end(), /*init=*/0,
                      [](unsigned int count, const auto &neighbors) {
                        return std::move(count) + neighbors.size();
                      });
  return count;
}

template <typename T> inline bool Graph<T>::contains_vertex(T v) const {
  return G_.count(v);
}

template <typename T> bool Graph<T>::contains_edge(T v, T u) const {
  if (!contains_vertex(v)) {
    return false;
  }
  if (!contains_vertex(u)) {
    return false;
  }
  return std::find(G_.at(v).begin(), G_.at(v).end(), u) != G_.at(v).end();
}

/*
    Check if the graph is empty.
*/
template <typename T> inline bool Graph<T>::empty() const { return G_.empty(); }

template <typename T>
typename std::map<T, std::vector<T>>::const_iterator Graph<T>::cbegin() const {
  return G_.cbegin();
}

template <typename T>
typename std::map<T, std::vector<T>>::const_iterator Graph<T>::cend() const {
  return G_.cend();
}

template <typename T>
typename std::map<T, std::vector<T>>::iterator Graph<T>::begin() {
  return G_.begin();
}

template <typename T>
typename std::map<T, std::vector<T>>::iterator Graph<T>::end() {
  return G_.end();
}

/*
        Find the length of the shortest (unweighted) path
        from src to dst.
*/
template <typename T>
unsigned int Graph<T>::unweighted_shortest_path_length(T src, T dst) const {
  // The queue can be seen as a set of "stack frames"
  // if the recursion was implemented with function calls.
  auto traversal = std::queue<std::pair<T, unsigned int>>();
  auto explored = std::set<T>();

  traversal.push(std::make_pair(src, 0));
  while (!traversal.empty()) {
    auto front = traversal.front();
    traversal.pop();
    if (explored.count(front.first)) {
      continue;
    }
    if (front.first == dst) {
      return front.second;
    }
    for (const auto &n : vertex_succ(front.first)) {
      traversal.push(std::make_pair(n, front.second + 1));
    }
    explored.insert(front.first);
  }
  return 0;
}

/*
    Kahn's topological sorting algorithm.
    From Wikipedia pseudocode.
*/
template <typename T> std::vector<T> Graph<T>::topological_ordering() const {
  Graph H = G_;
  std::vector<T> L;
  L.reserve(H.num_vertices());
  std::vector<T> S = H.get_frontier();

  while (!S.empty()) {
    T n = *S.begin();
    L.push_back(n);
    S.erase(S.begin());

    for (const auto &m : H.vertex_adj(n)) {
      H.remove_edge(n, m);
      if (H.in_degree_(m) == 0) {
        S.insert(m);
      }
    }
  }

  if (H.num_edges()) {
    std::cout << "Error in Graph::topological_ordering:" << std::endl
              << "\t Graph has a cycle. Returning empty vector." << std::endl;
    return std::vector<T>();
  } else {
    return L;
  }
}

/*
        Helper for longest path search.
*/
template <typename T>
std::map<T, unsigned int> Graph<T>::initialize_distance_map(T src) const {
  auto dist = std::map<T, unsigned int>();
  dist.reserve(num_vertices());
  auto min = std::numeric_limits<unsigned int>::min();
  for (const auto &v : get_vertex_set()) {
    dist[v] = min;
  }
  dist[src] = 0;
  return dist;
}

/*

*/
template <typename T> unsigned int Graph<T>::longest_path() const {
  auto ordering = topological_ordering();
  auto dist = initialize_distance_map(*ordering.begin());

  for (const auto &u : ordering) {
    for (const auto &v : vertex_adj(u)) {
      if (dist[v] < dist[u] + 1)
        dist[v] = dist[u] + 1;
    }
  }

  auto max_it =
      std::max_element(dist.begin(), dist.end(),
                       [](const std::pair<T, unsigned int> &a,
                          const std::pair<T, unsigned int> &b) -> bool {
                         return a.second < b.second;
                       });
  return max_it->second;
}

/*
    Get a string representation of the adjacency list.
        ex:
        {
                0 -> [ 0 1 2 ]
                ...
                8 -> [ 1 2 ]
        }
*/
template <typename T> std::string Graph<T>::to_string() const {
  std::ostringstream strm;
  strm << "{" << std::endl;
  for (const auto &entry : G_) {
    strm << "\t" << entry.first << " -> [ ";
    for (const auto &vertex : entry.second) {
      strm << vertex << " ";
    }
    strm << "]" << std::endl;
  }
  strm << "}" << std::endl;
  return strm.str();
}

/*
    Get a string representation of the in_degree list.
        For debugging.
*/
template <typename T> std::string Graph<T>::in_degrees_to_string() const {
  std::ostringstream strm;
  strm << "{" << std::endl;
  for (const auto &entry : in_degree_) {
    strm << "\t" << entry.first << " -> " << entry.second << std::endl;
  }
  strm << "}" << std::endl;
  return strm.str();
}

/*
    Both QISKIT and TKET accept device coupling graphs
    in the form of a Python list of tuples. In QISKIT's
    case, the edges are considered directed.

    Example: K3 Graph
    [[0,1], [1,0], [0,2], [2,0], [1,2], [2,1]]
*/
template <typename T> std::string Graph<T>::to_python_tuple_list() const {
  std::ostringstream strm;

  strm << "[";
  for (const auto &entry : G_) {
    for (const auto &vertex : entry.second) {
      strm << "[" << entry.first << "," << vertex << "],";
    }
  }
  strm.seekp(-1, std::ios_base::end); // Revert before the trailing ','
  strm << "]";
  return strm.str();
}

/*
        Construct a qrane::Graph<int> from a Python-style list of two-tuples of
   integers. The graph is assumed to be directed.
*/
template <typename T>
Graph<T> Graph<T>::read_from_edge_list_file(std::string coupling_path,
                                            bool directed_) {
  Graph<T> ret = Graph<T>(directed_);
  std::ifstream in_strm;
  std::string line, lhs, rhs;

  in_strm.open(coupling_path, std::ios_base::in);
  if (in_strm.is_open()) {
    while (std::getline(in_strm, line)) {
      if (line == "") {
        continue;
      }
      auto space = line.find(" ");
      lhs = line.substr(0, space);
      rhs = line.substr(space + 1);
      auto lhs_id = std::stoi(lhs);
      auto rhs_id = std::stoi(rhs);
      ret.add_edge(lhs_id, rhs_id);
    }
    in_strm.close();
  } else {
    std::cout << "Unable to open coupling graph file. Returning empty Graph.\n";
  }
  return ret;
}

} // namespace qrane

#endif
