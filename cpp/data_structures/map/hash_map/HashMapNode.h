#include "../HashNode.h"
#include <memory>

#ifndef HASHMAPNODE_H
#define HASHMAPNODE_H

template<typename K, typename V>
class HashMapNode : public HashNode {
public:

    HashMapNode(K key_in, V val_in) : HashNode(val_in) {
        key = key_in;
        val = val_in;
    }

    V val;
};

#endif
