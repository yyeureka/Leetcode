# dp
# dfs - TLE


# dp
class Solution:
    """
    @param s: A string
    @param p: A string includes "?" and "*"
    @return: is Match?
    """

    def is_match(self, s: str, p: str) -> bool:
        # write your code here
        if not p:
            return not s
        if not s:
            for i in p:
                if '*' != i:
                    return False
            return True

        n = len(s)
        m = len(p)
        dp = [[False for j in range(m + 1)] for i in range(n + 1)]
        dp[0][0] = True
        for j in range(1, m + 1):
            if '*' == p[j - 1]:
                dp[0][j] = dp[0][j - 1]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if '?' == p[j - 1] or s[i - 1] == p[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                elif '*' == p[j - 1]:
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]  # key point, no need dp[i - 1][j - 1]

        return dp[n][m]


# dfs
class Solution:
    """
    @param s: A string
    @param p: A string includes "?" and "*"
    @return: is Match?
    """

    def is_match(self, s: str, p: str) -> bool:
        # write your code here
        return self.dfs(s, p)

    def dfs(self, s, p):
        if not p:
            return not s
        if not s:
            for i in p:
                if '*' != i:
                    return False
            return True

        if '?' == p[0] or s[0] == p[0]:
            return self.dfs(s[1:], p[1:])
        elif '*' == p[0]:
            for i in range(len(s) + 1):
                if self.dfs(s[i:], p[1:]):
                    return True

        return False