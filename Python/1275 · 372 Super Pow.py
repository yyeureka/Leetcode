from typing import (
    List,
)

class Solution:
    """
    @param a: the given number a
    @param b: the given array
    @return: the result
    """
    def super_pow(self, a: int, b: List[int]) -> int:
        # Write your code here
        if 0 == a:
            return 0
        if not b:
            return 0

        def mod(x):
            return x % 1337

        res = 1
        for i in b:
            res = mod(mod(res ** 10) * mod(a ** i))

        return res


