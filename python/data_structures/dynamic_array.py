"""Simple implementation of a dynamically resized array with Ring Buffer.

"""

class Array:
    """Implemented with a statically sized array.

    """
    INITIAL_SIZE = 16

    def __init__(self, size=INITIAL_SIZE):
        self.index = 0
        self.array = []
        self.buffer = size
        
    def __getitem__(self, index):
        if index >= 0 and index < self.buffer:
            return self.array[index]
        else:
            return None
        
    def append(self, item):
        if len(self.array) == self.buffer:
            self.buffer *= 2

        self.array.append(item)
            
    def get(self):
        item = self.array[self.index]
        self.index = (self.index + 1) % (self.buffer)
        return item

    def remove(self,index):
        if index < 0 or index >= self.buffer:
            return
        self.array.pop(index)
