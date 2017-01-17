#include <vector>

#pragma once

template<typename T>
struct GraphNode {

    GraphNode(const T& val_in) {
        val = val_in;
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
    std::vector<int> edges;
};

