from typing import (
    List,
)

class Solution:
    """
    @param stk: an integer stack
    @return: nothing
    """
    def stack_sorting(self, stk: List[int]):
        # write your code here
        stack = []  # decreasing

        while stk:
            cur = stk.pop()

            while stack and stack[-1] < cur:
                stk.append(stack.pop())
            stack.append(cur)

        while stack:
            stk.append(stack.pop())
