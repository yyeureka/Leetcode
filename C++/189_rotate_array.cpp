#include <vector>
using namespace std;

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

解题思路：
k可能大于总个数，要round，非常贱
1、cyclic replacement
2、reverse：前、后半部分分别reverse，再reverse全部
3、extra space：vector tmp保存前半部分，后半部分赋值到前面，再把tmp放进去
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();  // corner case，k可能大于总个数，要round
		int cnt = 0;
		for (int i = 0; cnt < nums.size(); i++) {
			int idx = i;
			int value = nums[i];
			while (1) {
				idx = (idx + k) % nums.size();
				swap(value, nums[idx]);
				cnt++;
				if (idx == i) break;
			}
		}
	}
};

//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		k %= nums.size();  // corner case，k可能大于总个数，要round
//		reverse(nums.begin(), nums.end() - k);
//		reverse(nums.end() - k, nums.end());
//		reverse(nums.begin(), nums.end());
//	}
//};

//class Solution {
//public:
//	void rotate(vector<int>& nums, int k) {
//		k %= nums.size();  // corner case，k可能大于总个数，要round
//
//		vector<int> tmp(nums.begin(), nums.end() - k);
//		int i = 0;
//		int j = nums.size() - k;
//		while (j < nums.size()) nums[i++] = nums[j++];
//		j = 0;
//		while (i < nums.size()) nums[i++] = tmp[j++];
//	}
//};
