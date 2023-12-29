# 以4、9为例：nums为1234,找以0开始的8th
# digit 1：后3个数字6种排列，idx=8/6=1即为2，nums去掉2
# digit 2：后2个数字2种排列，idx=2/2=1即为3，nums去掉3
# digit 3，后1个数字1种排列，idx=0/1=0即为1，nums去掉1
# digit 4，后0个数字1种排列，idx=0/1=0即为4

class Solution:
    """
    @param n: n
    @param k: the k th permutation
    @return: return the k-th permutation
    """
    def get_permutation(self, n, k):
        # write your code here
        nums = [i for i in range(1, n + 1)]

        base = 1
        for i in range(1, n):
            base *= i

        k -= 1
        res = ''
        for i in range(n):
            cnt = k // base
            k %= base

            res += str(nums[cnt])
            nums.pop(cnt)

            if i < n - 1:  # tricky
                base /= (n - i - 1)

        return res
