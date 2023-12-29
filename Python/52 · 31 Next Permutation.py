# 找到最大的index i：nums[i] < nums[i + 1]
# 找到最大的index j：nums[j] > nums[i]，swap(nums[j], nums[i])——剩下的数中大于nums[i]的min
# reverse i+1~n-1

class Solution:
    """
    @param nums: A list of integers
    @return: A list of integers
    """
    def next_permutation(self, nums):
        # write your code here
        if len(nums) <= 1:
            return nums

        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:  # find right most nums[i] < nums[i + 1]
            i -= 1

        if i >= 0:
            j = len(nums) - 1
            while j > i and nums[i] >= nums[j]:  # find right most nums[j] > nums[i]
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        i = i + 1
        j = len(nums) - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        return nums