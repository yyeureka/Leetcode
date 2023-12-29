#include <vector>
using namespace std;

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

解题思路：就是straitforward一圈一圈打印
*/

void print(vector<vector<int>>& matrix, vector<int>& res, int row_begin, int row_end, int col_begin, int col_end)
{
	if ((row_begin > row_end) || (col_begin > col_end)) return;
	for (int i = col_begin; i <= col_end; i++)
	{
		res.push_back(matrix[row_begin][i]);
	}
	row_begin++;

	for (int i = row_begin; i <= row_end; i++)
	{
		res.push_back(matrix[i][col_end]);
	}
	col_end--;

	if (row_begin <= row_end)
	{
		for (int i = col_end; i >= col_begin; i--)
		{
			res.push_back(matrix[row_end][i]);
		}
		row_end--;
	}

	if (col_begin <= col_end)
	{
		for (int i = row_end; i >= row_begin; i--)
		{
			res.push_back(matrix[i][col_begin]);
		}
		col_begin++;
	}
	print(matrix, res, row_begin, row_end, col_begin, col_end);
}

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int n = matrix.size();
		if (!n) return res;
		int m = matrix[0].size();
		print(matrix, res, 0, n - 1, 0, m - 1);
		return res;
	}
};