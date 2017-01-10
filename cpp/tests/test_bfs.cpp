#include <string>
#include "catch.hpp"
#include "../data_structures/graph/Graph.h"
#include "../algorithms/bfs.h"

using std::string;

TEST_CASE("Test bfs", "[BFS]") {
    Graph<string> graph(true);
    int a = graph.add_node("A");
    int b = graph.add_node("B");
    int c = graph.add_node("C");
    int d = graph.add_node("D");
    int e = graph.add_node("E");
    int f = graph.add_node("F");
    int g = graph.add_node("G");
    
    graph.add_edge(a,b);
    graph.add_edge(a,c);
    graph.add_edge(b,d);
    graph.add_edge(b,e);
    graph.add_edge(c,f);
    graph.add_edge(c,g);

    auto vals = bfs(graph, 0);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");
    REQUIRE(vals[5] == "F");
    REQUIRE(vals[6] == "G");

}
