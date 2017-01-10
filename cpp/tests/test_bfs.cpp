#include <string>
#include "catch.hpp"
#include "../data_structures/graph/Graph.h"
#include "../algorithms/bfs.h"

using std::string;

REQUIRE("Test bfs", "[BFS]") {
    Graph<string> graph;
    graph.add_node("A");
    auto vals = bfs(graph, 0);

}
