class Solution:
    """
    @param s: A string
    @return: whether the string is a valid parentheses
    """
    def is_valid_parentheses(self, s: str) -> bool:
        # write your code here
        stack = []
        for c in s:
            if '(' == c:
                stack.append(')')
            elif '{' == c:
                stack.append('}')
            elif '[' == c:
                stack.append(']')
            else:
                if not stack or c != stack[-1]:  # tricky
                    return False
                stack.pop()

        return not stack  # tricky


class Solution:
    """
    @param s: A string
    @return: whether the string is a valid parentheses
    """
    def is_valid_parentheses(self, s: str) -> bool:
        # write your code here
        stack = []
        for c in s:
            if ')' == c:
                if not stack or '(' != stack[-1]:  # tricky
                    return False
                stack.pop()
            elif '}' == c:
                if not stack or  '{' != stack[-1]:
                    return False
                stack.pop()
            elif ']' == c:
                if not stack or  '[' != stack[-1]:
                    return False
                stack.pop()
            else:
                stack.append(c)

        return not stack  # tricky