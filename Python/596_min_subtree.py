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
    @return: the root of the minimum subtree
    """

    def find_subtree(self, root: TreeNode) -> TreeNode:
        # write your code here
        self.min_sum = float('inf')
        self.min_root = None
        self.helper(root)

        return self.min_root

    def helper(self, root):
        if not root:
            return 0

        sum = root.val + self.helper(root.left) + self.helper(root.right)

        if sum < self.min_sum:
            self.min_sum = sum
            self.min_root = root

        return sum
