import heapq

class Compare:
    def __init__(self, count, word):
        self.word = word
        self.count = count

    def __lt__(self, other):
        if self.count != other.count:
            return self.count < other.count
        return self.word > other.word

    def __eq__(self, other):
        return self.count == other.count and self.word == other.word

heapq.heappush(minheap, Compare(count[key], key))


# Hash heap
class HashHeap:
    def __init__(self, desc=False):
        self.heap = []
        self.hash = {}
        self.desc = desc

    def size(self):
        return len(self.heap)

    def push(self, item):
        idx = self.size()
        self.hash[item] = idx
        self.heap.append(item)
        self.sift_up(idx)

    def top(self):
        return self.heap[0]

    def pop(self):
        item = self.heap[0]
        self.remove(item)
        return item

    def remove(self, item):
        if item not in self.hash:
            return

        size = self.size()
        idx = self.hash[item]

        self.swap(idx, size - 1)
        self.heap.pop()
        self.hash.pop(item)

        if size - 1 != idx:
            self.sift_up(idx)
            self.sift_down(idx)

    def sift_up(self, idx):
        while 0 != idx:
            parent = (idx - 1) // 2

            if self.is_smaller(parent, idx):
                break

            self.swap(parent, idx)
            idx = parent

    def sift_down(self, idx):
        size = self.size()
        while idx * 2 + 1 < size:
            min = idx
            left = idx * 2 + 1
            right = idx * 2 + 2

            if left < size and self.is_smaller(left, min):
                min = left
            if right < size and self.is_smaller(right, min):
                min = right

            if min == idx:
                break

            self.swap(min, idx)
            idx = min

    def is_smaller(self, i, j):
        if self.desc:
            return self.heap[i] > self.heap[j]
        return self.heap[i] < self.heap[j]

    def swap(self, i, j):
        if i == j:
            return

        item_i = self.heap[i]
        item_j = self.heap[j]
        self.hash[item_i] = j
        self.hash[item_j] = i
        self.heap[i] = item_j
        self.heap[j] = item_i


# Heapify
# From leaf, sift down O(n) time, O(1) space
# From root, sift up O(nlogn) time, O(1) space

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