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
    @return: the root of the maximum average of subtree
    """

    def find_subtree2(self, root: TreeNode) -> TreeNode:
        # write your code here
        self.max_root = None
        self.max_avg = float('-inf')
        self.helper(root)

        return self.max_root

    def helper(self, root):
        if not root:
            return 0, 0

        sum_l, cnt_l = self.helper(root.left)
        sum_r, cnt_r = self.helper(root.right)

        sum = sum_l + sum_r + root.val
        cnt = cnt_l + cnt_r + 1

        if sum / cnt > self.max_avg:
            self.max_avg = sum / cnt
            self.max_root = root

        return sum, cnt

