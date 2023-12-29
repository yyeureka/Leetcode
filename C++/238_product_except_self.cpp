#include <vector>
using namespace std;

/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Note: Please solve it without division and in O(n).
Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]
*/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		int l = 1;
		int r = 1;
		vector <int> res(n, 1);

		for (int i = 0; i < n - 1; i++)
		{
			l *= nums[i];
			r *= nums[n - 1 - i];
			res[i + 1] *= l;
			res[n - 2 - i] *= r;
		}

		return res;
	}
};