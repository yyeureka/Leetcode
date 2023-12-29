from typing import (
    List,
)

class Solution:
    """
    @param grid: a list of lists of integers
    @return: An integer, minimizes the sum of all numbers along its path
    """
    def min_path_sum(self, grid: List[List[int]]) -> int:
        # write your code here
        if len(grid) <= 0:
            return 0
        
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for i in range(n)] for j in range(m)]

        for i in range(m):
            for j in range(n):
                dp[i][j] = 0x3f3f3f3f
                if i > 0 and dp[i - 1][j] < dp[i][j]:
                    dp[i][j] = dp[i - 1][j]
                if j > 0 and dp[i][j - 1] < dp[i][j]:
                    dp[i][j] = dp[i][j - 1]

                if 0x3f3f3f3f == dp[i][j]:
                    dp[i][j] = 0
                dp[i][j] += grid[i][j]
        
        return dp[m - 1][n - 1]
