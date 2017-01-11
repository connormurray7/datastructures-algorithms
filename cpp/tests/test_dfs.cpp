#include <string>
#include "catch.hpp"
#include "../data_structures/graph/Graph.h"
#include "../algorithms/dfs.h"

using std::string;

TEST_CASE("Test dfs", "[BFS]") {

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

    auto vals = dfs(graph, a);
    
    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "D");
    REQUIRE(vals[3] == "E");
    REQUIRE(vals[4] == "C");
    REQUIRE(vals[5] == "F");
    REQUIRE(vals[6] == "G");
}
