from typing import (
    List,
)

# non-increasing queue, store the index of the numbers, the front is the max
# pop() until back >= current number, append current index

from collections import deque

class Solution:
    """
    @param nums: A list of integers.
    @param k: An integer
    @return: The maximum number inside the window at each moving.
    """

    def max_sliding_window(self, nums: List[int], k: int) -> List[int]:
        # write your code here
        dq = deque()
        res = []

        for i in range(len(nums)):
            while dq and nums[dq[-1]] < nums[i]:  # key point
                dq.pop()
            dq.append(i)

            if dq[0] <= i - k:  # key point
                dq.popleft()

            if i >= k - 1:  # key point
                res.append(nums[dq[0]])

        return res

