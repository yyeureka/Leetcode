from typing import (
    List,
)

class Solution:
    """
    @param arrs: the arrays
    @return: the number of the intersection of the arrays
    """
    def intersection_of_arrays(self, arrs: List[List[int]]) -> int:
        # write your code here
        count = {}
        res = 0

        for arr in arrs:
            for i in arr:
                if i in count:
                    count[i] += 1
                else:
                    count[i] = 1

        for key in count:
            if len(arrs) == count[key]:
                res += 1

        return res
