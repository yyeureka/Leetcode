#include "head.h"

/*
Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

Example 1:
Input:  [3,4,8,5], backpack size=10
Output:  9
Example 2:
Input:  [2,3,5,7], backpack size=12
Output:  12

Challenge
O(n x m) time and O(m) memory.
O(n x m) memory is also acceptable if you do not know how to optimize memory.

Notice
You can not divide any item into small pieces.

解题思路：
dp，经典0-1背包问题 类似lint125：不限个数，不能重复取
dp[i][j]为前i个物品容量j时的最大size
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]] + A[i])
即为不取当前物品、取当前物品之间的最大值

challenge：空间优化
1、滚动数组，二维dp就可以解决
2、数组降维，没懂为什么？？

challenge：打印结果
*/

class Solution {
public:
	int backPack(int m, vector<int> &A) {
		if (A.empty() || m <= 0) {
			return 0;
		}

		int n = A.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //易错,不需要初始化0,0

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];

				if (j - A[i - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i - 1]] + A[i - 1]);
				}
			}
		}

		return dp[n][m];
	}
};

////滚动数组
//class Solution {
//public:
//	int backPack(int m, vector<int> &A) {
//		if (A.empty() || m <= 0) {
//			return 0;
//		}
//
//		int n = A.size();
//		vector<vector<int>> dp(2, vector<int>(m + 1, 0));
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				dp[i & 1][j] = dp[(i - 1) & 1][j];
//
//				if (j - A[i - 1] >= 0) {
//					dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j - A[i - 1]] + A[i - 1]);
//				}
//			}
//		}
//
//		return dp[n & 1][m];
//	}
//};

////dp降维
//class Solution {
//public:
//	int backPack(int m, vector<int> &A) {
//		if (A.empty() || m <= 0) {
//			return 0;
//		}
//
//		vector<int> dp(m + 1, 0);
//
//		for (int i = 0; i < A.size(); i++) {
//			for (int j = m; j >= A[i]; j--) { //j从A[i]到m即可重复选同一个数
//				dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
//			}
//		}
//
//		return dp[m];
//	}
//};

////dfs
//class Solution {
//public:
//	int backPack(int m, vector<int> &A) {
//		if (A.empty() || m <= 0) return 0;
//
//		int result = 0;
//		dfs(A, m, 0, 0, result);
//
//		return result;
//	}
//
//	void dfs(vector<int> &A, int m, int start, int size, int &result) {
//		if (size > m) {
//			return;
//		}
//		else {
//			result = max(result, size);
//		}
//
//		for (int i = start; i < A.size(); i++) {
//			dfs(A, m, i + 1, size + A[i], result);
//		}
//	}
//};