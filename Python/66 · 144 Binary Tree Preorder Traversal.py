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

# recursive or iterative


# recursive
class Solution:
    """
    @param root: A Tree
    @return: Preorder in ArrayList which contains node values.
    """
    def preorder_traversal(self, root: TreeNode) -> List[int]:
        # write your code here
        if not root:
            return []

        res = []
        self.helper(root, res)

        return res

    def helper(self, node, res):
        if not node:
            return

        res.append(node.val)
        if node.left:
            self.helper(node.left, res)
        if node.right:
            self.helper(node.right, res)


# iterative
class Solution:
    """
    @param root: A Tree
    @return: Preorder in ArrayList which contains node values.
    """

    def preorder_traversal(self, root: TreeNode) -> List[int]:
        # write your code here
        if not root:
            return []

        res = []
        stack = []

        while root or stack:
            while root:
                res.append(root.val)
                stack.append(root)
                root = root.left

            root = stack[-1]
            stack.pop()

            root = root.right

        return res