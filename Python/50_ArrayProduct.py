Description = '''
给定一个整数数组A。
定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。请输出B。
样例
给出A=[1, 2, 3]，返回 B为[6, 3, 2]
'''


class Solution:
    """
    @param: nums: Given an integers array A
    @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    """
    def productExcludeItself(self, nums):
        number = len(nums)
        l_product = 1
        r_product = 1
        left = [1] * number
        right = [1] * number
        for i in range(0, number - 1):
            l_product *= nums[i]
            r_product *= nums[number - 1 - i]
            left[i + 1] = l_product
            right[number - 2 - i] = r_product

        for i in range(0, number - 1):
            left[i] *= right[i]

        return left


s = Solution()
A=[1, 2, 3]
print(s.productExcludeItself(A))

