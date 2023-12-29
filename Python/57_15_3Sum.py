from typing import (
    List,
)

class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
             we will sort your return value in output
    """
    def three_sum(self, numbers: List[int]) -> List[List[int]]:
        # write your code here
        res = []
        numbers.sort()  # key point, in order to remove duplicates

        for i in range(len(numbers)):
            if i > 0 and numbers[i] == numbers[i - 1]:  # tricky
                continue

            l = i + 1
            r = len(numbers) - 1

            while l < r:
                if 0 == numbers[i] + numbers[l] + numbers[r]:
                    res.append([numbers[i], numbers[l], numbers[r]])
                    l += 1
                    r -= 1

                    while l < r and numbers[l] == numbers[l - 1]:  # tricky
                        l += 1
                    while l < r and numbers[r] == numbers[r + 1]:
                        r -= 1
                elif numbers[i] + numbers[l] + numbers[r] < 0:
                    l += 1
                else:
                    r -= 1

        return res
