from typing import (
    List,
)

class Solution:
    """
    @param m: the 01 matrix
    @return: the longest line of consecutive one in the matrix
    """
    def longest_line(self, m: List[List[int]]) -> int:
        # Write your code here
        if not m or not m[0]:
            return 0

        res = 0
        for i in range(len(m)):
            for j in range(len(m[0])):
                if 0 == m[i][j]:
                    continue

                res = max(res, self.helper(m, i, j))

        return res

    def helper(self, m, i, j):
        row = len(m)
        col = len(m[0])
        res = 1

        if 0 == j or 1 != m[i][j - 1]:  # check horizontal
            y = j + 1
            while y < col and 1 == m[i][y]:
                y += 1
            res = max(res, y - j)

        if 0 == i or 1 != m[i - 1][j]:  # check vertical
            x = i + 1
            while x < row and 1 == m[x][j]:
                x += 1
            res = max(res, x - i)

        if 0 == i or 0 == j or 1 != m[i - 1][j - 1]:  # check diagonal
            x, y = i + 1, j + 1
            while x < row and y < col and 1 == m[x][y]:
                x += 1
                y += 1
            res = max(res, x - i)

        if 0 == i or col - 1 == j or 1 != m[i - 1][j + 1]:  # check anti-diagonal
            x, y = i + 1, j - 1
            while x < row and y >= 0 and 1 == m[x][y]:
                x += 1
                y -= 1
            res = max(res, x - i)

        return res
