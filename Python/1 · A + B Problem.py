# 利用异或运算实现进位加法

class Solution:
    """
    @param a: An integer
    @param b: An integer
    @return: The sum of a and b
    """

    def aplusb(self, a: int, b: int) -> int:
        # write your code here
        if 0 == a:
            return b
        if 0 == b:
            return a

        INT_RANGE = pow(2, 32) - 1
        while b != 0:
            a, b = a ^ b, (a & b) << 1

            # python 没有 int 溢出，超过0x7FFFFFFF之后会自动转成大数 int 进行计算，
            # 可能会因为符号位，(a & b) << 1 一直进位跳不出loop，所以需要将结果a按二进制位保存下来
            # 由题意可知结果a最多31位，所以INT_RANGE二进制是32个1.
            # 二进制右数第32位记录符号位，右边31位记录数值
            a &= INT_RANGE

        # 查看a的符号位，有则为负数，正数直接输出，负数需要转成负数
        return a if a >> 31 <= 0 else a ^ ~INT_RANGE


