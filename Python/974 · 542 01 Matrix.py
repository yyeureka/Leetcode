from typing import (
    List,
)

from collections import deque


# BFS
# DP

class Solution:
    """
    @param matrix: a 0-1 matrix
    @return: return a matrix
    """

    def update_matrix(self, matrix: List[List[int]]) -> List[List[int]]:
        # write your code here
        n, m = len(matrix), len(matrix[0])
        dist = [[float('inf') for j in range(m)] for i in range(n)]
        dq = deque()

        for i in range(n):
            for j in range(m):
                if 0 == matrix[i][j]:
                    dq.append((i, j))
                    dist[i][j] = 0

        while dq:
            i, j = dq.popleft()
            for ni, nj in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if ni < 0 or ni >= n or nj < 0 or nj >= m or dist[ni][nj] <= dist[i][j] + 1:
                    continue

                dist[ni][nj] = dist[i][j] + 1
                dq.append((ni, nj))

        return dist


class Solution:
    """
    @param matrix: a 0-1 matrix
    @return: return a matrix
    """

    def update_matrix(self, matrix: List[List[int]]) -> List[List[int]]:
        # write your code here
        n, m = len(matrix), len(matrix[0])
        dp = [[float('inf') for j in range(m)] for i in range(n)]

        for i in range(n):
            for j in range(m):
                if 0 == matrix[i][j]:
                    dp[i][j] = 0

                if i > 0:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)
                if j > 0:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1)

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if i < n - 1:
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1)
                if j < m - 1:
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1)

        return dp