from typing import (
    List,
)

# 1、union-find：代码较复杂，但近似线性时间 O(n)
# 2、利用了unordered_set查找的时间效率为O(1)，如果某数i，i-1不在set中，依次判断i+1、i+2... O(n)


from typing import (
    List,
)


class UF:
    def __init__(self, n):
        self.v = [i for i in range(n)]
        self.sz = [1 for i in range(n)]

    def get_root(self, i):
        while i != self.v[i]:
            self.v[i] = self.v[self.v[i]]
            i = self.v[i]

        return i

    def quick_union(self, p, q):
        i = self.get_root(p)
        j = self.get_root(q)
        if i == j:
            return

        if self.sz[i] < self.sz[j]:
            self.v[i] = j
            self.sz[j] += self.sz[i]
        else:
            self.v[j] = i
            self.sz[i] += self.sz[j]

    def get_max_union(self):
        res = float('-inf')

        for i in self.sz:
            if i > res:
                res = i

        return res


class Solution:
    """
    @param num: A list of integers
    @return: An integer
    """

    def longest_consecutive(self, num: List[int]) -> int:
        # write your code here
        if not num:
            return 0

        uf = UF(len(num))
        memo = {}  # val:index

        for i, n in enumerate(num):
            if n in memo:
                continue

            memo[n] = i
            if n + 1 in memo:
                uf.quick_union(i, memo[n + 1])
            if n - 1 in memo:
                uf.quick_union(i, memo[n - 1])

        return uf.get_max_union()


class Solution:
    """
    @param num: A list of integers
    @return: An integer
    """

    def longest_consecutive(self, num: List[int]) -> int:
        # write your code here
        if not num:
            return 0

        memo = set()
        res = 0

        for i in num:
            memo.add(i)

        for i in num:
            if i - 1 in memo:  # key point 否则就不是O(n)了
                continue

            j = i + 1
            while j in memo:
                j += 1

            if j - i > res:
                res = j - i

        return res