#include <vector>
using namespace std;

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]

解题思路：
类似删除某个元素下标从0开始，插入某个元素下标从末尾m+n-1开始
*/

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int Index1 = m - 1;
		int Index2 = n - 1;

		for (int i = m + n - 1; i >= 0; i--) {
			if (Index2 < 0) { //提高效率
				break;
			}
			else if (Index1 < 0) {
				nums1[i] = nums2[Index2--];
			}
			else if (nums2[Index2] > nums1[Index1]) {
				nums1[i] = nums2[Index2--];
			}
			else {
				nums1[i] = nums1[Index1--];
			}
		}
	}
};