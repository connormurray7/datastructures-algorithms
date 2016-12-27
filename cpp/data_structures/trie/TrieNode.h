#include <string>


#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#define ALPHABET_SIZE 26;

template<typename T>
struct TrieNode {
    T val;
    TrieNode* children[ALPHABET_SIZE];

    TrieNode() {}
    TrieNode(T& val) : key(key), val(val) {}
}

#endif