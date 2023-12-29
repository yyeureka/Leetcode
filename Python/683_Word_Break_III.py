from typing import (
    Set,
)


class Solution:
    """
    @param s: A string
    @param dict: A set of word
    @return: the number of possible sentences.
    """

    def word_break3(self, s: str, dict: Set[str]) -> int:
        # Write your code here
        if not s:
            return 1
        if not dict:
            return 0

        n = len(s)
        str = s.lower()  # tricky
        dp = [0 for i in range(n + 1)]
        dp[0] = 1

        max_len = 0
        words = set()
        for word in dict:
            words.add(word.lower())  # tricky

            if len(word) > max_len:
                max_len = len(word)

        for i in range(1, n + 1):
            for j in range(1, max_len + 1):
                if i < j:
                    break

                if dp[i - j] > 0 and str[i - j: i] in words:
                    dp[i] += dp[i - j]

        return dp[n]

