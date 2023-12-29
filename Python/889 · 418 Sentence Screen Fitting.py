from typing import (
    List,
)


# dp
class Solution:
    """
    @param sentence: a list of string
    @param rows: an integer
    @param cols: an integer
    @return: return an integer, denote times the given sentence can be fitted on the screen
    """
    def words_typing(self, sentence: List[str], rows: int, cols: int) -> int:
        # Write your code here
        n = len(sentence)
        dp = [0 for _ in range(n)]  # the number of words can be fitted in a row start from index i

        for i in range(n):
            index = i
            remain_len = cols

            while len(sentence[index]) <= remain_len:
                dp[i] += 1
                remain_len -= len(sentence[index]) + 1  # key point
                index = (index + 1) % n

        count = 0
        index = 0

        for i in range(rows):
            count += dp[index]
            index = (index + dp[index]) % n

        return count // n


# bruteforce TLE
class Solution:
    """
    @param sentence: a list of string
    @param rows: an integer
    @param cols: an integer
    @return: return an integer, denote times the given sentence can be fitted on the screen
    """

    def words_typing(self, sentence: List[str], rows: int, cols: int) -> int:
        # Write your code here
        count = 0
        index = 0

        for i in range(rows):
            remain_len = cols

            while len(sentence[index]) <= remain_len:
                count += 1
                remain_len -= len(sentence[index]) + 1  # key point

                index += 1
                if index >= len(sentence):
                    index = 0

        return count // len(sentence)


