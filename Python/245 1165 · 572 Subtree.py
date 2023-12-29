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
    @param t1: The roots of binary tree T1.
    @param t2: The roots of binary tree T2.
    @return: True if T2 is a subtree of T1, or false.
    """

    def is_subtree(self, t1: TreeNode, t2: TreeNode) -> bool:
        # write your code here
        if not t1:
            return not t2
        if not t2:
            return True

        if self.is_same(t1, t2):
            return True

        return self.is_subtree(t1.left, t2) or self.is_subtree(t1.right, t2)

    def is_same(self, t1, t2):
        if not t1:
            return not t2
        if not t2:
            return not t1

        return t1.val == t2.val and self.is_same(t1.left, t2.left) and self.is_same(t1.right, t2.right)
