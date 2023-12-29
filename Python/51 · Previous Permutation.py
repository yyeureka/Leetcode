# similar to #31/52

class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers that's previous permuation
    """

    def previous_permuation(self, nums):
        # write your code here
        if len(nums) <= 1:
            return nums

        i = len(nums) - 2
        while i >= 0 and nums[i] <= nums[i + 1]:
            i -= 1

        if i >= 0:
            j = len(nums) - 1
            while j > i and nums[j] >= nums[i]:
                j -= 1
            nums[j], nums[i] = nums[i], nums[j]

        i += 1
        j = len(nums) - 1
        while i < j:
            nums[j], nums[i] = nums[i], nums[j]
            i += 1
            j -= 1

        return nums