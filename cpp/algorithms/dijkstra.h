#include "../data_structures/graph/Graph.h"
#include <vector>
#include <climits>
#include <queue>

struct ShortestPath {
    ShortestPath(int source_in, int size) {
        source = source_in;
        prev.resize(size, -1);
        distance.resize(size, INT_MAX);
    }

    int source;
    std::vector<int> prev;
    std::vector<int> distance;
};

template<typename T>
ShortestPath dijkstra(Graph<T>& graph, int source) {
    ShortestPath shortPath(source, graph.size());
    shortPath.distance[source] = 0;

    auto comp = [](const int& v1, const int& v2) { return dist[v1] < dist[v2]; };
    std::priority_queue<int, std::vector<int>, decltype(comp)> queue(comp);
    for(int i = 0; i < graph.size(); ++i) { 
        queue.push(i); 
    }
    while(!queue.empty()) {
        int cur = queue.top();
        queue.pop();

        for(int& v: graph.nodes[cur]->edges) {
            int dist = shortPath.distance[cur] + 1;
            if(dist < shortPath.distance[v]) {
                shortPath.distance[v] = dist;
                shortPath.prev[v] = cur;
            }
        }
    }
    return shortPath; 
}

