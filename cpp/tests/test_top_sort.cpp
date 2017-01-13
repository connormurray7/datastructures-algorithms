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

    graph.add_edge(a,c);
    graph.add_edge(a,b);
    graph.add_edge(b,e);
    graph.add_edge(b,d);
    graph.add_edge(c,g);
    graph.add_edge(c,f);



}

