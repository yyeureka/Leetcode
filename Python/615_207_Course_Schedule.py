from typing import (
    List,
)

from collections import deque

class Solution:
    """
    @param num_courses: a total of n courses
    @param prerequisites: a list of prerequisite pairs
    @return: true if can finish all courses or false
    """
    def can_finish(self, num_courses: int, prerequisites: List[List[int]]) -> bool:
        # write your code here
        courses = [[] for i in range(num_courses)]
        indegree = [0 for i in range(num_courses)]
        dq = deque()
        
        for course, pre in prerequisites:
            courses[pre].append(course)
            indegree[course] += 1

        for i in range(num_courses):
            if 0 == indegree[i]:
                dq.append(i)

        while dq:
            pre = dq.popleft()
            num_courses -= 1  # clever

            for course in courses[pre]:
                indegree[course] -= 1

                if 0 == indegree[course]:
                    dq.append(course)
        
        return 0 == num_courses