from typing import (
    List,
)

class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def subarray_sum_closest(self, nums: List[int]) -> List[int]:
        # write your code here
        if not nums:
            return []

        prefix_sum = [(0, -1)]  # key point
        sum = 0
        diff = float('inf')
        res = [0, 0]

        for i in range(len(nums)):
            sum += nums[i]
            prefix_sum.append((sum, i))

        prefix_sum.sort(key=lambda x: x[0])  # key point

        for i in range(1, len(prefix_sum)):
            if abs(prefix_sum[i][0] - prefix_sum[i - 1][0]) < diff:
                diff = abs(prefix_sum[i][0] - prefix_sum[i - 1][0])

                res[0] = min(prefix_sum[i][1], prefix_sum[i - 1][1]) + 1  # key point
                res[1] = max(prefix_sum[i][1], prefix_sum[i - 1][1])

        return res