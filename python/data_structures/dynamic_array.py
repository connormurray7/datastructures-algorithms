"""Simple implementation of a dynamically resized array with Ring Buffer.

"""


class Array:
    """Implemented with a statically sized array.

    """
    INITIAL_SIZE = 16

    def __init__(self):
        self.index = 0
        self.array = []
        self.buffer = INITIAL_SIZE
        
    def __getitem__(self, index):
        if i >= 0 and i < self.buffer:
            return self.array[index]
        else:
            return None
        
    def append(self, item):
        self.index += 1
        if index == self.buffer:
            self.buffer *= 2

        self.array.append(item)
            
    def get(self):
        item = self.array[self.index]
        self.index = (self.index + 1) % self.buffer
        return item

    def remove(self,index):
        if i < 0 or i >= self.buffer:
            return
        self.array.pop(index)
