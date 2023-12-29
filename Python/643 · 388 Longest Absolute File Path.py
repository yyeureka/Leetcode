class Solution:
    """
    @param input: an abstract file system
    @return: return the length of the longest absolute path to file
    """
    def length_longest_path(self, input: str) -> int:
        # write your code here
        input = input.split('\\n')  # tricky
        dir_len = {}
        res = 0

        for i in input:
            count = 0
            index = 0
            while '\\t' == i[index: index + 2]:  # tricky
                index += 2
                count += 1

            cur = i[index:]
            length = dir_len.get(count - 1, 0) + len(cur)

            if cur.find('.') >= 0:
                res = max(res, length)
            else:
                dir_len[count] = length + 1

        return res
