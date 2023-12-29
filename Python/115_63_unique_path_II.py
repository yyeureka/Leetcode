from typing import (
    List,
)

class Solution:
    """
    @param obstacle_grid: A list of lists of integers
    @return: An integer
    """
    def unique_paths_with_obstacles(self, obstacle_grid: List[List[int]]) -> int:
        # write your code here
        if len(obstacle_grid) <= 0:
            return 0

        m = len(obstacle_grid)
        n = len(obstacle_grid[0])

        if 1 == obstacle_grid[m - 1][n - 1] or 1 == obstacle_grid[0][0]:
            return 0

        dp = [[0 for i in range(n)] for j in range(m)]
        dp[0][0] = 1

        for i in range(m):
            for j in range(n):
                if 1 == obstacle_grid[i][j]:
                    continue
                
                if i > 0:
                    dp[i][j] += dp[i - 1][j]
                if j > 0:
                    dp[i][j] += dp[i][j - 1]
        
        return dp[m - 1][n - 1]