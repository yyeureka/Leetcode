#include <vector>
using namespace std;

/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]

解题思路：
起始位置i为：第一个arr[i]到x的距离<=x到arr[i+k]的距离
1、binary search
2、i从0开始遍历
*/

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int start = 0;
		int end = arr.size() - k;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (x - arr[mid] > arr[mid + k] - x) start = mid; //不需要abs也可以
			else end = mid;
		}

		if (arr[end + k - 1] - x < x - arr[start]) start = end;  //end+k-1易错

		return vector<int>(arr.begin() + start, arr.begin() + start + k);
	}
};