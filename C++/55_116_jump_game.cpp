#include <vector>
using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
jump length is 0, which makes it impossible to reach the last index.

解题思路：时间O(n^2)，空间O(n)
dp1：对每一个i，j从i-1开始到0，看有没有j+A[j]>=i的，有的话i即可走到
dp2：有点dfs的思路了，对每一个能走到的i，i+A[i]之内的状态都置为true，会TLE！！！
*/

class Solution {
public:
	bool canJump(vector<int> &A) {
		vector<bool> dp(A.size(), false);
		dp[0] = true;

		for (int i = 1; i < A.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (dp[j] && (j + A[j] >= i)) {
					dp[i] = true;
					break;
				}
			}
		}

		return dp.back();
	}
};

//class Solution {
//public:
//	bool canJump(vector<int> &A) {
//		vector<bool> dp(A.size(), false);
//		dp[0] = true;
//
//		for (int i = 0; i < A.size(); i++) {
//			if (!dp[i]) {
//				continue;
//			}
//
//			for (int j = 1; j <= A[i]; j++) {
//				if (i + j >= A.size() - 1) { //易错，是-1
//					return true;
//				}
//
//				dp[i + j] = true;
//			}
//		}
//
//		return dp.back(); //易错，不能直接return false，考虑[0]的情况
//	}
//};