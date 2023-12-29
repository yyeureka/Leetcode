from typing import (
    List,
)


# 2 pointers+hash
class Solution:
    """
    @param s: a string
    @param p: a string
    @return: a list of index
    """

    def find_anagrams(self, s: str, p: str) -> List[int]:
        # write your code here
        if not s or not p or len(s) < len(p):
            return []

        n = len(s)
        m = len(p)
        words = {}
        count = m
        res = []

        for i in p:
            if i in words:
                words[i] += 1
            else:
                words[i] = 1

        for i in range(n):
            if s[i] in words:
                words[s[i]] -= 1
            else:
                words[s[i]] = -1

            if words[s[i]] >= 0:
                count -= 1

            if i >= m:
                words[s[i - m]] += 1

                if words[s[i - m]] > 0:
                    count += 1

            if 0 == count:
                res.append(i - m + 1)

        return res

