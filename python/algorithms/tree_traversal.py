"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementations of tree traversals
"""


def pre_order(root):
    if root is None:
        return
    _process(root)
    pre_order(root.left)
    pre_order(root.right)


def in_order(root):
    if root is None:
        return
    pre_order(root.left)
    _process(root)
    pre_order(root.right)


def post_order(root):
    pre_order(root.left)
    pre_order(root.right)
    _process(root)


def _process(node):
    print(node.val)
