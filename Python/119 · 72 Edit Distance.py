class Solution:
    """
    @param word1: A string
    @param word2: A string
    @return: The minimum number of steps
    """
    def min_distance(self, word1, word2):
        # write your code here
        n = len(word1)
        m = len(word2)
        dp = [[0 for j in range(m + 1)] for i in range(n + 1)]

        for i in range(1, n + 1):
            dp[i][0] = i
        for j in range(1, m + 1):
            dp[0][j] = j

        for i in range(n):
            for j in range(m):
                if word1[i] == word2[j]:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1

        return dp[n][m]