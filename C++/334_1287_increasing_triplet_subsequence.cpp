#include <vector>
#include <algorithm>
using namespace std;

/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:
Input: [1,2,3,4,5]
Output: true
Example 2:
Input: [5,4,3,2,1]
Output: false

解题思路：LIS问题衍生
1、维护最小值和次小值，如果当前小于最小值，更新最小值，否则如果小于次小值，更新次小值，否则即为true
   O(n)时间，O(1)空间
2、binary search，O(nlogn)，O(n)空间
3、坐标型dp，O(n^2)时间，O(n)空间
*/

class Solution {
public:
	bool increasingTriplet(vector<int> &nums) {
		if (nums.empty()) {
			return false;
		}

		int min1 = INT_MAX;
		int min2 = INT_MAX;

		for (int i : nums) {
			if (i <= min1) { //易错
				min1 = i;
			}
			else if (i <= min2) {
				min2 = i;
			}
			else {
				return true;
			}
		}

		return false;
	}
};

//class Solution {
//public:
//	bool increasingTriplet(vector<int> &nums) {
//		if (nums.empty()) {
//			return false;
//		}
//
//		vector<int> lis;
//
//		for (int i : nums) {
//			if (lis.empty() || i > lis.back()) {
//				lis.push_back(i);
//			}
//			else {
//				int index = lowerBound(lis, i);
//				lis[index] = i;
//			}
//
//			if (lis.size() >= 3) {
//				return true;
//			}
//		}
//
//		return false;
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

////dp
//class Solution {
//public:
//	bool increasingTriplet(vector<int> &nums) {
//		if (nums.empty()) {
//			return false;
//		}
//
//		vector<int> dp(nums.size(), 0);
//
//		for (int i = 0; i < nums.size(); i++) {
//			dp[i] = 1;
//
//			for (int j = 0; j < i; j++) {
//				if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
//					dp[i] = dp[j] + 1;
//
//					if (dp[i] >= 3) {
//						return true;
//					}
//				}
//			}
//		}
//
//		return false;
//	}
//};