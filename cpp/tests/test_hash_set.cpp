#include "catch.hpp"
#include "../data_structures/map/Bucket.h"
#include "../data_structures/map/hash_set/HashSet.h"
#include <string>

TEST_CASE("Test insert and contains", "[HashSet]" ) {
    HashSet<int, std::hash<int>> intSet;
    HashSet<std::string, std::hash<std::string>> stringSet;

    for(int i = -1000; i < 1000; ++i) {
        intSet.insert(i);
    }
    for(int i = -1000; i < 1000; ++i) {
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

TEST_CASE("Test erase and contains", "[HashSet]" ) {
    HashSet<int, std::hash<int>> intSet;
    HashSet<std::string, std::hash<std::string>> stringSet;

    intSet.insert(0);
    intSet.insert(1);
    intSet.insert(2);
    intSet.insert(3);
    intSet.insert(4);

    REQUIRE(intSet.contains(0));
    REQUIRE(intSet.contains(1));
    REQUIRE(intSet.contains(2));
    REQUIRE(intSet.contains(3));
    REQUIRE(intSet.contains(4));

    intSet.erase(2);
    REQUIRE(!intSet.contains(2));

    intSet.erase(4);
    REQUIRE(!intSet.contains(4));

    intSet.erase(0);
    REQUIRE(!intSet.contains(0));

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

    stringSet.erase("baz");
    REQUIRE(!stringSet.contains("baz"));

    stringSet.erase("bar");
    REQUIRE(!stringSet.contains("bar"));

    stringSet.erase("foo");
    REQUIRE(!stringSet.contains("foo"));
}

TEST_CASE("Test size and empty", "[HashSet]" ) {
    HashSet<int, std::hash<int>> set;

    for(int i = 0; i < 1000; ++i) {
        REQUIRE(set.size() == i);
        set.insert(i);
        REQUIRE(!set.empty());
    }
    for(int i = 999; i >= 0; --i) {
        REQUIRE(!set.empty());
        set.erase(i);
        REQUIRE(set.size() == i);
    }
    REQUIRE(set.empty());
}
