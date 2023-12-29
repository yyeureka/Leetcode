from typing import (
    List,
    Set,
)


class Solution:
    """
    @param s: A string
    @param word_dict: A set of words.
    @return: All possible sentences.
             we will sort your return value in output
    """

    def word_break(self, s: str, word_dict: Set[str]) -> List[str]:
        # write your code here
        if not s or not word_dict:
            return []

        memo = {}
        max_len = max([len(word) for word in word_dict])
        return self.dfs(s, word_dict, max_len, memo)

    def dfs(self, s, word_dict, max_len, memo):
        if not s:
            return []
        if s in memo:  # key point
            return memo[s]

        res = []
        if s in word_dict:  # key point
            res.append(s)

        n = len(s)
        for i in range(1, n):
            if i > max_len:  # key point
                break

            left = s[:i]
            if left not in word_dict:
                continue

            right = self.dfs(s[i:], word_dict, max_len, memo)
            for str in right:
                res.append(left + ' ' + str)

        memo[s] = res
        return res


