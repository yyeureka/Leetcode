# similar to 204/lint1324


from typing import (
    List,
)

import math


class Solution:
    """
    @param n: an integer
    @return: return all prime numbers within n.
    """

    def prime(self, n: int) -> List[int]:
        # write your code here
        if n < 2:
            return []

        upper = math.sqrt(n)
        prime = [True for i in range(n + 1)]

        res = []
        for i in range(2, n + 1):
            if not prime[i]:
                continue

            res.append(i)

            if i > upper:
                continue

            for j in range(i * i, n + 1, i):
                prime[j] = False

        return res


