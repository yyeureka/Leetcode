Description = '''
给定整数n，计算出现在小于等于n的所有非负整数中的数字1的总数
解题思路：
1、最高位>1或=1，计算最高位1的个数
2、除去尾数后，计算除最高位的1的个数：如123，计算24~123，如223，计算24~223
3、尾数步骤1递归
特殊情况：10以内尾数，判断>=1
'''


def count1(number, len):
    result = 0
    if number >= 10:
        high_digit = number // pow(10, len - 1)
        remain = number % pow(10, len - 1)

        #最高位1的个数，如123为24个，223位100个
        if high_digit == 1:
            result = (remain + 1)
        elif high_digit > 1:
            result = pow(10, len - 1)

        base_cnt = (len - 1) * pow(10, len - 2)
        result += (high_digit * base_cnt)  #除去零头后，除最高位的1的个数
        #如123，以上结果为24~123中1的个数，如223，为24~223中结果
        result += count1(remain, len - 1)  #计算零头中1的个数
    elif number >= 1:
        result = 1

    return result


class Solution:
    """
    @param n: an integer
    @return: the total number of digit 1
    """
    def countDigitOne(self, n):
        result = 0
        len = 0
        number = n
        while number > 0:
            number //= 10
            len += 1

        result += count1(n, len)
        return result


number = 1033
s = Solution()
print(s.countDigitOne(number))
