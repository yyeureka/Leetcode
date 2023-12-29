#include <vector>
#include <string>
using namespace std;

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
Input: 4
Output: [
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

解题思路：
    | | |                / / /             \ \ \
    O O O               O O O               O O O
    | | |              / / / /             \ \ \ \
    O O O               O O O               O O O
    | | |              / / / /             \ \ \ \
    O O O               O O O               O O O
    | | |              / / /                 \ \ \
竖直方向col[n]进行判断
45度角方向diag1[2*n-1]进行判断，下标为row+col
135度角方向diag2[2*n-1]进行判断，下标为n-1+col-row
*/

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> cur(n, string(n, '.')); //这里开空间比递归里开好
		vector<bool> col(n, false);
		vector<bool> diag1(2 * n - 1, false);
		vector<bool> diag2(2 * n - 1, false);

		helper(0, col, diag1, diag2, cur, result);

		return result;
	}

	void helper(int row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, vector<string> &cur, vector<vector<string>> &result) {
		int size = cur.size();

		if (size == row) {
			result.push_back(cur);
			return;
		}

		for (int i = 0; i < size; i++) {
			if (col[i] || diag1[row + i] || diag2[size - row + i - 1]) continue;

			col[i] = true;
			diag1[row + i] = true;
			diag2[size - row + i - 1] = true;
			cur[row][i] = 'Q';

			helper(row + 1, col, diag1, diag2, cur, result);

			col[i] = false;
			diag1[row + i] = false;
			diag2[size - row + i - 1] = false;
			cur[row][i] = '.';
		}
	}
};