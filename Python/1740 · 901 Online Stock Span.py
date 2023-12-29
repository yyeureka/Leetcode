# dp
class StockSpanner:
    def __init__(self):
        self.prices = []
        self.dp = []

    """
    @param price: 
    @return: int
    """

    def next(self, price):
        # Write your code here.
        span = 1
        i = len(self.prices) - 1
        while i >= 0 and self.prices[i] <= price:
            span += self.dp[i]
            i -= self.dp[i]

        self.dp.append(span)
        self.prices.append(price)

        return span


# monotonic stack
class StockSpanner:
    def __init__(self):
        self.stack = []

    """
    @param price: 
    @return: int
    """

    def next(self, price):
        # Write your code here.
        span = 1

        while self.stack and self.stack[-1][0] <= price:
            span += self.stack.pop()[1]
        self.stack.append((price, span))

        return span


