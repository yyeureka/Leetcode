from typing import (
    List,
)
from lintcode import (
    TreeNode,
)

from collections import deque

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param root: A tree
    @return: buttom-up level order a list of lists of integer
    """

    def level_order_bottom(self, root: TreeNode) -> List[List[int]]:
        # write your code here
        if not root:
            return []

        dq = deque([root])
        res = []

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

            res.append(cur)

        return res[::-1]

