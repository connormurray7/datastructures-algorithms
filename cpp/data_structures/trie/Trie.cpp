#include "Trie.h"

#define ALPHABET_START 'a'

template<typename T>
Trie<T>::Trie() {
    root = std::make_shared<TrieNode<T>>();
}

template<typename T>
Trie<T>::Trie(const Trie& other) {
    root = other.root;
}

template<typename T>
Trie<T>::~Trie() {}

template<typename T>
T& Trie<T>::operator[](std::string& key) {
    return find_node(key)->val;
}

template<typename T>
T& Trie<T>::at(std::string& key) {
    auto cur = find_node(key);
    if(cur == nullptr) {
        throw std::out_of_range("Out of range");
    }
    return cur->val;
}

template<typename T>
void Trie<T>::erase(std::string& key) {
    std::shared_ptr<TrieNode<T>> last = root;
    std::shared_ptr<TrieNode<T>> cur = root;
    for(char& c: key) {
        if(cur->val == NULL) {
            break;
        }
        last = cur;
        cur = cur->children[c - ALPHABET_START];
    }
    return cur;
}

template<typename T>
bool Trie<T>::contains(std::string& key) {
    return find_node(key)->val != NULL;
}

template<typename T>
bool Trie<T>::has_prefix(std::string& prefix) {}

template<typename T>
std::unique_ptr<TrieNode<T>> find_node(std::string& key) {
    std::shared_ptr<TrieNode<T>> cur = root;
    for(char& c: key) {
        if(cur->val == NULL) {
            break;
        }
        cur = cur->children[c - ALPHABET_START];
    }
    return cur;
}