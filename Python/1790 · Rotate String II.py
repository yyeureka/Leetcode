class Solution:
    """
    @param str: An array of char
    @param left: a left offset
    @param right: a right offset
    @return: return a rotate string
    """

    def rotate_string2(self, str: str, left: int, right: int) -> str:
        # write your code here
        if not str:
            return ''
        if left == right:
            return str

        if left > right:
            offset = (left - right) % len(str)
        else:
            offset = len(str) - (right - left) % len(str)

        # return str[offset:] + str[:offset]
        return (str + str)[offset: offset + len(str)]