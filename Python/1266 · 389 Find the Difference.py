class Solution:
    """
    @param s: a string
    @param t: a string
    @return: the letter that was added in t
    """

    def find_the_difference(self, s: str, t: str) -> str:
        # Write your code here
        res = 0

        for i in s:
            res -= ord(i)
        for i in t:
            res += ord(i)

        return chr(res)


class Solution:
    """
    @param s: a string
    @param t: a string
    @return: the letter that was added in t
    """
    def find_the_difference(self, s: str, t: str) -> str:
        # Write your code here
        res = 0

        for i in s:
            res ^= ord(i)
        for i in t:
            res ^= ord(i)

        return chr(res)


class Solution:
    """
    @param s: a string
    @param t: a string
    @return: the letter that was added in t
    """

    def find_the_difference(self, s: str, t: str) -> str:
        # Write your code here
        hash = {}

        for i in s:
            if i in hash:
                hash[i] += 1
            else:
                hash[i] = 1
        for i in t:
            if i not in hash or hash[i] <= 0:
                return i

            hash[i] -= 1