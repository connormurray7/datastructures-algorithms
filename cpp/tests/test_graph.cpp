#include "../data_structures/graph/Graph.h"
#include "catch.hpp"

using std::string;

TEST_CASE("Test add_node", "[Graph]" ) {
    Graph<string> graph(true);

    int a = graph.add_node("A");
    REQUIRE(graph.nodes[a]->val == "A");
    REQUIRE(graph.size() == 1);
    REQUIRE(a == 0);

    int b = graph.add_node("B");
    REQUIRE(graph.nodes[b]->val == "B");
    REQUIRE(graph.size() == 2);
    REQUIRE(b == 1);
    
    int c = graph.add_node("C");
    REQUIRE(graph.nodes[c]->val == "C");
    REQUIRE(graph.size() == 3);
    REQUIRE(c == 2);

    int d = graph.add_node("D");
    REQUIRE(graph.nodes[d]->val == "D");
    REQUIRE(graph.size() == 4);
    REQUIRE(d == 3);

    int e = graph.add_node("E");
    REQUIRE(graph.nodes[e]->val == "E");
    REQUIRE(graph.size() == 5);
    REQUIRE(e == 4); 
}

TEST_CASE("Test add_edge", "[Graph]") {
    Graph<string> graph(true);
    Graph<string> bigraph(false);

    int a = graph.add_node("A");
    int b = graph.add_node("B");
    int c = graph.add_node("C");
    int d = graph.add_node("D");
    int e = graph.add_node("E");

    graph.add_edge(a,b);
    graph.add_edge(a,e);
    graph.add_edge(b,d);
    graph.add_edge(e,c);
    graph.add_edge(d,a);

    REQUIRE(graph.nodes[a]->containsEdge(b));
    REQUIRE(!graph.nodes[b]->containsEdge(a));

    REQUIRE(graph.nodes[a]->containsEdge(e));
    REQUIRE(!graph.nodes[e]->containsEdge(a));

    REQUIRE(graph.nodes[b]->containsEdge(d));
    REQUIRE(!graph.nodes[d]->containsEdge(b));

    REQUIRE(graph.nodes[e]->containsEdge(c));
    REQUIRE(!graph.nodes[c]->containsEdge(e));

    REQUIRE(graph.nodes[d]->containsEdge(a));
    REQUIRE(!graph.nodes[a]->containsEdge(d));

    a = bigraph.add_node("A");
    b = bigraph.add_node("B");
    c = bigraph.add_node("C");
    d = bigraph.add_node("D");
    e = bigraph.add_node("E");

    bigraph.add_edge(a,b);
    bigraph.add_edge(a,e);
    bigraph.add_edge(b,d);
    bigraph.add_edge(e,c);
    bigraph.add_edge(d,a);

    graph.add_edge(d,a);
    REQUIRE(bigraph.nodes[a]->containsEdge(b));
    REQUIRE(bigraph.nodes[b]->containsEdge(a));

    REQUIRE(bigraph.nodes[a]->containsEdge(e));
    REQUIRE(bigraph.nodes[e]->containsEdge(a));

    REQUIRE(bigraph.nodes[b]->containsEdge(d));
    REQUIRE(bigraph.nodes[d]->containsEdge(b));

    REQUIRE(bigraph.nodes[e]->containsEdge(c));
    REQUIRE(bigraph.nodes[c]->containsEdge(e));

    REQUIRE(bigraph.nodes[d]->containsEdge(a));
    REQUIRE(bigraph.nodes[a]->containsEdge(d));
}
