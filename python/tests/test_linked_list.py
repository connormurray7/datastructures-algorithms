import os
import sys
import unittest
sys.path.append(os.path.join(os.getcwd(), os.path.pardir))

from data_structures.linked_list import LinkedList

class LinkedListTest(unittest.TestCase):
    
    def test_append(self):
        print("Testing append")
        l = LinkedList()
        
        l.append(1)
        l.append(2)
        l.append(3)
        
        self.assertEqual(l.front().data, 1) 

        l.remove_front()
        self.assertEqual(l.front().data, 2)

        l.remove_front()
        self.assertEqual(l.front().data, 3)

        l.remove_front()
        self.assertEqual(l.front(), None)

    def test_prepend(self):
        print("Testing prepend")
        l = LinkedList()
        
        l.prepend(1)
        l.prepend(2)
        l.prepend(3)
        
        self.assertEqual(l.front().data, 3) 

        l.remove_front()
        self.assertEqual(l.front().data, 2)

        l.remove_front()
        self.assertEqual(l.front().data, 1)

        l.remove_front()
        self.assertEqual(l.front(), None)


    def test_delete(self):
        print("Testing delete")
        l = LinkedList()
        
        l.prepend(1)
        l.prepend(2)
        l.prepend(3)
        l.prepend(4)
        
        self.assertEqual(l.contains(4), True) 
        l.delete(4)
        self.assertEqual(l.contains(4), False)

        self.assertEqual(l.contains(2), True) 
        l.delete(2)
        self.assertEqual(l.contains(2), False)

        l.delete(1)
        l.delete(3)
        self.assertEqual(l.size, 0)
        self.assertEqual(l.front(), None)

    def test_size(self):
        print("Testing size")
    
if __name__ == '__main__':
    unittest.main()
