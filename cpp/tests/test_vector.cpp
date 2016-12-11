#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../data_structures/vector/Vector.cpp"
#include <string>

TEST_CASE("Test push_back", "[vector]" ) {
    Vector<int> v;
    v.push_back(0);
    REQUIRE(v[0] == 0);

    v.push_back(-1);
    REQUIRE(v[1] == -1);

    v.push_back(1);
    REQUIRE(v[2] == 1);

    v.push_back(2);
    REQUIRE(v[3] == 2);

    v.push_back(1000);
    REQUIRE(v[4] == 1000);

    v.push_back(-2000);
    REQUIRE(v[5] == -2000);

    v.push_back(3000);
    REQUIRE(v[6] == 3000);

    v.push_back(-4000);
    REQUIRE(v[7] == -4000);

}

TEST_CASE("Test pop_back", "[vector]" ) {
    Vector<int> v;
    v.push_back(0);
    v.push_back(-1);
    v.push_back(1);

    v.push_back(2);
    REQUIRE(v.back() == 2);

    v.pop_back();
    REQUIRE(v.back() == 1);

    v.pop_back();
    v.push_back(0);
    REQUIRE(v.back() == 0);

    v.pop_back();
    REQUIRE(v.back() == -1);

    v.pop_back();
    REQUIRE(v.back() == 0);

}

TEST_CASE("Test size and empty", "[vector]" ) {
    Vector<int> v;

    REQUIRE(v.empty());
    for(int i = 0; i < 10000; ++i) {
        REQUIRE(v.size() == i);
        v.push_back(i);
        REQUIRE(!v.empty());
    }

    for(int i = 10000; i >= 0; --i) {
        REQUIRE(v.size() == i);
        v.pop_back();
    }
    v.pop_back();
    REQUIRE(v.size() == 0);

    v.pop_back();
    REQUIRE(v.size() == 0);

    v.pop_back();
    REQUIRE(v.size() == 0);
}

TEST_CASE("Test front and back", "[vector]" ) {
    Vector<int> v;

    v.push_back(0);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 0);

    v.push_back(-1);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == -1);

    v.push_back(1);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 1);

    v.push_back(2);
    REQUIRE(v.front() == 0);
    REQUIRE(v.back() == 2);

    v.pop_back();
    REQUIRE(v.back() == 1);

    v.pop_back();
    REQUIRE(v.back() == -1);

    v.pop_back();
    REQUIRE(v.back() == 0);
}

TEST_CASE("Test copy constructor", "[vector]" ) {
    Vector<int> v;
    v.push_back(0);
    v.push_back(-1);
    v.push_back(1);
    v.push_back(2);

    Vector<int> v2(v);
    REQUIRE(v2[0] == 0);
    REQUIRE(v2[1] == -1);
    REQUIRE(v2[2] == 1);
    REQUIRE(v2[3] == 2);
}
