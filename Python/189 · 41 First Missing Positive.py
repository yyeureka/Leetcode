from typing import (
    List,
)


class Solution:
    """
    @param a: An array of integers
    @return: An integer
    """

    def first_missing_positive(self, a: List[int]) -> int:
        # write your code here
        i = 0
        n = len(a)

        while i < n:
            while a[i] != i + 1 and 0 < a[i] <= n and a[a[i] - 1] != a[i]:  # key point
                tmp = a[i]
                a[i] = a[tmp - 1]
                a[tmp - 1] = tmp

            i += 1

        for i in range(n):
            if a[i] != i + 1:  # key point
                return i + 1

        return n + 1  # key point