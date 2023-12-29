from typing import (
    List,
)

class Solution:
    """
    @param a: an integer sorted array
    @param target: an integer to be inserted
    @return: An integer
    """
    def search_insert(self, a: List[int], target: int) -> int:
        # write your code here
        if not a:
            return 0

        i = 0
        j = len(a) - 1

        while i + 1 < j:
            mid = (i + j) // 2

            if target == a[mid]:
                return mid
            elif target > a[mid]:
                i = mid
            else:
                j = mid

        if a[i] >= target:
            return i
        if a[j] >= target:
            return j
        return j + 1  # tricky
