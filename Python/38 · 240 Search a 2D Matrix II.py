# 1. Binary search on each row - O(nlogm)
# 2. Search from the right corner - O(n+m)
#    i=0, j=m-1
#    when ==target i++ j--
#    when <target i++
#    when >target j--


from typing import (
    List,
)


# Binary search on each row
class Solution:
    """
    @param matrix: A list of lists of integers
    @param target: An integer you want to search in matrix
    @return: An integer indicate the total occurrence of target in the given matrix
    """

    def search_matrix(self, matrix: List[List[int]], target: int) -> int:
        # write your code here
        if not matrix or not matrix[0]:
            return 0

        res = 0
        end = len(matrix[0]) - 1

        for i in range(len(matrix)):
            if target == matrix[i][0]:
                res += 1
                break
            elif matrix[i][0] > target:
                break
            else:
                col = self.bs(matrix[i], 0, end, target)

                if col >= 0:
                    res += 1
                    end = col - 1

        return res

    def bs(self, a, i, j, target):
        while i + 1 < j:
            mid = (i + j) // 2
            if target == a[mid]:
                return mid
            elif a[mid] < target:
                i = mid
            else:
                j = mid

        if target == a[i]:
            return i
        if target == a[j]:
            return j
        return -1


# Search from the right corner
class Solution:
    """
    @param matrix: A list of lists of integers
    @param target: An integer you want to search in matrix
    @return: An integer indicate the total occurrence of target in the given matrix
    """

    def search_matrix(self, matrix: List[List[int]], target: int) -> int:
        # write your code here
        if not matrix or not matrix[0]:
            return 0

        res = 0
        i = 0
        j = len(matrix[0]) - 1

        while i < len(matrix) and j >= 0:
            if target == matrix[i][j]:
                res += 1
                i += 1
                j -= 1
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1

        return res