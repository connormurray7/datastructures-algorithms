#ifndef NODE_H
#define NODE_H

#include <memory>

template<typename KEY, typename VALUE>
struct Node {

    KEY key;
    VALUE value;

    std::shared_ptr<Node<KEY,VALUE> > left;
    std::shared_ptr<Node<KEY,VALUE> > right;

    Node(KEY k_in, VALUE v_in)
        : key(k_in), value(v_in) {}

    bool operator<(const Node &other) {
        return key < other.key;
    }

};
#endif
