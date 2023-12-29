
# dfs+dp
# dfs+memo
# dfs


# DFS+memo
class Solution:
    """
    @param: s: A string
    @return: A list of lists of string
    """

    def partition(self, s):
        # write your code here
        if not s:
            return [[]]  # tricky

        memo = {}
        return self.dfs(s, memo)

    def dfs(self, s, memo):
        if not s:
            return [[]]  # tricky
        if 1 == len(s):
            return [[s]]
        if s in memo:
            return memo[s]

        res = []
        n = len(s)

        for i in range(n):
            right = s[i:]
            if not self.is_palindrome(right):
                continue

            left = self.dfs(s[:i], memo)
            for j in left:
                res.append(j + [right])

        memo[s] = res
        return res

    def is_palindrome(self, s):
        i = 0
        j = len(s) - 1

        while i < j:
            if s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True


# DFS
class Solution:
    """
    @param: s: A string
    @return: A list of lists of string
    """

    def partition(self, s):
        # write your code here
        if not s:
            return [[]]

        res = []
        cur = []
        self.dfs(s, res, cur)

        return res

    def dfs(self, s, res, cur):
        if not s:
            res.append(cur[:])
            return

        n = len(s)
        for i in range(1, n + 1):
            left = s[:i]
            if not self.is_palindrome(left):
                continue

            self.dfs(s[i:], res, cur + [left])

    def is_palindrome(self, s):
        i = 0
        j = len(s) - 1

        while i < j:
            if s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True