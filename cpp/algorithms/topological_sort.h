#include "../data_structures/graph/Graph.h"
#include <stack>
#include <vector>

//Requires a directed acyclic graph
template<typename T>
std::vector<T> topological_sort(Graph<T>& graph) {
    std::vector<T> order;
    std::vector<bool> visited(graph.size(), false);

    for(int i = 0; i < graph.size(); ++i) {
        if(!visited[i]) {
            topological_sort_helper(graph, i, visited, order);
        }
    }
    return order;
}

template<typename T>
void topological_sort_helper(Graph<T>& graph, int idx, std::vector<bool>& visited, std::vector<T>& order) {
    visited[idx] = true;

    for(int& i: graph.nodes[idx]->edges) {
        if(!visited[idx]) {
            topological_sort_helper(i, visited, order);
        }
    }
    order.push_back(graph.nodes[idx]->val);
}
