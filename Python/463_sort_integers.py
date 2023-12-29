from typing import (
    List,
)

# Merge sort
class Solution:
    """
    @param a: an integer array
    @return: nothing
    """

    def sort_integers(self, a: List[int]):
        # write your code here

        if len(a) <= 1:
            return

        n = len(a)

        mid = n >> 1
        left = a[:mid].copy()
        right = a[mid:].copy()
        nl = mid
        nr = n - mid
        self.sort_integers(left)
        self.sort_integers(right)

        l = 0 
        r = 0

        for i in range(n):
            if l >= nl:
                a[i] = right[r]
                r += 1
            elif r >= nr:
                a[i] = left[l]
                l += 1
            elif left[l] > right[r]:
                a[i] = right[r]
                r += 1
            else:
                a[i] = left[l]
                l += 1

# Quick sort:
# class Solution:
#     """
#     @param a: an integer array
#     @return: nothing
#     """
#     def sort_integers(self, a: List[int]):
#         # write your code here
#         if len(a) <= 1:
#             return

#         self.partition(a, 0, len(a) - 1)
    

#     def partition(self, a, start, end):
#         if start >= end:
#             return
        
#         l, r = start, end
#         pivot = a[(start + end) >> 1]

#         while l <= r:
#             while l <= r and a[l] < pivot:
#                 l += 1
#             while l <= r and a[r] > pivot:
#                 r -= 1
#             if l <= r:
#                 a[l], a[r] = a[r], a[l]
#                 l += 1
#                 r -= 1
        
#         self.partition(a, start, r)
#         self.partition(a, l, end)


            
