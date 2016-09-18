"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python implementation of a suffix tree based on:
https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/suffixtrees.pdf
"""

class SuffixTree:
    """Python implementation of suffix tree.

    Attributes:

    """

    class SuffixTreeNode:
        def __init__(self, link = None):
            self.children = {}
            if link is not None:
                self.link = link
            else:
                self.link = self

        def make_link(self, char, node):
            self.children[char] = node

    def __init__(self, s):
        self.root = self.build_tree(s)


    def build_tree(self, s):
        if s in None or len(s) == 0:
            return None

        root = SuffixTreeNode()
        longest = SuffixTreeNode(root)
        root.make_link(s[0], longest)

        for char in s[1:]:
            cur = longest
            prev = None

            while(char not in cur.children):

                node = SuffixTreeNode()
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
