# 5和5的倍数增加1个0
# 25和25的倍数再增加1个0
# 125的倍数再增加一个0
# ...依次类推

class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        base = 5

        while base <= n:
            res += n // base
            base *= 5

        return res