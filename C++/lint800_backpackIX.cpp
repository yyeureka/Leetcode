#include "head.h"

/*
You have a total of n thousand yuan, hoping to apply for a university abroad. The application is required to pay a certain fee. Give the cost of each university application and the probability of getting the University's offer, and the number of university is m. If the economy allows, you can apply for multiple universities. Find the highest probability of receiving at least one offer.

Example 1:
Input:
n = 10
prices = [4,4,5]
probability = [0.1,0.2,0.3]
Output:  0.440
Explanation��
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

����˼·��0-1������lint125����
������һ��ѧУ¼ȡ�ĸ���Ϊ1-ѧУ����¼ȡ�ĸ���
����ת��Ϊ��ѧУ����¼ȡ�ĸ��ʵ�min��
dp[i][j]Ϊǰi��ѧУ����jʱ�Ķ���¼ȡ����С����
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - A[i]] * (1 - P[i]))
��Ϊ��ѡ��ǰѧУ��ѡ��ǰѧУ֮�����Сֵ

��[4,4,5]��[0.1,0.2,0.3]���ܽ��Ϊ10Ϊ����
   0 1 2 3  4   5   6   7   8    9    10
0  1 1 1 1  1   1   1   1   1    1     1
1: 1 1 1 1 0.9 0.9 0.9 0.9 0.9  0.9  0.9
2: 1 1 1 1 0.8 0.8 0.8 0.8 0.72 0.72 0.72
3: 1 1 1 1 0.8 0.7 0.7 0.7 0.7  0.56 0.56

���ռ��Ż�����ͨdp��MLE������
challenge���ռ��Ż�
1���������飬��άdp�Ϳ��Խ��
2�����齵ά��û��Ϊʲô����

challenge����ӡ���
*/

//��������
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

//��ά
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