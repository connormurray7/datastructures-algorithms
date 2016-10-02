"""
Created by Connor Murray (connormurray7@gmail.com)
9/20/2016

Python implementation of topological sort using DFS
"""

from algorithms.depth_first_search import *

def topological_sort(graph, start):
    """Requires a DAG, runs in O(|E| + |V|)."""

    visited = set()
    dfs_order = []
    for v in graph.adj_list.keys():
        if v not in visited:
            dfs_order.extend(depth_first_search(graph, v, visited))

    dfs_order
    return dfs_order #This is now topologically sorted
