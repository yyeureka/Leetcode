#include "head.h"

/*
Given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee. (You need to pay fee only on selling.)
You can complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You can not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)
Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying  at prices[0] = 1
Selling at prices[3] = 8
Buying  at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:
Input: prices = [1, 4, 6, 2, 8, 3, 10, 14], fee = 3
Output: 13
Notice
0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

解题思路：类似#309
sell[i]表示前i天交易的最大利润。
buy[i]表示前i天交易的最小cost。
*/

class Solution {
public:
	int maxProfit(vector<int> &prices, int fee) {
		if (prices.size() <= 1) {
			return 0;
		}

		vector<int> buy(prices.size(), prices[0]);
		vector<int> sell(prices.size(), 0);

		for (int i = 1; i < prices.size(); i++) {
			buy[i] = min(buy[i - 1], prices[i] - sell[i - 1]);
			sell[i] = max(sell[i - 1], prices[i] - buy[i - 1] - fee);
		}

		return sell[prices.size() - 1];
	}
};

//优化
//class Solution {
//public:
//	int maxProfit(vector<int> &prices, int fee) {
//		if (prices.size() <= 1) {
//			return 0;
//		}
//
//		int minBuy = prices[0];
//		vector<int> sell(prices.size(), 0);
//
//		for (int i = 1; i < prices.size(); i++) {
//			sell[i] = max(sell[i - 1], prices[i] - minBuy - fee);
//			minBuy = min(minBuy, prices[i] - sell[i - 1]);
//		}
//
//		return sell[prices.size() - 1];
//	}
//};