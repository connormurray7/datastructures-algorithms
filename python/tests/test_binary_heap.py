import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.binary_heap import BinaryHeap

class ArrayTest(unittest.TestCase):

    def test_push(self):
        print("Testing push")
        h = BinaryHeap()

        h.push(1)
        self.assertEqual(h.peek(), 1)

        h.push(2)
        self.assertEqual(h.peek(), 2)

        h.push(0)
        self.assertEqual(h.peek(), 2)

    def test_pop(self):
        print("Testing pop")
        h = BinaryHeap()

        h.push(0)
        h.push(1)
        h.push(2)

        self.assertEqual(h.pop(), 2)
        self.assertEqual(h.pop(), 1)
        self.assertEqual(h.pop(), 0)
        self.assertEqual(h.pop(), None)

    def test_build_heap(self):
        print("Testing build heap")
        h = BinaryHeap()
        list1 = [0, 12, 3, 1, 15, 2, 4]

        h.build_heap(list1)

        self.assertEqual(h.pop(), 15)
        self.assertEqual(h.pop(), 12)
        self.assertEqual(h.pop(), 4)
        self.assertEqual(h.pop(), 3)
        self.assertEqual(h.pop(), 2)
        self.assertEqual(h.pop(), 1)
        self.assertEqual(h.pop(), 0)

        list2 = [45, 3, 10]
        h.build_heap(list2)
        self.assertEqual(h.pop(), 45)
        self.assertEqual(h.pop(), 10)
        self.assertEqual(h.pop(), 3)
        self.assertEqual(h.pop(), None)

    def test_peek(self):
        print("Testing peek")
        h = BinaryHeap()

        h.push(0)
        h.push(1)
        h.push(2)

        self.assertEqual(h.peek(), 2)
        h.pop()
        self.assertEqual(h.peek(), 1)
        h.pop()
        self.assertEqual(h.peek(), 0)
        h.pop()
        self.assertEqual(h.peek(), None)

if __name__ == '__main__':
    unittest.main()
