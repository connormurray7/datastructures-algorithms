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

    bool contains(const T& key);

    void add(const T& key);

    bool remove(const T& key);

    bool isEmpty();

    std::vector<T> get_keys();

private:
    std::shared_ptr<HashNode<T>> node;

    std::shared_ptr<HashNode<T>> find(const T& val);
};

#endif
