#include "head.h"

/*
You are playing a card game with your friends, there are n cards in total. Each card costs cost[i] and inflicts damage[i] damage to the opponent. You have a total of totalMoney dollars and need to inflict at least totalDamage damage to win. And Each card can only be used once. Determine if you can win the game.

Example1
Input:
cost = [1,2,3,4,5]
damage = [1,2,3,4,5]
totalMoney = 10
totalDamage = 10
Output: true
Explanation: We can use the [1,4,5] to cause 10 damage, which costs 10.
Example2
Input:
cost = [1,2]
damage = [3,4]
totalMoney = 10
totalDamage = 10
Output: false
Explanation: We can only cause 7 damage at most.

解题思路：本质跟lint125一模一样
*/

class Solution {
public:
	bool cardGame(vector<int> &cost, vector<int> &damage, int totalMoney, int totalDamage) {
		if (totalDamage <= 0) {
			return true;
		}
		if (cost.empty() || damage.size() != cost.size() || totalMoney <= 0) {
			return 0 == totalDamage;
		}

		vector<int> dp(totalMoney + 1, 0);

		for (int i = 0; i < cost.size(); i++) {
			for (int j = totalMoney; j >= cost[i]; j--) {
				dp[j] = max(dp[j], dp[j - cost[i]] + damage[i]);

				if (dp[j] >= totalDamage) {
					return true;
				}
			}
		}

		return false;
	}
};