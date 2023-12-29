from collections import deque

from typing import (
    List,
)
from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: A Tree
    @return: Level order a list of lists of integer
    """
    def level_order(self, root: TreeNode) -> List[List[int]]:
        # write your code here
        if not root:  # tricky
            return []

        res = []
        dq = deque([root])

        while dq:
            level = []
            size = len(dq)

            for i in range(size):  # key point
                node = dq.popleft()
                level.append(node.val)

                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)

            res.append(level)

        return res