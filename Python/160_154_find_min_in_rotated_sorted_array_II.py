from typing import (
    List,
)

class Solution:
    """
    @param nums: a rotated sorted array
    @return: the minimum number in the array
    """
    def find_min(self, nums: List[int]) -> int:
        # write your code here
        start = 0
        end = len(nums) - 1

        while start + 1 < end:
            mid = (start + end) >> 1

            if nums[start] < nums[end]:
                return nums[start]
            
            if nums[start] == nums[mid]:
                start += 1
            elif nums[start] < nums[mid]:
                start = mid
            else:
                end = mid
        
        return min(nums[start], nums[end])
