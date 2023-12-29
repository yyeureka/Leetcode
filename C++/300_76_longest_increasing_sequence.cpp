#include <vector>
#include <algorithm>
using namespace std;

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.
Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

解题思路：#334同样的思路
1、坐标型dp，dp[i]为以i结尾的LIS的长度，O(n^2)
2、binary search，O(nlogn)
   对于nums中的每一个i，在lis里找lower_bound，如果都比i小，i加进lis，否则替换第一个>=i的元素
   最后lis的size即为最大长度

follow up：同时找到一个方案
更新每个节点长度时，也记录这个节点的前继节点，找到最后那个节点再逆推回去
*/

//dp
class Solution {
public:
	int longestIncreasingSubsequence(vector<int> &nums) {
		if (nums.empty()) {
			return 0;
		}

		vector<int> dp(nums.size(), 1);
		int maxLen = 0;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] >= nums[i]) {
					continue;
				}

				dp[i] = max(dp[i], dp[j] + 1);
			}

			maxLen = max(maxLen, dp[i]);
		}

		return maxLen;
	}
};

////binary search
//class Solution {
//public:
//	int longestIncreasingSubsequence(vector<int> &nums) {
//		if (nums.empty()) {
//			return 0;
//		}
//
//		vector<int> lis;
//
//		for (int i : nums) {
//			if (lis.empty() || i > lis.back()) { //易错，先判断是否为空
//				lis.push_back(i);
//			}
//			else {
//				int index = lowerBound(lis, i);
//				lis[index] = i;
//			}
//		}
//
//		return lis.size();
//	}
//
//	int lowerBound(vector<int> &lis, int target) {
//		int start = 0;
//		int end = lis.size() - 1;
//
//		while (start + 1 < end) {
//			int mid = start + (end - start) / 2;
//
//			if (lis[mid] >= target) {
//				end = mid;
//			}
//			else {
//				start = mid;
//			}
//		}
//
//		if (lis[start] >= target) {
//			return start;
//		}
//		return end;
//	}
//};

//找LIS&一个方案
//class Solution {
//public:
//	int longestIncreasingSubsequence(vector<int> &nums) {
//		if (nums.empty()) {
//			return 0;
//		}
//
//		vector<int> dp(nums.size(), 1);
//		vector<int> preIdx(nums.size(), -1);
//		int maxLen = INT_MIN;
//		int maxIdx = -1;
//
//		for (int i = 0; i < nums.size(); i++) {
//			for (int j = 0; j < i; j++) {
//				if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
//					dp[i] = dp[j] + 1;
//					preIdx[i] = j;
//				}
//			}
//
//			if (dp[i] > maxLen) {
//				maxLen = dp[i];
//				maxIdx = i;
//			}
//		}
//
//		vector<int> path;
//		while (-1 != maxIdx) {
//			path.push_back(nums[maxIdx]);
//			maxIdx = preIdx[maxIdx];
//		}
//		reverse(path.begin(), path.end());
//
//		return maxLen;
//	}
//};