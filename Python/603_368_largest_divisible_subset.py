class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        nums.sort()
        dp = [[num] for num in nums]
        res = []
        
        for i in range(len(dp)):
            for j in range(i):
                if 0 == nums[i] % nums[j] and len(dp[j]) >= len(dp[i]):
                    dp[i] = dp[j] + [nums[i]]
            
            if len(dp[i]) > len(res):
                res = dp[i]
        
        return res
