class UF:
    def __init__(self, n):
        self.count = n
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

        self.count -= 1


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        if not isConnected or not isConnected[0]:
            return 0

        n = len(isConnected)
        uf = UF(n)

        for i in range(n):
            for j in range(i + 1, n):
                if 0 == isConnected[i][j]:
                    continue

                uf.quick_union(i, j)

        return uf.count