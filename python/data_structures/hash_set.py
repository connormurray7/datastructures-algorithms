"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Simple Python implementation of a Hash set.
"""

class HashSet:
    """Simple implementation of a Hash set.

    There is the possibility of collisions, in which case the 
    class overwrites the old value with the new.

    Attributes:
        load_factor: maximum ratio until the list doubles in size.
        buckets: list as the underlying data structure.
        size: how many elements currently in the set.
        max_size: size of the container.
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
        """String representation of set"""
        keys = []
        for b in self.buckets:
            if b is not None:
                keys.append(b)
        out_str = ' '.join([str(k) for k in keys])
        return "Hashset [" + out_str + "]"

    def __getitem__(self,key):
        """Overloads operator [] for O(1) access"""
        return self.get(key)

    def get(self,key):
        """Overloads operator [] for O(1) access"""
        return self.buckets[self.hash(key)]

    def grow(self):
        """Doubles size of container"""
        self.max_size *= 2
        tmp = self.buckets
        self.buckets = [None]*self.max_size

        for k in tmp:
            self.add(k)

    def add(self, key):
        """O(1) addition to set, if container too full, calls grow"""
        if self.size/self.max_size > self.load_factor:
            self.grow()
        b = self.hash(key)
        if self.buckets[b] is None:
            self.size += 1
        self.buckets[b] = key

    def remove(self, key):
        """O(1) removal of element (if exists)"""
        b = self.hash(key)
        if self.buckets[b] == key:
            self.buckets[b] = None
            self.size -= 1
