from typing import (
    List,
)

from collections import deque

class Solution:
    """
    @param num_courses: a total of n courses
    @param prerequisites: a list of prerequisite pairs
    @return: the course order
    """
    def find_order(self, num_courses: int, prerequisites: List[List[int]]) -> List[int]:
        # write your code here
        edge = [[] for i in range(num_courses)]
        degree = [0 for i in range(num_courses)]
        dq = deque()
        res = []

        for i, j in prerequisites:
            edge[j].append(i)
            degree[i] += 1
        
        for i in range(num_courses):
            if 0 == degree[i]:
                dq.append(i)

        while dq:
            pre = dq.popleft()
            num_courses -= 1
            res.append(pre)

            for x in edge[pre]:
                degree[x] -= 1

                if 0 == degree[x]:
                    dq.append(x)

        if 0 == num_courses:  # tricky
            return res
        return []
