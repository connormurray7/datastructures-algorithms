#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../data_structures/vector/Vector.cpp"
#include <string>

TEST_CASE( "Test push_back", "[vector]" ) {
    Vector<int> v;
    v.push_back(5);
    REQUIRE(v[0] == 5);
}
