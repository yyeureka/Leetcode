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
            return

        self.v[i] = j

class Solution:
    """
    @param accounts: List[List[str]]
    @return: return a List[List[str]]
             we will sort your return value in output
    """
    def accounts_merge(self, accounts: List[List[str]]) -> List[List[str]]:
        # write your code here
        email2id = {}
        email2name = {}

        for account in accounts:
            for email in account[1:]:
                if email in email2id:  # key point
                    continue

                email2id[email] = len(email2id)
                email2name[email] = account[0]

        uf = UF(len(email2id))
        for account in accounts:
            id = email2id[account[1]]

            for email in account[2:]:
                uf.quick_union(id, email2id[email])

        id2emails = {}
        for email in email2id:
            id = uf.get_root(email2id[email])

            if id in id2emails:
                id2emails[id].append(email)
            else:
                id2emails[id] = [email]

        res = []
        for id in id2emails:
            emails = id2emails[id]
            res.append([email2name[emails[0]]] + sorted(emails))  # key point

        return res


