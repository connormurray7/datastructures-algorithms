#include "HashMap.h"

template<typename K, typename V, typename H>
HashMap<K,V,H>::HashMap() {

}

template<typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(const HashMap& other) {

}

template<typename K, typename V, typename H>
HashMap<K,V,H>::~HashMap() {}

template<typename K, typename V, typename H>
V& HashMap<K,V,H>::operator[](const K& key) {
    return V();
}

template<typename K, typename V, typename H>
V& HashMap<K,V,H>::at(const K& key) {
    return V();
}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::insert(const K& key, const V& val) {

}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::erase(const T& key) {

}

template<typename K, typename V, typename H>
bool HashMap<K,V,H>::contains(const T& key) {
    return true;
}

template<typename K, typename V, typename H>
unsigned int HashMap<K,V,H>::size() {
    return 0;
}

template<typename K, typename V, typename H>
bool HashMap<K,V,H>::empty() {
    return true;
}

template<typename K, typename V, typename H>
unsigned int HashMap<K,V,H>::get_idx(const T& key) {
    return 0;
}

template<typename K, typename V, typename H>
bool HashMap<K,V,H>::too_full() {
    return true;
}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::expand() {

}

template<typename K, typename V, typename H>
void HashMap<K,V,H>::fill_table() {

}
