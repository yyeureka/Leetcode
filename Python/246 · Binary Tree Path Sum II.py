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
    @param root: the root of binary tree
    @param target: An integer
    @return: all valid paths
             we will sort your return value in output
    """

    def binary_tree_path_sum2(self, root: TreeNode, target: int) -> List[List[int]]:
        # write your code here
        if not root:
            return []

        res = []
        self.helper(root, target, [], res)

        return res

    def helper(self, root, target, path, res):
        if not root:
            return

        path.append(root.val)

        sum = 0
        for i in range(len(path))[::-1]:
            sum += path[i]

            if target == sum:
                res.append(path[i:])

        if root.left:
            self.helper(root.left, target, path, res)
        if root.right:
            self.helper(root.right, target, path, res)

        path.pop()

