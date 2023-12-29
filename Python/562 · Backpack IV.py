from typing import (
    List,
)

# complete knapsack

class Solution:
    """
    @param nums: an integer array and all positive numbers, no duplicates
    @param target: An integer
    @return: An integer
    """
    def back_pack_i_v(self, nums: List[int], target: int) -> int:
        # write your code here
        dp = [0 for _ in range(target + 1)]
        dp[0] = 1

        for i in nums:
            for j in range(target + 1):
                if j >= i:
                    dp[j] += dp[j - i]

        return dp[target]