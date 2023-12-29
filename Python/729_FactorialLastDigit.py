Description = '''
给出两个数 A 和 B, 其中 B >= A. 我们需要计算结果 F 的最后一位数是什么, 其中F = B! / A!(1 <= A, B <= 10^18, A 和 B 非常大)
例如：给出 A = 2, B = 4, 返回 2
A! = 2 以及 B! = 24, F = 24 / 2 = 12 --> 最后一位数为 2 
给出 A = 107, B = 109, 返回 2
解题思路：
1、存在某种规律，基本等于从A+1到B末位的乘积的最后一位
2、特殊情况：B等于A时结果为1
'''


class Solution:
    """
    @param A: the given number
    @param B: another number
    @return: the last digit of B! / A!
    """
    def computeLastDigit(self, A, B):
        diff = B - A
        A %= 10
        B %= 10

        if B < A:
            B += 10
        elif B == A:
            if 0 == diff:
                return 1   #这个地方坑爹啊！！！！
            else:
                B += 10
        elif diff > 10:
            B += 10

        result = 1
        for i in range(A + 1, B + 1):
            result *= i
            result %= 10

        return result

s = Solution()
print(s.computeLastDigit(7680103979767522, 85610382768811514))
