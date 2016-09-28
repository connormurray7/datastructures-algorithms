"""
Created by Connor Murray (connormurray7@gmail.com)
9/26/2016

BFS of graph in data_structures directory
"""

from queue import Queue

def breadth_first_search(graph, start):
    """Traverse tree with BFS, O(E*V)."""
    bfs_order = []
    q = Queue()
    discovered = set()

    q.put(start)
    discovered.add(start)

    while(not q.empty()):
        cur = q.get()
        bfs_order.append(cur)
        for vert in graph.adj_list[cur]:
            if vert not in discovered:
                q.put(vert)
                discovered.add(vert)

    return bfs_order
