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

# recursion 左node值应等于右node值，左左等于右右，左右等于右左
# iteration, stack


class Solution:
    """
    @param root: the root of binary tree.
    @return: true if it is a mirror of itself, or false.
    """

    def is_symmetric(self, root: TreeNode) -> bool:
        # write your code here
        if not root:
            return True

        return self.helper(root.left, root.right)

    def helper(self, a, b):
        if not a:
            return not b
        if not b:
            return False

        return a.val == b.val and self.helper(a.left, b.right) and self.helper(a.right, b.left)


