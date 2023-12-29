from typing import (
    List,
)


class UF:
    def __init__(self, n):
        self.v = [i for i in range(n)]

    def get_root(self, i):
        while i != self.v[i]:
            self.v[i] = self.v[self.v[i]]
            i = self.v[i]

        return i

    def quick_union(self, p, q):
        i = self.get_root(p)
        j = self.get_root(q)
        if i == j:
            return False

        self.v[j] = i
        return True


class Solution:
    """
    @param pair: a list of [parent, children]
    @return: a string of error type
    """

    def construct_binary_tree(self, pair: List[List[str]]) -> str:
        # write your code here
        child2parent = {}
        parent2child = {}
        point2id = {}
        repeat = False
        more_parent = False

        for edge in pair:
            parent = edge[0]
            child = edge[1]

            if parent not in parent2child:
                parent2child[parent] = set([child])
            else:
                if child in parent2child[parent]:
                    repeat = True
                else:
                    parent2child[parent].add(child)
            if len(parent2child[parent]) > 2:
                return 'more children'

            if child not in child2parent:
                child2parent[child] = set([parent])
            elif parent not in child2parent[child]:
                more_parent = True

            if parent not in point2id:
                point2id[parent] = len(point2id)
            if child not in point2id:
                point2id[child] = len(point2id)

        if repeat:
            return 'repeat edge'

        uf = UF(len(point2id))
        for parent in parent2child:
            for child in parent2child[parent]:
                if not uf.quick_union(point2id[parent], point2id[child]):
                    return 'have cycle'

        if more_parent:
            return 'more parent'

        for point in point2id:
            if 1 != len(point) or point not in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
                return 'input error'

        return 'successful'

