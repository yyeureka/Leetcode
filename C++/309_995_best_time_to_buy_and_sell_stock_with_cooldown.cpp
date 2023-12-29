#include "head.h"

/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example1
Input: [1, 2, 3, 0, 2]
Output: 3
Explanation:
transactions = [buy, sell, cooldown, buy, sell]
Example2
Input: [3,2,6,5,0,3]
Output: 7

解题思路：dp
sell[i]表示前i天交易的最大利润。
buy[i]表示前i天交易的最小cost。
*/

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) {
			return 0;
		}

		vector<int> buy(prices.size(), prices[0]);
		vector<int> sell(prices.size(), 0);

		for (int i = 1; i < prices.size(); i++) {
			buy[i] = min(buy[i - 1], prices[i] - (i >= 2 ? sell[i - 2] : 0)); //这次不买/买的min
			sell[i] = max(sell[i - 1], prices[i] - buy[i - 1]); //这次不卖/卖的max
		}

		return sell[prices.size() - 1];
	}
};

//优化
//class Solution {
//public:
//	int maxProfit(vector<int> &prices) {
//		if (prices.size() <= 1) {
//			return 0;
//		}
//
//		int minBuy = prices[0];
//		vector<int> sell(prices.size(), 0);
//
//		for (int i = 1; i < prices.size(); i++) {
//			sell[i] = max(sell[i - 1], prices[i] - minBuy);
//			minBuy = min(minBuy, prices[i] - (i >= 2 ? sell[i - 2] : 0));
//		}
//
//		return sell[prices.size() - 1];
//	}
//};

//class Solution {
//public:
//	int maxProfit(vector<int> &prices) {
//		if (prices.size() <= 1) {
//			return 0;
//		}
//
//		vector<int> dp(prices.size(), 0);
//
//		for (int i = 1; i < prices.size(); i++) {
//			dp[i] = dp[i - 1];
//
//			for (int j = 0; j < i; j++) {
//				if (prices[j] >= prices[i]) {
//					continue;
//				}
//
//				int cur = prices[i] - prices[j];
//				if (j >= 2) {
//					cur += dp[j - 2];
//				}
//
//				dp[i] = max(dp[i], cur);
//			}
//		}
//
//		return dp[prices.size() - 1];
//	}
//};