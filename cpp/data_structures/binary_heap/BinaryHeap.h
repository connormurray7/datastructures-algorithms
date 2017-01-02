#include <vector>
#include <functional>

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

template<typename K, typename V, typename C = std::less<K>>
class BinaryHeap {
public:

    BinaryHeap();

    BinaryHeap(const BinaryHeap& other);

    void push(K& key, V& val);

    V& pop(K& key);

    V& top(K& key) const;

    bool empty() const;


private:
    std::vector<HeapNode> table;
};

#endif
