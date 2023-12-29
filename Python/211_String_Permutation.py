class Solution:
    """
    @param a: a string
    @param b: a string
    @return: a boolean
    """
    def permutation(self, a: str, b: str) -> bool:
        # write your code here
        if len(a) != len(b):
            return False

        count = {}

        for i in a:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        for i in b:
            if i not in count or count[i] < 1:
                return False

            count[i] -= 1

        for i in count:
            if 0 != count[i]:  # key point
                return False
        return True

