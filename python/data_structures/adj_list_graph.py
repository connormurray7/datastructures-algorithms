"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python implementation of a graph using an adjacency list.
"""
from graph import Graph


class AdjListGraph(Graph):
    """Python implementation of a graph with adj list.

    Attributes:
        init: constructor
        add_vertex: constructs a vertex and keeps track of it
        add_edge: creates edge between two vertices
    """

    def __init__(self, directed = False, weighted = False):
        self.adj_list = {}
        self.directed = directed
        self.weights = {}

    def __str__(self):
        """String representation of set"""
        vertices = []
        for vert in self.adj_list:
            vertices.append(vert)
        out_str = ' '.join([str(v) for v in vertices])
        return "Graph [" + out_str + "]"

    def add_vertex(self, key):
        """Adds vertex to adjacency list, O(1)."""
        self.adj_list[key] = []

    def add_edge(self, v1, v2, w=None):
        """Adds edge between two vertices if O(1)."""
        if v1 in self.adj_list:
            self.adj_list[v1].append(v2)
            if w is not None:
                self.weights[(v1, v2)] = w

        if not self.directed and v2 in self.adj_list:
            self.adj_list[v2].append(v1)
            if w is not None:
                self.weights[(v2, v1)] = w
