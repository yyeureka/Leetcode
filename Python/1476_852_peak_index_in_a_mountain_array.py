from typing import (
    List,
)

class Solution:
    """
    @param a: an array
    @return: any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
    """
    def peak_index_in_mountain_array(self, a: List[int]) -> int:
        # Write your code here
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
