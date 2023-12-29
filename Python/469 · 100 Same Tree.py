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
    @param a: the root of binary tree a.
    @param b: the root of binary tree b.
    @return: true if they are identical, or false.
    """

    def is_identical(self, a: TreeNode, b: TreeNode) -> bool:
        # write your code here
        if not a:
            return not b
        if not b:
            return False

        return a.val == b.val and self.is_identical(a.left, b.left) and self.is_identical(a.right, b.right)