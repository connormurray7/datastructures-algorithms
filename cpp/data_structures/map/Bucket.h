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

    std::shared_ptr<HashNode<T>> get_node(const T& key) const;

    bool contains(const T& key) const;

    bool remove(const T& key);

    bool empty() const;

    std::vector<T> get_keys() const;

    std::vector<std::shared_ptr<HashNode<T>>> get_nodes() const;

private:
    std::shared_ptr<HashNode<T>> node;

    std::shared_ptr<HashNode<T>> find(const T& val) const;
};

#endif
