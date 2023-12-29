from typing import (
    List,
)


class Solution:
    """
    @param matrix: the given matrix
    @return: the largest possible sum
    """

    def max_submatrix(self, matrix: List[List[int]]) -> int:
        # write your code here
        if not matrix or not matrix[0]:  # tricky
            return 0

        n = len(matrix)
        m = len(matrix[0])
        prefix = [[0 for j in range(m)] for i in range(n + 1)]  # prefix sum of each column
        res = float('-inf')

        for i in range(n):
            for j in range(m):
                prefix[i + 1][j] = prefix[i][j] + matrix[i][j]

        for up in range(n):
            for down in range(up + 1, n + 1):
                sum = 0                  # prefix sum of up~down-1, 0~j
                min_sum = 0              # min prefix sum of up~down-1, 0~j

                for j in range(m):
                    sum += prefix[down][j] - prefix[up][j]
                    if sum - min_sum > res:
                        res = sum - min_sum
                    if sum < min_sum:
                        min_sum = sum

        return res


