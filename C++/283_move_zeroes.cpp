#include <vector>
using namespace std;

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

解题思路：two pointers
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (0 != nums[j]) nums[i++] = nums[j];
		}
		while (i < nums.size()) nums[i++] = 0;
	}
};