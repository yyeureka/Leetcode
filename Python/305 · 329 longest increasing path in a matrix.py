from typing import (
    List,
)

# dp[i][j] the length of longest path start from i, j
# if dp[i][j] > 0, return dp[i][j]


class Solution:
    """
    @param matrix: A matrix
    @return: An integer.
    """

    def longest_increasing_path(self, matrix: List[List[int]]) -> int:
        # Write your code here.
        if not matrix or not matrix[0]:
            return 0

        n = len(matrix)
        m = len(matrix[0])
        dp = [[-1 for j in range(m)] for i in range(n)]
        res = 0

        for i in range(n):
            for j in range(m):
                res = max(res, self.helper(matrix, i, j, dp))

        return res

    def helper(self, matrix, i, j, dp):
        if dp[i][j] > 0:
            return dp[i][j]

        n = len(matrix)
        m = len(matrix[0])
        res = 0

        for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            i_, j_ = i + di, j + dj

            if i_ < 0 or i_ >= n or j_ < 0 or j_ >= m or matrix[i_][j_] <= matrix[i][j]:
                continue

            res = max(res, self.helper(matrix, i_, j_, dp))

        res += 1
        dp[i][j] = res

        return res
