#include <vector>


#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
struct HashSetNode {

    HashSetNode(T& val_in) : val(val_in) {}

    T val;
    HashSetNode* next;
};

template<typename T>
class Bucket {
public:
    Bucket(HashSetNode<T>& n);

    bool contains(const T& val);

    void add(const T& val);

    void remove(const T& val);

    bool isEmpty();

    std::vector<T> get_keys();

private:
    HashSetNode<T>* node;

    HashSetNode<T>* find(T& val);
};

#endif
