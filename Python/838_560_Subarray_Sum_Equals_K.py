from typing import (
    List,
)

# prefix sum + two sum


class Solution:
    """
    @param nums: a list of integer
    @param k: an integer
    @return: return an integer, denote the number of continuous subarrays whose sum equals to k
    """

    def subarray_sum_equals_k(self, nums: List[int], k: int) -> int:
        # write your code here
        if not nums:
            return 0

        res = 0
        n = len(nums)
        sum = 0
        prefix_sum = {0: 1}  # prefix sum: count

        for i in range(n):
            sum += nums[i]

            target = sum - k

            if target in prefix_sum:
                res += prefix_sum[target]

            if sum in prefix_sum:
                prefix_sum[sum] += 1
            else:
                prefix_sum[sum] = 1

        return res