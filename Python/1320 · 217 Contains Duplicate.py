from typing import (
    List,
)


class Solution:
    """
    @param nums: the given array
    @return: if any value appears at least twice in the array
    """

    def contains_duplicate(self, nums: List[int]) -> bool:
        # Write your code here
        hash = set()

        for i in nums:
            if i in hash:
                return True

            hash.add(i)

        return False