#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>

template<typename K, typename V>
BinaryTree<K,V>::BinaryTree() {
    root = nullptr;
    num_nodes = 0;
}

//Shallow copy for now.
template<typename K, typename V>
BinaryTree<K,V>::BinaryTree(BinaryTree<K,V> &tree_in) {
    auto data = tree_in.get_nodes();
    std::sort(data.begin(), data.end(), sort_comp);
    root = build_tree(data, 0, data.size());
}

template<typename K, typename V>
BinaryTree<K,V>::~BinaryTree() {}

//  Standard map functions  //
template<typename K, typename V>
V& BinaryTree<K,V>::at(const K& key) {
    auto node = find_node(key);
    if(node == nullptr) {
        throw std::out_of_range("Element does not exist.");
    }
    return node->value;
}

template<typename K, typename V>
V& BinaryTree<K,V>::operator[] (const K& key) {
    auto node = find_node(key);
    if(node == nullptr) {
        node = insert_node(key, V());
    }
    return node->value;
}

template<typename K, typename V>
void BinaryTree<K,V>::insert(const K& key, const V& val) {
    insert_node(key, val);
}

template<typename K, typename V>
std::shared_ptr<Node<K,V>> BinaryTree<K,V>::find_node(const K& key) {
    auto ptr = root;
    while(ptr != nullptr && key != ptr->key) {
        ptr = (key < ptr->key) ? ptr->left : ptr->right;
    }
    return ptr;
}

template<typename K, typename V>
std::shared_ptr<Node<K,V>> BinaryTree<K,V>::insert_node(const K& key, const V& val) {
    std::shared_ptr<Node<K,V>> n = std::make_shared<Node<K,V>>(Node<K,V>(key,val));
    if(!root) {
        root = n;
        return n;
    }
    auto cur = root;
    auto last = cur;
    while(cur) {
        last = cur;
        cur = (n->key < cur->key) ? cur->left : cur->right;
    }
    if(n->key < last->key) {
        last->left = n;
    }
    else {
        last->right = n;
    }
    return n;
}
