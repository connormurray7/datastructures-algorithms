#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

template<typename KEY, typename VALUE>
struct TreeNode {

    KEY key;
    VALUE value;

    std::shared_ptr<TreeNode<KEY,VALUE> > left;
    std::shared_ptr<TreeNode<KEY,VALUE> > right;

    TreeNode(KEY k_in, VALUE v_in)
        : key(k_in), value(v_in) {}

    bool operator<(const TreeNode &other) {
        return key < other.key;
    }

};
#endif
