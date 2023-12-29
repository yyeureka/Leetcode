#include "head.h"

/*
Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.

Example1
Input:
matrix = [
[1,3,-1],
[2,3,-2],
[-1,-2,-3]
]
Output: 9
Explanation:
the submatrix with the largest possible sum is:
[
[1,3],
[2,3]
]
Example2
Input:
matrix = [
[1,1,1],
[1,1,1],
[1,1,1]
]
Output: 9
Explanation:
the submatrix with the largest possible sum is:
[
[1,1,1],
[1,1,1],
[1,1,1]
]

解题思路:
二维的prefix sum，以列将二维压缩成一维，再求一维的max区间和
*/

class Solution {
public:
	int maxSubmatrix(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}

		int maxMatrixSum = INT_MIN;
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> prefixColSum(n + 1, vector<int>(m, 0)); //每列得到prefix sum

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				prefixColSum[i + 1][j] = prefixColSum[i][j] + matrix[i][j];
			}
		}

		for (int top = 0; top < n; top++) {
			for (int down = top + 1; down <= n; down++) {
				vector<int> colSum(m, 0);
				int sum = 0;
				int minSum = 0;
				int maxSum = INT_MIN;

				for (int i = 0; i < m; i++) {
					colSum[i] = prefixColSum[down][i] - prefixColSum[top][i]; //每列的区间和

					sum += colSum[i];
					maxSum = max(maxSum, sum - minSum); 
					minSum = min(minSum, sum);
				}

				maxMatrixSum = max(maxMatrixSum, maxSum);
			}
		}

		return maxMatrixSum;
	}
};