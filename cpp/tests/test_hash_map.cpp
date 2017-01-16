#include "catch.hpp"
#include "../data_structures/map/Bucket.h"
#include "../data_structures/map/hash_map/HashMap.cpp"
#include <string>

TEST_CASE("Test insert and []", "[HashSet]" ) {
    HashMap<int, int> intMap;
    HashMap<std::string, int> stringMap;

    for(int i = -1000; i < 1000; ++i) {
        intMap.insert(i, i+1);
    }
    for(int i = -1000; i < 1000; ++i) {
        REQUIRE(intMap.at(i) == i+1);
        REQUIRE(intMap[i] == i+1);
    }

    stringMap.insert("foo", 0);
    stringMap.insert("bar", 1);
    stringMap.insert("baz", 2);
    stringMap.insert("foobar", 3);
    stringMap.insert("foobarbaz", 4);

    REQUIRE(stringMap["foo"] == 0);
    REQUIRE(stringMap["bar"] == 1);
    REQUIRE(stringMap["baz"] == 2);
    REQUIRE(stringMap["foobar"] == 3);
    REQUIRE(stringMap["foobarbaz"] == 4);
}

TEST_CASE("Test contains and erase", "[HashSet]" ) {
    HashMap<int, int> intMap;
    HashMap<std::string, int> stringMap;

    for(int i = -1000; i < 1000; ++i) {
        intMap.insert(i, i+1);
        REQUIRE(intMap.contains(i));
    }
    for(int i = -1000; i < 1000; ++i) {
        intMap.erase(i);
        REQUIRE(!intMap.contains(i));
    }

    stringMap.insert("foo", 0);
    stringMap.insert("bar", 1);
    stringMap.insert("baz", 2);
    stringMap.insert("foobar", 3);
    stringMap.insert("foobarbaz", 4);

    REQUIRE(stringMap.contains("foo"));
    REQUIRE(stringMap.contains("bar"));
    REQUIRE(stringMap.contains("baz"));
    REQUIRE(stringMap.contains("foobar"));
    REQUIRE(stringMap.contains("foobarbaz"));

    stringMap.erase("bar");
    stringMap.erase("baz");
    stringMap.erase("foobar");

    REQUIRE(!stringMap.contains("bar"));
    REQUIRE(!stringMap.contains("baz"));
    REQUIRE(!stringMap.contains("foobar"));
}

TEST_CASE("Test size and empty for map", "[HashMap]" ) {
    HashMap<int, int> map;

    REQUIRE(map.empty());
    for(int i = 0; i < 1000; ++i) {
        REQUIRE(map.size() == i);
        map.insert(i, i);
        REQUIRE(!map.empty());
    }
    for(int i = 999; i >= 0; --i) {
        REQUIRE(!map.empty());
        map.erase(i);
        REQUIRE(map.size() == i);
    }
    REQUIRE(map.empty());
}
