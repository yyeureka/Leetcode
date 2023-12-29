#include "head.h"

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1
Example 2:
Input:
11000
11000
00100
00011
Output: 3

解题思路：
1、BFS，遍历到某个1时，res++，并把他周围的1变为0，不用考虑循环visit问题，没有重复计算问题
2、DFS，也可以，但深度过大的时候有stack overflow风险
3、union find
*/

////BFS
//class Solution {
//public:
//	void bfs(vector<vector<bool>>& grid, int i, int j) {
//		grid[i][j] = 0;
//		queue<pair<int, int>> q;
//		q.push({ i, j });
//
//		vector<pair<int, int>> delta = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
//
//		while (!q.empty()) {
//			i = q.front().first;
//			j = q.front().second;
//			q.pop();
//
//			for (auto k : delta) {
//				int x = i + k.first;
//				int y = j + k.second;
//				if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y]) continue;
//
//				grid[x][y] = 0;
//				q.push({ x, y });
//			}
//		}
//	}
//
//	int numIslands(vector<vector<bool>>& grid) {
//		if (grid.empty()) return 0;
//
//		int count = 0;
//		for (int i = 0; i < grid.size(); i++) {
//			for (int j = 0; j < grid[0].size(); j++) {
//				if (!grid[i][j]) continue;
//
//				count++;
//				bfs(grid, i, j);
//			}
//		}
//		return count;
//	}
//};

////DFS
//class Solution {
//public:
//	void dfs(vector<vector<char>>& grid, int i, int j) {
//		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || '0' == grid[i][j]) return;
//
//		grid[i][j] = '0';
//		dfs(grid, i - 1, j);
//		dfs(grid, i + 1, j);
//		dfs(grid, i, j - 1);
//		dfs(grid, i, j + 1);
//	}
//
//	int numIslands(vector<vector<char>>& grid) {
//		if (grid.empty()) return 0;
//
//		int res = 0;
//		for (int i = 0; i < grid.size(); i++) {
//			for (int j = 0; j < grid[0].size(); j++) {
//				if ('1' == grid[i][j]) {
//					res++;
//					dfs(grid, i, j);
//				}
//			}
//		}
//		return res;
//	}
//};

class Solution {
private:
	class UF {
	private:
		vector<int> v;
		vector<int> sz;

		int getRoot(int i) {
			while (i != v[i]) {
				v[i] = v[v[i]];
				i = v[i];
			}
			return i;
		}

	public:
		int count = 0;

		UF(vector<vector<char>>& grid, int row, int col) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if ('1' == grid[i][j]) count++;
					v.push_back(i * col + j);
					sz.push_back(1);
				}
			}
		}

		void quickUnion(int p, int q) {
			int i = getRoot(p);
			int j = getRoot(q);
			if (i == j) return;

			if (sz[i] < sz[j]) {
				v[i] = j;
				sz[j] += sz[i];
			}
			else {
				v[j] = i;
				sz[i] += sz[j];
			}
			count--;
		}
	};

public:
	int numIslands(vector<vector<char>>& grid) {
		int row = grid.size();
		if (!row) return 0;
		int col = grid[0].size();

		UF uf(grid, row, col);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if ('0' == grid[i][j]) continue;

				if (i > 0 && '1' == grid[i - 1][j]) uf.quickUnion(i * col + j, (i - 1) * col + j);
				if (i < row - 1 && '1' == grid[i + 1][j]) uf.quickUnion(i * col + j, (i + 1) * col + j);
				if (j > 0 && '1' == grid[i][j - 1]) uf.quickUnion(i * col + j, i * col + j - 1);
				if (j < col - 1 && '1' == grid[i][j + 1]) uf.quickUnion(i * col + j, i * col + j + 1);
			}
		}
		return uf.count;
	}
};

//void main() {
//	Solution s;
//	vector<vector<char>> grid = { {'1', '1', '1', '1', '0' },{ '1', '1', '0', '1' , '0' },{ '1' , '1', '0', '0', '0' },{ '0', '0' , '0','0', '0' }};
//	int cnt = s.numIslands(grid);
//	cout << cnt << endl;
//}