#include "catch.hpp"
#include "../data_structures/trie/Trie.cpp"
#include <string>

TEST_CASE("Test insert, contains", "[Trie]" ) {
    Trie<int> trie;
    
    trie.insert("f", 0);
    trie.insert("fo", 1);
    trie.insert("foo", 3);
    trie.insert("foob", 4);
    trie.insert("fooba", 5);
    trie.insert("foobar", 6);
    trie.insert("b", 7);
    trie.insert("ba", 8);
    trie.insert("baz", 9);

    REQUIRE(trie.contains("f"));
    REQUIRE(trie.contains("fo"));
    REQUIRE(trie.contains("foo"));
    REQUIRE(trie.contains("foob"));
    REQUIRE(trie.contains("fooba"));
    REQUIRE(trie.contains("foobar"));
    REQUIRE(trie.contains("b"));
    REQUIRE(trie.contains("ba"));
    REQUIRE(trie.contains("baz"));
}

TEST_CASE("Test erase", "[Trie]" ) {
    Trie<int> trie;
    
    trie.insert("f", 0);
    trie.insert("fo", 1);
    trie.insert("foo", 3);
    trie.insert("foob", 4);
    trie.insert("fooba", 5);
    trie.insert("foobar", 6);
    trie.insert("b", 7);
    trie.insert("ba", 8);
    trie.insert("baz", 9);
    
    REQUIRE(trie.contains("f"));
    trie.erase("f");
    REQUIRE(!trie.contains("f"));

    REQUIRE(trie.contains("fo"));
    trie.erase("fo");
    REQUIRE(!trie.contains("fo"));

    REQUIRE(trie.contains("foobar"));
    trie.erase("foobar");
    REQUIRE(!trie.contains("foobar"));

    REQUIRE(trie.contains("fooba"));
    trie.erase("fooba");
    REQUIRE(!trie.contains("fooba"));

    REQUIRE(trie.contains("foo"));
    trie.erase("foo");
    REQUIRE(!trie.contains("foo"));

    REQUIRE(trie.contains("foob"));
    trie.erase("foob");
    REQUIRE(!trie.contains("foob"));

    REQUIRE(trie.contains("b"));
    trie.erase("b");
    REQUIRE(!trie.contains("b"));

    REQUIRE(trie.contains("ba"));
    trie.erase("ba");
    REQUIRE(!trie.contains("ba"));
    
    REQUIRE(trie.contains("baz"));
    trie.erase("baz");
    REQUIRE(!trie.contains("baz"));
}
