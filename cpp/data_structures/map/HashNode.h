#pragma once

#include <memory>

template<typename T>
class HashNode {
public:
    
    HashNode(T key_in) {
        key = key_in;
        next = nullptr;
    }

    T key;
    std::shared_ptr<HashNode<T>> next;
};
