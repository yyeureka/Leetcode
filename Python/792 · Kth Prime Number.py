import math

class Solution:
    """
    @param n: the number
    @return: the rank of the number
    """

    def kth_prime(self, n: int) -> int:
        # write your code here
        if n < 2:
            return -1

        res = 0
        prime = [True for i in range(n + 1)]
        upper = math.sqrt(n)

        for i in range(2, n + 1):
            if not prime[i]:
                continue

            res += 1

            if i > upper:
                continue

            for j in range(i * i, n + 1, i):
                prime[j] = False

        return res
