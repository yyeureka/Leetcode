
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: The root of binary tree.
    @return: True if this Binary tree is Balanced, or false.
    """
    def is_balanced(self, root: TreeNode) -> bool:
        # write your code here
        if not root:
            return True
        
        return -1 != self.depth(root)
    
    def depth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        left = self.depth(root.left)
        right = self.depth(root.right)

        if -1 == left or -1 == right or abs(left - right) > 1:
            return -1
        return max(left, right) + 1

