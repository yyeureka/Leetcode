# stack
# dfs

# stack
class Solution:
    """
    @param s: an expression includes numbers, letters and brackets
    @return: a string
    """
    def expression_expand(self, s: str) -> str:
        # write your code here
        stack = []

        for i in s:
            if ']' != i:
                stack.append(i)
                continue

            tmp = []
            while stack:  # tricky
                j = stack.pop()
                if '[' == j:
                    break

                tmp.append(j)

            count = 0
            base = 1
            while stack and stack[-1].isdigit():  # tricky
                count += int(stack.pop()) * base
                base *= 10

            stack.append(''.join(reversed(tmp)) * count)  # clever

        return ''.join(stack)


# dfs
class Solution:
    """
    @param s: an expression includes numbers, letters and brackets
    @return: a string
    """

    def expression_expand(self, s: str) -> str:
        # write your code here
        if not s:
            return ''

        return self.helper(s, 0, len(s) - 1)

    def helper(self, s, start, end):
        if start > end:
            return ''

        res = ''
        i = start
        while i <= end:
            count = 0
            while i <= end and s[i].isalpha():
                res += s[i]
                i += 1
            while i <= end and s[i].isdigit():
                count = count * 10 + int(s[i])
                i += 1

            if i <= end and '[' == s[i]:
                flag = 1
                j = i
                while 0 != flag:
                    j += 1
                    if '[' == s[j]:
                        flag += 1
                    elif ']' == s[j]:
                        flag -= 1

                exp = self.helper(s, i + 1, j - 1)
                res += exp * count
                i = j + 1

        return res

