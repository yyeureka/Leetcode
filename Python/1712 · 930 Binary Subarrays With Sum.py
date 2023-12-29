from typing import (
    List,
)

# prefix sum O(n^2) TLE

class Solution:
    """
    @param a: an array
    @param s: the sum
    @return: the number of non-empty subarrays
    """
    def num_subarrays_with_sum(self, a: List[int], s: int) -> int:
        # Write your code here.
        prefixSum = {0: 1}
        sum = 0
        res = 0

        for i in a:
            sum += i

            if sum - s in prefixSum:
                res += prefixSum[sum - s]

            if sum not in prefixSum:
                prefixSum[sum] = 1
            else:
                prefixSum[sum] += 1

        return res
