"""Created by Connor Murray (connormurray7@gmail.com)
on 08/30/2016.

A simple binary search tree with NO self-balancing.
"""

class BinarySearchTree:
    """A simple binary search tree with no self-balancing."""

    class Node:
        def __init(self, key, val):
            self.key = key
            self.val = val
            self.left = None
            self.right = None

    def __init__(self):
        self.head = None

    def get(self, key):
        if self.head is None:
            return None
        if self.head.key == key:
            return self.head.val
        cur = self.head
        while cur and cur != key:
            if key < cur.key:
                cur = cur.left
            else:
                cur = cur.right
        return cur

    def put(self, key, val):
        if self.head is None:
            self.head = self.Node(key,val)
        if self.head
