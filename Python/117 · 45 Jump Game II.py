from typing import (
    List,
)

# 1. greedy
# 起始start为0，end为0
# 依次检查里面的num,并记录最远的index
# 如果有能到target的，return，如果没有，start为end+1，end为下一跳最远的index，重复步骤1
# 2. dp TLE


class Solution:
    """
    @param a: A list of integers
    @return: An integer
    """
    def jump(self, a: List[int]) -> int:
        # write your code here
        n = len(a)
        step = 0
        start = 0
        end = 0

        while end < n - 1:
            step += 1

            next_end = 0
            for i in range(start, end + 1):
                next_end = max(next_end, i + a[i])
                if next_end >= n - 1:
                    break

            start = end + 1
            end = next_end

        return step



# dp
class Solution:
    """
    @param a: A list of integers
    @return: An integer
    """
    def jump(self, a: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [20000 for _ in range(n)]
        dp[0] = 0

        for i in range(1, n):
            for j in range(i - 1, -1, -1):
                if j + a[j] >= i and dp[j] + 1 < dp[i]:
                    dp[i] = dp[j] + 1

        return dp[-1]
