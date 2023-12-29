from typing import (
    List,
)


class Solution:
    """
    @param words: the list of word.
    @return: the length of the longest string chain.
    """

    def longest_str_chain(self, words: List[str]) -> int:
        if len(words) <= 1:
            return len(words)

        words.sort(key=lambda x: len(x))
        dp = [1 for i in range(len(words))]
        res = 1

        for i in range(len(words)):
            pre = set()
            cur = words[i]

            for j in range(len(cur)):
                pre.add(cur[:j] + cur[j + 1:])

            for j in range(i - 1, -1, -1):
                if len(words[j]) + 1 > len(cur):
                    continue
                if len(words[j]) + 1 < len(cur):
                    break

                if words[j] in pre and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1

            if dp[i] > res:
                res = dp[i]

        return res


class Solution:
    """
    @param words: the list of word.
    @return: the length of the longest string chain.
    """

    def longest_str_chain(self, words: List[str]) -> int:
        if len(words) <= 1:
            return len(words)

        words.sort(key=lambda x: len(x))
        dp = [1 for i in range(len(words))]
        res = 1

        for i in range(len(words)):
            for j in range(i - 1, -1, -1):
                if len(words[j]) + 1 > len(words[i]):
                    continue
                if len(words[j]) + 1 < len(words[i]):
                    break

                if self.valid(words[j], words[i]) and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1

            if dp[i] > res:
                res = dp[i]

        return res

    def valid(self, a, b):
        i = 0
        j = 0

        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                i += 1
            j += 1

        return i == len(a)