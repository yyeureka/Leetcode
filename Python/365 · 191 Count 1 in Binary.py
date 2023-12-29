class Solution:
    """
    @param num: An integer
    @return: An integer, the number of ones in num
    """
    def count_ones(self, num):
        # write your code here
        res = 0
        INT_RANGE = pow(2, 32) - 1

        while 0 != num:  # key point, cannot use num > 0
            num &= num - 1
            num &= INT_RANGE  # tricky
            res += 1

        return res
