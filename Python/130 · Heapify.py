from typing import (
    List,
)

# From leaf, sift down O(n) time, O(1) space
# From root, sift up O(nlogn) time, O(1) space
# Insert n times, O(nlogn) time, O(n) space


# sift down
class Solution:
    """
    @param a: Given an integer array
    @return: nothing
    """

    def heapify(self, a: List[int]):
        # write your code here
        if not a:
            return

        for i in range(len(a) // 2, -1, -1):
            self.siftdown(a, i)

    def siftdown(self, a, i):
        while i < len(a):
            left = 2 * i + 1
            right = 2 * i + 2
            minIdx = i

            if left < len(a) and a[left] < a[minIdx]:
                minIdx = left
            if right < len(a) and a[right] < a[minIdx]:
                minIdx = right

            if minIdx == i:
                break

            a[minIdx], a[i] = a[i], a[minIdx]
            i = minIdx


# sift up
class Solution:
    """
    @param a: Given an integer array
    @return: nothing
    """
    def heapify(self, a: List[int]):
        # write your code here
        if not a:
            return

        for i in range(len(a)):
            self.siftup(a, i)

    def siftup(self, a, i):
        while 0 != i:
            next = (i - 1) // 2

            if a[next] <= a[i]:
                break

            a[next], a[i] = a[i], a[next]
            i = next


# insert n times
class Solution:
    """
    @param a: Given an integer array
    @return: nothing
    """

    def heapify(self, a: List[int]):
        # write your code here
        if not a:
            return

        res = []
        for i in a:
            idx = len(res)
            res.append(i)

            while 0 != idx:
                next = (idx - 1) // 2

                if res[next] <= res[idx]:
                    break

                res[next], res[idx] = res[idx], res[next]
                idx = next

        for i in range(len(a)):
            a[i] = res[i]

