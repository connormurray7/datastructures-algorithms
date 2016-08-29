"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Simple Python implementation of a binary heap.
"""

class BinaryHeap:
    """Binary max heap, array as underlying data structure
    
    Attributes:
       data: list as the underlying data structure
       size: current length of the list 
       max_size: maximum number of vals that can fit
       comp: comparator function that dictates the heap ordering property
    """

    def __init__(self, init_size=16, comp=None):
        self.data = init_size*[None]
        self.size = 0
        self.max_size = init_size
        if comp is None:
            self.comp = lambda x, y : x < y
        else:
            self.comp = comp

    def __str__(self):
        """String representation of the heap"""
        vals = []
        for v in self.data:
            if v is not None:
                vals.append(v)
        out_str = ' '.join([str(v) for v in vals])
        return "Binary Heap [" + out_str + "]"

    def fix_up(self, idx):
        i = idx
        while(i > 1 and self.comp(self.parent(i), self.data[i])):
            self.swap(i,i//2)
            i = i // 2

    def fix_down(self, idx):
        """Ensures that the heap property is maintained.

        Recursize strategy given by Introduction to Algorithms.
        Iterative version will also be written
        """
        l = self.left(idx)
        r = self.right(idx)
        print("The left index is: " + str(l) + "and the right is: " + str(r))
        if l <= self.size and self.data[l] > self.data[r]:
            largest = l
        else:
            largest = idx
        if r <= self.size and self.data[r] > self.data[largest]:
            largest = r
        if largest != idx:
            self.swap(idx, largest)
            self.fix_down(largest)
        
    def build_heap(self, array):
        self.data = array
        self.size = len(array)
        self.max_size = len(array)
        print("The size of the array is: " + str(len(array)))
        for i in range(len(array)//2,0,-1):
            self.fix_down(i)

    def peek(self):
        return self.data[1]
    def pop(self):
        if self.size == 0:
            return None
        val = self.data[1]
        self.swap(1,self.size)
        self.size -= 1
        self.fix_down(1)
        return val
        
    def insert(self, val):
        if self.size == self.max_size:
            self.grow()
        self.size += 1
        self.data[self.size] = val
        self.fix_up(self.size)
            
    def grow(self):
        self.max_size *= 2
        old = self.data
        self.data = [None]*self.max_size
        for i in range(1,len(old)):
            self.data[i] = old[i]

    def left(self, idx):
        return idx*2
    def right(self, idx):
        return idx*2 + 1
    def parent(self, idx):
        return self.data[idx // 2]
    def swap(self, i, j):
        tmp = self.data[i]
        self.data[i] = self.data[j]
        self.data[j] = tmp











