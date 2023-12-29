from typing import (
    List,
)

# 1:
# 对 S 进行一次遍历得到 nxtPos[n][26] 数组, 其中 nxtPos[i] 表示串S的第i个位置起, the left most 'a'~'z' 的位置.
# 借助 nxtPos 数组我们可以在 O(word.length) 的时间内判断出 word 是否 S 的子序列.

# 2: brute force check if word is s's subsequence - TLE


class Solution:
    """
    @param s: a string
    @param words: a dictionary of words
    @return: the number of words[i] that is a subsequence of S
    """

    def num_matching_subseq(self, s: str, words: List[str]) -> int:
        # Write your code here
        res = 0
        n = len(s)

        dict = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11,
                'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22,
                'x': 23, 'y': 24, 'z': 25}

        nextPos = [[] for i in range(n)]
        tmp = [-1 for i in range(26)]

        for i in range(n - 1, -1, -1):
            tmp[dict[s[i]]] = i
            nextPos[i] = tmp[:]  # tricky

        for word in words:
            i = 0
            j = 0
            while i < len(s) and j < len(word):
                if -1 == nextPos[i][dict[word[j]]]:
                    break

                i = nextPos[i][dict[word[j]]] + 1
                j += 1

            if j == len(word):
                res += 1

        return res


# TLE
class Solution:
    """
    @param s: a string
    @param words: a dictionary of words
    @return: the number of words[i] that is a subsequence of S
    """

    def num_matching_subseq(self, s: str, words: List[str]) -> int:
        # Write your code here
        res = 0

        for word in words:
            i = 0
            j = 0

            while j < len(word):
                if i >= len(s):
                    break

                if s[i] == word[j]:
                    i += 1
                    j += 1
                else:
                    i += 1

            if j >= len(word):
                res += 1

        return res
