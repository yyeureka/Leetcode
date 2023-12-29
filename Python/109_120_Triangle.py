from typing import (
    List,
)

INF = 0x3f3f3f3f


class Solution:
    """
    @param triangle: a list of lists of integers
    @return: An integer, minimum path sum
    """

    def minimum_total(self, triangle: List[List[int]]) -> int:
        # write your code here
        if not triangle:
            return 0

        n = len(triangle)
        dp = triangle.copy()

        for i in range(1, n):
            size = len(dp[i])

            for j in range(size):
                sum = INF
                if j > 0 and dp[i - 1][j - 1] < sum:
                    sum = dp[i - 1][j - 1]
                if j < size - 1 and dp[i - 1][j] < sum:
                    sum = dp[i - 1][j]

                dp[i][j] += sum

        res = INF
        for sum in dp[-1]:
            if sum < res:
                res = sum

        return res


