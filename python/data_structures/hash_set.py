"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Simple Python implementation of a Hash set
"""

class HashSet:
    """Simple implementation of a Hash set.

    There is the possibility of collisions, in which case the 
    class overwrites the old value with the new.

    Attributes:
        

    """

    def __init__(self, init_size=16, h=None, load_factor=0.75):
        self.load_factor = load_factor
        self.size = 0
        self.max_size = init_size
        self.buckets = [None]*init_size
        if h is None:
            self.hash = lambda x: x % self.max_size
        else:
            self.hash = h

    def __str__(self):
        keys = []
        for b in self.buckets:
            if b is not None:
                keys.append(b)
        out_str = ' '.join([str(k) for k in keys])
        return "Hashset [" + out_str + "]"
            

    def grow(self):
        self.max_size *= 2
        tmp = self.buckets
        self.buckets = [None]*self.max_size

        for k in tmp:
            self.add(k)

    def add(self,key):
        if self.size/self.max_size > self.load_factor:
            self.grow()
        b = self.hash(key)
        if self.buckets[b] is None:
            self.size += 1
        self.buckets[b] = key
