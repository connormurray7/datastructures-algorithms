import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from data_structures.adj_list_graph import AdjListGraph
from algorithms.dijkstra import *

class BFSTest(unittest.TestCase):

    def test_breadth_first_search(self):
        print("Testing Dijkstra")
        g = AdjListGraph(weighted = True)

        g.add_vertex("A")
        g.add_vertex("B")
        g.add_vertex("C")
        g.add_vertex("D")
        g.add_vertex("E")
        g.add_vertex("F")

        g.add_edge("A", "B", 1)
        g.add_edge("A", "C", 4)
        g.add_edge("B", "D", 3)
        g.add_edge("C", "E", 1)
        g.add_edge("E", "D", 2)
        g.add_edge("B", "F", 12)
        g.add_edge("D", "F", 5)

        tup = dijkstra(g, "A")
        dist, prev = tup[0], tup[1]
        self.assertEqual(dist["A"], 0)
        self.assertEqual(dist["B"], 1)
        self.assertEqual(dist["C"], 4)
        self.assertEqual(dist["D"], 4)
        self.assertEqual(dist["E"], 5)
        self.assertEqual(dist["F"], 9)

        self.assertEqual(prev["A"], None)
        self.assertEqual(prev["B"], "A")
        self.assertEqual(prev["C"], "A")
        self.assertEqual(prev["D"], "B")
        self.assertEqual(prev["E"], "C")
        self.assertEqual(prev["F"], "D")


if __name__ == '__main__':
    unittest.main()

