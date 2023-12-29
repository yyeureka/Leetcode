import math

# 2 eggs - balanced binary tree
# trial 1: floor x, if fail x times in total
# trial 2: floor x', if fail x - 1 times in total
# trial 3: floor x", if fail x - 2 times in total
# ...
# x + x-1 + x-2 +...+ 1 >= n
# => find the smallest x that x * (x+1) >= 2n

class Solution:
    """
    @param n: An integer
    @return: The sum of a and b
    """
    def drop_eggs(self, n: int) -> int:
        # write your code here
        x = int(math.sqrt(2 * n))

        if x * (x + 1) >= 2 * n:
            return x
        return x + 1

