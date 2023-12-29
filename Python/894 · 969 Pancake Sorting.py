from typing import (
    List,
)

# end从n-1开始
# if end is the max, end--
# else 将max先交换到位置0，再交换到end位置，end--

class Solution:
    """
    @param array: an integer array
    @return: nothing
    """

    def pancake_sort(self, array: List[int]):
        # Write your code here
        if not array:
            return

        end = len(array) - 1

        while end >= 0:
            max_idx = 0
            for i in range(1, end + 1):
                if array[i] > array[max_idx]:
                    max_idx = i

            if array[max_idx] != array[end]:
                if max_idx > 0:
                    FlipTool.flip(array, max_idx)
                FlipTool.flip(array, end)
            end -= 1

