# similar to lint448/285
# 1、recursive BS方法，逻辑有点绕，O(h)时间
# 2、iterative reversal方法，O(h+k)时间

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


# recursive
class Solution:
    """
    @param root: the given BST
    @param p: the given node
    @return: the in-order predecessor of the given node in the BST
    """
    def inorderPredecessor(self, root, p):
        # write your code here
        if not root or not p:
            return None

        if root.val >= p.val:
            return self.inorderPredecessor(root.left, p)
        else:
            right = self.inorderPredecessor(root.right, p)
            return right if right else root


# iterative
class Solution:
    """
    @param root: the given BST
    @param p: the given node
    @return: the in-order predecessor of the given node in the BST
    """

    def inorderPredecessor(self, root, p):
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

            if root == p:
                return pre

            pre = root
            root = root.right

        return None
