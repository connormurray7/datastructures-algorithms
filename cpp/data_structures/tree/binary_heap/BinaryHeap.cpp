#include "BinaryHeap.h"
#include <memory>


template<typename K, typename V, typename C = std::less<K>>
BinaryHeap<K,V,C>::BinaryHeap() {
    table = std::vector<TreeNode<K,V>>();
}

template<typename K, typename V, typename C = std::less<K>>
BinaryHeap<K,V,C>::BinaryHeap(const BinaryHeap& other) {
    table = other.table;
}

template<typename K, typename V, typename C = std::less<K>>
BinaryHeap<K,V,C>::~BinaryHeap() {
    for(auto& i: table) {
        delete i;
    }
}

template<typename K, typename V, typename C = std::less<K>>
void BinaryHeap<K,V,C>::push(K& key, V& val) {
    table.push_back(std::make_unique<TreeNode<K,V>>(key, val));
    fix_up(table.size()-1);
}

template<typename K, typename V, typename C = std::less<K>>
V& BinaryHeap<K,V,C>::pop(K& key) {
    std::swap(table.begin()+1, table.end());
    table.pop_back();
    fix_down(1);
}

template<typename K, typename V, typename C = std::less<K>>
V& BinaryHeap<K,V,C>::top(K& key) const {
    return table[1];
}

template<typename K, typename V, typename C = std::less<K>>
bool BinaryHeap<K,V,C>::empty() const {
    return table.size() == 0;
}

template<typename K, typename V, typename C = std::less<K>>
void BinaryHeap<K,V,C>::fix_down(int node_idx) {
    for(int i = node_idx; i < table.size()/2; ++i) {
        auto node = max_node(i);
        if(table[node_idx] < *node) {
            std::swap(table.begin() + node_idx, node);
        } else {
            break;
        }
    }

}

template<typename K, typename V, typename C = std::less<K>>
void BinaryHeap<K,V,C>::fix_up(int node_idx) {
    int i = node_idx;
    while(i >= 0) {
        auto node = max_node(i);
        if(table[node_idx] < *node) {
            std::swap(table.begin() + node_idx, node);
        }
        i /= 2;
    }
}

