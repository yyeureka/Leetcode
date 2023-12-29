from typing import (
    List,
)

# 3 pointers

class Solution:
    """
    @param nums: an integer array
    @param low: An integer
    @param high: An integer
    @return: nothing
    """
    def partition2(self, nums: List[int], low: int, high: int):
        # write your code here
        l = 0
        r = len(nums) - 1
        i = 0

        while i <= r:
            if nums[i] < low:
                nums[i], nums[l] = nums[l], nums[i]
                i += 1
                l += 1
            elif nums[i] > high:
                nums[i], nums[r] = nums[r], nums[i]
                r -= 1
            else:
                i += 1