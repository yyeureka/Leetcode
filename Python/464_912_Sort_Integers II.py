from typing import (
    List,
)


# quick sort
class Solution:
    """
    @param a: an integer array
    @return: nothing
    """

    def sort_integers2(self, a: List[int]):
        # write your code here
        self.quick_sort(a, 0, len(a) - 1)

    def quick_sort(self, a, start, end):
        if start >= end:
            return

        l, r = start, end
        pivot = a[(start + end) >> 1]

        while l <= r:
            while l <= r and a[l] < pivot:
                l += 1
            while l <= r and a[r] > pivot:
                r -= 1
            if l <= r:
                a[l], a[r] = a[r], a[l]
                l += 1
                r -= 1

        self.quick_sort(a, start, r)
        self.quick_sort(a, l, end)


# merge sort
class Solution:
    """
    @param a: an integer array
    @return: nothing
    """
    def sort_integers2(self, a: List[int]):
        # write your code here
        tmp = [0 for i in range(len(a))]
        self.merge_sort(a, 0, len(a) - 1, tmp)

    def merge_sort(self, a, start, end, tmp):
        if start >= end:
            return

        mid = (start + end) // 2
        self.merge_sort(a, start, mid, tmp)
        self.merge_sort(a, mid + 1, end, tmp)
        self.merge(a, start, end, tmp)

    def merge(self, a, start, end, tmp):
        mid = (start + end) // 2
        l, r = start, mid + 1
        i = start

        while l <= mid and r <= end:
            if a[l] < a[r]:
                tmp[i] = a[l]
                l += 1
                i += 1
            else:
                tmp[i] = a[r]
                r += 1
                i += 1
        while l <= mid:
            tmp[i] = a[l]
            l += 1
            i += 1
        while r <= end:
            tmp[i] = a[r]
            r += 1
            i += 1

        for i in range(start, end + 1):
            a[i] = tmp[i]
