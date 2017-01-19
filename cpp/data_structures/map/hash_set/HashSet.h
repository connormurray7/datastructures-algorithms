#pragma once

#include <vector>
#include "../Bucket.h"

template<typename T, typename H = std::hash<T>>
class HashSet {
public:

    HashSet();
        //Empty HashSet

    HashSet(const HashSet& other);
        //Shallow copy.

    void insert(const T& key);
        //Adds key to the set.
        //O(1) operation amortized

    void erase(const T& key);
        //Removes key from the set
        //O(1) operation amortized.

    bool contains(const T& key);
        //Returns true if key in set.
        //O(1) operation amortized

    unsigned int size();
        //Number of elements in container, O(1)

    bool empty();
        //True if no elements.

private:

    unsigned int num_elements = 0;
        //Number of elements in container

    unsigned int capacity = 16;
        //Size of the container, doubles
        //when load factor is reached

    double load_factor = 0.75;
        //Maximum ratio of used spots in
        //the table

    std::vector<Bucket<T>> table;
        //Vector represents the table buckets

    H hash;
        //Hash function used for filling the container.

    unsigned int get_idx(const T& key);
        //Returns the index for the key. using
        //the hash function.

    bool too_full();
        //If the ratio of elements to the capacity
        //is greater than the load_factor, then
        //returns true.

    void expand();
        //Doubles container capacity and
        //rehashes values.

    void fill_table();

};

#include "HashSet-inl.h"
