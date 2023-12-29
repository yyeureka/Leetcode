#include "head.h"

/*
There are n items and a backpack with size m. Given array A representing the size of each item and array V representing the value of each item.
What's the maximum value can you put into the backpack?

Example 1:
Input: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
Output: 9
Explanation: Put A[1] and A[3] into backpack, getting the maximum value V[1] + V[3] = 9
Example 2:
Input: m = 10, A = [2, 3, 8], V = [2, 5, 8]
Output: 10
Explanation: Put A[0] and A[2] into backpack, getting the maximum value V[0] + V[2] = 10

Challenge
O(nm) memory is acceptable, can you do it in O(m) memory?

Notice
A[i], V[i], n, m are all integers.
You can not split an item.
The sum size of the items you want to put into backpack can not exceed m.
Each item can only be picked up once

����˼·����dfs��TLE
dp������0-1�������⣺���޸����������ظ�ȡ
dp[i][j]Ϊǰi����Ʒ����jʱ������ֵ
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i]] + V[i])
��Ϊ��ȡ��ǰ��Ʒ��ȡ��ǰ��Ʒ֮������ֵ

��[2,3,5,7]��[1,5,2,4]��sizeΪ10Ϊ��
   0 1 2 3 4 5 6 7 8 9 10
0: 0 0 0 0 0 0 0 0 0 0 0
1: 0 0 1 1 1 1 1 1 1 1 1
2: 0 0 1 5 5 6 6 6 6 6 6
3: 0 0 1 5 5 6 6 6 7 7 8
4: 0 0 1 5 5 6 6 6 7 7 9

challenge���ռ��Ż�
1���������飬��άdp�Ϳ��Խ��
2�����齵ά��û��Ϊʲô����

challenge����ӡ���������ӡ��ʲô����
*/

class Solution {
public:
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		if (A.empty() || A.size() != V.size() || m <= 0) {
			return 0;
		}

		int n = A.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //����Ҫ��ʼ��0,0

		for (int i = 1; i <= n; i++) { //iΪǰ������������index
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];

				if (j - A[i - 1] >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i - 1]] + V[i - 1]); //�״� A��V���±�Ҫ-1
				}
			}
		}

		return dp[n][m];
	}
};

////dp��ά
//class Solution {
//public:
//	int backPackII(int m, vector<int> &A, vector<int> &V) {
//		if (A.empty() || A.size() != V.size() || m <= 0) {
//			return 0;
//		}
//
//		int n = A.size();
//		vector<int> dp(m + 1, 0);
//
//		for (int i = 0; i < A.size(); i++) {
//			for (int j = m; j >= A[i]; j--) { //j��A[i]��m�����ظ�ѡͬһ����
//				dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
//			}
//		}
//
//		return dp[m];
//	}
//};

////��������
//class Solution {
//public:
//	int backPackII(int m, vector<int> &A, vector<int> &V) {
//		if (A.empty() || A.size() != V.size() || m <= 0) {
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
//					dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j - A[i - 1]] + V[i - 1]);
//				}
//			}
//		}
//
//		return dp[n & 1][m];
//	}
//};

////dfs
//class Solution {
//public:
//	int backPackII(int m, vector<int> &A, vector<int> &V) {
//		if (A.empty() || V.empty() || A.size() != V.size() || m <= 0) {
//			return 0;
//		}
//
//		int result = 0;
//		dfs(A, V, m, 0, 0, 0, result);
//
//		return result;
//	}
//
//	void dfs(vector<int> &A, vector<int> &V, int m, int start, int size, int value, int &result) {
//		if (size > m) { //�������Ҫ���startҲ��start>A.size()
//			return;
//		}
//		else {
//			result = max(result, value);
//		}
//
//		for (int i = start; i < A.size(); i++) {
//			dfs(A, V, m, i + 1, size + A[i], value + V[i], result);
//		}
//	}
//};