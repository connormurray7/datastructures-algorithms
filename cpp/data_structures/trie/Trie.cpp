#include "Trie.h"

template<typename T>
Trie<T>::Trie() {
    root = std::make_shared<TrieNode<T>>();
}

template<typename T>
Trie<T>::Trie(const Trie& other) {
    root = other.root; //shallow copy.
}

template<typename T>
Trie<T>::~Trie() {}

template<typename T>
T& Trie<T>::operator[](std::string& key) {
    return find_node(key, true)->val;
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
void Trie<T>::insert(std::string& key, T& val) {
    auto node = find_node(key, true);
    node->val = val;
}

template<typename T>
void Trie<T>::erase(std::string& key) {
    std::shared_ptr<TrieNode<T>> last = root;
    std::shared_ptr<TrieNode<T>> cur = root;
    for(char& c: key) {
        cur = cur->children[c - ALPHABET_START];
        if(cur == nullptr) {
            break;
        }
        last = cur;
    }
    last->children[key.back() - ALPHABET_START] = nullptr;
}

template<typename T>
bool Trie<T>::contains(std::string& key) {
    return find_node(key, false) == nullptr;
}

template<typename T>
bool Trie<T>::has_prefix(std::string& prefix) {
    return contains(prefix) == nullptr;
}

template<typename T>
std::shared_ptr<TrieNode<T>> Trie<T>::find_node(std::string& key, bool create_path) {
    std::shared_ptr<TrieNode<T>> cur = root;
    for(char& c: key) {
        if(create_path) {
            cur = cur->get_or_emplace(c);
        }
        else {
            cur = cur->children[c - ALPHABET_START];
            if(cur == nullptr) {
                break;
            }
        }
    }
    return cur;
}
