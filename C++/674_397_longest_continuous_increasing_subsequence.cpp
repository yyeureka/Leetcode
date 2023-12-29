#include <vector>
#include <algorithm>
using namespace std;

/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
Note: Length of the array will not exceed 10,000.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.

解题思路：
最基础的dp，corner case：空输入，一个元素输入注意处理
leetcode版本更简单
*/

//lintcode
class Solution {
public:
	int longestIncreasingContinuousSubsequence(vector<int> &A) {
		if (A.empty()) {
			return 0;
		}

		int maxLen = 0;
		int dp1 = 0; //increasing;
		int dp2 = 0; //decreasing

		for (int i = 0; i < A.size(); i++) {
			dp1 = (i > 0 && A[i - 1] < A[i]) ? dp1 + 1 : 1;
			dp2 = (i > 0 && A[i - 1] > A[i]) ? dp2 + 1 : 1;
			maxLen = max(maxLen, max(dp1, dp2));
		}

		return maxLen;
	}
};

//leetcode
//class Solution {
//public:
//	int findLengthOfLCIS(vector<int>& nums) {
//		if (nums.empty()) {
//			return 0;
//		}
//
//		int maxLen = INT_MIN;
//		int dp = 1;
//
//		for (int i = 0; i < nums.size(); i++) {
//			dp = (i > 0 && nums[i - 1] < nums[i]) ? dp + 1 : 1;
//
//			maxLen = max(maxLen, dp);
//		}
//
//		return maxLen;
//	}
//};