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
    
    def __str__(self):
        return str(data)

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
        node_data = []
        while node:
            node_data.append(str(node.data))
            node = node.next
        out_str = ' '.join([d for d in node_data])
        print("LinkedList [" + out_str + "]")

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

    def contains(self, data):
        cur = self.head
        while cur:
            if cur.data == data:
                return True
            cur = cur.next
        return False
    
    def delete(self, data):
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

