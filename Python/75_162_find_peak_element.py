from typing import (
    List,
)

class Solution:
    """
    @param a: An integers array.
    @return: return any of peek positions.
    """
    def find_peak(self, a: List[int]) -> int:
        # write your code here
        if not a:
            return -1
        
        start, end = 0, len(a) - 1

        while start + 1 < end:
            mid = (start + end) // 2

            if a[mid] < a[mid + 1]:
                start = mid
            else:
                end = mid
        
        return start if a[start] > a[end] else end