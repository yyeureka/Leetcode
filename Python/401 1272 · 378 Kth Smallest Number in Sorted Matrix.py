# minheap O(klogn)
# pop from minheap and push the right and below elements
# binary search

from typing import (
    List,
)

import heapq


class Solution:
    """
    @param matrix: a matrix of integers
    @param k: An integer
    @return: the kth smallest number in the matrix
    """

    def kth_smallest(self, matrix: List[List[int]], k: int) -> int:
        # write your code here
        if not matrix or not matrix[0]:
            return 0

        n = len(matrix)
        m = len(matrix[0])
        heap = []
        heapq.heappush(heap, (matrix[0][0], 0, 0))

        while k > 0:
            if not heap:
                break

            val, i, j = heapq.heappop(heap)

            if i + 1 < n and '#' != matrix[i + 1][j]:
                heapq.heappush(heap, (matrix[i + 1][j], i + 1, j))
                matrix[i + 1][j] = '#'
            if j + 1 < m and '#' != matrix[i][j + 1]:
                heapq.heappush(heap, (matrix[i][j + 1], i, j + 1))
                matrix[i][j + 1] = '#'

            k -= 1

        return val