import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from algorithms.mergesort import *

class MergeSortTest(unittest.TestCase):

    def test_mergesort(self):
        print("Testing Merge Sort")

        nums1 = []
        nums2 = [1]
        nums3 = [6, 4]
        nums4 = [4, 6, 1]
        nums5 = [-1, -2, 1, 0]
        nums6 = [4, 6, 1, 2, 9, 8, 10, 5]

        mergesort(nums1, 0, len(nums1) - 1)
        mergesort(nums2, 0, len(nums2) - 1)
        mergesort(nums3, 0, len(nums3) - 1)
        mergesort(nums4, 0, len(nums4) - 1)
        mergesort(nums5, 0, len(nums5) - 1)
        mergesort(nums6, 0, len(nums6) - 1)

        self.assertListEqual(nums1, sorted(nums1))
        self.assertListEqual(nums2, sorted(nums2))
        self.assertListEqual(nums3, sorted(nums3))
        self.assertListEqual(nums4, sorted(nums4))
        self.assertListEqual(nums5, sorted(nums5))
        self.assertListEqual(nums6, sorted(nums6))

if __name__ == '__main__':
    unittest.main()
