import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.suffix_trie import SuffixTrie

class SuffixTrieTest(unittest.TestCase):

    def test_substring(self):
        print("Testing has substring")
        t = SuffixTrie("foobarbaz")

        self.assertEqual(t.has_substring("barbaz"), True)
        self.assertEqual(t.has_substring("bar"), True)
        self.assertEqual(t.has_substring("foo"), True)
        self.assertEqual(t.has_substring("oob"), True)
        self.assertEqual(t.has_substring("arb"), True)
        self.assertEqual(t.has_substring("foobarba"), True)
        self.assertEqual(t.has_substring("foobarbaz"), True)
        self.assertEqual(t.has_substring("f"), True)
        self.assertEqual(t.has_substring("o"), True)
        self.assertEqual(t.has_substring("a"), True)
        self.assertEqual(t.has_substring("z"), True)

        self.assertEqual(t.has_substring("bz"), False)
        self.assertEqual(t.has_substring("foobarbazz"), False)
        self.assertEqual(t.has_substring("ooo"), False)


    def test_suffix(self):
        print("Testing is suffix")
        t = SuffixTrie("foobarbaz")

        self.assertEqual(t.is_suffix("barbaz"), True)
        self.assertEqual(t.is_suffix("foobarbaz"), True)
        self.assertEqual(t.is_suffix("oobarbaz"), True)

        self.assertEqual(t.is_suffix("bar"), False)
        self.assertEqual(t.is_suffix("foo"), False)
        self.assertEqual(t.is_suffix("foobarba"), False)

if __name__ == '__main__':
    unittest.main()
