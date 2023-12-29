# hash O(n+m)
# hash2 O(n*m) - TLE

# hash
class Solution:
    """
    @param s1: a string
    @param s2: a string
    @return: if s2 contains the permutation of s1
    """

    def check_inclusion(self, s1: str, s2: str) -> bool:
        # write your code here
        if not s1:
            return True
        if len(s1) > len(s2):
            return False

        n = len(s1)
        m = len(s2)
        words = {}
        count = n

        for i in s1:
            if i in words:
                words[i] += 1
            else:
                words[i] = 1

        for i in range(m):
            if s2[i] in words:
                words[s2[i]] -= 1
            else:
                words[s2[i]] = -1

            if words[s2[i]] >= 0:
                count -= 1

            if i >= n:
                words[s2[i - n]] += 1

                if words[s2[i - n]] > 0:
                    count += 1

            if 0 == count:
                return True

        return False


# hash2
class Solution:
    """
    @param s1: a string
    @param s2: a string
    @return: if s2 contains the permutation of s1
    """

    def check_inclusion(self, s1: str, s2: str) -> bool:
        # write your code here
        if not s1:
            return True
        if len(s1) > len(s2):
            return False

        n = len(s1)
        m = len(s2)
        for i in range(m - n + 1):
            substr = s2[i: i + n]
            if self.is_permutation(s1, substr):
                return True

        return False

    def is_permutation(self, s1, s2):
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True

        count = {}
        for i in s1:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        for i in s2:
            if i not in count or count[i] < 1:
                return False

            count[i] -= 1
        for i in count:
            if 0 != count[i]:
                return False

        return True