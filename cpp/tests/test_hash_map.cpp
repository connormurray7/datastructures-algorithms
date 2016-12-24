#include "catch.hpp"
#include "../data_structures/map/Bucket.cpp"
#include "../data_structures/map/hash_map/HashMap.cpp"
#include <string>

TEST_CASE("Test insert and []", "[HashSet]" ) {
    HashMap<int, int> intMap;
    HashMap<std::string, int> stringMap;

    for(int i = -10000; i < 10000; ++i) {
        intMap.insert(i, i+1);
    }
    for(int i = -10000; i < 10000; ++i) {
        REQUIRE(intMap[i] == i+1);
    }

    // stringSet.insert("foo");
    // stringSet.insert("bar");
    // stringSet.insert("baz");
    // stringSet.insert("foobar");
    // stringSet.insert("foobarbaz");
    //
    // REQUIRE(stringSet.contains("foo"));
    // REQUIRE(stringSet.contains("bar"));
    // REQUIRE(stringSet.contains("baz"));
    // REQUIRE(stringSet.contains("foobar"));
    // REQUIRE(stringSet.contains("foobarbaz"));
}
