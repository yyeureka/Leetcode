from typing import (
    List,
)

# dp[i]为到当前房子为止钱的max
# 对于房子i，dp[i]为当前房子里的钱nums[i]+dp[i - 2]和前一个房子dp[i-1]的最大值
# dp1, 1D array
# dp2, circular array


# dp1
class Solution:
    """
    @param a: An array of non-negative integers
    @return: The maximum amount of money you can rob tonight
    """
    def house_robber(self, a: List[int]) -> int:
        # write your code here
        if not a:
            return 0

        dp = [i for i in a]

        for i in range(len(a)):
            if i >= 2:
                dp[i] += dp[i - 2]
            if i >= 1:
                dp[i] = max(dp[i - 1], dp[i])

        return dp[len(a) - 1]


# dp2
class Solution:
    """
    @param a: An array of non-negative integers
    @return: The maximum amount of money you can rob tonight
    """

    def house_robber(self, a: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [0, 0]

        for i in range(n):
            cur = a[i]
            if i >= 2:
                cur += dp[i & 1]
            if i >= 1:
                cur = max(cur, dp[(i - 1) & 1])

            dp[i & 1] = cur

        return dp[(n - 1) & 1]