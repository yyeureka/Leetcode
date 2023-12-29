#include "head.h"

/*
You have a total of n thousand yuan, hoping to apply for a university abroad. The application is required to pay a certain fee. Give the cost of each university application and the probability of getting the University's offer, and the number of university is m. If the economy allows, you can apply for multiple universities. Find the highest probability of receiving at least one offer.

Example 1:
Input:
n = 10
prices = [4,4,5]
probability = [0.1,0.2,0.3]
Output:  0.440
Explanation：
select the second and the third school.
Example 2:
Input:
n = 10
prices = [4,5,6]
probability = [0.1,0.2,0.3]
Output:  0.370
Explanation:
select the first and the third school.

Notice
0<=n<=10000,0<=m<=10000

解题思路：0-1背包，lint125变种
至少有一所学校录取的概率为1-学校都不录取的概率
问题转化为求学校都不录取的概率的min：
dp[i][j]为前i所学校花费j时的都不录取的最小概率
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - A[i]] * (1 - P[i]))
即为不选当前学校、选当前学校之间的最小值

以[4,4,5]、[0.1,0.2,0.3]，总金额为10为例：
   0 1 2 3  4   5   6   7   8    9    10
0  1 1 1 1  1   1   1   1   1    1     1
1: 1 1 1 1 0.9 0.9 0.9 0.9 0.9  0.9  0.9
2: 1 1 1 1 0.8 0.8 0.8 0.8 0.72 0.72 0.72
3: 1 1 1 1 0.8 0.7 0.7 0.7 0.7  0.56 0.56

不空间优化的普通dp会MLE！！！
challenge：空间优化
1、滚动数组，二维dp就可以解决
2、数组降维，没懂为什么？？

challenge：打印结果
*/

//滚动数组
class Solution {
public:
	double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
		if (prices.empty() || probability.size() != prices.size() || n <= 0) {
			return 0.0;
		}

		vector<vector<double>> dp(2, vector<double>(n + 1, 1.0));
		for (int i = 1; i <= prices.size(); i++) {
			for (int j = 1; j <= n; j++) {
				dp[i & 1][j] = dp[(i - 1) & 1][j];

				if (j - prices[i - 1] >= 0) {
					dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j - prices[i - 1]] * (1 - probability[i - 1]));
				}
			}
		}

		return 1 - dp[prices.size() & 1][n];
	}
};

//降维
//class Solution {
//public:
//	double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
//		if (prices.empty() || probability.size() != prices.size() || n <= 0) {
//			return 0.0;
//		}
//
//		vector<double> dp(n + 1, 1.0);
//
//		for (int i = 0; i < prices.size(); i++) {
//			for (int j = n; j >= prices[i]; j--) {
//				dp[j] = min(dp[j], dp[j - prices[i]] * (1 - probability[i]));
//			}
//		}
//
//		return 1 - dp[n];
//	}
//};

//class Solution {
//public:
//	double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
//		if (prices.empty() || probability.size() != prices.size() || n <= 0) {
//			return 0.0;
//		}
//
//		vector<vector<double>> dp(prices.size() + 1, vector<double>(n + 1, 1.0));
//
//		for (int i = 1; i <= prices.size(); i++) {
//			for (int j = 1; j <= n; j++) {
//				dp[i][j] = dp[i - 1][j];
//
//				if (j - prices[i - 1] >= 0) {
//					dp[i][j] = min(dp[i][j], dp[i - 1][j - prices[i - 1]] * (1 - probability[i - 1]));
//				}
//			}
//		}
//
//		return 1 - dp[prices.size()][n];
//	}
//};