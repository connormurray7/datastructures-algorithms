#include "TrieNode.h"
#include <string>

#ifndef TRIE_H
#define TRIE_H

template<typename T>
class Trie {
public:

    //==============================================//
    //         Constructors and Destructor
    //==============================================//

    Trie();
        //Requires nothing, creates empty trie.

    Trie(const Trie& other);
        //Copy constructor, shallow copy.

    ~Trie();
        //Does nothing unique ptr takes care of deletion.

    //==============================================//
    //             Member functions
    //==============================================//

    T& operator[](const std::string& key);
        //Returns val for associated key,
        //O(k) time where k is len of key.

    T& at(const std::string& key);
        //Returns val for associated key,
        //Will throw out of bounds if key 
        //does not exist.
        //O(k) time where k is len of key.
    
    void insert(const std::string& key, const T& val);
        //Inserts value for key.
        //O(k) time where k is len of key.

    void erase(const std::string& key);
        //Removes val for associated key,
        //O(k) time where k is len of key.

    bool contains(const std::string& key);
        //True if key existsin Trie.
        //O(k) time where k is len of key.

    bool has_prefix(const std::string& prefix);
        //True if prefix exists in Trie.
        //O(p) time where p is len of prefix.

private:

    //==============================================//
    //           Implementation Details 
    //==============================================//

    std::shared_ptr<TrieNode<T>> find_node(const std::string& key, bool create_path);
        //Traverses tree, returns node for key.
        //If node does not exist, constructs nodes
        //along the way. O(k) time.

    std::shared_ptr<TrieNode<T>> root;
        //Root of the tree.
};

#endif
