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
    @param root: the root of binary tree.
    @return: An integer
    """
    def max_path_sum2(self, root: TreeNode) -> int:
        # write your code here
        if not root:
            return 0

        self.res = float('-inf')
        self.helper(root, 0)

        return self.res

    def helper(self, root, sum):
        if not root:
            return

        sum += root.val
        if sum > self.res:
            self.res = sum

        self.helper(root.left, sum)
        self.helper(root.right, sum)
