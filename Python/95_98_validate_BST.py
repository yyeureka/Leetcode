
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: The root of binary tree.
    @return: True if the binary tree is BST, or false
    """
    pre = None

    def is_valid_b_s_t(self, root: TreeNode) -> bool:
        # write your code here
        if not root:
            return True
        
        if not self.is_valid_b_s_t(root.left):
            return False
        
        if self.pre and self.pre.val >= root.val:
            return False
        self.pre = root

        return self.is_valid_b_s_t(root.right)

# class Solution:
#     """
#     @param root: The root of binary tree.
#     @return: True if the binary tree is BST, or false
#     """
#     def is_valid_b_s_t(self, root: TreeNode) -> bool:
#         # write your code here
#         if not root:
#             return True
        
#         return self.helper(root)[0]
    
#     def helper(self, root: TreeNode):
#         if not root:
#             return True, 0, 0
        
#         high, low = root.val, root.val

#         if root.left:
#             res, h, l = self.helper(root.left)
#             low = l

#             if not res or h >= root.val:
#                 return False, 0, 0
#         if root.right:
#             res, h, l = self.helper(root.right)
#             high = h

#             if not res or l <= root.val:
#                 return False, 0, 0

#         return True, high, low