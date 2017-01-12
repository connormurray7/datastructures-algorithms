#include "../data_structures/graph/Graph.h"
#include <stack>
#include <vector>
#include <memory>

//Requires directed acyclic graph. Returns pre-order dfs.
template<typename T>
std::vector<T> dfs(Graph<T>& graph, int start) {
    std::vector<T> order;
    std::vector<bool> visited;
    std::stack<int> stack;
    
    visited.resize(graph.size(), false);
    
    stack.push(start);
    
    while(!stack.empty()) {
        auto cur = stack.top();
        stack.pop();
        if(!visited[cur]) {
            order.push_back(graph.nodes[cur]->val);
        } 
        for(int& edge: graph.nodes[cur]->edges) {
            if(!visited[edge]) {
                stack.push(edge);
            }
        }
    }
    return order;
}


