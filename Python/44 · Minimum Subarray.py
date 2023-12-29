class Solution:
    """
    @param nums: a list of integers
    @return: A integer indicate the sum of minimum subarray
    """
    def min_sub_array(self, nums):
        # write your code here
        if not nums:
            return 0

        res = float('inf')
        sum = 0
        max = 0  # key point

        for num in nums:
            sum += num
            if sum - max < res:
                res = sum - max
            if sum > max:
                max = sum

        return res
