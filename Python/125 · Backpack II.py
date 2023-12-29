from typing import (
    List,
)

# dp 01knapsack 1D circular array
# dp 01knapsack 2D


class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param a: Given n items with size A[i]
    @param v: Given n items with value V[i]
    @return: The maximum value
    """
    def back_pack_i_i(self, m: int, a: List[int], v: List[int]) -> int:
        # write your code here
        dp = [0 for _ in range(m + 1)]

        for i in range(len(a)):
            for j in range(m, -1, -1):  # key point, 需要的dp[j - a[i]]不会被提前更新
                if j < a[i]:
                    break

                dp[j] = max(dp[j], dp[j - a[i]] + v[i])

        return dp[m]


class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param a: Given n items with size A[i]
    @param v: Given n items with value V[i]
    @return: The maximum value
    """
    def back_pack_i_i(self, m: int, a: List[int], v: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                dp[i][j] = dp[i - 1][j]

                if j >= a[i - 1]:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + v[i - 1])

        return dp[n][m]
