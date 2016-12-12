#include "catch.hpp"
#include "../data_structures/binary_tree/BinaryTree.cpp"
#include <string>

using std::string;

TEST_CASE("Test insert and at", "[Binary Tree]" ) {
    BinaryTree<int, string> map;

    map.insert(0, "foo");
    REQUIRE(map.at(0) == "foo");

    map.insert(1, "bar");
    REQUIRE(map.at(1) == "bar");

    map.insert(-1, "baz");
    REQUIRE(map.at(-1) == "baz");

    map.insert(2, "foobar");
    REQUIRE(map.at(2) == "foobar");

    map.insert(-2, "foobarbaz");
    REQUIRE(map.at(-2) == "foobarbaz");
}

TEST_CASE("Test operator[]", "[Binary Tree]" ) {
    BinaryTree<int, string> map;

    map.insert(0, "foo");
    REQUIRE(map[0] == "foo");

    map.insert(1, "bar");
    REQUIRE(map[1] == "bar");

    map.insert(-1, "baz");
    REQUIRE(map[-1] == "baz");

    map.insert(2, "foobar");
    REQUIRE(map[2] == "foobar");

    map.insert(-2, "foobarbaz");
    REQUIRE(map[-2] == "foobarbaz");

    map.clear();

    map[0] = "foo";
    REQUIRE(map[0] == "foo");

    map[1] = "bar";
    REQUIRE(map[1] == "bar");

    map[-1] = "baz";
    REQUIRE(map[-1] == "baz");

    map[2] = "foobar";
    REQUIRE(map[2] == "foobar");

    map[-2] = "foobarbaz";
    REQUIRE(map[-2] == "foobarbaz");
}

TEST_CASE("Test clear", "[Binary Tree]" ) {
    BinaryTree<int, string> map;

    map.insert(0, "foo");
    map.insert(1, "bar");
    map.insert(-1, "baz");
    map.insert(2, "foobar");
    map.insert(-2, "foobarbaz");
    REQUIRE(map.at(0) == "foo");
    REQUIRE(map.at(1) == "bar");
    REQUIRE(map.at(-1) == "baz");
    REQUIRE(map.at(2) == "foobar");
    REQUIRE(map.at(-2) == "foobarbaz");

    map.clear();
    REQUIRE_THROWS(map.at(0));
    REQUIRE_THROWS(map.at(1));
    REQUIRE_THROWS(map.at(-1));
    REQUIRE_THROWS(map.at(2));
    REQUIRE_THROWS(map.at(-2));
}
