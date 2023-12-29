from typing import (
    List,
)

# dp1：对每一个i，j从i-1开始到0，看有没有j+A[j]>=i的，有的话i即可走到
# dp2：有点dfs的思路了，对每一个能走到的i，i+A[i]之内的状态都置为true


# dp1
class Solution:
    """
    @param a: A list of integers
    @return: A boolean
    """
    def can_jump(self, a: List[int]) -> bool:
        # write your code here
        n = len(a)
        dp = [False for _ in range(n)]
        dp[0] = True

        for i in range(1, n):
            for j in range(i - 1, -1, -1):
                if dp[j] and (j + a[j] >= i):
                    dp[i] = True
                    break

        return dp[-1]


# dp2
class Solution:
    """
    @param a: A list of integers
    @return: A boolean
    """
    def can_jump(self, a: List[int]) -> bool:
        # write your code here
        n = len(a)
        dp = [False for _ in range(n)]
        dp[0] = True

        for i in range(n):
            if 0 == a[i] or not dp[i]:
                continue
            if i + a[i] >= n - 1:
                return True

            for j in range(i + 1, i + a[i] + 1):
                dp[j] = True

        return dp[-1]
