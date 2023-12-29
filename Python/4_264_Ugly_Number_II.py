class Solution:
    """
    @param n: An integer
    @return: return a  integer as description.
    """

    def nth_ugly_number(self, n: int) -> int:
        # write your code here
        nums = [1] * n
        p2 = 0
        p3 = 0
        p5 = 0

        for i in range(1, n):
            nums[i] = min(nums[p2] * 2, nums[p3] * 3, nums[p5] * 5)

            if nums[i] == nums[p2] * 2:  # tricky, elif with have duplicates
                p2 += 1
            if nums[i] == nums[p3] * 3:
                p3 += 1
            if nums[i] == nums[p5] * 5:
                p5 += 1

        return nums[n - 1]