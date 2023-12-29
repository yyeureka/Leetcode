from typing import (
    List,
)


class Solution:
    """
    @param nums: A list of integer which is 0, 1 or 2
    @return: nothing
    """

    def sort_colors(self, nums: List[int]):
        # write your code here
        l = 0
        r = len(nums) - 1
        i = 0

        while i <= r:
            if 0 == nums[i]:
                nums[l], nums[i] = nums[i], nums[l]
                l += 1
                i += 1
            elif 2 == nums[i]:
                nums[r], nums[i] = nums[i], nums[r]
                r -= 1
            else:
                i += 1

