
# dp
# dfs TLE


# dfs
class Solution:
    """
    @param n: int
    @param k: int
    @param w: int
    @return: the probability
    """

    def new21_game(self, n: int, k: int, w: int) -> float:
        # Write your code here.
        return self.helper(n, k, w, 0)

    def helper(self, n, k, w, cur):
        if k <= 0:
            return 1

        res = 0
        for i in range(1, w + 1):
            if cur + i > n:
                break

            res += 1 / w * self.helper(n, k - i, w, cur + i)

        return res
