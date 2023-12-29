#include <vector>
#include <algorithm>
using namespace std;

/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:
Input: coins = [2], amount = 3
Output: -1

解题思路：dp，时间复杂度amount*n，n为硬币数
*/

class Solution {
public:
	int coinChange(vector<int> &coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX); //易错，求min
		dp[0] = 0;

		for (int i = 1; i <= amount; i++) {
			for (int j : coins) {
				if (i - j < 0 || INT_MAX == dp[i - j]) { //易错，前一个stop有效
					continue;
				}

				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}

		return INT_MAX == dp[amount] ? -1 : dp[amount]; //易错
	}
};