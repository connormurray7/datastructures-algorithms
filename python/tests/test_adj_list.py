import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.adj_list_graph import AdjListGraph

class AdjListTest(unittest.TestCase):

    def test_find_path(self):
        print("Testing find path")
        g = AdjListGraph()

        g.add_vertex("A")
        g.add_vertex("B")
        g.add_vertex("C")
        g.add_vertex("D")

        g.add_edge("A","B")
        g.add_edge("B","D")
        g.add_edge("A","C")
        g.add_edge("A","B")

        path = g.find_path("A","D")
        print(path)


if __name__ == '__main__':
    unittest.main()
