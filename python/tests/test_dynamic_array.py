import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from data_structures.dynamic_array import Array

class ArrayTest(unittest.TestCase):

    def test_append_and_get(self):
        print("Testing append and get")
        a = Array(3)

        a.append(1)
        a.append(2)
        a.append(3)

        self.assertEqual(a.get(), 1)
        self.assertEqual(a.get(), 2)
        self.assertEqual(a.get(), 3)
        self.assertEqual(a.get(), 1)

    def test_operator(self):
        print("Testing operator []")
        a = Array()

        a.append(1)
        self.assertEqual(a[0], 1)

        a.append(2)
        self.assertEqual(a[1], 2)

        a.append(3)
        self.assertEqual(a[0], 1)
        self.assertEqual(a[1], 2)
        self.assertEqual(a[2], 3)



    def test_remove(self):
        print("Testing remove")
        a = Array()

        a.append(1)
        a.append(2)
        a.append(3)

        self.assertEqual(a[0], 1)
        a.remove(0)

        self.assertEqual(a[0], 2)
        self.assertEqual(a[1], 3)

        a.remove(1)
        self.assertEqual(a[0], 2)

if __name__ == '__main__':
    unittest.main()
