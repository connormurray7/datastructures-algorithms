import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from data_structures.adj_list_graph import AdjListGraph
from algorithms.depth_first_search import *

class DFSTest(unittest.TestCase):

    def test_depth_first_search(self):
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

        order = depth_first_search(g, "A")
        print(str(order))
        self.assertEqual(order[0], "E")
        self.assertEqual(order[1], "D")
        self.assertEqual(order[2], "C")
        self.assertEqual(order[3], "B")
        self.assertEqual(order[4], "A")


if __name__ == '__main__':
    unittest.main()
