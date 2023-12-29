#include "head.h"

/*
Given an unsorted array, sort the given array. You are allowed to do only following operation on array.
flip(arr, i): Reverse array from 0 to i
Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible.

Example 1:
Input: array = [6,11,10,12,7,23,20]
Output：[6,7,10,11,12,20,23]
Explanation：
flip(array, 5)
flip(array, 6)
flip(array, 0)
flip(array, 5)
flip(array, 1)
flip(array, 4)
flip(array, 1)
flip(array, 3)
flip(array, 1)
flip(array, 2)
Example 2:
Input: array = [4, 2, 3]
Output: [2, 3, 4]
Explanation:
flip(array, 2)
flip(array, 1)

Notice
You only call flip function.
Don't allow to use any sort function or other sort methods.

Java：you can call FlipTool.flip(arr, i)
C++： you can call FlipTool::flip(arr, i)
Python2&3 you can call FlipTool.flip(arr, i)

解题思路：
end从n-1开始
每次将0~end中最大的数字先交换到第一个，然后再交换end，end--
*/

class Solution {
public:
	void pancakeSort(vector<int> &array) {
		for (int end = array.size() - 1; end > 0; end--) {
			int maxIdx = 0;

			int i;
			for (i = 1; i <= end; i++) {
				if (array[i] <= array[maxIdx]) continue;

				maxIdx = i;
			}

			if (end != maxIdx) {
				if (0 != maxIdx) {
					reverse(array.begin(), array.begin() + maxIdx + 1);
				}
				reverse(array.begin(), array.begin() + end + 1);
			}
		}
	}
};

//leetcode
//class Solution {
//public:
//	vector<int> pancakeSort(vector<int>& A) {
//		vector<int> result;
//
//		for (int num = A.size(); num > 0; num--) {
//			int i = 0;
//			while (A[i] != num) {
//				i++;
//			}
//
//			if (i == num - 1) continue;
//
//			if (0 != i) {
//				reverse(A.begin(), A.begin() + i + 1);
//				result.push_back(i + 1);
//			}
//			reverse(A.begin(), A.begin() + num);
//			result.push_back(num);
//		}
//
//		return result;
//	}
//};