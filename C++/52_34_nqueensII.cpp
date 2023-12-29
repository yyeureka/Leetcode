#include "head.h"

/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*/

class Solution {
public:
	int totalNQueens(int n) {
		int result = 0;
		vector<bool> col(n, false);
		vector<bool> diag1(2 * n - 1, false);
		vector<bool> diag2(2 * n - 1, false);

		helper(0, col, diag1, diag2, result);

		return result;
	}

	void helper(int row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int &result) {
		int size = col.size();

		if (size == row) {
			result++;
			return;
		}

		for (int i = 0; i < size; i++) {
			if (col[i] || diag1[row + i] || diag2[size - row + i - 1]) continue;

			col[i] = true;
			diag1[row + i] = true;
			diag2[size - row + i - 1] = true;

			helper(row + 1, col, diag1, diag2, result);

			col[i] = false;
			diag1[row + i] = false;
			diag2[size - row + i - 1] = false;
		}
	}
};