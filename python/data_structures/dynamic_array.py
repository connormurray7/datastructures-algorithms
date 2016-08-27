"""
Simple implementation of a dynamically resized array with Ring Buffer.

Connor Murray (connormurray7@gmail.com)
on 8/25/2016
"""

class Array:
    """Implemented with a python list because there are no static arrays.

    Uses a ring buffer to get objects.

    Attributes:
        index: current element that the ring buffer is on, wraps at buffer size
        array: python list that holds the data
        buffer: current maximum size of the array

    """

    def __init__(self, init_size=16):
        self.index = 0
        self.array = []
        self.buffer = init_size
        
    def __getitem__(self, index):
        """Overloads operator [] for random access if exists."""
        if index >= 0 and index < self.buffer:
            return self.array[index]
        else:
            return None
        
    def append(self, item):
        """If size is the same as the buffer, array doubles in size."""
        if len(self.array) == self.buffer:
            self.buffer *= 2

        self.array.append(item)
            
    def get(self):
        """Returns what element the ring buffer is currently on.""" 
        item = self.array[self.index]
        self.index = (self.index + 1) % (self.buffer)
        return item

    def remove(self,index):
        """Removes element at index, if it exists."""
        if index < 0 or index >= self.buffer:
            return
        self.array.pop(index)
