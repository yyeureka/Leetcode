#include <vector>
using namespace std;

/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: You are not suppose to use the library's sort function for this problem.
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

解题思路：
1、三指针算法
2、counting sort以后，重新填回去
*/

//三指针算法
class Solution {
public:
	void sortColors(vector<int> &nums) {
		if (nums.empty()) return;

		int left = 0;
		int right = nums.size() - 1;
		int i = 0;

		while (i <= right) {
			if (0 == nums[i]) swap(nums[left++], nums[i++]);
			else if (2 == nums[i]) swap(nums[right--], nums[i]);
			else i++;
		}
	}
};

////counting sort
//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int cnt_0 = 0;
//		int cnt_1 = 0;
//
//		for (int i : nums) {
//			if (0 == i) cnt_0++;
//			if (1 == i) cnt_1++;
//		}
//
//		for (int i = 0; i < nums.size(); i++) {
//			if (i < cnt_0) nums[i] = 0;
//			else if (i < cnt_0 + cnt_1) nums[i] = 1; //这里特容易错
//			else nums[i] = 2;
//		}
//	}
//};