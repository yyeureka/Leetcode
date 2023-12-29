from typing import (
    List,
)


class Solution:
    """
    @param n: An integer
    @return: a list of combination
             we will sort your return value in output
    """

    def get_factors(self, n: int) -> List[List[int]]:
        # write your code here
        if n < 2:
            return []

        res = []
        self.helper(n, 2, [], res)

        return res

    def helper(self, n, start, cur, res):
        if n < 2:
            res.append(cur[:])
            return

        upper = int(math.sqrt(n))
        for i in range(start, upper + 1):  # key point
            if 0 != n % i:
                continue

            cur.append(i)
            self.helper(n // i, i, cur, res)

            if n // i >= i:  # key point
                res.append(cur + [n // i])

            cur.pop()



