from typing import (
    List,
)

class Solution:
    """
    @param a: sorted integer array A
    @param b: sorted integer array B
    @return: A new sorted integer array
    """
    def merge_sorted_array(self, a: List[int], b: List[int]) -> List[int]:
        # write your code here
        if not a:
            return b
        if not b:
            return a

        n = len(a)
        m = len(b)
        res = [0 for i in range(n + m)]

        i = 0
        j = 0
        for k in range(len(res)):
            if i >= n:
                res[k] = b[j]
                j += 1
            elif j >= m:
                res[k] = a[i]
                i += 1
            elif a[i] < b[j]:
                res[k] = a[i]
                i += 1
            else:
                res[k] = b[j]
                j += 1

        return res