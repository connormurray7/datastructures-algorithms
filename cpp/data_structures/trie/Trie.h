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

    //==============================================//
    //             Member functions
    //==============================================//

    T& operator[](std::string& key);

    T& at(std::string& key);

    void erase(std::string& key);


}




#endif