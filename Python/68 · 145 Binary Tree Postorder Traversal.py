# reversive or iterative


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


# reversive
class Solution:
    """
    @param root: A Tree
    @return: Postorder in ArrayList which contains node values.
    """

    def postorder_traversal(self, root: TreeNode) -> List[int]:
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
        if root.right:
            self.helper(root.right, res)

        res.append(root.val)


# iterative
class Solution:
    """
    @param root: A Tree
    @return: Postorder in ArrayList which contains node values.
    """

    def postorder_traversal(self, root: TreeNode) -> List[int]:
        # write your code here
        if not root:
            return []

        res = []
        stack = []

        while root or stack:
            while root:
                res.append(root.val)
                stack.append(root)
                root = root.right

            root = stack[-1]
            stack.pop()

            root = root.left

        return res[::-1]

