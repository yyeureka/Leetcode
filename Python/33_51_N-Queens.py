from typing import (
    List,
)


class Solution:
    """
    @param n: The number of queens
    @return: All distinct solutions
             we will sort your return value in output
    """

    def solve_n_queens(self, n: int) -> List[List[str]]:
        # write your code here
        if n <= 0:
            return []

        res = []
        cur = []
        c = [False for i in range(n)]  # col
        d1 = [False for i in range(2 * n - 1)]  # diagonal
        d2 = [False for i in range(2 * n - 1)]  # counter diagonal

        self.dfs(n, 0, res, cur, c, d1, d2)

        return res

    def dfs(self, n, index, res, cur, c, d1, d2):
        if index >= n:
            res.append(cur[:])
            return

        str = '.' * n

        for i in range(n):
            if c[i] or d1[index + i] or d2[n - index + i - 1]:  # occupied by other queens
                continue

            c[i] = True
            d1[index + i] = True
            d2[n - index + i - 1] = True
            cur.append(str[:i] + 'Q' + str[i + 1:])
            self.dfs(n, index + 1, res, cur, c, d1, d2)
            cur.pop()
            c[i] = False
            d1[index + i] = False
            d2[n - index + i - 1] = False