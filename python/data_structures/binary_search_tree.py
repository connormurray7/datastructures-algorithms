"""Created by Connor Murray (connormurray7@gmail.com)
on 08/30/2016.

A simple binary search tree with NO self-balancing.
"""
from collections import deque


class BinarySearchTree(object):
    """A simple binary search tree with no self-balancing."""

    class Node(object):
        """Node as internal data structure"""
        def __init__(self, key, val):
            self.key = key
            self.val = val
            self.left = None
            self.right = None

    def __init__(self):
        self.head = None

    def __getitem__(self, key):
        """Operator [] overloaded, O(log n) to get"""
        return self.get(key)

    def __setitem__(self, key, val):
        """Operator [] overloaded, O(log n) to set"""
        self.put(key, val)

    def get(self, key):
        """Returns the value for the key given O(log n)"""
        if self.head is None:
            return None
        if self.head.key == key:
            return self.head.val
        cur = self.head
        while cur and cur.key != key:
            if key < cur.key:
                cur = cur.left
            else:
                cur = cur.right
        return None if cur is None else cur.val

    def put(self, key, val):
        """Constructs a node and places it in the tree O(log n)"""
        if self.head is None:
            self.head = self.Node(key, val)
            return
        cur = self.head
        while cur:
            last = cur
            if key < cur.key:
                cur = cur.left
            else:
                cur = cur.right
        if key < last.key:
            last.left = self.Node(key, val)
        else:
            last.right = self.Node(key, val)

    def __str__(self):
        d = deque()
        d.append(self.head)
        vals = []
        while len(d) > 0:
            cur = d.popleft()
            if cur is not None:
                vals.append(str(cur.val))
                d.append(cur.left)
                d.append(cur.right)
        out_str = ' '.join([val for val in vals])
        return "BST [" + out_str + "]"
