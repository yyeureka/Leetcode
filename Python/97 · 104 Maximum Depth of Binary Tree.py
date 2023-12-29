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
    @param root: The root of binary tree.
    @return: An integer
    """

    def max_depth(self, root: TreeNode) -> int:
        # write your code here
        if not root:
            return 0

        return max(self.max_depth(root.left), self.max_depth(root.right)) + 1
