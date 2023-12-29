from typing import (
    List,
)
from lintcode import (
    UndirectedGraphNode,
)

"""
class UndirectedGraphNode:
     def __init__(self, x):
         self.label = x
         self.neighbors = []
"""


class Solution:
    """
    @param nodes: a array of Undirected graph node
    @return: a connected set of a Undirected graph
    """

    def connectedSet(self, nodes: List[UndirectedGraphNode]) -> List[List[int]]:
        # write your code here
        visited = {}
        res = []

        for node in nodes:
            visited[node.label] = False
        for node in nodes:
            if visited[node.label]:
                continue

            cur = []
            self.dfs(node, cur, visited)
            res.append(sorted(cur))  # tricky

        return res

    def dfs(self, node, cur, visited):
        cur.append(node.label)
        visited[node.label] = True

        for neighbor in node.neighbors:
            if visited[neighbor.label]:
                continue

            self.dfs(neighbor, cur, visited)


