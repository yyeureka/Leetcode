class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def ways_n_cents(self, n: int) -> int:
        # write your code here
        coins = [1, 5, 10, 25]
        dp = [0 for i in range(n + 1)]
        dp[0] = 1

        for coin in coins:
            for i in range(coin, n + 1):
                dp[i] += dp[i - coin]

        return dp[n]