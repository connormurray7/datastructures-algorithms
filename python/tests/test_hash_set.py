import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.hash_set import HashSet

class HashSetTest(unittest.TestCase):
    
    def test_add(self):
        print("Testing add")
        h = HashSet()

        h.add(1)
        h.add(2)
        h.add(3)

        self.assertEquals(h.get(1),1)
        self.assertEquals(h.get(2),2)
        self.assertEquals(h.get(4),None)
        self.assertEquals(h.get(0),None)

    def test_remove(self):
        print("Testing remove")
        h = HashSet()

        self.assertEquals(h.get(1),None)
        h.add(1)
        h.add(2)
        h.add(3)

        self.assertEquals(h.get(1),1)
        h.remove(1)
        self.assertEquals(h.get(1),None)

        h.add(1)
        self.assertEquals(h.get(1),1)


        self.assertEquals(h.get(2),2)
        h.remove(2)
        self.assertEquals(h.get(2),None)

    def test_operator_get(self):
        print("Testing operator[] get")
        h = HashSet()

        h.add(1)
        h.add(2)
        h.add(3)

        self.assertEquals(h[1],1)
        self.assertEquals(h[2],2)
        self.assertEquals(h[4],None)
        self.assertEquals(h[0],None)

    def test_size(self):
        print("Testing size")
        h = HashSet()

        self.assertEquals(h.size,0)
        h.add(1)
        self.assertEquals(h.size,1)
        h.add(2)
        self.assertEquals(h.size,2)
        h.remove(2)
        self.assertEquals(h.size,1)
        h.remove(1)
        self.assertEquals(h.size,0)
    
if __name__ == '__main__':
    unittest.main()

