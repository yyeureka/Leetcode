from typing import (
    Set,
)

# DP
# DFS - TLE

# DP
class Solution:
    """
    @param s: A string
    @param word_set: A dictionary of words dict
    @return: A boolean
    """
    def word_break(self, s: str, word_set: Set[str]) -> bool:
        # write your code here
        if not s:
            return True
        if not word_set:
            return False

        n = len(s)
        dp = [False for i in range(n + 1)]
        dp[0] = True
        max_len = max([len(word) for word in word_set])  # key point

        for i in range(1, n + 1):
            for j in range(1, max_len + 1):  # from left to right may TLE
                if i < j:
                    break
                if dp[i - j] and s[i - j: i] in word_set:
                    dp[i] = True
                    break

        return dp[n]


# DFS
class Solution:
    """
    @param s: A string
    @param word_set: A dictionary of words dict
    @return: A boolean
    """
    def word_break(self, s: str, word_set: Set[str]) -> bool:
        # write your code here
        return self.dfs(s, word_set)

    def dfs(self, s, word_set):
        if not s:
            return True

        for word in word_set:
            if not s.startswith(word):
                continue

            if self.dfs(s[len(word):], word_set):
                return True

        return False
