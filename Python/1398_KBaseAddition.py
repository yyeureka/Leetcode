Description = '''
给出一个k，a，b，代表a和b都是一个k进制的数，输出a + b的k进制数。
2 <= k <= 10
a, b均为字符串，长度不超过1000。
可能有前导零
注意事项：
a，b可能有前导0，但输出不能有！
'''


def str_add(base, a, b):
    result = ''
    exceed = 0
    len_a = len(a)
    len_b = len(b)

    for i in range(max(len_a, len_b) + 1): #别忘了可能有进位啊！！
        digit = 0
        digit += exceed
        if i < len_a:
            digit += int(a[i])
        if i < len_b:
            digit += int(b[i])

        if digit >= base:
            digit -= base
            exceed = 1
        else:
            exceed = 0

        result += '{}'.format(digit)
    print(result)
    return result


class Solution:
    """
    @param k: The k
    @param a: The A
    @param b: The B
    @return: The answer
    """
    def addition(self, k, a, b):
        rev_a = a[::-1]
        rev_b = b[::-1]
        result = str_add(k, rev_a, rev_b)
        result = int(result[::-1])  #去掉前面多余的0
        result = '{}'.format(result)
        return result


s = Solution()
print(s.addition(2, '1', '1'))
