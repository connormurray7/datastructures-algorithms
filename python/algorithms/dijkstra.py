"""
Created by Connor Murray (connormurray7@gmail.com)
10/03/2016

Python implementation of Dijkstra's Algorithm
"""
import sys

def dijkstra(graph, start):

    dist = {}
    prev = {}

    q = set()

    for vert in graph.adj_list:
        dist[vert] = sys.maxsize
        prev[vert] = None
        q.add(vert)

    dist[start] = 0

    while q:
        u = _min_vert(q, dist)
        q.remove(u)

        for v in graph.adj_list[u]:
            alt = dist[u] + graph.weights[(u,v)]
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
    
    return (dist, prev)
            


def _min_vert(q, dist):
    min_val = sys.maxsize

    for vert in q:
        if dist[vert] <= min_val:
            min_val = dist[vert]
            min_vert = vert
        
    return min_vert
