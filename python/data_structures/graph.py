"""
Created by Connor Murray (connormurray7@gmail.com)
8/27/2016

Python abstract class of a graph.
"""
from abc import ABCMeta

class Vertex:
    """Vertex in a graph."""
    def __init__(self, key):
        self.key = key

class Edge:
    """Connects two vertices with optional weight."""

    def __init__(self, v1, v2, w=None):
        self.edge = (v1, v2)
        self.weight = w

class Graph:
    """Python abstract class of a graph.

    Attributes:
        init: constructor
        add_vertex: constructs a vertex and keeps track of it
    """
    __metaclass__ = ABCMeta

    def __init__(self):
        pass

    def add_vertex(self, key):
        pass

    def __str__(self):
        pass
