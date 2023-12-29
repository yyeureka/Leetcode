from typing import (
    List,
)

class Solution:
    """
    @param a: an integer ratated sorted array and duplicates are allowed
    @param target: An integer
    @return: a boolean 
    """
    def search(self, a: List[int], target: int) -> bool:
        # write your code here
        if not a:
            return False
        
        start = 0
        end = len(a) - 1

        while start + 1 < end:
            mid = (start + end) >> 1

            if target == a[mid] or target == a[start]:
                return True

            if a[mid] == a[start]:
                start += 1
            elif a[mid] < target:
                if (a[start] < a[mid]) == (a[start] < target):
                    start = mid
                else:
                    end = mid
            else:
                if (a[start] < a[mid]) == (a[start] < target):
                    end = mid
                else:
                    start = mid
        
        if target == a[start] or target == a[end]:
            return True
        return False