# 辗转相除法

class Solution:
    """
    @param a: the given number
    @param b: another number
    @return: the greatest common divisor of two numbers
    """
    def gcd(self, a: int, b: int) -> int:
        # write your code here
        while b:
            a, b = b, a % b

        return a
