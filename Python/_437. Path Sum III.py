# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0

        self.res = 0
        self.helper(root, targetSum, [])

        return self.res

    def helper(self, root, target, path):
        if not root:
            return

        path.append(root.val)

        sum = 0
        for i in range(len(path))[::-1]:
            sum += path[i]

            if target == sum:
                self.res += 1

        if root.left:
            self.helper(root.left, target, path)
        if root.right:
            self.helper(root.right, target, path)

        path.pop()
