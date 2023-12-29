from typing import (
    List,
)

# dfs+memo O(n*m)

DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]


class Solution:
    """
    @param matrix: A 2D-array of integers
    @return: an integer
    """

    def longest_continuous_increasing_subsequence2(self, matrix: List[List[int]]) -> int:
        # write your code here
        if not matrix:
            return 0

        n = len(matrix)
        m = len(matrix[0])
        dp = [[-1 for j in range(m)] for i in range(n)]  # the length to the end of current IS
        res = 1

        for i in range(n):
            for j in range(m):
                self.dfs(matrix, i, j, dp)

                if dp[i][j] > res:
                    res = dp[i][j]

        return res

    def dfs(self, matrix, i, j, dp):
        if -1 != dp[i][j]:  # visited
            return

        dp[i][j] = 1

        for delta_i, delta_j in DIRECTIONS:
            next_i = i + delta_i
            next_j = j + delta_j

            if next_i < 0 or next_i >= len(matrix) or next_j < 0 or next_j >= len(matrix[0]) or matrix[next_i][
                next_j] <= matrix[i][j]:
                continue

            self.dfs(matrix, next_i, next_j, dp)

            if dp[next_i][next_j] + 1 > dp[i][j]:
                dp[i][j] = dp[next_i][next_j] + 1




