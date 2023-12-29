# Given an integer array, find the top k largest numbers in it.
# Example1
# Input: [3, 10, 1000, -99, 4, 100] and k = 3
# Output: [1000, 100, 10]
# Example2
# Input: [8, 7, 6, 5, 4, 3, 2, 1] and k = 5
# Output: [8, 7, 6, 5, 4]


import heapq

# Minheap O(nlogk)
class Solution:
    def topKLargest(self, nums: List[int], k: int) -> List[int]:
        heap = []

        for num in nums:
            heapq.heappush(heap, num)
            
            if len(heap) > k:
                heapq.heappop(heap)
        
        return heap.sort(reverse=True)


# Quickselect O(n + klogk)
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

