"""
Created by Connor Murray (connormurray7@gmail.com)
9/26/2016

DFS of graph in data_structures directory
"""

def breadth_first_search(self, graph, start):
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
        for vert in graph.adj_list[cur]:
            if vert not in processed:
                print("Processed edge: (" + cur + "," + vert + ")")
            if vert not in discovered:
                q.put(vert)
                discovered.add(vert)

    print("Finished processing all vertexes")
