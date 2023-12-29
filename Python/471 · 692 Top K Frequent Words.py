from typing import (
    List,
)

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


class Solution:
    """
    @param words: an array of string
    @param k: An integer
    @return: an array of string
    """

    def top_k_frequent_words(self, words: List[str], k: int) -> List[str]:
        # write your code here
        count = {}
        for word in words:
            if word in count:
                count[word] += 1
            else:
                count[word] = 1

        minheap = []
        for key in count:
            heapq.heappush(minheap, Compare(count[key], key))

            if len(minheap) > k:
                heapq.heappop(minheap)

        res = []
        while minheap:
            res.append(heapq.heappop(minheap).word)

        res.reverse()
        return res