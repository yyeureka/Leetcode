import math

class Solution:
    """
    @param n: a integer
    @return: return a integer
    """

    def count_primes(self, n: int) -> int:
        # write your code here
        if n <= 2:
            return 0

        upper = math.sqrt(n)
        prime = [True for i in range(n)]

        res = 0
        for i in range(2, n):
            if not prime[i]:
                continue

            res += 1

            if i > upper:
                continue

            for j in range(i * i, n, i):
                prime[j] = False

        return res