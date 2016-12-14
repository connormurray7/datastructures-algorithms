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
    HashSet<int> intSet;
    HashSet<std::string> stringSet;

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

    intSet.erase("baz");
    REQUIRE(!intSet.contains("baz"));

    intSet.erase("bar");
    REQUIRE(!intSet.contains("bar"));

    intSet.erase("foo");
    REQUIRE(!intSet.contains("foo"));
}

TEST_CASE("Test contains", "[HashSet]" ) {

}

TEST_CASE("Test size", "[HashSet]" ) {

}

TEST_CASE("Test empty", "[HashSet]" ) {

}
