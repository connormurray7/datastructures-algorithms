#include <vector>
#include <memory>

#ifdef GRAPH_H
#define GRAPH_H

template<typename T>
struct GraphNode {

    GraphNode(const T& val) {
        val = val_in;
        visited = false;
    }

    T val;
    bool visited;
    std::vector<int> edges;
};

template<typename T>
class Graph {
public:

    Graph();

    Graph(const Graph& other);

    ~Graph();

    int add_node(const T& val);

    void add_edge(int node1, node2);

    int size();

    std::vector<GraphNode<T>*> nodes;
};

template<typename T>
Graph<T>::Graph() {
    nodes = std::vector<GraphNode<T>>();
}

template<typename T>
Graph<T>::Graph(const Graph<T>& other) {
    nodes = other.nodes;
}

template<typename T>
Graph<T>::~Graph() {}

template<typename T>
int Graph<T>::add_node(const T& val) {
    int num = nodes.size();
    nodes.push_back(std::make_shared(val));
}




#endif
