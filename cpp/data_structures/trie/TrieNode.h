#include <string>


#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#define ALPHABET_SIZE 26;

template<typename T>
struct TrieNode {
    T val;
    TrieNode* children;

    TrieNode() {
        children = new TrieNode<T>[ALPHABET_SIZE];
        val = NULL;
    }
    ~TrieNode() {
        delete[] children;
    }
};

#endif
