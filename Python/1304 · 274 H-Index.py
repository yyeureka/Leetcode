from typing import (
    List,
)


class Solution:
    """
    @param citations: a list of integers
    @return: return a integer
    """

    def h_index(self, citations: List[int]) -> int:
        # write your code here
        citations.sort()

        n = len(citations)
        for i in range(n):
            if citations[i] >= n - i:  # key point
                return n - i

        return 0  # tricky


class Solution:
    """
    @param citations: a list of integers
    @return: return a integer
    """

    def h_index(self, citations: List[int]) -> int:
        # write your code here
        citations.sort()

        n = len(citations)
        start = 0
        end = n - 1

        while start + 1 < end:
            mid = (start + end) // 2

            if citations[mid] > n - mid:
                end = mid
            else:
                start = mid

        if citations[start] >= n - start:
            return n - start
        if citations[end] >= n - end:
            return n - end
        return 0  # tricky
