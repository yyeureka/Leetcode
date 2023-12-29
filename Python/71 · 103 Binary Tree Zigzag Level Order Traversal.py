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

from collections import deque

class Solution:
    """
    @param root: A Tree
    @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
    """
    def zigzag_level_order(self, root: TreeNode) -> List[List[int]]:
        # write your code here
        if not root:
            return[]

        dq = deque([root])
        res = []
        flip = False

        while dq:
            size = len(dq)
            cur = []

            for i in range(size):
                node = dq.popleft()
                cur.append(node.val)

                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)

            if flip:
                res.append(cur[::-1])
            else:
                res.append(cur)
            flip ^= 1

        return res

