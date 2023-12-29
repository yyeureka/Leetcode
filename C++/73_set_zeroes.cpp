#include <vector>
using namespace std;

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Example 1:
Input:
[
[1,1,1],
[1,0,1],
[1,1,1]
]
Output:
[
[1,0,1],
[0,0,0],
[1,0,1]
]
Example 2:
Input:
[
[0,1,2,0],
[3,4,5,2],
[1,3,1,5]
]
Output:
[
[0,0,0,0],
[0,4,5,0],
[0,3,1,0]
]

解题思路：思路不难，细节特别容易错
set_row判断是否set当前行，如果是第一行，暂不处理
第一行判断是否set当前列
set_row_0判断是否set第一行
*/

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (!n) return;
		int m = matrix[0].size();

		bool set_row_0 = false;
		for (int i = 0; i < n; i++) {
			bool set_row = false;
			for (int j = 0; j < m; j++) {
				if (0 == matrix[i][j]) {
					if (0 == i) {
						set_row_0 = true;
						break;
					}

					if (!set_row) {
						set_row = true;
						for (int k = 0; k < j; k++) matrix[i][k] = 0;
					}
					if (0 != matrix[0][j]) {
						for (int k = 0; k < i; k++) matrix[k][j] = 0;
					}
				}
				else if (set_row || 0 == matrix[0][j]) matrix[i][j] = 0;
			}
		}
		if (set_row_0) matrix[0] = vector<int>(m, 0);
	}
};