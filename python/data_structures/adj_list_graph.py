"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python implementation of a graph using an adjacency list.
"""
from graph import Graph
from queue import Queue

class AdjListGraph(Graph):
    """Python implementation of a graph with adj list.

    Attributes:
        init: constructor
        add_vertex: constructs a vertex and keeps track of it
    """

    def __init__(self):
        print("it worked wooo!")
        self.adj_list = {}

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

    def add_edge(self, v1, v2):
        """Adds edge between two vertices O(1)."""
        if v1 in self.adj_list:
            self.adj_list[v1].append(v2)
        if v2 in self.adj_list:
            self.adj_list[v2].append(v1)

    def find_path(self, v1, v2):
        """Find path between two vertices, O(n!)."""
        path = [v1]
        queue = Queue()
        queue.put(v1)
        while(not queue.empty()):
            vert = queue.get()
            if vert== v2:
                return path
            if self.adj_list[vert] is None:
                path.pop()
            else:
                for v in self.adj_list[vert]:
                    queue.put(v)
        print(path)
        return path
