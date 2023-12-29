class Solution:
    """
    @param source:
    @param target:
    @return: return the index
    """

    def str_str(self, source: str, target: str) -> int:
        # Write your code here
        len_s = len(source)
        len_t = len(target)

        for i in range(len_s - len_t + 1):
            j = 0
            while j < len_t:
                if source[i + j] != target[j]:
                    break

                j += 1

            if len_t == j:
                return i

        return -1
