#include "HashSet.h"

template<typename T, typename H>
HashSet<T,H>::HashSet() {
    table = std::vector<Bucket<T>>();
    table.reserve(capacity);

}

template<typename T, typename H>
HashSet<T,H>::HashSet(const HashSet& other) {
    this.table = std::vector<Bucket<T>>();
    this.table.reserve(other.capacity);
    for(Bucket<T>& i: other.table) {
        for(auto& key: i.get_keys()) {
            insert(key)
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
bool HashSet<T,H>::too_full() {
    return (num_elements*1.0 / capacity) > load_factor;
}
