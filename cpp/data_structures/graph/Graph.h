#include <vector>
#include <memory>

#ifndef GRAPH_H
#define GRAPH_H


template<typename T>
struct GraphNode {

    GraphNode(const T& val_in) {
        val = val_in;
        visited = false;
    }

    bool containsEdge(int edge) {
        for(auto& e: edges) {
            if(e == edge) {
                return true;
            }
        }
        return false;
    }

    T val;
    bool visited;
    std::vector<int> edges;
};

template<typename T>
class Graph {
public:
    
    typedef std::shared_ptr<GraphNode<T>> node_ptr;
    //==============================================//
    //         Constructors and Destructor
    //==============================================//

    Graph(bool directed);
        //Default ctor, creates empty graph. 
        //Must specify whether it is a directed or 
        //undirected graph.

    Graph(const Graph& other);
        //Copy ctor, shallow copy

    ~Graph();
        //Dtor, shared_ptrs take care of memory release.

    int add_node(const T& val);
        //Appends node to nodes vector and returns the 
        //position (it's id) in the vector. This can be
        //used to create edges between two nodes. O(1).

    void add_edge(int node1, int node2);
        //Creates edge between nodes, if directed, then
        //this creates edge ony from node1 to node2. O(1)

    int size();
        //Number of nodes in graph, O(!)

    std::vector<node_ptr> nodes;
        //List of nodes in the graph. Their index is the
        //"id" of the node.

private:

    bool directed;
        //If directed then edges are not bi-directional.
};

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


#endif
