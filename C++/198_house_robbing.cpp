#include <vector>
#include <algorithm>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

解题思路：
sum[i]为到当前房子为止钱的max
对于房子i，sum[i]为当前房子里的钱nums[i]+sum[i - 2]和前一个房子sum[i-1]的最大值
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		vector<int> sum(2, 0);
		for (int i = 0; i < n; i++) {
			int cur = nums[i];
			if (i > 1) cur += sum[i & 1];
			if (i > 0) cur = max(cur, sum[(i - 1) & 1]);
			sum[i & 1] = cur;
		}
		return sum[(n - 1) & 1];
	}
};