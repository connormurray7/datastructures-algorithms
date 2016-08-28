"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Simple Python implementation of a binary heap.
"""

class BinaryHeap:
	"""Binary max heap, array as underlying data structure
	
	Attributes:

	"""


	def __init__(self,init_size=16,comp=min):
		self.data = init_size*[None]
		self.comp = comp
		self.size = init_size

	#Recursize strategy given by Introduction to Algorithms
	def max_heapify(self,idx):
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
			max_heapify(largest)




	def left(self,idx):
		return idx*2
	def right(self,idx):
		return idx*2 + 1