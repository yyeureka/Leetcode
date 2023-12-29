from typing import (
    List,
)

# upper bound is max(a) - min(a)
# 对于有序的 A，设 A[i] 是最大的需要增长的 i，A[0] + K ... A[i] + K, A[i+1] - K ... A[A.length - 1] - K
# 这时 max 为 A[i] + K or A[A.length - 1] - K，min 为 A[i+1] - K or A[0] + K
# diff 为 max - min

class Solution:
    """
    @param a: a integer array
    @param k: a integer number
    @return: return a integer number
    """

    def smallest_range_i_i(self, a: List[int], k: int) -> int:
        # write your code here
        a.sort()
        maxV = a[-1]
        minV = a[0]

        res = maxV - minV
        for i in range(len(a) - 1):
            res = min(res, max(maxV - k, a[i] + k) - min(minV + k, a[i + 1] - k))

        return res

