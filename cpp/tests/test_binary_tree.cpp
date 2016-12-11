#include "catch.hpp"
#include "../data_structures/binary_tree/BinaryTree.cpp"
#include <string>

using std::string;

TEST_CASE("Test insert", "[Binary Tree]" ) {
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
