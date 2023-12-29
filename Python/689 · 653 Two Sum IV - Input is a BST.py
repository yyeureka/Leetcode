"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

# inorder traversal or bfs or whatever + set, O(n), O(n)


class Solution:
    """
    @param: : the root of tree
    @param: : the target sum
    @return: two numbers from tree which sum is n
    """

    def twoSum(self, root, n):
        # write your code here
        if not root:
            return None

        stack = []
        nums = set()

        while root or stack:
            while root:
                stack.append(root)
                root = root.left

            root = stack[-1]
            stack.pop()

            if n - root.val in nums:
                return n - root.val, root.val
            nums.add(root.val)

            root = root.right

        return None
