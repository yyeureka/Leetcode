# binary indexed tree

class NumArray:
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.bit = [0]
        for i in range(1, len(nums) + 1):
            sum = 0

            for j in range(i, i - (i & (-i)), -1):
                sum += nums[j - 1]

            self.bit.append(sum)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        diff = val - self.sumRange(i, i)
        i += 1

        while i < len(self.bit):
            self.bit[i] += diff
            i += i & (-i)

    def sumPrefix(self, i):
        sum = 0
        i += 1

        while i > 0:
            sum += self.bit[i]
            i -= i & (-i)

        return sum

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sumPrefix(j) - self.sumPrefix(i - 1)

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)