import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.dynamic_array import Array



class ArrayTest(unittest.TestCase):
    
    def test_append(self):
        a = Array()

        a.append(1)
        a.append(2)
        a.append(3)

        self.assertEquals(a.get(),1)
        self.assertEquals(a.get(),2)
        self.assertEquals(a.get(),3)
        self.assertEquals(a.get(),1)


    def test_operator(self):
    def test_get(self):
    def test_remove(self):




if __name__ == '__main__':
    unittest.main()
