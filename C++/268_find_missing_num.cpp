#include <vector>
using namespace std;

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Example 1:
Input: [3,0,1]
Output: 2
Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

解题思路：
1、类似ex41
2、异或：a^b^b = a,nums没有少的时候序号0~i ^ 数值0~i为0
   缺少数值j时，数值i+1替换进来，序号0~i ^现在的所有数值后为j ^ i+1，再^i+1后即为结果j
3、sort
*/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		while (i < n) {
			if (nums[i] == i) i++;
			else if (nums[i] >= n) i++;
			else swap(nums[nums[i]], nums[i]);
		}

		for (i = 0; i < n; i++) {
			if (nums[i] != i) break;
		}
		return i;

		//int res = 0; //因为后面是^=，这里一定要初始化为0
		//int i;
		//for (i = 0; i < nums.size(); i++) res ^= (i ^ nums[i]);
		//return res ^ i;
	}
};