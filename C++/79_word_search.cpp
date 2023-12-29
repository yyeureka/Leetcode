#include <vector>
#include <string>
using namespace std;

/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:
board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

解题思路：dfs递归，要注意已经用过的字符要标记
*/

bool search(vector<vector<char>>& board, int row, int col, string word)  // board是要修改的，&不能省
{
	if (word.empty()) return true;
	if ((row < 0) || (row >= board.size()) || (col < 0) || (col >= board[0].size())) return false;
	if (word[0] != board[row][col]) return false;
	word = word.substr(1);
	board[row][col] ^= -1;  // 用过的字符标记
	bool get = search(board, row + 1, col, word)
		|| search(board, row - 1, col, word)
		|| search(board, row, col + 1, word)
		|| search(board, row, col - 1, word);
	board[row][col] ^= -1;  // reset用过的字符
	return get;
}

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (search(board, i, j, word)) return true;
			}
		}
		return false;
	}
};