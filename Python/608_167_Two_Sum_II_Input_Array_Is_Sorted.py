# two pointers
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1

        while l < r:
            sum = numbers[l] + numbers[r]

            if target == sum:
                return [l + 1, r + 1]
            elif sum < target:
                l += 1
            else:
                r -= 1

        return []


# hash
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        index = {}

        for i in range(len(numbers)):
            pre = target - numbers[i]

            if pre in index:
                return [index[pre], i + 1]

            index[numbers[i]] = i + 1

        return []