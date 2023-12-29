"""
class DirectedGraphNode:
     def __init__(self, x):
         self.label = x
         self.neighbors = []
"""

from collections import deque

class Solution:
    """
    @param graph: A list of Directed graph node
    @return: Any topological order for the given graph.
    """
    def topSort(self, graph):
        # write your code here
        if not graph:
            return []

        # the neighbors is the edge
        degree = {}
        dq = deque()
        res = []

        for node in graph:
            if node not in degree:
                degree[node] = 0
            
            for neighbor in node.neighbors:
                if neighbor not in degree:
                    degree[neighbor] = 1
                else:
                    degree[neighbor] += 1
        
        for node in degree:
            if 0 == degree[node]:
                dq.append(node)
        
        while dq:
            node = dq.popleft()
            res.append(node)

            for neighbor in node.neighbors:
                degree[neighbor] -= 1

                if 0 == degree[neighbor]:
                    dq.append(neighbor)
        
        return res

