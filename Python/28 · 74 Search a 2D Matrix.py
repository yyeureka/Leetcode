# 1. Treat matrix as 1D array and binary search on it - O(log(m*n))
# 2. Binary search on row and col separately - O(logn+logm)
# 3. Search from the right corner - O(n+m)
#    i=0, j=m-1
#    when <target i++
#    when >target j--

from typing import (
    List,
)


# 1D array
class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """

    def search_matrix(self, matrix: List[List[int]], target: int) -> bool:
        # write your code here
        if not matrix or not matrix[0]:
            return False

        n = len(matrix)
        m = len(matrix[0])

        i = 0
        j = n * m - 1
        while i + 1 < j:
            mid = (i + j) // 2
            row = mid // m
            col = mid % m

            if target == matrix[row][col]:
                return True
            elif matrix[row][col] > target:
                j = mid
            else:
                i = mid

        if target == matrix[i // m][i % m] or target == matrix[j // m][j % m]:
            return True
        return False


# Binary search on row and col separately
class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """

    def search_matrix(self, matrix: List[List[int]], target: int) -> bool:
        # write your code here
        if not matrix or not matrix[0]:
            return False

        n = len(matrix)
        m = len(matrix[0])

        i = 0
        j = n - 1
        while i + 1 < j:
            mid = (i + j) // 2

            if matrix[mid][0] > target:
                j = mid
            else:
                i = mid

        if matrix[i][0] > target:
            return False
        elif matrix[j][0] > target:
            row = i
        else:
            row = j

        i = 0
        j = m - 1
        while i + 1 < j:
            mid = (i + j) // 2

            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] > target:
                j = mid
            else:
                i = mid

        if matrix[row][i] == target or matrix[row][j] == target:
            return True
        return False


# Search from the right corner
class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """

    def search_matrix(self, matrix: List[List[int]], target: int) -> bool:
        # write your code here
        if not matrix or not matrix[0]:
            return False

        i = 0
        j = len(matrix[0]) - 1

        while i < len(matrix) and j >= 0:
            if target == matrix[i][j]:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1

        return False

