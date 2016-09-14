"""
Created by Connor Murray (connormurray7@gmail.com)
9/13/2016

Python implementation of a graph using an adjacency matrix.
"""
from graph import Graph

class AdjMatrixGraph(Graph):
    """Python implementation of a graph with adj matrix.

    Attributes:
        init: constructor
        add_vertex: constructs a vertex and keeps track of it
        add_edge: creates edge between two vertices
        find_path: returns first found path between vertices
    """

    def __init__(self):
        self.adj_matrix = []
        self.map = {}
        self.vert_size = 0

    def add_vertex(self, key):
        """Adds vertex to adjacency matrix."""
        self.map[key] = self.vert_size
        for row in self.adj_matrix:
            row.append(0)
        self.adj_matrix.append([0]*(self.vert_size + 1))
        self.vert_size += 1

    def add_edge(self, v1, v2):
        """Adds edge between two vertices O(1)."""
        if v1 in self.map and v2 in self.map:
            i = self.map[v1]
            j = self.map[v2]
            self.adj_matrix[i][j] = 1
            self.adj_matrix[j][i] = 1

