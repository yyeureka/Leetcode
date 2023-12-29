class Solution:
    def firstUniqChar(self, s: str) -> int:
        counter = {}

        for c in str:
            counter[c] = counter.get(c, 0) + 1
        
        for c in str:
            if 1 == counter[c]:
                return c
        
        return -1