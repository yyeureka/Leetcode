from typing import (
    List,
)

class Solution:
    """
    @param nums: an array of integers
    @return: nothing
    """
    def partition_array(self, nums: List[int]):
        # write your code here
        i = 0
        j = len(nums) - 1

        while i <= j:
            while i <= j and 1 == nums[i] % 2:
                i += 1
            while i <= j and 0 == nums[j] % 2:
                j -= 1

            if i <= j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1