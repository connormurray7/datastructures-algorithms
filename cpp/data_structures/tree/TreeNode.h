#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

template<typename K, typename V>
struct TreeNode {

    K key;
    V value;

    std::shared_ptr<TreeNode<K,V> > left;
    std::shared_ptr<TreeNode<K,V> > right;

    TreeNode(K k_in, V v_in)
        : key(k_in), value(v_in) {}

    bool operator<(const TreeNode &other) {
        return key < other.key;
    }

};
#endif
