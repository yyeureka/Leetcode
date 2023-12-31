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
    @param root: param root: The root of the binary search tree
    @param k1: An integer
    @param k2: An integer
    @return: return: Return all keys that k1<=key<=k2 in ascending order
    """
    def search_range(self, root: TreeNode, k1: int, k2: int) -> List[int]:
        # write your code here
        if not root or k1 > k2:
            return []

        res = []
        self.search(root, k1, k2, res)

        return res

    def search(self, root, k1, k2, res):
        if not root:
            return

        if root.val < k1:
            self.search(root.right, k1, k2, res)
        elif root.val > k2:
            self.search(root.left, k1, k2, res)
        else:
            self.search(root.left, k1, k2, res)
            res.append(root.val)
            self.search(root.right, k1, k2, res)
