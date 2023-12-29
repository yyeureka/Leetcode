from typing import (
    List,
)


# hash
class Solution:
    """
    @param nums: a list of integers
    @return: return a list of integers
             we will sort your return value in output
    """
    def find_duplicates(self, nums: List[int]) -> List[int]:
        # write your code here
        hash = set()
        res = []
        for i in nums:
            if i in hash:
                res.append(i)
            else:
                hash.add(i)

        return res


# swap
class Solution:
    """
    @param nums: a list of integers
    @return: return a list of integers
             we will sort your return value in output
    """
    def find_duplicates(self, nums: List[int]) -> List[int]:
        # write your code here
        res = []
        for i in nums:
            i = abs(i)
            if nums[i - 1] > 0:  # first time
                nums[i - 1] = -nums[i - 1]
            else:  # second time
                res.append(i)

        return res
