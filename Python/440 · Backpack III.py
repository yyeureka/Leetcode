from typing import (
    List,
)

# complete knapsack 1D

class Solution:
    """
    @param a: an integer array
    @param v: an integer array
    @param m: An integer
    @return: an array
    """
    def back_pack_i_i_i(self, a: List[int], v: List[int], m: int) -> int:
        # write your code here
        dp = [0 for _ in range(m + 1)]

        for i in range(len(a)):
            for j in range(m + 1):
                if j >= a[i] and dp[j - a[i]] + v[i] > dp[j]:
                    dp[j] = dp[j - a[i]] + v[i]

        return dp[m]