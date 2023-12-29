"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""


class Solution:
    """
    @param: root: the root of binary tree
    @return: collect and remove all leaves
    """

    def findLeaves(self, root):
        # write your code here
        if not root:
            return []

        res = []
        self.helper(root, res)

        return res

    def helper(self, root, res):
        if not root:
            return 0

        depth = 1 + max(self.helper(root.left, res), self.helper(root.right, res))

        if depth > len(res):
            res.append([root.val])
        else:
            res[depth - 1].append(root.val)

        return depth
