from typing import (
    List,
)

# hash - O(n) time and space
# sort + 2 pointers - O(nlogn) time and O(1) space

# hash
class Solution:
    """
    @param nums: an integer array
    @return: int
    """

    def deduplication(self, nums: List[int]):
        hash = set()

        i = 0
        for num in nums:
            if num in hash:
                continue

            hash.add(num)
            nums[i] = num
            i += 1

        return i


# sort + 2 pointers
class Solution:
    """
    @param nums: an integer array
    @return: int
    """

    def deduplication(self, nums: List[int]):
        # write your code here
        nums.sort()
        i = 0

        for j in range(len(nums)):
            if j > 0 and nums[j] == nums[j - 1]:
                continue

            nums[i] = nums[j]
            i += 1

        return i
