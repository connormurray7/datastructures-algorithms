"""
Created by Connor Murray (connormurray7@gmail.com)
9/18/2016

Python implementation of a suffix tree based on:
https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/suffixtrees.pdf
"""


class _SuffixTrieNode:
    """Implementation of node in suffix trie, not meant for external use."""
    def __init__(self, link=None):
        self.children = {}
        if link is not None:
            self.link = link
        else:
            self.link = self

    def make_link(self, char, node):
        self.children[char] = node


class SuffixTrie:
    """Python implementation of suffix tree.

    Uncompressed trie implementation, uses O(n^2) space created in O(n^2) time.

    Attributes:
        _root: Used for traversal, not meant for external use.
    """

    def __init__(self, s):
        """Creates suffix trie for string s."""
        self._root = self._build_tree(s)

    @staticmethod
    def _build_tree(s):
        """Builds trie for string s. Returns root node."""
        if s is None or len(s) == 0:
            return None

        root = _SuffixTrieNode()
        longest = _SuffixTrieNode(root)
        root.make_link(s[0], longest)

        for char in s[1:]:
            cur = longest
            prev = None

            while char not in cur.children:
                node = _SuffixTrieNode()
                cur.make_link(char, node)

                if prev is not None:
                    prev.link = node

                prev = node
                cur = cur.link

            if cur is root:
                prev.link = root
            else:
                prev.link = cur.children[char]

            longest = longest.children[char]

        return root

    def _walk_trie(self, s):
        """Traverses trie for string s, returns final node if s is substring."""
        if s is None or len(s) == 0:
            return None
        cur = self._root
        for char in s:
            if char in cur.children:
                cur = cur.children[char]
            else:
                return None
        return cur 
        
    def has_substring(self, s):
        """True if string is a substring."""
        node = self._walk_trie(s)
        return node is not None

    def is_suffix(self, s):
        """True if string is a suffix.""" 
        node = self._walk_trie(s)
        if node is None:
            return False
        
        return len(node.children) == 0
