#include "catch.hpp"
#include "../data_structures/map/Bucket.cpp"
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
    REQUIRE(stringMap.contains("baz"));
    REQUIRE(stringMap.contains("foobar"));
    REQUIRE(stringMap.contains("foobarbaz"));
}
