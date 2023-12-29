
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing
    """
    def flatten(self, root: TreeNode):
        # write your code here
        if not root:
            return
        
        self.helper(root)
           
    def helper(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        
        left_last = self.helper(root.left)
        right_last = self.helper(root.right)

        if left_last:
            left_last.right = root.right
            root.right = root.left
            root.left = None
        
        if right_last:
            return right_last
        if left_last:
            return left_last
        return root


# class Solution:
#     """
#     @param root: a TreeNode, the root of the binary tree
#     @return: nothing
#     """
#     def flatten(self, root: TreeNode):
#         # write your code here
#         if not root:
#             return
        
#         self.flatten(root.left)
#         self.flatten(root.right)
    
#         if root.left:
#             cur = root.left

#             while True:
#                 if not cur.right:
#                     break
            
#                 cur = cur.right

#             cur.right = root.right
#             root.right = root.left
#             root.left = None
           
