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
    @param root: The root of the binary search tree.
    @param value: Remove the node with given value.
    @return: The root of the binary search tree after removal.
    """
    def remove_node(self, root: TreeNode, value: int) -> TreeNode:
        # write your code here
        if not root:
            return None

        if root.val < value:
            root.right = self.remove_node(root.right, value)
        elif root.val > value:
            root.left = self.remove_node(root.left, value)
        else:
            if not root.left:
                return root.right
            if not root.right:
                return root.left

            head = root.right
            while head.left:
                head = head.left

            root.val = head.val
            root.right = self.remove_node(root.right, head.val)

        return root


class Solution:
    """
    @param root: The root of the binary search tree.
    @param value: Remove the node with given value.
    @return: The root of the binary search tree after removal.
    """

    def remove_node(self, root: TreeNode, value: int) -> TreeNode:
        # write your code here
        if not root:
            return None

        if root.val < value:
            root.right = self.remove_node(root.right, value)
            return root
        elif root.val > value:
            root.left = self.remove_node(root.left, value)
            return root
        else:
            if not root.left:
                return root.right
            if not root.right:
                return root.left

            head = root.left
            while head and head.right:
                head = head.right

            head.right = root.right  # add right subtree to the right most of left subtree, but unbalance
            return root.left

