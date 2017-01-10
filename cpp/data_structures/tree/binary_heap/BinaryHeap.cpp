#include "BinaryHeap.h"
#include <memory>
#include <utility>


template<typename K, typename V, typename C>
BinaryHeap<K,V,C>::BinaryHeap() {
    heap = std::vector<std::unique_ptr<TreeNode<K,V>>>();
    heap.push_back(nullptr); //Not using index 0
    comp = C();
}

template<typename K, typename V, typename C>
BinaryHeap<K,V,C>::BinaryHeap(const BinaryHeap& other) {
    heap = other.heap;
    comp = other.comp;
}

template<typename K, typename V, typename C>
BinaryHeap<K,V,C>::~BinaryHeap() {}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::push(const K& key, const V& val) {
    heap.push_back(std::make_unique<TreeNode<K,V>>(key, val));
    fix_up(heap.size()-1);
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::pop() {
    std::swap(heap[1], heap[heap.size()-1]);
    heap.pop_back();
    fix_down(1);
}

template<typename K, typename V, typename C>
V& BinaryHeap<K,V,C>::top() const {
    return heap[1]->value;
}

template<typename K, typename V, typename C>
bool BinaryHeap<K,V,C>::empty() const {
    return heap.size() == 1; //First entry is not used
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::fix_down(int node_idx) {
    unsigned int size = heap.size()-1;
    unsigned int parent = node_idx;

    while(2*parent <= size) {
        unsigned int child = 2 * parent; //left first
        if(child < size && comp(heap[child]->key, heap[child+1]->key)) {
            ++child; //right child
        }
        if(heap[child]->key < heap[parent]->key) {
            break;
        }
        std::swap(heap[child], heap[parent]);
        parent = child;
    }
}

template<typename K, typename V, typename C>
void BinaryHeap<K,V,C>::fix_up(int node) {
    int cur_node = node;
    while(cur_node > 1 && comp(heap[cur_node/2]->key, heap[cur_node]->key)) {
        std::swap(heap[cur_node], heap[cur_node/2]);
        cur_node /= 2;
    }
}
