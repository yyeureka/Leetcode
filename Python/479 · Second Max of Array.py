from typing import (
    List,
)

class Solution:
    """
    @param nums: An integer array
    @return: The second max number in the array.
    """
    def second_max(self, nums: List[int]) -> int:
        # write your code here
        max = float('-inf')
        res = float('-inf')

        for i in nums:
            if i > max:
                res = max  # key point
                max = i
            elif i > res:
                res = i

        return res
