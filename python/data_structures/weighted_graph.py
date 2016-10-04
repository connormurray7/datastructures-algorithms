"""
Created by Connor Murray (connormurray7@gmail.com)
10/03/2016

Python implementation of a weighted graph.
"""
from data_structures.adj_list import AdjListGraph

class WeightedGraph(AdjListGraph):
    """Python implementation of a weighted graph with adj list.

    Attributes:
        init: constructor
        add_vertex: constructs a vertex and keeps track of it
    """

    def __init__(self, directed = False):
        self.adj_list = {}
        self.directed = directed

