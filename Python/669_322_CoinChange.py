Description = '''
You are given an integer array coins representing coins of different denominations and an integer 
amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money 
cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
'''


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = 0x3f3f3f3f
        dp = [INF] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0 and dp[i - coin] + 1 < dp[i]:
                    dp[i] = dp[i - coin] + 1

        if INF == dp[amount]:
            return -1
        else:
            return dp[amount]