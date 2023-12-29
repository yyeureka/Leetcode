# 以2 4 3 5 1为例
# 5：1个数比他小——1*1
# 3：1个数比他小——1*2！
# 4：2个数比他小——2*3！
# 2：1个数比他小——1*4！

class Solution:
    """
    @param a: An array of integers
    @return: A long integer
    """

    def permutation_index(self, a):
        # write your code here
        n = len(a)
        if n <= 1:
            return n

        res = 1
        base = 1
        i = n - 1
        while i >= 0:
            cnt = 0
            for j in range(i + 1, n):
                if a[j] < a[i]:
                    cnt += 1

            res += cnt * base
            base *= n - i
            i -= 1

        return res

