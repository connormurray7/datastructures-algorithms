#pragma once 

#include <vector>
#include "../Bucket.h"

template<typename K, typename V, typename H = std::hash<K>>
class HashMap {
public:

    HashMap();
        //Empty map.

    HashMap(const HashMap& other);
        //Shallow copy.

    V& operator[](const K& key) const;
        //Gets element for key, if exists.
        //Does not check before accessing
        //O(1)

    V& at(const K& key) const;
        //Gets element for key, if exists.
        //Throws out_of_range if does not exist
        //O(1)

    void insert(const K& key, const V& val);
        //Adds key, value pairs to map.
        //O(1) operation amortized

    void erase(const K& key);
        //Removes key values from the map
        //O(1) operation amortized.

    bool contains(const K& key) const;
        //Returns true if key in map.
        //O(1) operation amortized

    unsigned int size() const;
        //Number of elements in container, O(1)

    bool empty() const;
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

    std::vector<Bucket<K>> table;
        //Vector represents the table buckets

    H hash;
        //Hash function used for filling the container.

    unsigned int get_idx(const K& key) const;
        //Returns the index for the key. using
        //the hash function.

    bool too_full() const;
        //If the ratio of elements to the capacity
        //is greater than the load_factor, then
        //returns true.

    void expand();
        //Doubles container capacity and
        //rehashes values.

    void fill_table();
        //Fills the table with empty buckets
        //Used when expanding the table.

};

#include "HashMap-inl.h"
