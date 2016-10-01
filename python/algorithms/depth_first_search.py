"""
Created by Connor Murray (connormurray7@gmail.com)
9/26/2016

DFS of graph in data_structures directory
"""

def depth_first_search(graph, start, visited = None):
    """Find path between two vertices with DFS, O(E*V)."""
    if visited is None:
        print("We should never get here")
        visited = set() #Can be used for topological sorting if passed in.
    stack = [] #Use list as stack
    dfs_order = []

    stack.append(start)

    while stack:
        vert = stack[-1] #Back of list is top of stack
        if vert in visited:
            dfs_order.append(vert)
            stack.pop()
        else:
            visited.add(vert)
            for v in graph.adj_list[vert]:
                if v not in visited:
                    stack.append(v)

    return dfs_order
