#pragma once 

#include "../HashNode.h"
#include <memory>

template<typename K, typename V>
class HashMapNode : public HashNode<K> {
public:

    HashMapNode(K key_in, V val_in) : HashNode<K>(key_in) {
        val = val_in;
    }

    V val;
};
