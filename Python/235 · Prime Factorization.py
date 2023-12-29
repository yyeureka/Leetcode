from typing import (
    List,
)

import math


class Solution:
    """
    @param num: An integer
    @return: an integer array
    """

    def prime_factorization(self, num: int) -> List[int]:
        # write your code here
        if num < 2:
            return []

        upper = int(math.sqrt(num))  # without int, range will throw error
        res = []

        for i in range(2, upper + 1):
            while 0 == num % i:
                res.append(i)
                num //= i  # tricky, if use /=, float result

        if 1 != num:  # key point
            res.append(num)

        return res
