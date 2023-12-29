from typing import (
    List,
)
from lintcode import (
    TreeNode,
)

# similar to lint73/105

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param inorder: A list of integers that inorder traversal of a tree
    @param postorder: A list of integers that postorder traversal of a tree
    @return: Root of a tree
    """
    def build_tree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        # write your code here
        if not inorder or not postorder:
            return None

        root = TreeNode(postorder[-1])
        index = inorder.index(postorder[-1])
        root.left = self.build_tree(inorder[:index], postorder[:index])
        root.right = self.build_tree(inorder[index + 1:], postorder[index:-1])

        return root
