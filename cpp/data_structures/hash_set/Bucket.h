#include <vector>
#include <memory>

#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
struct HashSetNode {

    HashSetNode(T key_in) {
        key = key_in;
        next = nullptr;
    }

    T key;
    std::shared_ptr<HashSetNode<T>> next;
};

template<typename T>
class Bucket {
public:
    Bucket();

    Bucket(HashSetNode<T>& n);

    bool contains(const T& key);

    void add(const T& key);

    bool remove(const T& key);

    bool isEmpty();

    std::vector<T> get_keys();

private:
    std::shared_ptr<HashSetNode<T>> node;

    std::shared_ptr<HashSetNode<T>> find(const T& val);
};

#endif
