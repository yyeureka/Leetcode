class Solution:
    """
    @param m: positive integer (1 <= m <= 100)
    @param n: positive integer (1 <= n <= 100)
    @return: An integer
    """
    def unique_paths(self, m: int, n: int) -> int:
        # write your code here
        dp = [[0 for i in range(n)] for j in range(m)]
        dp[0][0] = 1

        for i in range(m):
            for j in range(n):
                if j > 0:
                    dp[i][j] += dp[i][j - 1]
                if i > 0:
                    dp[i][j] += dp[i - 1][j]

        return dp[m - 1][n - 1]