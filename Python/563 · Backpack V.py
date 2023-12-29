from typing import (
    List,
)

# dp 01knapsack 1D circular array

class Solution:
    """
    @param nums: an integer array and all positive numbers
    @param target: An integer
    @return: An integer
    """

    def back_pack_v(self, nums: List[int], target: int) -> int:
        # write your code here
        dp = [0 for _ in range(target + 1)]
        dp[0] = 1  # key point

        for i in nums:
            for j in range(target, -1, -1):  # key point
                if j < i:
                    break

                dp[j] += dp[j - i]

        return dp[target]

