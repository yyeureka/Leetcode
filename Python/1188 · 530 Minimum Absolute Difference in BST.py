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
    @param root: the root
    @return: the minimum absolute difference between values of any two nodes
    """
    def get_minimum_difference(self, root: TreeNode) -> int:
        # Write your code here
        res = float('inf')
        pre = None
        dq = []

        while dq or root:
            while root:
                dq.append(root)
                root = root.left

            root = dq.pop()
            if pre and root.val - pre.val < res:
                res = root.val - pre.val
            pre = root

            root = root.right

        return res


class Solution:
    """
    @param root: the root
    @return: the minimum absolute difference between values of any two nodes
    """

    def get_minimum_difference(self, root: TreeNode) -> int:
        # Write your code here
        self.res = float('inf')
        self.pre = None
        self.helper(root)

        return self.res

    def helper(self, root):
        if not root:
            return

        self.helper(root.left)

        if self.pre and root.val - self.pre.val < self.res:
            self.res = root.val - self.pre.val
        self.pre = root

        self.helper(root.right)


