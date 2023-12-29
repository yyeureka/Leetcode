class Solution:
    """
    @param a: An array of integers
    @return: A long integer
    """

    def permutation_index_i_i(self, a):
        # write your code here
        n = len(a)
        if n <= 1:
            return n

        res = 1
        base = 1
        i = n - 1
        nums = {}
        dup = 1
        while i >= 0:
            if a[i] in nums:
                nums[a[i]] += 1
                dup *= nums[a[i]]  # key point
            else:
                nums[a[i]] = 1

            cnt = 0
            for j in range(i + 1, n):
                if a[j] < a[i]:
                    cnt += 1

            res += cnt * base / dup  # key point
            base *= n - i
            i -= 1

        return res
