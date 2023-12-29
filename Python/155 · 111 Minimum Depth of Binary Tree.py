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
    @param root: The root of binary tree
    @return: An integer
    """

    def min_depth(self, root: TreeNode) -> int:
        # write your code here
        if not root:
            return 0

        left = self.min_depth(root.left)
        right = self.min_depth(root.right)

        if 0 == left:  # tricky
            return right + 1
        if 0 == right:
            return left + 1
        return min(left, right) + 1