# Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
# The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
# Return null if LCA does not exist.

# Example1
# Input:
# {4, 3, 7, #, #, 5, 6}
# 3 5
# 5 6
# 6 7
# 5 8
# Output:
# 4
# 7
# 7
# null
# Explanation:
# 4
# / \
# 3   7
# / \
# 5   6
# LCA(3, 5) = 4
# LCA(5, 6) = 7
# LCA(6, 7) = 7
# LCA(5, 8) = null
# Example2
# Input:
# {1}
# 1 1
# Output:
# 1
# Explanation:
# The tree is just a node, whose value is 1.

# Notice
# node A or node B may not exist in tree.
# Each node has a different value

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""


class Solution:
    """
    @param: root: The root of the binary tree.
    @param: A: A TreeNode
    @param: B: A TreeNode
    @return: Return the LCA of the two nodes.
    """

    def lowestCommonAncestor3(self, root, A, B):
        # write your code here
        if not root or not A or not B:
            return None
        if A == B:
            return A

        return self.helper(root, A, B)[0]

    def helper(self, root, A, B):
        if not root:
            return None, False, False

        node_l, hasA_l, hasB_l = self.helper(root.left, A, B)
        if node_l:
            return node_l, True, True

        node_r, hasA_r, hasB_r = self.helper(root.right, A, B)
        if node_r:
            return node_r, True, True

        hasA = (root == A) or hasA_l or hasA_r
        hasB = (root == B) or hasB_l or hasB_r

        if hasA and hasB:
            return root, True, True
        return None, hasA, hasB
