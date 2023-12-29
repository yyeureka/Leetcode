from typing import (
    List,
)

# have more speed up version


class Solution:
    """
    @param a: a sparse matrix
    @param b: a sparse matrix
    @return: the result of A * B
    """

    def multiply(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        # write your code here
        if not a or not b:
            return [[]]

        r = len(a)
        m = len(a[0])
        c = len(b[0])
        res = [[0 for j in range(c)] for i in range(r)]

        for i in range(r):
            for k in range(m):
                if 0 == a[i][k]:
                    continue

                for j in range(c):
                    if 0 == b[k][j]:
                        continue

                    res[i][j] += a[i][k] * b[k][j]

        return res

