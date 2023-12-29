class Solution:
    """
    @param source: A source string
    @param target: A target string
    @return: An integer as index
    """

    def str_str2(self, source: str, target: str) -> int:
        # write your code here
        if not target:  # tricky
            return 0
        if not source:
            return -1

        n = len(source)
        m = len(target)

        t_hash = 0
        power = 1
        size = 10 ^ 6
        for c in target:
            t_hash = (t_hash * 33 + ord(c)) % size
            power = (power * 33) % size  # key point

        s_hash = 0
        for i in range(n):
            s_hash = (s_hash * 33 + ord(source[i])) % size

            if i >= m:
                s_hash = (s_hash - ord(source[i - m]) * power) % size  # key point

            if s_hash == t_hash:
                if source[i - m + 1: i + 1] == target:  # key point, double check
                    return i - m + 1

        return -1


