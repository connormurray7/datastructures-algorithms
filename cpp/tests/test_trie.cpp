#include "catch.hpp"
#include "../data_structures/trie/Trie.cpp"
#include <string>

TEST_CASE("Test insert", "[Trie]" ) {
    Trie<int> trie;
    
    trie.insert("hello", 0);
    trie.insert("hey", 1);
    trie.insert("hi", 3);
    trie.insert("word", 4);
}
