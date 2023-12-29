from typing import (
    List,
)

# dfs memo, similar to word break or palindrome partition

class Solution:
    """
    @param words: List[str]
    @return: return List[str]
             we will sort your return value in output
    """
    def find_all_concatenated_words_in_a_dict(self, words: List[str]) -> List[str]:
        # write your code here
        res = []
        dp = {}
        hash = set(words)

        for word in words:
            hash.remove(word)
            if self.helper(word, hash, dp):
                res.append(word)
            hash.add(word)

        return res

    def helper(self, word, hash, dp):
        if word in hash:
            return True
        if word in dp:
            return dp[word]

        flag = False
        for i in range(1, len(word)):
            if word[:i] in hash and self.helper(word[i:], hash, dp):
                flag = True
                break

        dp[word] = flag
        return flag
