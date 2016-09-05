"""Written by Connor Murray (connormurray7@gmail.com)
on 9/5/2016

Python implementation of a Trie
"""


class Trie:
    """Python implentation of a Trie.

    Many operations run in O(m) time where 
    m denotes the length of the string key.

    Attributes:


    """

    class Node:
        """Used within Trie to find and store data."""

        def __init__(self, val=None):
            self.children = {}
            self.val = val
        

    def __init__(self):
        self.head = self.Node()

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, val):
        self.set(key,val)

    def get(self, key):
        """Finds val associated with string key, O(m) time"""
        cur = self.head

        for char in key:
            if char in cur.children:
                cur = cur.children[char]
            else:
                return None
        
        return cur.val

    def set(self, key, val):
        cur = self.head

        for char in key:
            if char not in cur.children:
                cur.children[char] = self.Node()
            cur = cur.children[char]
        cur.val = val

    def has_prefix(self, prefix):
        cur = self.head
        for char in prefix:
            if char in cur.children:
                cur = cur.children[char]
            else:
                return False
        return True
