# 1 可能的和为n~6 * n，和的总数为6^n，和的分布是对称的，算一半就行
# 2 sum[n + 1][6 * n + 1]，sum[i][j]为i个色子和为j的概率= i-1个色子色出1~6概率的和再除以6
#   = (sum[i-1][j-1] + sum[i-1][j-2] + sum[i-1][j-3] + sum[i-1][j-4] + sum[i-1][j-5] + sum[i-1][j-6])/6.0 (j – k > 0)
#   不能将维度缩减为2！！
# 3 初始条件sum[1][1] = sum[1][2] = sum[1][3] = sum[1][4] = sum[1][5] = sum[1][6] = 1.0/6
# 4 结果为sum[n][n]~ sum[n][6 * n]


class Solution:
    # @param {int} n an integer
    # @return {tuple[]} a list of tuple(sum, probability)
    def dicesSum(self, n):
        # Write your code here
        dp = [[0 for j in range(6 * n + 1)] for i in range(n + 1)]  # n dices, sum from n~6n
        for i in range(1, 7):
            dp[1][i] = 1 / 6

        for i in range(2, n + 1):
            for j in range(i, 6 * i + 1):
                if j <= 7 * i // 2:
                    for k in range(1, 7):
                        if j <= k:
                            break

                        dp[i][j] += dp[i - 1][j - k]

                    dp[i][j] /= 6
                else:
                    dp[i][j] = dp[i][7 * i - j]  # sum对称分布

        res = []
        for i in range(n, 6 * n + 1):
            res.append((i, dp[n][i]))
        return res
