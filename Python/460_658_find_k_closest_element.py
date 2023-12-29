from typing import (
    List,
)

class Solution:
    """
    @param a: an integer array
    @param target: An integer
    @param k: An integer
    @return: an integer array
    """
    def k_closest_numbers(self, a: List[int], target: int, k: int) -> List[int]:
        # write your code here
        if not a:
            return []
        
        start = 0
        end = len(a) - 1

        while start + 1 < end:
            mid = (start + end) >> 1

            if a[mid] <= target:
                start = mid
            else:
                end = mid
        
        res = []
    
        while k > 0:
            if start < 0:
                res.append(a[end])
                end += 1
            elif end >= len(a):
                res.append(a[start])
                start -= 1
            elif target - a[start] <= a[end] - target:
                res.append(a[start])
                start -= 1
            else:
                res.append(a[end])
                end += 1

            k -= 1

        return res


# leetcode 658 C
# class Solution {
# public:
# 	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
# 		int start = 0;
# 		int end = arr.size() - k;

# 		while (start + 1 < end) {
# 			int mid = start + (end - start) / 2;

# 			if (x - arr[mid] > arr[mid + k] - x) start = mid; //不需要abs也可以
# 			else end = mid;
# 		}

# 		if (arr[end + k - 1] - x < x - arr[start]) start = end;  //end+k-1易错

# 		return vector<int>(arr.begin() + start, arr.begin() + start + k);
# 	}
# };