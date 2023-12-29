from typing import (
    List,
)

class Solution:
    """
    @param tokens: The Reverse Polish Notation
    @return: the value
    """
    def eval_r_p_n(self, tokens: List[str]) -> int:
        # write your code here
        if not tokens:
            return 0

        stack = []

        for i in tokens:
            if i not in ('+', '-', '*', '/'):
                stack.append(int(i))
            else:
                y = stack.pop()
                x = stack.pop()

                if '+' == i:
                    stack.append(x + y)
                elif '-' == i:
                    stack.append(x - y)
                elif '*' == i:
                    stack.append(x * y)
                else:
                    stack.append(int(x / y))  # tricky

        return 0 if len(stack) > 1 else stack[0]