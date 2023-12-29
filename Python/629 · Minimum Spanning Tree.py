'''
Definition for a Connection
class Connection:

    def __init__(self, city1, city2, cost):
        self.city1, self.city2, self.cost = city1, city2, cost
'''

# 先按cost、city1、city2排序Connection
# 将所有city加进hash，value即序号、依次递增
# unionfind，遍历Connection，将city1和city2 union，如果union个数为1时，即成功
# 注意！！只有city1和city2可以union成功时，才能加进结果中！！


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
            return False  # key point

        if self.sz[i] < self.sz[j]:
            self.v[i] = j
            self.sz[j] += self.sz[i]
        else:
            self.v[j] = i
            self.sz[i] += self.sz[j]
        self.count -= 1
        return True

class Solution:
    # @param {Connection[]} connections given a list of connections
    # include two cities and cost
    # @return {Connection[]} a list of connections from results
    def lowestCost(self, connections):
        # Write your code here
        connections.sort(key=lambda x: (x.cost, x.city1, x.city2))  # tricky

        count = 0
        city = {}
        for i in connections:
            if i.city1 not in city:
                city[i.city1] = count
                count += 1
            if i.city2 not in city:
                city[i.city2] = count
                count += 1

        uf = UF(count)
        res = []
        for i in connections:
            if not uf.quick_union(city[i.city1], city[i.city2]):  # key point
                continue

            res.append(i)

            if 1 == uf.count:
                return res

        return []

