# 2 pointers

# dfs - TLE


class Solution:
    """
    @param start: the start
    @param end: the end
    @return: is there exists a sequence of moves to transform one string to the other
    """

    def can_transform(self, start: str, end: str) -> bool:
        # Write your code here
        if start.replace("X", "") != end.replace("X", ""):  # key point
            return False

        n = len(start)
        i = 0
        j = 0

        while i < n and j < n:
            while i < n and 'X' == start[i]:
                i += 1
            while j < n and 'X' == end[j]:
                j += 1

            if i >= n:  # key point
                return j >= n
            if j >= n:
                return i >= n

            if start[i] != end[j] or ('L' == start[i] and i < j) or ('R' == start[i] and i > j):
                return False

            i += 1
            j += 1

        return True


class Solution:
    """
    @param start: the start
    @param end: the end
    @return: is there exists a sequence of moves to transform one string to the other
    """

    def can_transform(self, start: str, end: str) -> bool:
        # Write your code here
        return self.helper(start, 0, end)

    def helper(self, start, idx, end):
        if start == end:
            return True
        if idx >= len(start):
            return False

        for i in range(idx, len(start)):
            if start[i: i + 2] in ('XL', 'RX'):
                if self.helper(start, idx + 1, end):
                    return True

                tmp = start[:i] + start[i + 1] + start[i] + start[i + 2:]
                if self.helper(tmp, idx + 1, end):
                    return True

        return False
