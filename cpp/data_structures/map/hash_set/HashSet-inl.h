#pragma once

#include <iostream>

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
        for(auto& n: b.nodes()) {
            insert(n);
        }
    }
}

template<typename T, typename H>
void HashSet<T,H>::insert(const T& key) {
    ++num_elements;
    if(too_full())  {
        expand();
    }
    auto node = std::make_shared<HashNode<T>>(key);
    table[get_idx(key)].add(node);
}

template<typename T, typename H>
void HashSet<T,H>::erase(const T& key) {
    bool success = table[get_idx(key)].remove(key);
    if(success) {
        --num_elements;
    }
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
    std::vector<Bucket<T>> old_table = table;
    table = std::vector<Bucket<T>>();
    capacity *= 2;
    fill_table();

    for(Bucket<T>& b: old_table) {
        for(auto& n: b.get_nodes()) {
            table[get_idx(n->key)].add(n);
        }
    }
}

template<typename T, typename H>
void HashSet<T,H>::fill_table() {
    table.reserve(capacity);
    for(unsigned int i = 0; i < capacity; ++i) {
        table.push_back(Bucket<T>());
    }
}
