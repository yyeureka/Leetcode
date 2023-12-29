# Iterative O(n)

class Solution:
    """
    @param n: an integer
    @return: an ineger f(n)
    """

    def fibonacci(self, n: int) -> int:
        # write your code here
        if n <= 2:
            return n - 1

        f0 = 0
        f1 = 1

        while n > 2:
            f0, f1 = f1, f0 + f1
            n -= 1

        return f1