from typing import (
    List,
)

from itertools import combinations


class Solution:
    """
    @param a: the n numbers
    @param k: the number of integers you can choose
    @return: how many ways that the sum of the k integers is a prime number
    """

    def get_ways(self, a: List[int], k: int) -> int:
        # Write your code here
        sum_list = [sum(item) for item in combinations(a, k)]

        count = 0
        for s in sum_list:
            if self.is_prime(s):
                count += 1

        return count

    def is_prime(self, n):
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True