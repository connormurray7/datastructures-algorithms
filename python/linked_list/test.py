from linked_list import LinkedList
from linked_list import Node
import time

def my_benchmark(n):
    l = LinkedList()
    before = time.perf_counter()
    
    for i in range(1,n):
        l.prepend(i)
    
    after = time.perf_counter()
    return after-before 

def control(n):
    l = []
    before = time.perf_counter()
    
    for i in range(1,n):
        l.append(Node(i))
    
    after = time.perf_counter()
    return after-before 

if __name__ == '__main__':
    n = 10000000
    m = 10
    print("Running benchmark for Linked List implementation in python")
    total_time = 0.0
    for i in range(0,m):
       total_time += my_benchmark(n)
    
    avg_time = total_time/m
    print("----------------------------")
    print(("Linked List implementation took an average time of " 
            + str(avg_time) + " for " + str(n) + " iterations"))
            
    print("Running benchmark for regular list in python")
    total_time = 0.0
    for i in range(0,m):
       total_time += control(n)
    
    avg_time = total_time/m
    print("----------------------------")
    print(("Regular list in python took an average time of " 
            + str(avg_time) + " for " + str(n) + " iterations"))
