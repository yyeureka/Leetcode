# 维护最小值和次小值，如果当前小于最小值，更新最小值，否则如果小于次小值，更新次小值，否则即为true
# Maintain a LIS list


class Solution:
    """
    @param nums: a list of integers
    @return: return a boolean
    """
    def increasing_triplet(self, nums):
        # write your code
        n = len(nums)
        if n < 3:
            return False

        min = float('inf')
        mid = float('inf')

        for i in nums:
            if i <= min:
                min = i
            elif i <= mid:
                mid = i
            else:
                return True

        return False


class Solution:
    """
    @param nums: a list of integers
    @return: return a boolean
    """

    def increasing_triplet(self, nums):
        # write your code
        n = len(nums)
        if n < 3:
            return False

        lis = []

        for i in nums:
            if not lis or i > lis[-1]:
                lis.append(i)
            else:
                for j in range(len(lis)):
                    if i <= lis[j]:  # key point
                        lis[j] = i

            if 3 == len(lis):
                return True

        return False