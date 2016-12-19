#ifndef BUCKET_H
#define BUCKET_H

template<typename T>
struct HashSetNode {

    HashSetNode(T& val_in) : val(val_in) {}

    T val;
    HashSetNode* next;
}

template<typename T>
class Bucket {
public:
    Bucket(HashSetNode& n);

    bool contains(T& val);

    void add(T& val);

    void remove(T& val);

    bool isEmpty();

    std::vector<T> get_keys();

private:
    HashSetNode* node;

    HashSetNode* find(T& val);
}

#endif
