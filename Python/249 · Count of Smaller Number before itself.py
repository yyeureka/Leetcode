from typing import (
    List,
)

# 1、binary indexed tree
#    初始bit[1]~bit[maxNum]均为0
#    每一个num，更新A(num)的值为1，并更新相应的bit[?]
#    对每一个num，计算prefixSum(num-1),有几个比它小的就是几个1相加
# 2、segment tree


class Solution:
    """
    @param a: an integer array
    @return: A list of integers includes the index of the first number and the index of the last number
    """

    def update(self, i, val):
        i += 1

        while i < len(self.bit):
            self.bit[i] += val
            i += i & (-i)

    def prefixSum(self, i):
        sum = 0
        i += 1

        while i > 0:
            sum += self.bit[i]
            i -= i & (-i)

        return sum

    def count_of_smaller_number_i_i(self, a: List[int]) -> List[int]:
        # write your code here
        if not a:
            return []

        maxNum = max(a)
        self.bit = [0 for i in range(maxNum + 1)]  # key point
        res = []

        for i in a:
            res.append(self.prefixSum(i - 1))  # key point
            self.update(i, 1)

        return res



