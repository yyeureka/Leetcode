from typing import (
    List,
)

# dp，每个状态保存max和min，下一个状态如果>0，max和min分别考虑上一个的max和min，如果<0，max和min分别考虑上一个的min和max
# follow up：
# 空间优化 只要一个max和min就可以代替vector了！！！


class Solution:
    """
    @param nums: An array of integers
    @return: An integer
    """

    def max_product(self, nums: List[int]) -> int:
        # write your code here
        pre_max = 1
        pre_min = 1
        res = float('-inf')

        for i in nums:
            if i >= 0:
                pre_max, pre_min = max(pre_max * i, i), min(pre_min * i, i)  # tricky, 分两行写就错了
            else:
                pre_max, pre_min = max(pre_min * i, i), min(pre_max * i, i)

            if pre_max > res:
                res = pre_max

        return res
