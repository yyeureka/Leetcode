from typing import (
    List,
)

class Solution:
    """
    @param s: a string
    @param indexes: the index array
    @param sources: the source array
    @param targets: the target array
    @return: the string after operation
    """
    def find_replace_string(self, s: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        # Write your code here.
        for i, src, tgt in sorted(zip(indexes, sources, targets), reverse=True):
            if s[i: i + len(src)] == src:
                s = s[: i] + tgt + s[i + len(src):]

        return s
