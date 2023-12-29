# binary search o(nlogn)
# sort + dp (longest increasing subsequence) O(n^2) - TLE

from typing import (
    List,
)


# binary search
class Solution:
    """
    @param envelopes: a number of envelopes with widths and heights
    @return: the maximum number of envelopes
    """

    def max_envelopes(self, envelopes: List[List[int]]) -> int:
        # write your code here
        if not envelopes:
            return 0

        envelopes.sort(key=lambda x: (x[0], -x[1]))  # key point, if h is increasing, the envelop is increasing
        lis = []  # increasing h => increasing envelop

        for w, h in envelopes:
            if not lis or h > lis[-1]:
                lis.append(h)
            else:  # find the first position where h' >= h, insert h to maintain increasing
                index = self.insert(lis, h)
                lis[index] = h

        return len(lis)

    def insert(self, lis, h):
        i = 0
        j = len(lis) - 1

        while i + 1 < j:
            mid = (i + j) // 2

            if lis[mid] < h:
                i = mid
            else:
                j = mid

        if lis[i] >= h:
            return i
        return j

# dp
class Solution:
    """
    @param envelopes: a number of envelopes with widths and heights
    @return: the maximum number of envelopes
    """
    def max_envelopes(self, envelopes: List[List[int]]) -> int:
        # write your code here
        if not envelopes:
            return 0

        envelopes.sort(key=lambda x:(x[0], x[1]))
        n = len(envelopes)
        dp = [1 for i in range(n)]
        res = 1

        for i in range(1, len(envelopes)):
            for j in range(i):
                if envelopes[j][0] >= envelopes[i][0] or envelopes[j][1] >= envelopes[i][1]:
                    continue
                if dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1

            if dp[i] > res:
                res = dp[i]

        return res






