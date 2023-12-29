#include "head.h"

/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
engaging multiple transactions at the same time. You must sell before buying again.
Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

解题思路：dp，#188的特殊情况
For k transactions, on i-th day,
dp[k][i] = dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j - 1], j = 0,...,i

if we don't trade then the profit is same as previous day dp[k, i-1];
if we bought the share on j-th day where j=[0..i-1], then sell the share on i-th day, the profit is prices[i] - prices[j] + dp[k-1, j-1] .
When j is i, the one more extra item prices[i] - prices[j] + dp[k-1, j-1] = dp[k-1, i-1] looks like we just lose one chance of transaction.
*/

//straightforward
//class Solution {
//public:
//	int maxProfit(vector<int> &prices) {
//		if (prices.size() <= 1) {
//			return 0;
//		}
//
//		//dp[k][i] = dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j - 1], j = 0,...,i
//		vector<vector<int>> dp(3, vector<int>(prices.size()));
//
//		for (int k = 1; k <= 2; k++) {
//			int minBuy = prices[0];
//
//			for (int i = 1; i < prices.size(); i++) {
//				minBuy = min(minBuy, prices[i] - dp[k - 1][i - 1]);
//				dp[k][i] = max(dp[k][i - 1], prices[i] - minBuy);
//			}
//		}
//
//		return dp[2][prices.size() - 1];
//	}
//};

//优化1
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) {
			return 0;
		}

		vector<int> buy(3, INT_MAX);
		vector<int> sell(3, 0);

		for (int i = 0; i < prices.size(); i++) {
			for (int k = 1; k <= 2; k++) {
				buy[k] = min(buy[k], prices[i] - sell[k - 1]);
				sell[k] = max(sell[k], prices[i] - buy[k]);
			}
		}

		return sell[2];
	}
};

//优化2
//class Solution {
//public:
//	int maxProfit(vector<int> &prices) {
//		if (prices.size() <= 1) {
//			return 0;
//		}
//
//		int buy1 = INT_MAX;
//		int buy2 = INT_MAX;
//		int sell1 = 0;
//		int sell2 = 0;
//
//		for (int i = 0; i < prices.size(); i++) {
//			buy1 = min(buy1, prices[i]);
//			sell1 = max(sell1, prices[i] - buy1);
//			buy2 = min(buy2, prices[i] - sell1);
//			sell2 = max(sell2, prices[i] - buy2);
//		}
//
//		return sell2;
//	}
//};