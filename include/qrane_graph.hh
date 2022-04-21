/*
Qrane
Filename: qrane_deps.hh
Creation date: December 26, 2020
Copyright (C) 2020

This program is free software: you can redistribute it and/or modify
it under the terms of the G_NU G_eneral Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
G_NU G_eneral Public License for more details.

You should have received a copy of the G_NU G_eneral Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QRANE_GRAPH_H
#define QRANE_GRAPH_H

#include <initializer_list>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>

namespace qrane {

    template <typename T>
    using adjacency_t = std::vector<T>;

    template <typename T>
    using graph_t = std::map<T, adjacency_t<T>>;

    template<typename T>
    class Graph {

        private:
            graph_t<T> G_;
            std::map<T, unsigned int> in_degree_;
            bool directed_;

            // Helpers
            std::map<T, unsigned int> initialize_distance_map(T src);

        public:
            Graph();
            Graph(bool directed);
            Graph(std::vector<T>& V, bool directed);
            Graph(std::initializer_list<T>& V, bool directed);

            void add_vertex(T v);
            void add_edge(T v, T u);
            void remove_vertex(T v);
            void remove_edge(T v, T u);
            void remove_vertices(const adjacency_t<T>& v);
            std::vector<T> get_vertex_set();
            std::vector<T> get_frontier();
            std::vector<T> get_neighbors(T v);
        
            typename std::map<T, std::vector<T>>::const_iterator cbegin() const;
            typename std::map<T, std::vector<T>>::const_iterator cend() const;
            typename std::map<T, std::vector<T>>::iterator begin();
            typename std::map<T, std::vector<T>>::iterator end();

            bool empty();
            unsigned int num_vertices();
            unsigned int num_edges();
            std::string to_string();
            std::string in_degree_s_to_string();
            std::string to_python_tuple_list();
            static Graph<T> read_from_edge_list_file(std::string path, bool directed_);

            bool contains_vertex(T v);
            bool contains_edge(T v, T u);
            std::vector<T> vertex_pred(T v);
            std::vector<T> vertex_succ(T v);
            std::vector<T> vertex_adj(T v);

            // Algorithms
            unsigned int unweighted_shortest_path_length(T src, T dst);
            std::vector<T> topological_ordering();
            unsigned int longest_path();
    };

    /*
        Default constructor.
    */
    template <typename T>
    Graph<T>::Graph() {
        directed_ = true; 
    };

    /*
        Constructor with directed_ boolean.
    */
    template <typename T> 
    Graph<T>::Graph(bool directed_) {
        directed_ = directed_;
    }

    /*
        Add all vertices in vertex_set to the graph
        with in-degree zero.
    */
    template <typename T> 
    Graph<T>::Graph(std::vector<T>& vertex_set, bool directed_) {
        directed_ = directed_;

        //G_.reserve(vertex_set.size());
        G_ = graph_t<T>();
        for (const T& v : vertex_set) {
            add_vertex(v);
        }
    }

    template <typename T> 
    Graph<T>::Graph(std::initializer_list<T>& vertex_set, bool directed_) {
        directed_ = directed_;

        //G_.reserve(vertex_set.size());
        G_ = graph_t<T>();
        for (const T& v : vertex_set) {
            add_vertex(v);
        }
    }

    /*
        Add vertex v to the graph with in-degree zero.
    */
    template <typename T> 
    void Graph<T>::add_vertex(T v) {
        G_.insert(std::make_pair(v, std::vector<T>()));
        in_degree_.insert(std::make_pair(v, 0));
    }

    /*
        Add the edge (v, u) to the graph. Vertex v
        is added to the graph if not already present.
    */
    template <typename T> 
    void Graph<T>::add_edge(T v, T u) {
        if (!G_.count(v)) {
            add_vertex(v);
        }
        if (!G_.count(u)) {
            add_vertex(u);
        }

        bool v_already = std::find(G_[v].begin(), G_[v].end(), u) != G_[v].end();
        bool u_already = std::find(G_[u].begin(), G_[u].end(), v) != G_[u].end();
        if (!v_already && !u_already) {
            G_[v].push_back(u);
            in_degree_[u] += 1;
            if (!directed_) { 
                G_[u].push_back(v);
                in_degree_[v] += 1; 
            }
        }
    }

    /*
        Remove vertex v from the graph, if it exists.
    */
    template <typename T> 
    void Graph<T>::remove_vertex(T v) {
        if (G_.count(v)) {

            // Decrement in_degree_ of all neighbors of vertex v
            // Operation is identical for directed_ and undirected_ graphs
            for (const T& n : get_neighbors(v)) {
                in_degree_[n] -= 1;
            }

            // Remove any reference to v in an adjacency list
            for (auto& entry : G_) {
                auto it = std::find(entry.second.begin(), entry.second.end(), v);
                if (it != entry.second.end()) {
                    entry.second.erase(it);
                }
            }

            // Remove v from the graph and in_degree_ map
            G_.erase(v);
            in_degree_.erase(v);
        }
    }

    /*
        Remove vertex v from the graph, if it exists.
    */
    template <typename T> 
    void Graph<T>::remove_vertices(const adjacency_t<T>& vertices) {
        for (const auto& v : vertices) {
            if (G_.count(v)) {

                // Decrement in_degree_ of all neighbors of vertex v
                // Operation is identical for directed_ and undirected_ graphs
                for (const T& n : get_neighbors(v)) {
                    in_degree_[n] -= 1;
                }

                // Remove any reference to v in an adjacency list
                for (auto& entry : G_) {
                    auto it = std::find(entry.second.begin(), entry.second.end(), v);
                    if (it != entry.second.end()) {
                        entry.second.erase(it);
                    }
                }

                // Remove v from the graph and in_degree_ map
                G_.erase(v);
                in_degree_.erase(v);
            }
        }
    }

    /*
        Remove edge (v, u) from the graph, if it exists.
    */
    template <typename T> 
    void Graph<T>::remove_edge(T v, T u) {
        if (G_.count(v)) {
            if (std::find(G_[v].begin(), G_[v].end(), u) != G_[v].end()) {
                G_[v].erase(u);
                in_degree_[u] -= 1;
                if (!directed_) {
                    G_[u].erase(v); 
                    in_degree_[v] -= 1; 
                }
            }
        }
    }

    /*
        G_et a copy of the vertex set of the graph.
    */
    template <typename T>
    std::vector<T> Graph<T>::get_vertex_set() {
        std::vector<T> vertex_set;
        for (const auto entry : G_) {
            vertex_set.push_back(entry.first);
        }
        return vertex_set;
    }

    /*
        G_et a copy of the neighboring vertices of
        vertex v. Return an empty std::vector<T> 
        if v is not present in the graph.
    */
    template <typename T>
    std::vector<T> Graph<T>::get_neighbors(T v) {
        if (G_.count(v)) {
            return G_[v];
        } else {
            return std::vector<T>();
        }
    }

    /*
        G_et the frontier of the graph, that is, the set
        of vertices of zero in-degree.
    */
    template <typename T>
    std::vector<T> Graph<T>::get_frontier() {
        std::vector<T> frontier;
        for (const auto& entry : in_degree_) {
            if (entry.second == 0) {
                frontier.push_back(entry.first);
            }
        }
        return frontier;
    }

    template <typename T>
    unsigned int Graph<T>::num_vertices() {
        return G_.size();
    }

    template <typename T>
    unsigned int Graph<T>::num_edges() {
        unsigned int cnt = 0;
        for (const auto& entry : G_) {
            for (const auto& neighbor : G_) {
                cnt += 1;
            }
        }
        if (!directed_) { cnt /= 2; }
        return cnt;
    }

    template <typename T>
    bool Graph<T>::contains_vertex(T v) {
        return G_.count(v);
    }

    template <typename T>
    bool Graph<T>::contains_edge(T v, T u) {
        if (G_.count(v) && G_.count(u)) {
            //return G_[v].count(u);
            return std::find(G_[v].begin(), G_[v].end(), u) != G_[v].end();
        }
        return false;
    }

    /*
        Check if the graph is empty.
    */
    template <typename T>
    bool Graph<T>::empty() {
        return G_.empty();
    }

    template <typename T>
    typename std::map<T, std::vector<T>>::const_iterator
        Graph<T>::cbegin() const {
        return G_.cbegin();
    }

    template <typename T>
    typename std::map<T, std::vector<T>>::const_iterator
        Graph<T>::cend() const {
        return G_.cend();
    }

    template <typename T>
    typename std::map<T, std::vector<T>>::iterator
        Graph<T>::begin() {
        return G_.begin();
    }

    template <typename T>
    typename std::map<T, std::vector<T>>::iterator
        Graph<T>::end() {
        return G_.end();
    }

    /*
        G_et a string representation of the adjacency list.
    */
    template <typename T>
    std::string Graph<T>::to_string() {
        std::ostringstream strm;
        strm << "{" << std::endl;
        for (const auto& entry : G_) {
            strm << "\t" << entry.first << " -> [ ";
            for (const auto& vertex : entry.second) {
                strm << vertex << " ";
            }
            strm << "]" << std::endl;
        }
        strm << "}" << std::endl;
        return strm.str();
    }

    /*
        G_et a string representation of the adjacency list.
    */
    template <typename T>
    std::string Graph<T>::in_degree_s_to_string() {
        std::ostringstream strm;
        strm << "{" << std::endl;
        for (const auto& entry : in_degree_) {
            strm << "\t" << entry.first << " -> " << entry.second << std::endl;
        }
        strm << "}" << std::endl;
        return strm.str();
    }

    /*
        Both QISKIT and TKET accept device coupling graphs
        in the form of a Python list of tuples. In QISKIT's
        case, the edges are considered directed_.

        Example: K3
        [[0,1], [1,0], [0,2], [2,0], [1,2], [2,1]]
    */
    template <typename T>
    std::string Graph<T>::to_python_tuple_list() {
        std::ostringstream strm;

        strm << "[";
        for (const auto& entry : G_) {
            for (const auto& vertex : entry.second) {
                strm << "[" << entry.first << "," << vertex << "],";
            }
        }
        strm.seekp(-1, std::ios_base::end); // Revert before the trailing ','
        strm << "]";
        return strm.str();
    }

    /*
        G_et the predecessors of a vertex. If the graph
        is undirected_, the result of vertex_pred is
        equivalent to vertex_adj.
    */
    template <typename T>
    std::vector<T> Graph<T>::vertex_pred(T v) {
        auto pred = std::vector<T>();
        for (const auto& entry : G_) {
            for (const auto& neighbor : entry.second) {
                if (neighbor == v) {
                    pred.push_back(entry.first);
                }
            }
        }
        return pred;
    }

    /*
        G_et the successors of a vertex. If the graph
        is undirected_, the result of vertex_succ is
        equivalent to vertex_adj.
    */
    template <typename T>
    std::vector<T> Graph<T>::vertex_succ(T v) {
        if (G_.count(v)) {
            return G_[v];
        } else {
            return std::vector<T>();
        }
    }

    /*
        G_et the neighbors of a vertex. If the graph
        is directed_, the result of vertex_adj is
        equivalent to vertex_succ.
    */
    template <typename T>
    std::vector<T> Graph<T>::vertex_adj(T v) {
        if (G_.count(v)) {
            return G_[v];
        } else {
            return std::vector<T>();
        }
    }

    template <typename T>
    unsigned int Graph<T>::unweighted_shortest_path_length(T src, T dst) {
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
            for (const auto& n : vertex_succ(front.first)) {
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
    template <typename T>
    std::vector<T> Graph<T>::topological_ordering() {
        Graph H = G_;
        std::vector<T> L; L.reserve(H.num_vertices());
        std::vector<T> S = H.get_frontier();

        while (!S.empty()) {
            T n = *S.begin();
            L.push_back(n);
            S.erase(S.begin());
            
            for (const auto& m : H.vertex_adj(n)) {
                H.remove_edge(n, m);
                if (H.vertex_in_degree_(m) == 0) {
                    S.insert(m);
                }
            }
        }

        if (H.num_edges()) {
            std::cout << "Graph has a cycle. Returning empty vector." << std::endl;
            return std::vector<T>();
        } else {
            return L;
        }
    }

    template <typename T>
    std::map<T, unsigned int> Graph<T>::initialize_distance_map(T src) {
        auto dist = std::map<T, unsigned int>();
        dist.reserve(num_vertices());
        auto min = std::numeric_limits<unsigned int>::min();
        for (const auto& v : get_vertex_set()) {
            dist[v] = min;
        }
        dist[src] = 0;
        return dist;
    }

    template <typename T>
    unsigned int Graph<T>::longest_path() {
        auto ordering = topological_ordering();
        auto dist = initialize_distance_map(*ordering.begin());

        for (const auto& u : ordering) {
            for (const auto& v : vertex_adj(u)) {
                if (dist[v] < dist[u] + 1)
                    dist[v] = dist[u] + 1;
            }
        }
        
        auto max_it = std::max_element(dist.begin(), dist.end(),
            [] (const std::pair<T, unsigned int>& a, const std::pair<T,unsigned int>& b) 
            -> bool { return a.second < b.second; });
        return max_it->second;
    }

    template <typename T>
    Graph<T> Graph<T>::read_from_edge_list_file(std::string coupling_path, bool directed_) {
        Graph<T> ret = Graph<T>(directed_);
        std::ifstream in_strm;
        std::string line, lhs, rhs;

        in_strm.open(coupling_path, std::ios_base::in);
        if (in_strm.is_open()) {
            while(std::getline(in_strm, line)) {
                if (line == "") { continue; }
                auto space = line.find(" ");
                lhs = line.substr(0, space);
                rhs = line.substr(space+1);
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

}

#endif