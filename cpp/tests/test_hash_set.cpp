#include "catch.hpp"
#include "../data_structures/hash_set/HashSet.cpp"
#include <string>

TEST_CASE("Test insert", "[HashSet]" ) {
    HashSet<int> intSet;
    HashSet<std::string> stringSet;

    for(int i = -10000; i < 10000; ++i) {
        intSet.insert(i);
    }
    for(int i = -10000; i < 10000; ++i) {
        REQUIRE(intSet.contains(i));
    }

    stringSet.insert("foo");
    stringSet.insert("bar");
    stringSet.insert("baz");
    stringSet.insert("foobar");
    stringSet.insert("foobarbaz");

    REQUIRE(stringSet.contains("foo"));
    REQUIRE(stringSet.contains("bar"));
    REQUIRE(stringSet.contains("baz"));
    REQUIRE(stringSet.contains("foobar"));
    REQUIRE(stringSet.contains("foobarbaz"));
}

TEST_CASE("Test erase", "[HashSet]" ) {

}

TEST_CASE("Test contains", "[HashSet]" ) {

}

TEST_CASE("Test size", "[HashSet]" ) {

}

TEST_CASE("Test empty", "[HashSet]" ) {

}
