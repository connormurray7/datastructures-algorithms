#include "HashSet.h"

template<typename T, typename H>
HashSet<T,H>::HashSet() {
    table = std::vector<Bucket<T>>();
    fill_table();
}

template<typename T, typename H>
HashSet<T,H>::HashSet(const HashSet& other) {
    table = std::vector<Bucket<T>>();
    capacity = other.capacity;
    fill_table();
    for(Bucket<T>& b: other.table) {
        for(auto& key: b.get_keys()) {
            insert(key);
        }
    }
}

template<typename T, typename H>
HashSet<T,H>::~HashSet() {}

template<typename T, typename H>
void HashSet<T,H>::insert(const T& key) {
    ++num_elements;
    if(too_full())  {
        expand();
    }
    table[get_idx(key)].add(key);
}

template<typename T, typename H>
void HashSet<T,H>::erase(const T& key) {
    table[get_idx(key)].remove(key);
}

template<typename T, typename H>
bool HashSet<T,H>::contains(const T& key) {
    return table[get_idx(key)].contains(key);
}

template<typename T, typename H>
unsigned int HashSet<T,H>::size() {
    return num_elements;
}

template<typename T, typename H>
bool HashSet<T,H>::empty() {
    return num_elements == 0;
}

template<typename T, typename H>
unsigned int HashSet<T,H>::get_idx(const T& key) {
    return static_cast<unsigned int>(hash(key)) % capacity;
}

template<typename T, typename H>
bool HashSet<T,H>::too_full() {
    return (num_elements*1.0 / capacity) > load_factor;
}

template<typename T, typename H>
void HashSet<T,H>::expand() {
    capacity *= 2;
    std::vector<Bucket<T>> new_table;

    new_table.reserve(capacity);
    for(Bucket<T>& b: table) {
        for(auto& key: b.get_keys()) {
            new_table[get_idx(key)].add(key);
        }
    }
    table = new_table;
}

template<typename T, typename H>
void HashSet<T,H>::fill_table() {
    table.reserve(capacity);
    for(unsigned int i = 0; i < capacity; ++i) {
        table.push_back(Bucket<T>());
    }
}
