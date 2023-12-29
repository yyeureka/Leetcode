# Find the last position of a target number in a sorted array. Return -1 if target does not exist.

# Example 1:
# Input: nums = [1,2,2,4,5,5], target = 2
# Output: 2
# Example 2:
# Input: nums = [1,2,2,4,5,5], target = 6
# Output: -1


class Solution:
    def lastPosition(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        
        start = 0
        end = len(nums) - 1

        while start + 1 < end:
            mid = (start + end) >> 1

            if nums[mid] <= target:
                start = mid
            else:
                end = mid
        
        if target == nums[end]:
            return end
        if target == nums[start]:
            return end
        return -1