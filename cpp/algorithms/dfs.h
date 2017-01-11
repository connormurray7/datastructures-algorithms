#include "../data_structures/graph/Graph.h"
#include <stack>
#include <vector>
#include <memory>

//Requires directed acyclic graph.
template<typename T>
std::vector<T> dfs(Graph<T>& graph, int start) {
    std::vector<T> order;
    std::vector<bool> visited;
    std::vector<bool> seen;
    std::stack<int> stack;
    
    visited.resize(graph.size(), false);
    seen.resize(graph.size(), false);
    
    stack.push(start);
    seen[start] = true;
    
    while(!stack.empty()) {
        auto cur = stack.top();
        for(int& edge: graph.nodes[cur]->edges) {
            if(!seen[edge]) {
                stack.push(edge);
                seen[edge] = true;
            }
        }
        visited[cur] = true;
        order.push_back(graph.nodes[cur]->val);
        stack.pop();
    }
    return order;
}


