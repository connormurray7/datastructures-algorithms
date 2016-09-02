import os
import sys
import unittest
from data_structures.hash_map import HashMap
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

class HashMapTest(unittest.TestCase):

    def test_add(self):
        print("Testing add")
        h = HashMap()

        h.add(1, "foo")
        h.add(2, "bar")
        h.add(3, "baz")

        self.assertEqual(h.get(1), "foo")
        self.assertEqual(h.get(2), "bar")
        self.assertEqual(h.get(3), "baz")
        self.assertEqual(h.get(0), None)

        #Chaining
        h.add(17, "foobar")
        self.assertEqual(h.get(17), "foobar")
        self.assertEqual(h.get(1), "foo")

    def test_remove(self):
        print("Testing remove")
        h = HashMap()

        h.add(1, "foo")
        h.add(2, "bar")
        h.add(3, "baz")

        self.assertEqual(h.get(1), "foo")
        h.remove(1)
        self.assertEqual(h.get(1), None)

        h.add(1, "foo")
        self.assertEqual(h.get(1), "foo")


        self.assertEqual(h.get(2), "bar")
        h.remove(2)
        self.assertEqual(h.get(2), None)

    def test_operator_get(self):
        print("Testing operator[] get")
        h = HashMap()

        h.add(1, "foo")
        h.add(2, "bar")
        h.add(3, "baz")

        self.assertEqual(h[1], "foo")
        self.assertEqual(h[2], "bar")
        self.assertEqual(h[4], None)
        self.assertEqual(h[0], None)

    def test_size(self):
        print("Testing size")
        h = HashMap()

        self.assertEqual(h.size, 0)
        h.add(1, "foo")
        self.assertEqual(h.size, 1)
        h.add(2, "bar")
        self.assertEqual(h.size, 2)
        h.remove(2)
        self.assertEqual(h.size, 1)
        h.remove(1)
        self.assertEqual(h.size, 0)

if __name__ == '__main__':
    unittest.main()
