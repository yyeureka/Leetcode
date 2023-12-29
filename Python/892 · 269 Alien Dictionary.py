from typing import (
    List,
)

import heapq


class Solution:
    """
    @param words: a list of words
    @return: a string which is correct order
    """

    def alien_order(self, words: List[str]) -> str:
        # Write your code here
        if not words:
            return ''

        res = ''
        degree = {}
        edge = {}
        heap = []  # key point

        for s in words:
            for c in s:
                degree[c] = 0
                edge[c] = []

        for i in range(1, len(words)):
            pre = words[i - 1]
            cur = words[i]
            if len(pre) > len(cur) and pre.startswith(cur):  # 'abc', 'ab' is invalid
                return ''

            l = 0
            r = 0
            while l < len(pre) and r < len(cur):
                if pre[l] != cur[r]:
                    degree[cur[r]] += 1
                    edge[pre[l]].append(cur[r])  # can have same character
                    break

                l += 1
                r += 1

        for key in degree:
            if 0 == degree[key]:
                heapq.heappush(heap, key)

        while heap:
            cur = heapq.heappop(heap)
            res += cur

            for c in edge[cur]:
                degree[c] -= 1

                if 0 == degree[c]:
                    heapq.heappush(heap, c)

        if len(res) != len(edge):  # tricky
            return ''
        return res