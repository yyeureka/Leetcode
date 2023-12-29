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
    @param root: the root of the tree
    @return: the total sum of all root-to-leaf numbers
    """

    def sum_numbers(self, root: TreeNode) -> int:
        # write your code here
        if not root:
            return 0

        self.res = 0
        self.helper(root, 0)

        return self.res

    def helper(self, root, sum):
        sum = sum * 10 + root.val
        if not root.left and not root.right:
            self.res += sum
            return

        if root.left:
            self.helper(root.left, sum)
        if root.right:
            self.helper(root.right, sum)


