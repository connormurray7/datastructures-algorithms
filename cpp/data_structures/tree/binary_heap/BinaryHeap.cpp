#include "BinaryHeap.h"
#include <memory>
#include <utility>


template<typename K, typename V, typename C>
BinaryHeap<K,V,C>::BinaryHeap() {
    table = std::vector<std::unique_ptr<TreeNode<K,V>>>();
    table.push_back(nullptr); //Not using index 0
    comp = C();
}

template<typename K, typename V, typename C>
BinaryHeap<K,V,C>::BinaryHeap(const BinaryHeap& other) {
    table = other.table;
    comp = other.comp;
}

template<typename K, typename V, typename C>
BinaryHeap<K,V,C>::~BinaryHeap() {}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::push(const K& key, const V& val) {
    table.push_back(std::make_unique<TreeNode<K,V>>(key, val));
    fix_up(table.size());
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::pop() {
    std::swap(table[1], table[table.size()-1]);
    table.pop_back();
    fix_down(1);
}

template<typename K, typename V, typename C>
V& BinaryHeap<K,V,C>::top() const {
    return table[1]->value;
}

template<typename K, typename V, typename C>
bool BinaryHeap<K,V,C>::empty() const {
    return table.size() == 0;
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::fix_down(int node_idx) {
    unsigned int parent = node_idx;
    while(parent < table.size()) {
        int child = max_node(parent);
        if(comp(table[parent]->key, table[child]->key)) {
            std::swap(table[parent], table[child]);
        }
        parent = child;
    }
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::fix_up(int node) {
    int parent = node / 2;
    while(parent > 0) {
        int child = max_node(parent);
        if(comp(table[parent]->key, table[child]->key)) {
            std::swap(table[parent], table[child]);
        }
        parent /= 2;
    }
}

template<typename K, typename V, typename C>
int BinaryHeap<K,V,C>::max_node(int parent) {
    if(table[parent*2] == nullptr) {
        return parent;
    }
    if(table[parent*2 + 1] == nullptr) {
        return parent*2;
    }
    if(comp(table[parent*2]->key, table[parent*2 + 1]->key)) {
        return parent*2 + 1;
    }
    return parent*2;
}
