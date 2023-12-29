#include <vector>
#include <algorithm>
using namespace std;

/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.
The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
Notes:
All costs are positive integers.

Example 1:
Input: [[14,2,11],[11,14,5],[14,3,10]]
Output: 10
Explanation: blue green blue, 2 + 5 + 3 = 10
Example 2:
Input: [[1,2,3],[1,4,6]]
Output: 3

解题思路：坐标型dp
res[2][3]保存当前和前一个房子分别涂红、蓝、绿的最小cost
res[i][j]当前房子涂j色的最小cost等于前一个房子涂非j色的的min+cost[i][j]
*/

class Solution {
public:
	int minCost(vector<vector<int>> &costs) {
		if (costs.empty()) {
			return 0;
		}

		int n = costs.size();
		vector<vector<int>> dp(n, vector<int>(3, 0));
		dp[0][0] = costs[0][0];
		dp[0][1] = costs[0][1];
		dp[0][2] = costs[0][2];

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = INT_MAX;

				for (int k = 0; k < 3; k++) {
					if (j == k) {
						continue;
					}

					dp[i][j] = min(dp[i][j], dp[i - 1][k]);
				}

				dp[i][j] += costs[i][j];
			}
		}

		return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	}
};

//滚动数组
//class Solution {
//public:
//	int minCost(vector<vector<int>> &costs) {
//		if (costs.empty()) {
//			return 0;
//		}
//
//		int n = costs.size();
//		vector<vector<int>> dp(2, vector<int>(3, 0));
//		dp[0][0] = costs[0][0];
//		dp[0][1] = costs[0][1];
//		dp[0][2] = costs[0][2];
//
//		for (int i = 1; i < n; i++) {
//			for (int j = 0; j < 3; j++) {
//				dp[i % 2][j] = INT_MAX;
//
//				for (int k = 0; k < 3; k++) {
//					if (j == k) {
//						continue;
//					}
//
//					dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][k]);
//				}
//
//				dp[i % 2][j] += costs[i][j];
//			}
//		}
//
//		return min(dp[(n - 1) % 2][0], min(dp[(n - 1) % 2][1], dp[(n - 1) % 2][2]));
//	}
//};