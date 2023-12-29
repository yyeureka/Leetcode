class Solution:
    """
    @param source: A string
    @param target: A string
    @return: A string denote the minimum window, return "" if there is no such a string
    """

    def min_window(self, source: str, target: str) -> str:
        # write your code here
        if not target:
            return ''
        if len(source) < len(target):
            return ''

        n = len(source)
        m = len(target)
        words = {}
        count = m
        res = ''

        for i in target:
            if i in words:
                words[i] += 1
            else:
                words[i] = 1

        j = 0
        for i in range(n):
            if source[i] in words:
                words[source[i]] -= 1
            else:
                words[source[i]] = -1

            if words[source[i]] >= 0:
                count -= 1

            while 0 == count:
                words[source[j]] += 1
                if words[source[j]] > 0:
                    count += 1

                    substr = source[j: i + 1]
                    if not res or len(substr) < len(res):
                        res = substr

                j += 1  # tricky

        return res
