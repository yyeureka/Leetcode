from lintcode import (
    UndirectedGraphNode,
)

from collections import deque

"""
Definition for a UndirectedGraphNode:
class UndirectedGraphNode:
    def __init__(self, label):
        self.label = label
        self.neighbors = []
"""

class Solution:
    """
    @param node: A undirected graph node
    @return: A undirected graph node
    """
    def clone_graph(self, node: UndirectedGraphNode) -> UndirectedGraphNode:
        # write your code here
        if not node:  # tricky
            return None

        nodes = {node: UndirectedGraphNode(node.label)}  # original: new node
        dq = deque([node])  # original node

        while dq:
            cur = dq.popleft()
            cpy = nodes[cur]

            for neighbor in cur.neighbors:
                if neighbor not in nodes:
                    nodes[neighbor] = UndirectedGraphNode(neighbor.label)
                    dq.append(neighbor)
                
                cpy.neighbors.append(nodes[neighbor])
        
        return nodes[node]