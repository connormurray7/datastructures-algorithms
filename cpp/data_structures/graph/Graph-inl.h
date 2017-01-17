#pragma once

template<typename T>
Graph<T>::Graph(bool directed_in) {
    nodes = std::vector<node_ptr>();
    directed = directed_in;
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
    nodes.push_back(std::make_shared<GraphNode<T>>(val));
    return num;
}

template<typename T>
void Graph<T>::add_edge(int node1, int node2) {
    nodes[node1]->edges.push_back(node2);
    if(!directed) {
        nodes[node2]->edges.push_back(node1);
    }
}

template<typename T>
int Graph<T>::size() {
    return nodes.size();
}

