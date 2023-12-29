from typing import (
    List,
)

# res[i][j]当前房子涂j色的最小cost等于前一个房子涂非j色的的min+cost[i][j]

class Solution:
    """
    @param costs: n x 3 cost matrix
    @return: An integer, the minimum cost to paint all houses
    """
    def min_cost(self, costs: List[List[int]]) -> int:
        # write your code here
        if not costs:
            return 0

        n = len(costs)
        m = len(costs[0])
        dp = [[float('inf') for j in range(m)] for i in range(n)]
        for j in range(m):
            dp[0][j] = costs[0][j]

        for i in range(1, n):
            for j in range(m):
                for k in range(m):
                    if j == k:
                        continue

                    dp[i][j] = min(dp[i][j], dp[i - 1][k])

                dp[i][j] += costs[i][j]

        return min(dp[n - 1])
