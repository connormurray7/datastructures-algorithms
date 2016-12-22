#include "HashNode.h"
#include <vector>
#include <memory>

#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
class Bucket {
public:
    Bucket();

    Bucket(HashNode<T>& n);

    void add(std::shared_ptr<HashNode<T>> node);

    std::shared_ptr<HashNode<T>> get_node(const T& key);

    bool contains(const T& key);

    bool remove(const T& key);

    bool empty();

    std::vector<T> get_keys();

    std::vector<std::shared_ptr<HashNode<T>>> get_nodes();

private:
    std::shared_ptr<HashNode<T>> node;

    std::shared_ptr<HashNode<T>> find(const T& val);
};

#endif
