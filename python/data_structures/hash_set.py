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

    def __init__(self, init_size=16, hash=None, load_factor=0.75):
        self.load_factor = load_factor
        self.max_size = init_size
        self.buckets = [None]*max
        if self.hash is None:
            self.hash = lambda x: x % self.max
        else:
            self.hash = hash

    def grow(self):
        self.max_size *= 2
        tmp = self.buckets
        self.buckets = [None]*self.max

        for k in tmp:
            self.add(k)

    def add(self,key):
        if len(self.buckets)/self.max_size > load_factor:
            grow()
        self.buckets[self.hash(key)] = key
