#include "../TreeNode.h"
#include <vector>
#include <memory>
#include <functional>


#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

template<typename K, typename V, typename C = std::less<K>>
class BinaryHeap {
public:

    BinaryHeap();

    BinaryHeap(const BinaryHeap& other);

    ~BinaryHeap();

    void push(const K& key, const V& val);

    void pop();

    V& top() const;

    bool empty() const;

private:
    
    std::vector<std::unique_ptr<TreeNode<K,V>>> table;

    void fix_down(int node_idx);

    void fix_up(int node_idx);

    C comp;
};

#endif
