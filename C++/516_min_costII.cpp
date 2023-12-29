#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	* @param costs: n x k cost matrix
	* @return: an integer, the minimum cost to paint all houses
	*/
	int minCostII(vector<vector<int>> &costs) {
		int room_num = costs.size();
		if (!room_num)
		{
			return 0;
		}
		int color_num = costs[0].size();
		if (!color_num)
		{
			return 0;
		}

		vector <vector <int>> p(2, vector <int>(color_num, 0));
		int result;

		for (int i = 0; i < color_num; i++)
		{
			p[0][i] = costs[0][i];
		}

		for (int i = 1; i < room_num; i++)
		{
			for (int j = 0; j < color_num; j++)
			{
				result = 0x7FFFFFFF;
				for (int k = 0; k < color_num; k++)
				{
					if (k != j)
					{
						if (p[(i - 1) & 1][k] < result)
						{
							result = p[(i - 1) & 1][k];
						}
					}
				}
				p[i & 1][j] = costs[i][j] + result;
			}
		}

		result = p[(room_num - 1) & 1][0];
		for (int i = 1; i < color_num; i++)
		{
			if (p[(room_num - 1) & 1][i] < result)
			{
				result = p[(room_num - 1) & 1][i];
			}
		}

		return result;
	}
};

//void main()
//{
//	vector<vector<int>> costs = { {14, 2, 11 }, { 11, 14, 5 }, { 14, 3, 10} };
//	//vector<vector<int>> costs = { {1,2,3}, {1,4,6} };
//	//vector<vector<int>> costs = { {19,3,24},{8,6,23 } ,{13,14,29},{19,30,30},{31,26,31},{26,33,21},{30,15,29},{12,5,26},{18,2,29},{11,8,18},{3,1,1},{33,14,28},{28,25,21},{16,26,21},{3,15,13},{6,4,23 },{ 32,16,4 },{ 5,21,10 },{ 23,4,6 },{ 21,8,23 },{ 16,10,20 },{ 16,16,17 },{ 19,28,19 },{ 18,13,20 },{18,19,23 } };
//	Solution s;
//	cout << s.minCostII(costs) << endl;
//}