"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

# Only works when A,B exist!!
# If A,B may not exist, lint578


class Solution:
    """
    @param: root: The root of the binary tree.
    @param: A: A TreeNode in a Binary.
    @param: B: A TreeNode in a Binary.
    @return: Return the least common ancestor(LCA) of the two nodes.
    """

    def lowestCommonAncestor(self, root, A, B):
        # write your code here
        if not root or not A or not B:
            return None
        if A == B:
            return A

        if A == root or B == root:
            return root

        left = self.lowestCommonAncestor(root.left, A, B)
        right = self.lowestCommonAncestor(root.right, A, B)

        if left and not right:
            return left
        elif right and not left:
            return right
        elif left and right:
            return root
        else:
            return None



