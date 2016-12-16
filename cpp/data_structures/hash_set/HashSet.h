#include <vector>

#ifndef HASHSET_H
#define HASHSET_H

template<typename T, typename H = std::hash<T>>
class HashSet {
public:

    HashSet();
    HashSet(const HashSet& other);

    void insert(const T& key);
    void erase(const T& key);
    bool contains(const T& key);

    unsigned int size();
    bool empty();

private:

    unsigned int capacity = 16;

    std::vector<T> table;

    H hash;
}

#endif
