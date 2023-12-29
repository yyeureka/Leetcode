from typing import (
    List,
)


class Solution:
    """
    @param matrix: a matrix
    @return: return how many square submatrices have all ones
    """

    def count_squares(self, matrix: List[List[int]]) -> int:
        # write your code here
        if not matrix or not matrix[0]:
            return 0

        n = len(matrix)
        m = len(matrix[0])
        dp = [[0 for j in range(m)] for i in range(n)]  # the number of all 1 squares ended with i, j
        res = 0

        for i in range(n):
            for j in range(m):
                if 0 == matrix[i][j]:
                    continue

                if 0 == i or 0 == j:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1  # key point

                res += dp[i][j]

        return res

