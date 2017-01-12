#include <string>
#include "catch.hpp"
#include "../data_structures/graph/Graph.h"
#include "../algorithms/breadth_first_search.h"

using std::string;

TEST_CASE("Test bfs on directed graph", "[BFS]") {
    Graph<string> graph(true);
    int a = graph.add_node("A");
    int b = graph.add_node("B");
    
    graph.add_edge(a,b);
    auto vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");

    int c = graph.add_node("C");
    graph.add_edge(a,c);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");

    int d = graph.add_node("D");
    graph.add_edge(b,d);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");

    int e = graph.add_node("E");
    graph.add_edge(b,e);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");

    int f = graph.add_node("F");
    graph.add_edge(c,f);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");
    REQUIRE(vals[5] == "F");

    int g = graph.add_node("G");
    graph.add_edge(c,g);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");
    REQUIRE(vals[5] == "F");
    REQUIRE(vals[6] == "G");

    Graph<string> graph2(true);
    a = graph2.add_node("A");
    b = graph2.add_node("B");
    c = graph2.add_node("C");
    d = graph2.add_node("D");
    e = graph2.add_node("E");
    f = graph2.add_node("F");
    g = graph2.add_node("G");
    
    graph2.add_edge(a,g);
    graph2.add_edge(g,c);
    graph2.add_edge(c,a);
    graph2.add_edge(c,d);
    graph2.add_edge(d,e);
    graph2.add_edge(e,b);
    graph2.add_edge(e,f);

    auto vals2 = bfs(graph2, 0);

    REQUIRE(vals2[0] == "A");
    REQUIRE(vals2[1] == "G");
    REQUIRE(vals2[2] == "C");
    REQUIRE(vals2[3] == "D");
    REQUIRE(vals2[4] == "E");
    REQUIRE(vals2[5] == "B");
    REQUIRE(vals2[6] == "F");
}

TEST_CASE("Test bfs on undirected graph", "[BFS]") {
    Graph<string> graph(false);
    int a = graph.add_node("A");
    int b = graph.add_node("B");
    
    graph.add_edge(b,a);
    auto vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");

    int c = graph.add_node("C");
    graph.add_edge(a,c);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");

    int d = graph.add_node("D");
    graph.add_edge(d,b);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");

    int e = graph.add_node("E");
    graph.add_edge(e,b);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");

    int f = graph.add_node("F");
    graph.add_edge(f,c);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");
    REQUIRE(vals[5] == "F");

    int g = graph.add_node("G");
    graph.add_edge(c,g);

    vals = bfs(graph, a);

    REQUIRE(vals[0] == "A");
    REQUIRE(vals[1] == "B");
    REQUIRE(vals[2] == "C");
    REQUIRE(vals[3] == "D");
    REQUIRE(vals[4] == "E");
    REQUIRE(vals[5] == "F");
    REQUIRE(vals[6] == "G");

    Graph<string> graph2(false);
    a = graph2.add_node("A");
    b = graph2.add_node("B");
    c = graph2.add_node("C");
    d = graph2.add_node("D");
    e = graph2.add_node("E");
    f = graph2.add_node("F");
    g = graph2.add_node("G");
    
    graph2.add_edge(a,g);
    graph2.add_edge(g,c);
    graph2.add_edge(c,a);
    graph2.add_edge(c,d);
    graph2.add_edge(d,e);
    graph2.add_edge(e,b);
    graph2.add_edge(e,f);

    auto vals2 = bfs(graph2, 0);

    REQUIRE(vals2[0] == "A");
    REQUIRE(vals2[1] == "G");
    REQUIRE(vals2[2] == "C");
    REQUIRE(vals2[3] == "D");
    REQUIRE(vals2[4] == "E");
    REQUIRE(vals2[5] == "B");
    REQUIRE(vals2[6] == "F");
}
