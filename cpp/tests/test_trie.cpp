#include "catch.hpp"
#include "../data_structures/trie/Trie.cpp"
#include <string>

TEST_CASE("Test insert", "[Trie]" ) {
    Trie<std::string> trie;
    std::string s = "hello";
    std::string s2 = "hi";
    
    trie.insert(s, s2);
}
