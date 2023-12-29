# heap
# Merge sort

from typing import (
    List,
)

import heapq


class Solution:
    """
    @param arrays: k sorted integer arrays
    @return: a sorted array
    """
    def mergek_sorted_arrays(self, arrays: List[List[int]]) -> List[int]:
        if not arrays:
            return []

        heap = []
        res = []

        for i in arrays:
            for j in i:
                heapq.heappush(heap, j)

        while heap:
            res.append(heapq.heappop(heap))

        return res


class Solution:
    """
    @param arrays: k sorted integer arrays
    @return: a sorted array
    """

    def mergek_sorted_arrays(self, arrays: List[List[int]]) -> List[int]:
        return self.merge(arrays, 0, len(arrays) - 1)

    def merge(self, arrays, left, right):
        if right <= left:
            return arrays[left]

        mid = (left + right) // 2
        left = self.merge(arrays, left, mid)
        right = self.merge(arrays, mid + 1, right)

        res = []
        i = 0
        j = 0

        while i < len(left) or j < len(right):
            if i >= len(left):
                res.append(right[j])
                j += 1
            elif j >= len(right):
                res.append(left[i])
                i += 1
            elif left[i] < right[j]:
                res.append(left[i])
                i += 1
            else:
                res.append(right[j])
                j += 1

        return res
