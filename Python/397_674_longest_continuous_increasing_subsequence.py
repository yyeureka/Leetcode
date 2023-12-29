from typing import (
    List,
)

class Solution:
    """
    @param a: An array of Integer
    @return: an integer
    """
    def longest_increasing_continuous_subsequence(self, a: List[int]) -> int:
        # write your code here
        if len(a) <= 1:
            return len(a)

        dp_l = 1  # increasing
        dp_r = 1  # decreasing
        max_len = 1

        for i in range(1, len(a)):
            if a[i] > a[i - 1]:
                dp_l += 1
                max_len = max(max_len, dp_l)
            else:
                dp_l = 1
            
            if a[i] < a[i - 1]:
                dp_r += 1
                max_len = max(max_len, dp_r)
            else:
                dp_r = 1
            
        return max_len
