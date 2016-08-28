"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Simple Python implementation of a binary heap.
"""

class BinaryHeap:
	"""Binary max heap, array as underlying data structure
	
	Attributes:
		data: list as the underlying data structure
		size: current length of the list 
		max_size: maximum number of vals that can fit
		comp: comparator function that dictates the heap ordering property
	"""


	def __init__(self,init_size=16,comp=min):
		self.data = init_size*[None]
		self.size = 1
		self.max_size = init_size
		self.comp = comp


	def fix_up(self,idx):
		i = idx
		while(i > 1 and left(i) < self.data[i]):
			swap(i,i/2)
			i /= 2

	def fix_down(self,idx):
		"""Ensures that the heap property is maintained.

		Recursize strategy given by Introduction to Algorithms.
		Iterative version will also be written
		"""
		l = left(idx)
		r = right(idx)
		if l <= self.size and self.data[l] > self.data[r]:
			largest = l
		else:
			largest = idx
		if r <= self.size and self.data[r] > self.data[largest]:
			largest = r
		if largest != idx:
			swap(idx, largest)
			self.max_heapify(largest)
		

	def build_heap(self, array):
		self.data = array
		for i in range(len(array)/2,0,-1):
			self.max_heapify(i)

	def peek():
		return self.data[1]
	def pop():
		val = self.data[1]
		swap(self.data[1],self.data[self.size])
		self.size -= 1
		fix_down(1)
		return val
		

	def insert(self,val):
		if self.size == self.max_size:
			self.grow()
		self.size += 1
		self.data[self.size] = val
		self.fix_up(self.size)
			
	def grow(self):
		self.max_size *= 2
		old = self.data
		self.data = [None]*self.max_size
		for i in range(1,len(old)):
			self.data[i] = old[i]

	def left(self,idx):
		return self.data[idx*2]
	def right(self,idx):
		return self.data[idx*2 + 1]











