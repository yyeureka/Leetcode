from typing import (
    List,
)

# 1、将每栋楼的起始点和高度存进vector：{i,h}，{j,-h}
# 2、sort vector，坐标不相等时以坐标从小到大排，坐标相等时以高度从大到小排
# 3、遍历vector，当高度>0时，存进HashHeap，否则从HashHeap中删除-高度
#    从HashHeap中获取当前高度，当前高度和pre不同时，即为key points将坐标和当前高度存进res


class HashHeap:
    def __init__(self, desc=False):
        self.heap = []
        self.hash = {}
        self.desc = desc

    def push(self, item):
        idx = self.size()
        self.hash[item] = idx
        self.heap.append(item)
        self.sift_up(idx)

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

    def top(self):
        return self.heap[0]

    def pop(self):
        item = self.heap[0]
        self.remove(item)
        return item

    def size(self):
        return len(self.heap)

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


class Solution:
    """
    @param buildings: A list of lists of integers
    @return: Find the outline of those buildings
    """

    def building_outline(self, buildings: List[List[int]]) -> List[List[int]]:
        # write your code here
        points = []
        for i, (start, end, height) in enumerate(buildings):
            points.append((start, height, i))
            points.append((end, -height, i))  # key point

        points.sort(key=lambda x: (x[0], -x[1]))  # key point

        maxheap = HashHeap(desc=True)
        pre_idx = None
        height = None
        res = []

        for idx, h, i in points:
            if h > 0:
                maxheap.push((h, i))
            else:
                maxheap.remove((-h, i))  # key point

            if maxheap.size() > 0:  # tricky
                h = maxheap.top()[0]
            else:
                h = 0

            if not height or h != height:
                if pre_idx and idx > pre_idx and height > 0:  # tricky
                    res.append([pre_idx, idx, height])
                height = h
                pre_idx = idx

        return res



