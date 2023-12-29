from typing import (
    List,
)

class Solution:
    """
    @param m: the limit
    @param k: the sum of choose
    @param arr: the array
    @return: yes or no
    """
    def depress(self, m: int, k: int, arr: List[int]) -> str:
        # Write your code here.
        arr.sort()
        if sum(arr[:k]) < m:
            return 'yes'
        return 'no'