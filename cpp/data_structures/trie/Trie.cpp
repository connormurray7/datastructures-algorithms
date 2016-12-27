#include "Trie.h"

template<typename T>
Trie<T>::Trie() {}

template<typename T>
Trie<T>::Trie(const Trie& other) {}

template<typename T>
Trie<T>::~Trie() {}

template<typename T>
T& Trie<T>::operator[](std::string& key) {}

template<typename T>
T& Trie<T>::at(std::string& key) {}

template<typename T>
void Trie<T>::erase(std::string& key) {}

template<typename T>
bool Trie<T>::contains(std::string& key) {}

template<typename T>
bool Trie<T>::has_prefix(std::string& prefix) {}