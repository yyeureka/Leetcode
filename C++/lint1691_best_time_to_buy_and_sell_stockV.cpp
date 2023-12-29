#include "head.h"

/*
Given a stock n-day price, you can only trade at most once a day, you can choose to buy a stock or sell a stock or give up the trade today, output the maximum profit can reach.

Example 1:
Given `a = [1,2,10,9]`, return `16`
Input:
[1,2,10,9]
Output:
16
Explanation:
you can buy in day 1,2 and sell in 3,4.
profit:-1-2+10+9 = 16
Example 2:
Given `a = [9,5,9,10,5]`, return `5`
Input:
[9,5,9,10,5]
Output:
5

Explanation:
you can buy in day 2 and sell in 4.
profit:-5 + 10 = 5

Notice
1 \leq n \leq 100001≤n≤10000

解题思路：
DFS会TLE！
*/

//dfs
//class Solution {
//public:
//	int getAns(vector<int> &a) {
//		if (a.empty()) {
//			return 0;
//		}
//
//		int maxProfit = INT_MIN;
//
//		helper(a, 0, 0, 0, maxProfit);
//
//		return maxProfit;
//	}
//
//	void helper(vector<int> &a, int index, int buyCount, int profit, int &maxProfit) {
//		if (index >= a.size()) {
//			if (0 == buyCount) {
//				maxProfit = max(maxProfit, profit);
//			}
//			return;
//		}
//
//		if (buyCount < a.size() / 2) {
//			helper(a, index + 1, buyCount + 1, profit - a[index], maxProfit);
//		}
//		if (buyCount > 0) {
//			helper(a, index + 1, buyCount - 1, profit + a[index], maxProfit);
//		}
//		helper(a, index + 1, buyCount, profit, maxProfit);
//	}
//};