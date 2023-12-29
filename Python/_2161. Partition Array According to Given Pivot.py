class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        res = []
        count_equal = 0

        for i in nums:
            if i < pivot:
                res.append(i)
            elif pivot == i:
                count_equal += 1

        for i in range(count_equal):
            res.append(pivot)

        for i in nums:
            if i > pivot:
                res.append(i)

        return res
