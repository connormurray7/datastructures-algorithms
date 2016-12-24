#include "HashMap.h"
#include "HashMapNode.h"

template<typename K, typename V, typename H>
HashMap<K,V,H>::HashMap() {
    table = std::vector<Bucket<K>>();
    fill_table();
}

template<typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(const HashMap& other) {
    table = std::vector<Bucket<K>>();
    capacity = other.capacity;
    fill_table();
    for(Bucket<K>& b: other.table) {
        for(auto& n: b.nodes()) {
            insert(n);
        }
    }
}

template<typename K, typename V, typename H>
HashMap<K,V,H>::~HashMap() {}

template<typename K, typename V, typename H>
V& HashMap<K,V,H>::operator[](const K& key) const {
    std::shared_ptr<HashNode<K>> n = table[get_idx(key)].get_node(key);
    return static_cast<HashMapNode<K,V>*>(n.get())->val;
}

template<typename K, typename V, typename H>
V& HashMap<K,V,H>::at(const K& key) const {
    std::shared_ptr<HashMapNode<K,V>> n = table[get_idx(key)].get_node(key);
    if(n == nullptr) {
        throw std::out_of_range ("Index out of bounds.");
    }
    return table[get_idx(key)].get_node(key)->val;
}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::insert(const K& key, const V& val) {
    auto n = std::make_shared<HashMapNode<K,V>>(key, val);
    table[get_idx(key)].add(n);
}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const K& key) {
    table[get_idx(key)].remove(key);
}

template<typename K, typename V, typename H>
bool HashMap<K,V,H>::contains(const K& key) const {
    return table[get_idx(key)].contains(key);
}

template<typename K, typename V, typename H>
unsigned int HashMap<K,V,H>::size() const {
    return num_elements;
}

template<typename K, typename V, typename H>
bool HashMap<K,V,H>::empty() const {
    return num_elements == 0;
}

template<typename K, typename V, typename H>
unsigned int HashMap<K,V,H>::get_idx(const K& key) const {
    return static_cast<unsigned int>(hash(key)) % capacity;
}

template<typename K, typename V, typename H>
bool HashMap<K,V,H>::too_full() const {
    return (num_elements*1.0 / capacity) > load_factor;
}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::expand() {
    std::vector<Bucket<K>> old_table = table;
    table = std::vector<Bucket<K>>();
    capacity *= 2;
    fill_table();

    for(Bucket<K>& b: old_table) {
        for(auto& n: b.get_nodes()) {
            table[get_idx(n->key)].add(n);
        }
    }
}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::fill_table() {
    table.reserve(capacity);
    for(unsigned int i = 0; i < capacity; ++i) {
        table.push_back(Bucket<K>());
    }
}
