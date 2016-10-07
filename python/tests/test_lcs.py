import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(),  os.path.pardir))

from algorithms.longest_common_subsequence import *

class LCSTest(unittest.TestCase):

    def test_lcs(self):
        print("Testing LCS")

        lcs_1 = lcs("abc", "abc")
        lcs_2 = lcs("", "abc")
        lcs_3 = lcs("adc", "abc")
        lcs_4 = lcs("aaa", "aaaaa")
        lcs_5 = lcs("aabasaa", "aabbsaabas")
        
        self.assertEqual(lcs_1, "abc")
        self.assertEqual(lcs_2, "")
        self.assertEqual(lcs_3, "ac")
        self.assertEqual(lcs_4, "aaa")
        self.assertEqual(lcs_5, "aabaaa")

if __name__ == '__main__':
    unittest.main()
