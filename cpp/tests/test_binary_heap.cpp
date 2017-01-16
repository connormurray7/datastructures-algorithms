#include "catch.hpp"
#include "../data_structures/tree/binary_heap/BinaryHeap.h"
#include <string>

using std::string;

TEST_CASE("Test push/pop and top", "[Binary Heap]" ) {
    BinaryHeap<int, string> intHeap;

    for(int i = 0; i < 1000; ++i) {
        intHeap.push(i, std::to_string(i));
    }
    for(int i = 999; i >= 0; --i) {
        REQUIRE(intHeap.top() == std::to_string(i));
        intHeap.pop();
    }
}

TEST_CASE("Test empty", "[Binary Heap]" ) {
    BinaryHeap<int, string> heap;

    REQUIRE(heap.empty());
    for(int i = 0; i < 1000; ++i) {
        heap.push(i, std::to_string(i));
        REQUIRE(!heap.empty());
    }
    for(int i = 999; i >= 0; --i) {
        REQUIRE(!heap.empty());
        heap.pop();
    }
    REQUIRE(heap.empty());
}
