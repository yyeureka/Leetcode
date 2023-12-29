from typing import (
    List,
)


# hash O(n+m), O(n+m)
# sort 2 pointers O(nlogn+mlogm), O(logn+logm)
# sort binary search


# hash
class Solution:
    """
    @param nums1: an integer array
    @param nums2: an integer array
    @return: an integer array
             we will sort your return value in output
    """

    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # write your code here
        set1 = set(nums1)
        set2 = set(nums2)
        res = []

        for num in set2:
            if num in set1:
                res.append(num)

        return res