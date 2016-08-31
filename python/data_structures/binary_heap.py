"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python implementation of a binary heap.
"""

class BinaryHeap(object):
    """Binary max heap, array as underlying data structure

    Attributes:
       data: list as the underlying data structure
       size: current length of the list
       max_size: maximum number of vals that can fit
       comp: comparator function that dictates the heap ordering property
    """

    def __init__(self, init_size=1, comp=None):
        self.heap = init_size*[None]
        self.size = 0
        if comp is None:
            self.comp = lambda x, y : x > y
        else:
            self.comp = comp

    def __str__(self):
        """String representation of the heap"""
        vals = []
        for v in self.heap:
            if v is not None:
                vals.append(v)
        out_str = ' '.join([str(v) for v in vals])
        return "Binary Heap [" + out_str + "]"

    def fix_up(self, idx):
        parent = idx // 2
        while parent:
            if self.comp(self.heap[idx], self.heap[parent]):
                self.swap(idx,parent)
            idx = parent
            parent = parent // 2

    def fix_down(self, idx):
        """Ensures that the heap property is maintained.

        Rewritten as an iterative algorithm
        """
        cur = idx
        child = self.left(idx)
        while child <= self.size:
            child = self.min_child(cur)
            if self.comp(self.heap[child], self.heap[cur]):
                self.swap(cur,child)
            cur = child
            child = self.left(child)

    def min_child(self, idx):
        l = self.left(idx)
        r = self.right(idx)
        if r > self.size:
            return l
        elif self.comp(self.heap[l], self.heap[r]):
            return l
        return r

    def build_heap(self, array):
        self.size = len(array)
        self.heap = array
        self.heap.insert(0, None)
        for i in range(len(self.heap)//2,0,-1):
            self.fix_down(i)

    def peek(self):
        return self.heap[1]
    def pop(self):
        if self.size == 0:
            return None
        val = self.heap[1]
        self.swap(1,self.size)
        self.heap.pop()
        self.size -= 1
        self.fix_down(1)
        return val

    def push(self, val):
        self.size += 1
        self.heap.append(val)
        self.fix_up(self.size)

    def left(self, idx):
        return idx * 2
    def right(self, idx):
        return idx * 2 + 1
    def swap(self, i, j):
        tmp = self.heap[i]
        self.heap[i] = self.heap[j]
        self.heap[j] = tmp
