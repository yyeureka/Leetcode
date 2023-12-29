from typing import (
    List,
    Set,
)

from collections import deque


# BFS from end + DFS from start
# BFS from start + DFS from start TLE!


from typing import (
    List,
    Set,
)

from collections import deque


# BFS from end
class Solution:
    """
    @param start: a string
    @param end: a string
    @param dict: a set of string
    @return: a list of lists of string
             we will sort your return value in output
    """

    def find_ladders(self, start: str, end: str, dict: Set[str]) -> List[List[str]]:
        # write your code here
        if len(start) != len(end):
            return []
        if start == end:
            return [[start]]

        dict.add(start)  # tricky add start
        # dict.add(end)
        distance = {}
        self.bfs(end, dict, distance)
        if start not in distance:  # no path between start and end
            return []

        res = []
        cur = [start]
        self.dfs(start, end, dict, distance, res, cur)

        return res

    def bfs(self, start, dict, distance):
        n = len(start)
        dq = deque([start])
        distance[start] = 0

        while dq:
            word = dq.popleft()

            for i in range(n):
                for j in 'abcdefghijklmnopqrstuvwxyz':
                    if word[i] == j:
                        continue

                    adj = word[:i] + j + word[i + 1:]
                    if adj not in dict:
                        continue

                    if adj not in distance:  # key point
                        distance[adj] = distance[word] + 1
                        dq.append(adj)

    def dfs(self, start, end, dict, distance, res, cur):
        if start == end:
            res.append(cur[:])
            return

        n = len(start)

        for i in range(n):
            for j in 'abcdefghijklmnopqrstuvwxyz':
                if start[i] == j:
                    continue

                adj = start[:i] + j + start[i + 1:]
                if adj not in dict:
                    continue
                if distance[adj] != distance[start] - 1:  # key point
                    continue

                cur.append(adj)
                self.dfs(adj, end, dict, distance, res, cur)
                cur.pop()


# BFS from start
class Solution:
    """
    @param start: a string
    @param end: a string
    @param dict: a set of string
    @return: a list of lists of string
             we will sort your return value in output
    """

    def find_ladders(self, start: str, end: str, dict: Set[str]) -> List[List[str]]:
        # write your code here
        if len(start) != len(end):
            return []
        if start == end:
            return [[start]]

        dict.add(start)
        dict.add(end)
        distance = {}
        self.bfs(start, dict, distance)
        if end not in distance:  # no path between start and end
            return []

        res = []
        cur = [start]
        self.dfs(start, end, dict, distance, res, cur)

        return res

    def bfs(self, start, dict, distance):
        n = len(start)
        dq = deque([start])
        distance[start] = 0

        while dq:
            word = dq.popleft()

            for i in range(n):
                for j in 'abcdefghijklmnopqrstuvwxyz':
                    if word[i] == j:
                        continue

                    adj = word[:i] + j + word[i + 1:]
                    if adj not in dict:
                        continue

                    if adj not in distance:
                        distance[adj] = distance[word] + 1
                        dq.append(adj)

    def dfs(self, start, end, dict, distance, res, cur):
        if start == end:
            res.append(cur[:])
            return

        n = len(start)

        for i in range(n):
            for j in 'abcdefghijklmnopqrstuvwxyz':
                if start[i] == j:
                    continue

                adj = start[:i] + j + start[i + 1:]
                if adj not in dict:
                    continue
                if distance[adj] != distance[start] + 1:
                    continue

                cur.append(adj)
                self.dfs(adj, end, dict, distance, res, cur)
                cur.pop()

