#include <string>
#include "catch.hpp"
#include "../data_structures/graph/Graph.h"
#include "../algorithms/topological_sort.h"

using std::string;

TEST_CASE("Test topological sort", "[BFS]") {
    Graph<string> graph(true);

    int a = graph.add_node("A");
    int b = graph.add_node("B");
    int c = graph.add_node("C");
    int d = graph.add_node("D");
    int e = graph.add_node("E");
    int f = graph.add_node("F");
    int g = graph.add_node("G");

    graph.add_edge(a,b);
    graph.add_edge(b,c);
    graph.add_edge(c,d);
    graph.add_edge(d,e);
    graph.add_edge(e,f);
    graph.add_edge(f,g);

    auto vals = topological_sort(graph);

    REQUIRE(vals[6] == "A");
    REQUIRE(vals[5] == "B");
    REQUIRE(vals[4] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[2] == "E");
    REQUIRE(vals[1] == "F");
    REQUIRE(vals[0] == "G");

    Graph<string> graph2(true);

    a = graph2.add_node("A");
    b = graph2.add_node("B");
    c = graph2.add_node("C");
    d = graph2.add_node("D");
    e = graph2.add_node("E");
    f = graph2.add_node("F");
    g = graph2.add_node("G");

    graph2.add_edge(a,c);
    graph2.add_edge(a,b);
    graph2.add_edge(c,d);
    graph2.add_edge(b,e);
    graph2.add_edge(b,f);
    graph2.add_edge(c,g);

    vals = topological_sort(graph2);

    REQUIRE(vals[6] == "A");
    REQUIRE(vals[5] == "B");
    REQUIRE(vals[4] == "F");
    REQUIRE(vals[3] == "E");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[1] == "G");
    REQUIRE(vals[0] == "D");
}

