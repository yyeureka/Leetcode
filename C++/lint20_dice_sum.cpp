#include <vector>
#include <iostream>
using namespace std;

/*
扔 n 个骰子，向上面的数字之和为 S。给定 Given n，请列出所有可能的 S 值及其相应的概率。
你不需要关心结果的准确性，我们会帮你输出结果。
给定 n = 1，返回 [ [1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]]。

解题思路：
1．	可能的和为n~6 * n，和的总数为6^n，和的分布是对称的，算一半就行
2．	sum[n + 1][6 * n + 1]，sum[i][j]为i个色子和为j的概率= i-1个色子色出1~6概率的和再除以6 
    = (sum[i-1][j-1] + sum[i-1][j-2] + sum[i-1][j-3] + sum[i-1][j-4] + sum[i-1][j-5] + sum[i-1][j-6])/6.0 (j – k > 0)
    不能将维度缩减为2！！
3．	初始条件sum[1][1] = sum[1][2] = sum[1][3] = sum[1][4] = sum[1][5] = sum[1][6] = 1.0/6
4．	结果为sum[n][n]~ sum[n][6 * n]
*/

class Solution {
public:
	vector<pair<int, double>> dicesSum(int n) {
		vector<pair<int, double>> res;
		vector<vector<double>> dice(n + 1, vector<double>(6 * n + 1, 0.0)); //n dices，sum from n~6n
		for (int i = 1; i <= 6; i++) dice[1][i] = 1 / 6.0;
		for (int i = 2; i <= n; i++) { //dice
			for (int j = i; j <= 6 * i; j++) { //sum
				if (j <= (7 * i) / 2) {
					if (j > 1) dice[i][j] += dice[i - 1][j - 1];
					if (j > 2) dice[i][j] += dice[i - 1][j - 2];
					if (j > 3) dice[i][j] += dice[i - 1][j - 3];
					if (j > 4) dice[i][j] += dice[i - 1][j - 4];
					if (j > 5) dice[i][j] += dice[i - 1][j - 5];
					if (j > 6) dice[i][j] += dice[i - 1][j - 6];
					dice[i][j] /= 6.0;
				}
				else dice[i][j] = dice[i][7 * i - j]; //sum对称分布
			}
		}
		for (int i = n; i <= 6 * n; i++) { //这个放上一个for循环里面n=1时会出错
			res.push_back({ i, dice[n][i] });
		}
		return res;
	}
};

//void main()
//{
//	Solution s;
//	s.dicesSum(4);
//}