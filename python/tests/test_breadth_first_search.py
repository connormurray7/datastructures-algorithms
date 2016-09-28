import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from data_structures.adj_list_graph import AdjListGraph
from algorithms.breadth_first_search import *

class BFSTest(unittest.TestCase):

    def test_breadth_first_search(self):
        print("Testing BFS")
        g = AdjListGraph()

        g.add_vertex("A")
        g.add_vertex("B")
        g.add_vertex("C")
        g.add_vertex("D")
        g.add_vertex("E")

        g.add_edge("A", "B")
        g.add_edge("B", "C")
        g.add_edge("B", "D")
        g.add_edge("D", "E")

        order = breadth_first_search(g, "A")
        print(str(order))
        self.assertEqual(order[0], "A")
        self.assertEqual(order[1], "B")
        self.assertEqual(order[2], "C")
        self.assertEqual(order[3], "D")
        self.assertEqual(order[4], "E")


if __name__ == '__main__':
    unittest.main()
