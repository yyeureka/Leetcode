from typing import (
    List,
)

# prefix sum + two sum
# sum[i~j] = prefix_sum[j] - prefix_sum[i-1]

class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """

    def subarray_sum(self, nums: List[int]) -> List[int]:
        # write your code here
        if not nums:
            return []

        n = len(nums)
        sum = 0
        prefix_sum = {0: -1}  # key point, prefix sum: index

        for i in range(n):
            sum += nums[i]

            if sum in prefix_sum:
                return [prefix_sum[sum] + 1, i]

            prefix_sum[sum] = i

        return []