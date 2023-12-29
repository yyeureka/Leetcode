from typing import (
    List,
)

class Solution:
    """
    @param nums: a list of integers.
    @param k: length of window.
    @return: the sum of the element inside the window at each moving.
    """
    def win_sum(self, nums: List[int], k: int) -> List[int]:
        # write your code here
        sum = 0
        res = []

        for i in range(len(nums)):
            sum += nums[i]
            if i >= k:
                sum -= nums[i - k]

            if i >= k - 1:
                res.append(sum)

        return res
