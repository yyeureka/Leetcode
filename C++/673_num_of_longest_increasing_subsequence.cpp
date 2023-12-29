#include <vector>
using namespace std;

/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.

解题思路：dp
vector<pair<int,int>> dp(n,{1,1})，记录以每一个nums[i]结尾的increasing subsequence的length和cnt
j从0~i-1遍历之前的dp[j],更新dp[i]
*/

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int res = 0;
		int max_len = 0;
		vector<pair<int, int>> v(nums.size(), { 1, 1 });  // len of subsequence, num of subsequence

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (v[j].first + 1 > v[i].first) v[i] = { v[j].first + 1, v[j].second };
					else if (v[j].first + 1 == v[i].first) v[i].second += v[j].second;
				}
			}
			if (v[i].first > max_len) {
				max_len = v[i].first;
				res = v[i].second;
			}
			else if (v[i].first == max_len) res += v[i].second;
		}
		return res;
	}
};