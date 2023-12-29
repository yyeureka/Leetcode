from typing import (
    List,
)
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


# 类似#106，preorder中的顶点，在inorder中他左边的为左子树，右边的为右子树，recursive细分


class Solution:
    """
    @param preorder: A list of integers that preorder traversal of a tree
    @param inorder: A list of integers that inorder traversal of a tree
    @return: Root of a tree
    """

    def build_tree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # write your code here
        if not preorder or not inorder or len(preorder) != len(inorder):
            return None

        root = TreeNode(preorder[0])
        index = inorder.index(preorder[0])
        root.left = self.build_tree(preorder[1:index + 1], inorder[:index])
        root.right = self.build_tree(preorder[index + 1:], inorder[index + 1:])
        return root


class Solution:
    """
    @param preorder: A list of integers that preorder traversal of a tree
    @param inorder: A list of integers that inorder traversal of a tree
    @return: Root of a tree
    """

    def build_tree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # write your code here
        if not preorder or not inorder or len(preorder) != len(inorder):
            return None

        return self.helper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)

    def helper(self, preorder, pre_s, pre_e, inorder, in_s, in_e):
        if in_s > in_e:
            return None

        root = TreeNode(preorder[pre_s])
        if in_s == in_e:
            return root

        for i in range(in_s, in_e + 1):
            if inorder[i] == preorder[pre_s]:
                break

        root.left = self.helper(preorder, pre_s + 1, pre_s + i - in_s, inorder, in_s, i - 1)
        root.right = self.helper(preorder, pre_s + i - in_s + 1, pre_e, inorder, i + 1, in_e)

        return root

