from typing import (
    List,
)

# 如果 max - min ≤ 2k，我们总可以将整数数组 nums 的所有元素都改为同一个整数，因此更改后的整数数组 nums 的最低分数为 0
# 如果 max - min > 2k，更改后的整数数组 nums 的最低分数为 max - min − 2k


class Solution:
    """
    @param a:
    @param k:
    @return: return a integer
    """
    def smallest_range_i(self, a: List[int], k: int) -> int:
        # write your code here
        maxV = max(a)
        minV = min(a)

        if maxV - minV <= 2 * k:
            return 0
        return maxV - minV - 2 * k
