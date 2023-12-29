from typing import (
    List,
)

class Solution:
    """
    @param nums: A list of integers
    @return: An integer denotes the middle number of the array
    """
    def median(self, nums: List[int]) -> int:
        # write your code here
        n = len(nums)
        return self.quick_select(nums, 0, n - 1, (n + 1) // 2)

    def quick_select(self, nums, start, end, k):
        if start >= end:
            return nums[start]

        l, r = start, end
        pivot = nums[(start + end) // 2]

        while l <= r:
            while l <= r and nums[l] < pivot:
                l += 1
            while l <= r and nums[r] > pivot:
                r -= 1

            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        if r >= k - 1:
            return self.quick_select(nums, start, r, k)
        if l <= k - 1:
            return self.quick_select(nums, l, end, k)
        return nums[k - 1]