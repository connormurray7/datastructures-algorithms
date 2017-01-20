#pragma once

#include <memory>

template<typename K, typename V>
struct TreeNode {

    K key;
    V value;

    std::shared_ptr<TreeNode<K,V> > left = nullptr;
    std::shared_ptr<TreeNode<K,V> > right = nullptr;

    TreeNode(K k_in, V v_in)
        : key(k_in), value(v_in) {}

    bool operator<(const TreeNode &other) {
        return key < other.key;
    }

};
