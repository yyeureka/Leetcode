class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: the given BST
    @param target: the given target
    @return: the value in the BST that is closest to the target
    """
    def closest_value(self, root: TreeNode, target: float) -> int:
        # write your code here
        if not root:
            return -1

        upper = self.upper_bound(root, target)
        lower = self.lower_bound(root, target)

        if not upper:
            return lower.val
        if not lower:
            return upper.val
        if target - lower.val <= upper.val - target:
            return lower.val
        return upper.val
    
    def upper_bound(self, root: TreeNode, target: float) -> TreeNode:
        if not root:
            return None
        
        if target == root.val:
            return root
        elif root.val < target:
            return self.upper_bound(root.right, target)
        
        left = self.upper_bound(root.left, target)

        return left if left else root
    
    def lower_bound(self, root: TreeNode, target: float) -> TreeNode:
        if not root:
            return None
        
        if target == root.val:
            return root
        elif root.val > target:
            return self.lower_bound(root.left, target)
        
        right = self.lower_bound(root.right, target)

        return right if right else root


# class Solution:
#     """
#     @param root: the given BST
#     @param target: the given target
#     @return: the value in the BST that is closest to the target
#     """
#     def closest_value(self, root: TreeNode, target: float) -> int:
#         # write your code here
#         if not root:
#             return None

#         res = root.val

#         if root.val < target:
#             if root.right:
#                 right = self.closest_value(root.right, target)

#                 if abs(right - target) < abs(root.val - target):
#                     res = right
#         elif root.val > target:
#             if root.left:
#                 left = self.closest_value(root.left, target)

#                 if abs(left - target) < abs(root.val - target):
#                     res = left

#         return int(res)