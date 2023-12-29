from typing import (
    List,
)

# 2D prefix sum, similar to lint 944

class Solution:
    """
    @param arr: The given matrix
    @return: Return the mininum sum
    """

    def minimum_submatrix(self, arr: List[List[int]]) -> int:
        # Write your code here
        if not arr or not arr[0]:
            return 0

        n = len(arr)
        m = len(arr[0])
        prefix = [[0 for j in range(m)] for i in range(n + 1)]
        res = float('inf')

        for i in range(n):
            for j in range(m):
                prefix[i + 1][j] = prefix[i][j] + arr[i][j]

        for up in range(n):
            for down in range(up + 1, n + 1):
                sum = 0
                min_sum = float('inf')
                max_sum = 0

                for j in range(m):
                    sum += prefix[down][j] - prefix[up][j]
                    if sum - max_sum < min_sum:
                        min_sum = sum - max_sum
                    if sum > max_sum:
                        max_sum = sum

                if min_sum < res:
                    res = min_sum

        return res