from typing import (
    List,
)

# 2D prefix sum + two sum, similar to lint944

class Solution:
    """
    @param matrix: an integer matrix
    @return: the coordinate of the left-up and right-down number
    """
    def submatrix_sum(self, matrix: List[List[int]]) -> List[List[int]]:
        # write your code here
        if not matrix or not matrix[0]:
            return [[]]

        n = len(matrix)
        m = len(matrix[0])
        prefix = [[0 for j in range(m)] for i in range(n + 1)]

        for i in range(n):
            for j in range(m):
                prefix[i + 1][j] = prefix[i][j] + matrix[i][j]

        for up in range(n):
            for down in range(up + 1, n + 1):
                sum = 0
                pre = {0: -1}  # key point!

                for j in range(m):
                    sum += prefix[down][j] - prefix[up][j]

                    if sum in pre:
                        return [[up, pre[sum] + 1], [down - 1, j]]  # key point!

                    if sum not in pre:
                        pre[sum] = j

        return [[]]


# leetcode 1074
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        if not matrix or not matrix[0]:
            return 0

        n = len(matrix)
        m = len(matrix[0])
        prefix = [[0 for j in range(m)] for i in range(n + 1)]
        res = 0

        for i in range(n):
            for j in range(m):
                prefix[i + 1][j] = prefix[i][j] + matrix[i][j]

        for up in range(n):
            for down in range(up + 1, n + 1):
                sum = 0
                pre = {0: 1}  # key point!

                for j in range(m):
                    sum += prefix[down][j] - prefix[up][j]

                    if sum - target in pre:
                        res += pre[sum - target]

                    if sum not in pre:
                        pre[sum] = 1
                    else:
                        pre[sum] += 1

        return res