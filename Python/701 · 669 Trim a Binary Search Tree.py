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
    @param root: given BST
    @param minimum: the lower limit
    @param maximum: the upper limit
    @return: the root of the new tree
    """
    def trim_b_s_t(self, root: TreeNode, minimum: int, maximum: int) -> TreeNode:
        # write your code here
        if not root or minimum > maximum:
            return None

        if root.val < minimum:
            return self.trim_b_s_t(root.right, minimum, maximum)
        elif root.val > maximum:
            return self.trim_b_s_t(root.left, minimum, maximum)
        else:
            root.left = self.trim_b_s_t(root.left, minimum, maximum)
            root.right = self.trim_b_s_t(root.right, minimum, maximum)
            return root
