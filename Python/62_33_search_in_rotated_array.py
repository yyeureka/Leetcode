from typing import (
    List,
)

class Solution:
    """
    @param a: an integer rotated sorted array
    @param target: an integer to be searched
    @return: an integer
    """
    def search(self, a: List[int], target: int) -> int:
        # write your code here
        if not a:
            return -1

        start = 0
        end = len(a) - 1

        while start + 1 < end:
            mid = (start + end) // 2

            if a[mid] == target:
                return mid
            if a[start] == target:
                return start

            if a[mid] < target:
                if (a[start] < a[mid]) == (a[start] < target):
                    start = mid
                else:
                    end = mid
            else:
                if (a[start] < a[mid]) == (a[start] < target):
                    end = mid
                else:
                    start = mid

        if a[start] == target:
            return start
        if a[end] == target:
            return end
        return -1