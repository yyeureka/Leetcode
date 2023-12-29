from typing import (
    List,
)

class Solution:
    """
    @param n: The number of digits
    @return: All narcissistic numbers with n digits
    """
    def get_narcissistic_numbers(self, n: int) -> List[int]:
        # write your code here
        res = []

        if 1 == n:
            start = 0
        else:
            start = 10 ** (n - 1)

        for i in range(start, 10 ** n):
            if self.valid(i, n):
                res.append(i)

        return res

    def valid(self, num, n):
        sum = 0
        for i in str(num):
            sum += int(i) ** n
            if sum > num:
                return False

        return sum == num