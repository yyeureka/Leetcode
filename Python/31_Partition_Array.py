from typing import (
    List,
)


class Solution:
    """
    @param nums: The integer array you should partition
    @param k: An integer
    @return: The index after partition
    """

    def partition_array(self, nums: List[int], k: int) -> int:
        # write your code here
        if not nums:
            return 0

        l = 0
        r = len(nums) - 1

        while l <= r:
            while l <= r and nums[l] < k:
                l += 1
            while l <= r and nums[r] >= k:  # key point
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        return l  # key point
