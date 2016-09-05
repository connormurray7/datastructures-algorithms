import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.trie import Trie

class TrieTest(unittest.TestCase):

    def test_insert_find(self):
        print("Testing insert/find")
        t = Trie()

        t["bar"] = 1
        t["baz"] = 2
        t["foo"] = 0

        self.assertEqual(1, t.get("bar"))
        self.assertEqual(0, t.get("foo"))
        self.assertEqual(2, t.get("baz"))

        self.assertEqual(1, t["bar"])
        self.assertEqual(0, t["foo"])
        self.assertEqual(2, t["baz"])

    def test_has_prefix(self):
        print("Testing has prefix")
        t = Trie()

        t["bar"] = 1
        t["baz"] = 2
        t["foo"] = 0

        self.assertEqual(True, t.has_prefix("b"))
        self.assertEqual(True, t.has_prefix("ba"))
        self.assertEqual(True, t.has_prefix("bar"))
        self.assertEqual(True, t.has_prefix("baz"))
        self.assertEqual(True, t.has_prefix("f"))
        self.assertEqual(False, t.has_prefix("bat"))
        self.assertEqual(False, t.has_prefix("a"))


if __name__ == '__main__':
    unittest.main()
