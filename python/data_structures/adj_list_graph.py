"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python implementation of a graph using an adjacency list.
"""
from data_structures.graph import Graph
from queue import Queue

class AdjListGraph(Graph):
    """Python implementation of a graph with adj list.

    Attributes:
        init: constructor
        add_vertex: constructs a vertex and keeps track of it
    """

    def __init__(self):
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
        """Find path between two vertices with DFS, O(E*V)."""
        visited = set()
        stack = [] #Use list as stack
        stack.append(v1)
        while(len(stack) > 0):
            vert = stack[len(stack)-1] #Last value in stack is top
            if vert == v2:
                return stack
            if vert in visited:
                stack.pop()
            else:
                visited.add(vert)
                for v in self.adj_list[vert]:
                    if v not in visited:
                        stack.append(v)
        return stack

    def breadth_first_search(self, start):
        """Traverse tree with BFS, O(E*V)."""
        q = Queue()
        discovered = set()
        processed = set()

        q.put(start)
        discovered.add(start)

        while(not q.empty()):
            cur = q.get()
            print("Processed vertex: " + cur)
            processed.add(cur)
            for vert in self.adj_list[cur]:
                if vert not in processed:
                    print("Processed edge: (" + cur + "," + vert + ")")
                if vert not in discovered:
                    q.put(vert)
                    discovered.add(vert)

        print("Finished processing all vertexes")


    def minimum_spanning_tree(self, start):


    def find_cycles(self, start):

