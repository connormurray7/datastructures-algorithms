import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from data_structures.adj_list_graph import AdjListGraph
from algorithms.topological_sort import *

class TopologicalSortTest(unittest.TestCase):

    def test_breadth_first_search(self):
        print("Testing Topological Sort")
        g = AdjListGraph(directed = True)

        g.add_vertex("0")
        g.add_vertex("1")
        g.add_vertex("2")
        g.add_vertex("3")
        g.add_vertex("4")
        g.add_vertex("5")
        g.add_vertex("6")

        g.add_edge("0", "5")
        g.add_edge("0", "2")
        g.add_edge("0", "1")
        g.add_edge("3", "6")
        g.add_edge("3", "5")
        g.add_edge("3", "4")
        g.add_edge("5", "4")
        g.add_edge("6", "4")
        g.add_edge("6", "0")
        g.add_edge("3", "2")
        g.add_edge("1", "4")

        order = topological_sort(g, "0")
        print(str(order))


if __name__ == '__main__':
    unittest.main()
