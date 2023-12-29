from typing import (
    Set,
)

from collections import deque

# n: number of words in dict
# m: length of word
# time: O(n*m*26)
# space: O(n)


class Solution:
    """
    @param start: a string
    @param end: a string
    @param dict: a set of string
    @return: An integer
    """

    def ladder_length(self, start: str, end: str, dict: Set[str]) -> int:
        # write your code here
        if len(start) != len(end):
            return -1
        if start == end:
            return 1

        n = len(start)
        res = 1
        dq = deque([start])

        if start in dict:  # tricky
            dict.remove(start)
        if end not in dict:  # tricky
            dict.add(end)

        while dq:
            size = len(dq)

            for i in range(size):
                cur = dq.popleft()
                if end == cur:
                    return res

                for j in range(n):
                    for z in 'abcdefghijklmnopqrstuvwxyz':
                        if cur[j] == z:
                            continue
                        adj = cur[:j] + z + cur[j + 1:]
                        if adj not in dict:
                            continue

                        dq.append(adj)
                        dict.remove(adj)  # key point, otherwise TLE

            res += 1

        return -1
