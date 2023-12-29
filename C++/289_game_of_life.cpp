#include <vector>
#include <algorithm>
using namespace std;

/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

Example:
Input:
[
[0,1,0],
[0,0,1],
[1,1,1],
[0,0,0]
]
Output:
[
[0,0,0],
[1,0,1],
[0,1,1],
[0,1,0]
]

解题思路：
想复杂了，所有cell是同时flip的，不考虑变了某个cell对neighbor的影响
但处理的时候还是依次遍历、更新每个cell，每个cell的值需要保存当前和next两个状态的结果
LIVE可能保持LIVE或GODIE
DIE可能保持DIE或ALIVE
*/

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty()) return;

#define DIE   0
#define LIVE  1
#define ALIVE 2
#define GODIE 3

		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int live = 0;
				for (int row = max(0, i - 1); row <= min(m - 1, i + 1); row++) {
					for (int col = max(0, j - 1); col <= min(n - 1, j + 1); col++) {
						if (row == i && col == j) continue;
						if (LIVE == board[row][col] || GODIE == board[row][col]) live++;
					}
				}

				if (LIVE == board[i][j]) {
					if (live < 2 || live > 3) board[i][j] = GODIE;
				}
				else if (3 == live) board[i][j] = ALIVE;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (ALIVE == board[i][j]) board[i][j] = 1;
				else if (GODIE == board[i][j]) board[i][j] = 0;
			}
		}
	}
};