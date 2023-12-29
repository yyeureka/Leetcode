"""
Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""

# 1、recursive BS方法，逻辑有点绕，O(h)时间
# 2、iterative reversal方法，O(h+k)时间


# Recursive
class Solution:
    """
    @param: root: The root of the BST.
    @param: p: You need find the successor node of p.
    @return: Successor of p.
    """

    def inorderSuccessor(self, root, p):
        # write your code here
        if not root or not p:
            return None

        if root.val <= p.val:
            return self.inorderSuccessor(root.right, p)
        else:
            left = self.inorderSuccessor(root.left, p)
            return left if left else root


# Iterative
class Solution:
    """
    @param: root: The root of the BST.
    @param: p: You need find the successor node of p.
    @return: Successor of p.
    """
    def inorderSuccessor(self, root, p):
        # write your code here
        if not root or not p:
            return None

        stack = []
        pre = None

        while root or stack:
            while root:
                stack.append(root)
                root = root.left

            root = stack[-1]
            stack.pop()

            if pre == p:
                return root

            pre = root
            root = root.right

        return None
