import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.hash_set import HashSet

class HashMapTest(unittest.TestCase):
    
    def test_add(self):
        print("Testing add")
        h = HashSet()

        h.add(1,"foo")
        h.add(2,"bar")
        h.add(3,"baz")

        self.assertEquals(h.get(1),"foo")
        self.assertEquals(h.get(2),"bar")
        self.assertEquals(h.get(3),"baz")
        self.assertEquals(h.get(0),None)

    def test_remove(self):
        print("Testing remove")
        h = HashSet()

        h.add(1,"foo")
        h.add(2,"bar")
        h.add(3,"baz")

        self.assertEquals(h.get(1),"foo")
        h.remove(1)
        self.assertEquals(h.get(1),None)

        h.add(1,"foo")
        self.assertEquals(h.get(1),"foo")


        self.assertEquals(h.get(2),"bar")
        h.remove(2)
        self.assertEquals(h.get(2),None)

    def test_operator_get(self):
        print("Testing operator[] get")
        h = HashSet()

        h.add(1,"foo")
        h.add(2,"bar")
        h.add(3,"baz")

        self.assertEquals(h[1],"foo")
        self.assertEquals(h[2],"bar")
        self.assertEquals(h[4],None)
        self.assertEquals(h[0],None)

    def test_size(self):
        print("Testing size")
        h = HashSet()

        self.assertEquals(h.size,0)
        h.add(1,"foo")
        self.assertEquals(h.size,1)
        h.add(2,"bar")
        self.assertEquals(h.size,2)
        h.remove(2)
        self.assertEquals(h.size,1)
        h.remove(1)
        self.assertEquals(h.size,0)
    
if __name__ == '__main__':
    unittest.main()
