#include <vector>

#ifdef GRAPH_H
#define GRAPH_H

template<typename T>
struct GraphNode {

    GraphNode(const T& val) : val(val) {}

    T val;
    std::vector<GraphNode<T>> edges;
};

template<typename T>
struct Graph {
    
    Graph() {
        nodes = std::vector<GraphNode<T>>();
    }

    std::vector<GraphNode<T>> nodes;
};



#endif
