class Solution:
    """
    @param s: A string
    @param p: A string includes "." and "*"
    @return: A boolean
    """

    def is_match(self, s: str, p: str) -> bool:
        # write your code here
        if not p:
            return not s
        if not s:
            for i in range(1, len(p), 2):
                if '*' != p[i]:
                    return False
            return '*' == p[-1]

        n = len(s)
        m = len(p)
        dp = [[False for j in range(m + 1)] for i in range(n + 1)]
        dp[0][0] = True
        for j in range(2, m + 1):
            if '*' == p[j - 1]:
                dp[0][j] = dp[0][j - 2]  # key point

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if '.' == p[j - 1] or s[i - 1] == p[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                elif '*' == p[j - 1]:
                    if j >= 2:
                        dp[i][j] |= dp[i][j - 2]
                    if s[i - 1] == p[j - 2] or '.' == p[j - 2]:  # tricky
                        dp[i][j] |= dp[i - 1][j]

        return dp[n][m]