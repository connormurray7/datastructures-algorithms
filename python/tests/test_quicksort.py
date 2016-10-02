import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from algorithms.quicksort import *

class QuickSortTest(unittest.TestCase):

    def test_quicksort(self):
        print("Testing Quick Sort")

        nums1 = []
        nums2 = [1]
        nums3 = [6, 4]
        nums4 = [4, 6, 1]
        nums5 = [-1, -2, 1, 0]
        nums6 = [4, 6, 1, 2, 9, 8, 10, 5]

        quicksort(nums1)
        quicksort(nums2)
        quicksort(nums3)
        quicksort(nums4)
        quicksort(nums5)
        quicksort(nums6)

        self.assertListEqual(nums1, sorted(nums1))
        self.assertListEqual(nums2, sorted(nums2))
        self.assertListEqual(nums3, sorted(nums3))
        self.assertListEqual(nums4, sorted(nums4))
        self.assertListEqual(nums5, sorted(nums5))
        self.assertListEqual(nums6, sorted(nums6))

if __name__ == '__main__':
    unittest.main()
