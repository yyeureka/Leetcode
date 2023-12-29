#include "head.h"

/*
Given two Sparse Matrix A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.

Example1
Input:
[[1,0,0],[-1,0,3]]
[[7,0,0],[0,0,0],[0,0,1]]
Output:
[[7,0,0],[-7,0,3]]
Explanation:
A = [
[ 1, 0, 0],
[-1, 0, 3]
]

B = [
[ 7, 0, 0 ],
[ 0, 0, 0 ],
[ 0, 0, 1 ]
]

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
      | 0 0 1 |

Example2
Input:
[[1,0],[0,1]]
[[0,1],[1,0]]
Output:
[[0,1],[1,0]]

解题思路：矩阵相乘
*/

class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		if (A.empty() || A[0].empty() || B.empty() || B[0].empty()) {
			return{};
		}

		int row = A.size();
		int col = B[0].size();
		vector<vector<int>> result(row, vector<int>(col, 0));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < A[0].size(); k++) {
					result[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		return result;
	}
};