import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.binary_search_tree import BinarySearchTree

class HashMapTest(unittest.TestCase):

    def test_get(self):
        print("Testing add")
        b = BinarySearchTree()

        b.put(2, "bar")
        print(str(b))
        b.put(1, "foo")
        print(str(b))
        b.put(3, "baz")
        print(str(b))

        self.assertEqual(b.get(1), "foo")
        self.assertEqual(b.get(2), "bar")
        self.assertEqual(b.get(3), "baz")
        self.assertEqual(b.get(0), None)

if __name__ == '__main__':
    unittest.main()
