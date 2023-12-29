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

# recursive 1
class Solution:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing
    """
    def invert_binary_tree(self, root: TreeNode):
        # write your code here
        if not root:
            return

        root = self.helper(root)

    def helper(self, root):
        if not root:
            return None

        root.left, root.right = self.helper(root.right), self.helper(root.left)
        return root


# recursive 2
class Solution:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing
    """
    def invert_binary_tree(self, root: TreeNode):
        # write your code here
        if not root:
            return

        root.left, root.right = root.right, root.left
        self.invert_binary_tree(root.right)
        self.invert_binary_tree(root.left)


# iterative
class Solution:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing
    """
    def invert_binary_tree(self, root: TreeNode):
        # write your code here
        if not root:
            return

        dq = collections.deque([root])
        while dq:
            node = dq.popleft()
            node.left, node.right = node.right, node.left

            if node.left:
                dq.append(node.left)
            if node.right:
                dq.append(node.right)