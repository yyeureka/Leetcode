#include <vector>
#include <algorithm>
using namespace std;

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

解题思路：
1、数学方法，我不会
2、dp，i从1~n，对每一个i，j从1开始，j*j<=i，num[i] = min(num[i], num[i-j*j]+1)，
3、dp，先把<=n的square都列出来，类似#322 coin change的方法，时间/空间复杂度比dp1差
*/

class Solution {
public:
	int numSquares(int n) {
		vector<int> num(n + 1, INT_MAX);
		num[0] = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j * j <= i; j++) {
				num[i] = min(num[i], num[i - j * j] + 1);
			}
		}
		return num[n];
	}
};

//class Solution {
//public:
//	int numSquares(int n) {
//		vector<int> num(n + 1, INT_MAX);
//		num[0] = 0;
//		vector<int> chart;
//		for (int i = 1; ; i++) {
//			if (i * i > n) break;
//			chart.push_back(i * i);
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j < chart.size(); j++) {
//				if (i < chart[j]) break;
//				num[i] = min(num[i], num[i - chart[j]] + 1);
//			}
//		}
//		return num[n];
//	}
//};