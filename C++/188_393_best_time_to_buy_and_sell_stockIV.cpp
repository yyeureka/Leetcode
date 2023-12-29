#include "head.h"

/*
Say you have an array for which the i-th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:
Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:
Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

解题思路：dp
For k transactions, on i-th day,
dp[k][i] = dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j - 1], j = 0,...,i

if we don't trade then the profit is same as previous day dp[k, i-1];
if we bought the share on j-th day where j=[0..i-1], then sell the share on i-th day, the profit is prices[i] - prices[j] + dp[k-1, j-1] .
When j is i, the one more extra item prices[i] - prices[j] + dp[k-1, j-1] = dp[k-1, i-1] looks like we just lose one chance of transaction.
*/

//straightforward
//class Solution {
//public:
//	int maxProfit(int K, vector<int> &prices) {
//		if (prices.size() <= 1 || K < 1) {
//			return 0;
//		}
//
//		if (K > prices.size() / 2) { //易错，不加这个会MLE
//			int maxP = 0;
//
//			for (int i = 1; i < prices.size(); i++) {
//				if (prices[i] > prices[i - 1]) {
//					maxP += prices[i] - prices[i - 1];
//				}
//			}
//
//			return maxP;
//		}
//
//		//dp[k][i] = max(dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j - 1]);
//		vector<vector<int>> sell(K + 1, vector<int>(prices.size()));
//
//		for (int k = 1; k <= K; k++) {
//			int minBuy = prices[0];
//
//			for (int i = 1; i < prices.size(); i++) {
//				minBuy = min(minBuy, prices[i] - sell[k - 1][i - 1]);
//				sell[k][i] = max(sell[k][i - 1], prices[i] - minBuy);
//			}
//		}
//
//		return sell[K][prices.size() - 1];
//	}
//};

//优化
class Solution {
public:
	int maxProfit(int K, vector<int> &prices) {
		if (prices.size() <= 1 || K < 1) {
			return 0;
		}

		if (K > prices.size() / 2) { //易错，不加这个会MLE
			int maxP = 0;

			for (int i = 1; i < prices.size(); i++) {
				if (prices[i] > prices[i - 1]) {
					maxP += prices[i] - prices[i - 1];
				}
			}

			return maxP;
		}

		vector<int> buy(K + 1, INT_MAX);
		vector<int> sell(K + 1, 0);

		for (int i = 0; i < prices.size(); i++) {
			for (int k = 1; k <= K; k++) {
				buy[k] = min(buy[k], prices[i] - sell[k - 1]);
				sell[k] = max(sell[k], prices[i] - buy[k]);
			}
		}

		return sell[K];
	}
};