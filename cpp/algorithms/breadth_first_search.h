#include "../data_structures/graph/Graph.h"
#include <queue>
#include <vector>
#include <memory>

template<typename T>
std::vector<T> bfs(Graph<T> graph, int start) {
    std::vector<T> order;
    std::vector<bool> visited;
    std::vector<bool> seen;
    std::queue<int> queue;
    
    visited.resize(graph.size(), false);
    seen.resize(graph.size(), false);
    
    queue.push(start);
    seen[start] = true;
    
    while(!queue.empty()) {
        auto cur = queue.front();
        for(int& edge: graph.nodes[cur]->edges) {
            if(!seen[edge]) {
                queue.push(edge);
                seen[edge] = true;
            }
        }
        visited[cur] = true;
        order.push_back(graph.nodes[cur]->val);
        queue.pop();
    }
    return order;
}

