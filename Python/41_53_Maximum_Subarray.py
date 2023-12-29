from typing import (
    List,
)


class Solution:
    """
    @param nums: A list of integers
    @return: A integer indicate the sum of max subarray
    """

    def max_sub_array(self, nums: List[int]) -> int:
        # write your code here
        if not nums:
            return 0

        res = nums[0]
        sum = 0  # prefix sum
        min = 0  # min prefix sum

        for num in nums:
            sum += num

            if sum - min > res:
                res = sum - min

            if sum < min:
                min = sum

        return res