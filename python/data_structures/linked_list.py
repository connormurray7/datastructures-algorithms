"""
Created by Connor Murray (connormurray7@gmail.com)
8/21/2016

Simple Python implementation of a linked list
"""

class Node:
    """Every element in linked list is a Node """
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

class LinkedList:
    """Simple implementation of a linked list.
    
    Attributes:
        head: first node in the list
        size: length of the list
    """

    def __init__(self, head=None, size=0):
        self.head = head
        self.size = size

    def print_list(self):
        node = self.head
        datas = []
        while node:
            datas += node.data
            node = node.next
        out_str = ''.join("LinkedList [", [str(d) for d in datas ],"]")
        print(out_str)

    def size(self):
        return self.size

    def front(self):
        return self.head

    def prepend(self, data):
        node = Node(data)
        if self.head is not None:
            node.next = self.head
        self.head = node
        self.size += 1

    def append(self, data):
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
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
        self.size -= 1

    def remove_back(self):
        if self.head is None:
            return
        cur = self.head
        last = cur
        while cur:
            last = cur
            cur = cur.next
        last.next = None

    def exists(self, data):
        cur = self.head
        while cur:
            if cur.data == data:
                return true
            cur = cur.next
        return false
    
    def delete(self, data):
        cur = self.head
        last = cur
        while cur:
            if cur.data == data:
                last.next = cur.next
                return
            last = cur
            cur = cur.next

