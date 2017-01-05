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
    fix_up(table.size()-1);
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
    return table.size() == 1; //First entry is not used
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::fix_down(int node_idx) {
    unsigned int size = table.size()-1;
    unsigned int parent = node_idx;

    while(2*parent <= size) {
        unsigned int child = 2 * parent; //left first
        if(child < size && comp(table[child]->key, table[child+1]->key)) {
            ++child; //right child
        }
        if(table[child]->key < table[parent]->key) {
            break;
        }
        std::swap(table[child], table[parent]);
        parent = child;
    }
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::fix_up(int node) {
    int cur_node = node;
    while(cur_node > 1 && comp(table[cur_node/2]->key, table[cur_node]->key)) {
        std::swap(table[cur_node], table[cur_node/2]);
        cur_node /= 2;
    }
}
