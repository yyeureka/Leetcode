#include <vector>
#include <iostream>
using namespace std;

/*
这里有n个房子在一列直线上，现在我们需要给房屋染色，分别有红色蓝色和绿色。每个房屋染不同的颜色费用也不同，你需要设计一种染色方案使得相邻的房屋颜色不同，并且费用最小，返回最小的费用。
费用通过一个nx3 的矩阵给出，比如cost[0][0]表示房屋0染红色的费用，cost[1][2]表示房屋1染绿色的费用。
所有费用都是正整数
输入: [[14,2,11],[11,14,5],[14,3,10]]
输出: 10
解释: 蓝 绿 蓝, 2 + 5 + 3 = 10
输入: [[1,2,3],[1,4,6]]
输出: 3

解题思路：
1. 递归太费时间，用穷举法！！
2. p[2][3]，p[i&1][j]为i房染成j色时前i个房间的最小费用 = i-1个房间染成非j色的最小费用+i房的染色费用 cost[i][j] + min(p[(i-1)&1][k])(k != j)
3. 初始条件：p[0][j] = cost[0][j]
4. 结果为min(p[(n-1) & 1][0], p[(n-1) & 1][1], p[(n-1) & 1][2])
*/

int min(int a, int b, int c)
{
	int result = a;
	if (b < result)
	{
		result = b;
	}
	if (c < result)
	{
		result = c;
	}
	return result;
}

class Solution {
public:
	/**
	* @param costs: n x 3 cost matrix
	* @return: An integer, the minimum cost to paint all houses
	*/
	int minCost(vector<vector<int>> &costs) {
		int num = costs.size();
		if (0 == num)
		{
			return 0;
		}

		int result[2][3];
		result[0][0] = costs[0][0];
		result[0][1] = costs[0][1];
		result[0][2] = costs[0][2];
		int pre;
		for (int i = 1; i < num; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				pre = 0x7FFFFFFF;
				for (int k = 0; k < 3; k++)
				{
					if (k != j)
					{
						if (result[(i - 1) & 1][k] < pre)
						{
							pre = result[(i - 1) & 1][k];
						}
					}
				}
				result[i & 1][j] = pre + costs[i][j];
			}
		}

		return min(result[(num - 1) & 1][0], result[(num - 1) & 1][1], result[(num - 1) & 1][2]);
	}
};

//void main()
//{
//	//vector<vector<int>> costs = { {14, 2, 11 }, { 11, 14, 5 }, { 14, 3, 10} };
//	//vector<vector<int>> costs = { {1,2,3}, {1,4,6} };
//	vector<vector<int>> costs = { {19,3,24},{8,6,23 } ,{13,14,29},{19,30,30},{31,26,31},{26,33,21},{30,15,29},{12,5,26},{18,2,29},{11,8,18},{3,1,1},{33,14,28},{28,25,21},{16,26,21},{3,15,13},{6,4,23 },{ 32,16,4 },{ 5,21,10 },{ 23,4,6 },{ 21,8,23 },{ 16,10,20 },{ 16,16,17 },{ 19,28,19 },{ 18,13,20 },{18,19,23 } };
//	Solution s;
//	cout << s.minCost(costs) << endl;
//}