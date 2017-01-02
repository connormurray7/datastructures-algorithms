#include "BinaryHeap.h"


template<typename K, typename V, typename C = std::less<K>>
BinaryHeap<K,V,C>::BinaryHeap() {
    table = std::vector<HeapNode<K,V>>();
}

template<typename K, typename V, typename C = std::less<K>>
BinaryHeap<K,V,C>::BinaryHeap(const BinaryHeap& other) {
    table = other.table;
}

template<typename K, typename V, typename C = std::less<K>>
void BinaryHeap<K,V,C>::push(K& key, V& val);

template<typename K, typename V, typename C = std::less<K>>
V& BinaryHeap<K,V,C>::pop(K& key);

template<typename K, typename V, typename C = std::less<K>>
V& BinaryHeap<K,V,C>::top(K& key) const {
    return table[1];
}

template<typename K, typename V, typename C = std::less<K>>
bool BinaryHeap<K,V,C>::empty() const {
    return table.size() == 0;
}

