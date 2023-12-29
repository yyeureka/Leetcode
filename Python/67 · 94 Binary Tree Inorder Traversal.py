# recersive or iterative


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


# recersive
class Solution:
    """
    @param root: A Tree
    @return: Inorder in ArrayList which contains node values.
    """

    def inorder_traversal(self, root: TreeNode) -> List[int]:
        # write your code here
        if not root:
            return []

        res = []
        self.helper(root, res)

        return res

    def helper(self, root, res):
        if not root:
            return

        if root.left:
            self.helper(root.left, res)

        res.append(root.val)

        if root.right:
            self.helper(root.right, res)


# iterative
class Solution:
    """
    @param root: A Tree
    @return: Inorder in ArrayList which contains node values.
    """

    def inorder_traversal(self, root: TreeNode) -> List[int]:
        # write your code here
        if not root:
            return []

        res = []
        stack = []

        while root or stack:
            while root:
                stack.append(root)
                root = root.left

            root = stack.pop()
            res.append(root.val)

            root = root.right

        return res

