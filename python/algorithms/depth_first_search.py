"""
Created by Connor Murray (connormurray7@gmail.com)
9/26/2016

DFS of graph in data_structures directory
"""

def depth_first_search(graph, start):
    """Find path between two vertices with DFS, O(E*V)."""
    stack = [] #Use list as stack
    visited = set()
    dfs_order = []

    stack.append(start)

    while(len(stack) > 0):
        vert = stack[len(stack)-1] #Last value in stack is top
        if vert in visited:
            dfs_order.append(vert)
            stack.pop()
        else:
            visited.add(vert)
            for v in graph.adj_list[vert]:
                if v not in visited:
                    stack.append(v)

    return dfs_order