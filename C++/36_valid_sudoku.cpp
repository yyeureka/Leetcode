#include <vector>
#include <map>
using namespace std;

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.

Example 1:
Input:
[
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:
Input:
[
["8","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

解题思路：
rol定义1个vector，每遍历完一行clear一次
col定义9个vector
box定义3个vector，每遍历完三行clear一次
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<char> row;
		vector<vector<char>> col(9);
		vector<vector<char>> box(3);

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char digit = board[i][j];
				if ('.' == digit)
				{
					continue;
				}

				if (!row.empty())
				{
					if (find(row.begin(), row.end(), digit) != row.end())
					{
						return false;
					}
				}
				row.push_back(digit);

				if (!col[j].empty())
				{
					if (find(col[j].begin(), col[j].end(), digit) != col[j].end())
					{
						return false;
					}
				}
				col[j].push_back(digit);

				if (!box[j / 3].empty())
				{
					if (find(box[j / 3].begin(), box[j / 3].end(), digit) != box[j / 3].end())
					{
						return false;
					}
				}
				box[j / 3].push_back(digit);
			}

			row.clear();
			if (2 == i % 3)
			{
				box.clear();
				box.resize(3);
			}
		}
		return true;
	}
};