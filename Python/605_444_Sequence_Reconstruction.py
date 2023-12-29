from typing import (
    List,
)

from collections import deque

class Solution:
    """
    @param org: a permutation of the integers from 1 to n
    @param seqs: a list of sequences
    @return: true if it can be reconstructed only one or false
    """
    def sequence_reconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        # write your code here
        edge = {}
        degree = {}
        dq = deque()
        res = []

        for seq in seqs:
            for i in seq:
                edge[i] = []
                degree[i] = 0

        for seq in seqs:
            for i in range(1, len(seq)):
                degree[seq[i]] += 1
                edge[seq[i - 1]].append(seq[i])

        for key in degree:
            if 0 == degree[key]:
                dq.append(key)

        while dq:
            if len(dq) > 1:
                return False

            cur = dq.popleft()
            res.append(cur)

            for i in edge[cur]:
                degree[i] -= 1

                if 0 == degree[i]:
                    dq.append(i)

        return res == org