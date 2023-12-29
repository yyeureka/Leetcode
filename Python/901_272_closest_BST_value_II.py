from typing import (
    List,
)

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Solution:
    """
    @param root: the given BST
    @param target: the given target
    @param k: the given k
    @return: k values in the BST that are closest to the target
             we will sort your return value in output
    """
    def closest_k_values(self, root: TreeNode, target: float, k: int) -> List[int]:
        # write your code here
        if not root:
            return []
        
        cur = root
        upper = []  # decreasing
        while cur:
            upper.append(cur)
            cur = cur.left
        
        cur = root
        lower = []  # increasing
        while cur:
            lower.append(cur)
            cur = cur.right
        
        while len(upper) > 0 and upper[-1].val < target:
            self.get_larger(upper)
        while len(lower) > 0 and lower[-1].val >= target:  # tricky
            self.get_smaller(lower)
        
        res = []
        while k > 0:
            if not upper:
                res.append(lower[-1].val)
                self.get_smaller(lower)
            elif not lower:
                res.append(upper[-1].val)
                self.get_larger(upper)
            else:
                if target - lower[-1].val <= upper[-1].val - target:
                    res.append(lower[-1].val)
                    self.get_smaller(lower)
                else:
                    res.append(upper[-1].val)
                    self.get_larger(upper)

            k -= 1
        
        return res

    def get_larger(self, upper: List[int]):
        cur = upper.pop()
        cur = cur.right
        while cur:
            upper.append(cur)
            cur = cur.left
    
    def get_smaller(self, lower: List[int]):
        cur = lower.pop()
        cur = cur.left
        while cur:
            lower.append(cur)
            cur = cur.right


# # traverse + BS
# class Solution:
#     """
#     @param root: the given BST
#     @param target: the given target
#     @param k: the given k
#     @return: k values in the BST that are closest to the target
#              we will sort your return value in output
#     """
#     def closest_k_values(self, root: TreeNode, target: float, k: int) -> List[int]:
#         # write your code here
#         if not root:
#             return []
        
#         values = []
#         self.bst(root, values)

#         start, end = 0, len(values) - 1

#         while start + 1 < end:
#             mid = (start + end) // 2
        
#             if values[mid] <= target:
#                 start = mid
#             else:
#                 end = mid
        
#         res = []

#         while k > 0:
#             if start < 0:
#                 res.append(values[end])
#                 end += 1
#             elif end >= len(values):
#                 res.append(values[start])
#                 start -= 1
#             elif target - values[start] < values[end] - target:
#                 res.append(values[start])
#                 start -= 1
#             else:
#                 res.append(values[end])
#                 end += 1
            
#             k -= 1
        
#         return res

#     def bst(self, root: TreeNode, values: List[int]):
#         if not root.left and not root.right:
#             values.append(int(root.val))
#             return
        
#         if root.left:
#             self.bst(root.left, values)

#         values.append(int(root.val))

#         if root.right:
#             self.bst(root.right, values)