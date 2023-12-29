#include <vector>
using namespace std;

/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix =
[
[1,2,3],
[4,5,6],
[7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
[7,4,1],
[8,5,2],
[9,6,3]
]
Example 2:
Given input matrix =
[
[ 5, 1, 9,11],
[ 2, 4, 8,10],
[13, 3, 6, 7],
[15,14,12,16]
],
rotate the input matrix in-place such that it becomes:
[
[15,13, 2, 5],
[14, 3, 4, 1],
[12, 6, 8, 9],
[16, 7,10,11]
]

解题思路：
1、直接根据规律进行坐标转换，代码复杂，容易出错
2、先转置，再按row翻转，简单明了！!
1 2 3      1 4 7      7 4 1
4 5 6  ->  2 5 8  ->  8 5 2
7 8 9      3 6 9      9 6 3
*/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < n; i++) {
			reverse(matrix[i].begin(), matrix[i].end());
		}

		//int n = matrix.size();
		//int i = 0;
		//while (i < n / 2)
		//{
		//	for (int j = i; j < n - i - 1; j++)
		//	{
		//		int tmp = matrix[i][j];
		//		matrix[i][j] = matrix[n - 1 - j][i];
		//		matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
		//		matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
		//		matrix[j][n - 1 - i] = tmp;
		//	}
		//	i++;
		//}
	}
};