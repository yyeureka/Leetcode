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

class Solution:
    """
    @param root: the root of binary tree
    @param target: An integer
    @return: all valid paths
             we will sort your return value in output
    """
    def binary_tree_path_sum(self, root: TreeNode, target: int) -> List[List[int]]:
        # write your code here
        if not root:
            return []

        res = []
        self.helper(root, target, [], res)

        return res

    def helper(self, node, target, cur, res):
        target -= node.val
        path = cur + [node.val]

        if not node.left and not node.right:
            if 0 == target:
                res.append(path)
            return

        if node.left:
            self.helper(node.left, target, path, res)
        if node.right:
            self.helper(node.right, target, path, res)


class Solution:
    """
    @param root: the root of binary tree
    @param target: An integer
    @return: all valid paths
             we will sort your return value in output
    """
    def binary_tree_path_sum(self, root: TreeNode, target: int) -> List[List[int]]:
        # write your code here
        if not root:
            return []

        res = []
        self.helper(root, target, [], res)

        return res

    def helper(self, root, target, path, res):
        if not root:
            return

        path.append(root.val)
        target -= root.val

        if not root.left and not root.right and 0 == target:
            res.append(path[:])  # key point

        if root.left:
            self.helper(root.left, target, path, res)
        if root.right:
            self.helper(root.right, target, path, res)

        path.pop()  # key point
