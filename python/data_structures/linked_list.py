"""
Created by Connor Murray (connormurray7@gmail.com)
8/21/2016

Python implementation of a linked list
"""

class Node:
    """Every element in linked list is a Node """
    def __init__(self, data=None):
        self.data = data
        self.next = None

    def __str__(self):
        return str(self.data)

class LinkedList:
    """Python implementation of a linked list.

    Attributes:
        head: first node in the list
        size: length of the list
    """

    def __init__(self, head=None, size=0):
        self.head = head
        self.size = size

    def print_list(self):
        """ O(n) time and O(n) extra memory """
        node = self.head
        node_data = []
        while node:
            node_data.append(str(node.data))
            node = node.next
        out_str = ' '.join([d for d in node_data])
        print("LinkedList [" + out_str + "]")

    def front(self):
        """O(1) to get front of list """
        return self.head

    def prepend(self, data):
        """ O(1) insertion in front of list """
        node = Node(data)
        if self.head is not None:
            node.next = self.head
        self.head = node
        self.size += 1

    def append(self, data):
        """ O(n) insertion at end of list """
        self.size += 1
        if self.head is None:
            self.head = Node(data)
            return
        cur = self.head
        last = cur
        while cur:
            last = cur
            cur = cur.next
        last.next = Node(data)

    def remove_front(self):
        """ O(1) removal of front of list """
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
        self.size -= 1

    def remove_back(self):
        """ O(n) removal of back of list """
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
            self.size -= 1
            return
        cur = self.head
        last = cur
        while cur.next:
            last = cur
            cur = cur.next
        last.next = None
        self.size -= 1

    def contains(self, data):
        """ Returns boolean, runs in O(n) time """
        cur = self.head
        while cur:
            if cur.data == data:
                return True
            cur = cur.next
        return False

    def delete(self, data):
        """ O(n) removal by value of element """
        if self.head is None:
            return
        if self.head.data == data:
            self.head = self.head.next
            self.size -= 1
            return
        cur = self.head
        last = cur
        while cur:
            if cur.data == data:
                last.next = cur.next
                self.size -= 1
                return
            last = cur
            cur = cur.next
