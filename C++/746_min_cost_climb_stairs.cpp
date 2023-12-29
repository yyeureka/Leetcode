#include <vector>
#include <algorithm>
using namespace std;

/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

解题思路：动态规划，vector里放从当前stair过的cost
*/

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		if (0 == n) return 0;
		if (1 == n) return cost[0];
		for (int i = 2; i < n; i++) {
			cost[i] += min(cost[i - 1], cost[i - 2]);
		}
		return min(cost[n - 1], cost[n - 2]);
	}
};

//class Solution {
//public:
//	int minCostClimbingStairs(vector<int>& cost) {
//		int n = cost.size();
//		if (0 == n) return 0;
//		if (1 == n) return cost[0];
//		int s0 = cost[0];
//		int s1 = cost[1];
//		for (int i = 2; i < n; i++) {
//			int tmp = cost[i] + min(s0, s1);
//			s0 = s1;
//			s1 = tmp;
//		}
//		return min(s0, s1);
//	}
//};