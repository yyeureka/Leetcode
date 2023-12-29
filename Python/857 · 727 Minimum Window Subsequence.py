# dp1 前缀递推
#
# dp2
# dp[i][j]表示匹配T串的前i个字符，S中前j个字符中匹配的起点
# 当前两字符相同时，则有dp[i][j] = dp[i-1][j-1]
# 当两字符不相同时，相当于第j个字符被跳过，则有dp[i][j] = dp[i][j-1]


# dp2
class Solution:
    """
    @param s: a string
    @param t: a string
    @return: the minimum substring of S
    """

    def min_window(self, s: str, t: str) -> str:
        # Write your code here
        if not t or not s:
            return ''

        n = len(s)
        m = len(t)
        dp = [[0 for j in range(n + 1)] for i in range(m + 1)]
        for j in range(n + 1):
            dp[0][j] = j + 1

        start = 0
        length = n + 1
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if t[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]

        for j in range(1, n + 1):
            if 0 == dp[m][j]:
                continue

            if j - dp[m][j] + 1 < length:
                start = dp[m][j] - 1
                length = j - dp[m][j] + 1

        return '' if n + 1 == length else s[start: start + length]