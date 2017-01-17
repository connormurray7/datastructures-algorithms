#pragma once

#include <vector>
#include <memory>

#include "GraphNode.h"

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

#include "Graph-inl.h"
