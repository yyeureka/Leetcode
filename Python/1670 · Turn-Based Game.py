from typing import (
    List,
)

class Solution:
    """
    @param atk: the atk of monsters
    @return: Output the minimal damage QW will suffer
    """
    def get_ans(self, atk: List[int]) -> int:
        # Write your code here
        atk.sort()
        res = 0
        prefix_sum = 0

        for i in range(len(atk) - 1):
            prefix_sum += atk[i]
            res += prefix_sum

        return res
