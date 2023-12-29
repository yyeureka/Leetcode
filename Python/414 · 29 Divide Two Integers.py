# Exponential backoff

class Solution:
    """
    @param dividend: the dividend
    @param divisor: the divisor
    @return: the result
    """

    def divide(self, dividend: int, divisor: int) -> int:
        # write your code here
        INT_MAX = 2147483647

        if 0 == dividend:
            return 0
        if 0 == divisor:
            return INT_MAX  # int overflow
        if 1 == divisor:
            return dividend
        if -1 == divisor:
            if ~INT_MAX == dividend:
                return INT_MAX  # int overflow
            return -dividend

        sign = 1  # key point
        if dividend < 0:
            dividend = -dividend
            sign *= -1
        if divisor < 0:
            divisor = -divisor
            sign *= -1

        res = 0
        while divisor <= dividend:
            count = 1
            base = divisor

            while base <= dividend:
                dividend -= base
                res += count
                base <<= 1
                count <<= 1

        return res * sign

