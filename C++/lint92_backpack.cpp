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

����˼·��
dp������0-1�������� ����lint125�����޸����������ظ�ȡ
dp[i][j]Ϊǰi����Ʒ����jʱ�����size
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]] + A[i])
��Ϊ��ȡ��ǰ��Ʒ��ȡ��ǰ��Ʒ֮������ֵ

challenge���ռ��Ż�
1���������飬��άdp�Ϳ��Խ��
2�����齵ά��û��Ϊʲô����

challenge����ӡ���
*/

class Solution {
public:
	int backPack(int m, vector<int> &A) {
		if (A.empty() || m <= 0) {
			return 0;
		}

		int n = A.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //�״�,����Ҫ��ʼ��0,0

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

////��������
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

////dp��ά
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
//			for (int j = m; j >= A[i]; j--) { //j��A[i]��m�����ظ�ѡͬһ����
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