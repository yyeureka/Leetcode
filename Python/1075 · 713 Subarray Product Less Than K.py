from typing import (
    List,
)

class Solution:
    """
    @param nums: an array
    @param k: an integer
    @return: the number of subarrays where the product of all the elements in the subarray is less than k
    """
    def num_subarray_product_less_than_k(self, nums: List[int], k: int) -> int:
        # Write your code here
        i = 0
        product = 1
        res = 0

        for j in range(len(nums)):
            product *= nums[j]

            while i <= j and product >= k:  # key point
                product /= nums[i]
                i += 1

            res += j - i + 1  # key point

        return res


# prefix product TLE
class Solution:
    """
    @param nums: an array
    @param k: an integer
    @return: the number of subarrays where the product of all the elements in the subarray is less than k
    """

    def num_subarray_product_less_than_k(self, nums: List[int], k: int) -> int:
        # Write your code here
        res = 0
        prefix_product = [1 for _ in range(len(nums) + 1)]
        for i in range(len(nums)):
            prefix_product[i + 1] = prefix_product[i] * nums[i]

            for j in range(i, -1, -1):
                if prefix_product[i + 1] / prefix_product[j] >= k:
                    break

                res += 1

        return res