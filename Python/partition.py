# kth O(n)
class Solution:
    """
    @param k: An integer
    @param nums: An array
    @return: the Kth largest element
    """

    def kth_largest_element(self, k: int, nums: List[int]) -> int:
        # write your code here
        if not nums or k < 1 or k > len(nums):
            return None

        return self.partition(nums, 0, len(nums) - 1, k)

    def partition(self, nums, start, end, k):
        if start >= end:
            return nums[k - 1]

        l, r = start, end
        pivot = nums[(start + end) // 2]

        while l <= r:
            while l <= r and nums[l] > pivot:
                l += 1
            while l <= r and nums[r] < pivot:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        if r >= k - 1:
            return self.partition(nums, start, r, k)
        if l <= k - 1:
            return self.partition(nums, l, end, k)
        return nums[k - 1]


# top k O(n + klogk)
class Solution:
    def topKLargest(self, nums: List[int], k: int) -> List[int]:
        self.quick_select(nums, 0, len(nums) - 1, k)
        return nums[:k].sort(reverse=True)

    def quick_select(self, nums, start, end, k):
        if start >= end:
            return

        l, r = start, end
        pivot = nums[(start + end) >> 1]

        while l <= r:  # triky
            while l <= r and nums[l] > pivot:
                l += 1
            while l <= r and nums[r] < pivot:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        if r >= k:  # tricky
            self.quick_select(nums, start, r, k)
        if l <= k:
            self.quick_select(nums, l, end, k)


# 3 pointers
def partition2(self, nums: List[int], low: int, high: int):
    # write your code here
    l = 0
    r = len(nums) - 1
    i = 0

    while i <= r:
        if nums[i] < low:
            nums[i], nums[l] = nums[l], nums[i]
            i += 1
            l += 1
        elif nums[i] > high:
            nums[i], nums[r] = nums[r], nums[i]
            r -= 1
        else:
            i += 1