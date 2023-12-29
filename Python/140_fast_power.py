class Solution:
    """
    @param a: A 32bit integer
    @param b: A 32bit integer
    @param n: A 32bit integer
    @return: An integer
    """
    def fast_power(self, a: int, b: int, n: int) -> int:
        # write your code here
        if 0 == n:
            return 1 % b
        
        res = self.fast_power(a, b, n >> 1)

        if n & 1:
            return res * res * a % b
        return res * res % b

