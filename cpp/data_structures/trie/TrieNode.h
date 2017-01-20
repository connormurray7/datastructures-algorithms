#pragma once

#include <string>
#include <vector>
#include <memory>

#define ALPHABET_START 'a'

template<typename T>
struct TrieNode {

    TrieNode() {
        children = std::vector<std::shared_ptr<TrieNode<T>>>();
        children.resize(ALPHABET_SIZE, nullptr);
        set = false;
    }
    
    std::shared_ptr<TrieNode<T>> get_or_emplace(char letter) {
        int idx = letter - ALPHABET_START;
        if(children[idx] == nullptr) {
            children[idx] = std::make_shared<TrieNode<T>>();
        }
        return children[idx];
    }

    T val;
    bool set;
    std::vector<std::shared_ptr<TrieNode<T>>> children;
    const static int ALPHABET_SIZE = 26;
};
