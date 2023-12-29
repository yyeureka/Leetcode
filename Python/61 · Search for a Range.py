from typing import (
    List,
)

class Solution:
    """
    @param a: an integer sorted array
    @param target: an integer to be inserted
    @return: a list of length 2, [index1, index2]
    """
    def search_range(self, a: List[int], target: int) -> List[int]:
        # write your code here
        if not a:
            return [-1, -1]

        start = self.find_first(a, target)
        end = self.find_last(a, target)

        return [start, end]

    def find_first(self, a, target):
        i = 0
        j = len(a) - 1

        while i + 1 < j:
            mid = (i + j) // 2

            if a[mid] >= target:
                j = mid
            else:
                i = mid

        if target == a[i]:
            return i
        elif target == a[j]:
            return j
        return -1

    def find_last(self, a, target):
        i = 0
        j = len(a) - 1

        while i + 1 < j:
            mid = (i + j) // 2

            if a[mid] <= target:
                i = mid
            else:
                j = mid

        if target == a[j]:
            return j
        elif target == a[i]:
            return i
        return -1