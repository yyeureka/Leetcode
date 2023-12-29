# dp1, get the perfect squares first, knapsack dp
# dp2
# math平方和定理


# dp1
class Solution:
    """
    @param n: a positive integer
    @return: An integer
    """

    def num_squares(self, n: int) -> int:
        # write your code here
        nums = []
        for i in range(1, n + 1):
            if i * i > n:
                break

            nums.append(i * i)

        dp = [i for i in range(n + 1)]
        dp[0] = 0
        for i in range(1, n + 1):
            for num in nums:
                if i < num:
                    break

                dp[i] = min(dp[i], dp[i - num] + 1)

        return dp[n]


# dp2
class Solution:
    """
    @param n: a positive integer
    @return: An integer
    """

    def num_squares(self, n: int) -> int:
        # write your code here
        dp = [i for i in range(n + 1)]
        dp[0] = 0

        for i in range(1, n + 1):
            upper = int(math.sqrt(i))
            if upper * upper == i:
                dp[i] = 1
                continue

            for j in range(1, upper + 1):
                dp[i] = min(dp[i], dp[i - j * j] + 1)

        return dp[n]


# math
class Solution:
    """
    @param n: a positive integer
    @return: An integer
    """

    def num_squares(self, n: int) -> int:
        # write your code here
        while 0 == n % 4:
            n //= 4

        if 7 == n % 8:
            return 4

        for i in range(n + 1):
            temp = i * i
            if temp <= n:
                if n == int((n - temp) ** 0.5) ** 2 + temp:
                    return 1 + (0 if 0 == temp else 1)
            else:
                break

        return 3