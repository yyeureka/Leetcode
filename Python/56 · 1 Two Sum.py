from typing import (
    List,
)


class Solution:
    """
    @param numbers: An array of Integer
    @param target: target = numbers[index1] + numbers[index2]
    @return: [index1, index2] (index1 < index2)
    """

    def two_sum(self, numbers: List[int], target: int) -> List[int]:
        # write your code here
        num = {}

        for i in range(len(numbers)):
            if target - numbers[i] in num:
                return [num[target - numbers[i]], i]

            num[numbers[i]] = i

        return []
