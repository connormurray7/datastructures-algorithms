"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementation of topological sort using DFS
"""

from algorithms.depth_first_search import *

def topological_sort(graph, start):
    """Requires a DAG, runs in O(|E| + |V|)."""

    visited = set()
    topological_sort = []
    for v in graph.adj_list.keys():
        print(str(visited))
        if v not in visited:
            topological_sort.extend(depth_first_search(graph, v))

    return topological_sort.reverse()
