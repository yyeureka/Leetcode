#include <vector>
#include <queue>
using namespace std;

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

解题思路：
#200的follow up版本，BFS/DFS，BFS貌似稍许快一点？
1、先检查4个border，如果有O，将O和附近的O置为*
2、将所有的O变为X，将*变为O

union-find：将边界及周围的O连接到dummy，未连接到dummy的O可以capture
*/

//bfs
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) return;

		int m = board.size();
		int n = board[0].size();
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++) {
			if ('O' == board[i][0]) q.push({ i, 0 });
			if ('O' == board[i][n - 1]) q.push({ i, n - 1 });
		}
		for (int i = 1; i < n - 1; i++) {
			if ('O' == board[0][i]) q.push({ 0, i });
			if ('O' == board[m - 1][i]) q.push({ m - 1, i });
		}

		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			if (i < 0 || i >= m || j < 0 || j >= n || 'O' != board[i][j]) continue;
			board[i][j] = '*';
			q.push({ i - 1, j });
			q.push({ i + 1, j });
			q.push({ i, j - 1 });
			q.push({ i, j + 1 });
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if ('O' == board[i][j]) board[i][j] = 'X';
				else if ('*' == board[i][j]) board[i][j] = 'O';
			}
		}
	}
};

//dfs
//class Solution {
//public:
//	void dfs(vector<vector<char>>& board, int i, int j) {
//		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 'O' != board[i][j]) return;
//
//		board[i][j] = '*';
//		dfs(board, i - 1, j);
//		dfs(board, i + 1, j);
//		dfs(board, i, j - 1);
//		dfs(board, i, j + 1);
//	}
//
//	void solve(vector<vector<char>>& board) {
//		if (board.empty()) return;
//
//		int m = board.size();
//		int n = board[0].size();
//		for (int i = 0; i < m; i++) {
//			if ('O' == board[i][0]) dfs(board, i, 0);
//			if ('O' == board[i][n - 1]) dfs(board, i, n - 1);
//		}
//		for (int i = 1; i < n - 1; i++) {
//			if ('O' == board[0][i]) dfs(board, 0, i);
//			if ('O' == board[m - 1][i]) dfs(board, m - 1, i);
//		}
//
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if ('O' == board[i][j]) board[i][j] = 'X';
//				else if ('*' == board[i][j]) board[i][j] = 'O';
//			}
//		}
//	}
//};

//class Solution {
//public:
//	void solve(vector<vector<char>>& board) {
//		int m = board.size();
//		if (!m) return;
//		int n = board[0].size();
//
//		UF uf(n * m + 1); //m*n为dummy
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if ('X' == board[i][j]) continue;
//
//				if (0 == i || (m - 1) == i || 0 == j || (n - 1) == j) {
//					uf.quickUnion(i * n + j, m * n); //将boarder上的O连接到dummy
//				}
//				else {
//					if ('O' == board[i - 1][j]) uf.quickUnion(i * n + j, (i - 1) * n + j);
//					if ('O' == board[i + 1][j]) uf.quickUnion(i * n + j, (i + 1) * n + j);
//					if ('O' == board[i][j - 1]) uf.quickUnion(i * n + j, i * n + j - 1);
//					if ('O' == board[i][j + 1]) uf.quickUnion(i * n + j, i * n + j + 1);
//				}
//			}
//		}
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if ('O' == board[i][j] && !uf.find(i * n + j, m * n)) board[i][j] = 'X'; //没连接到dummy的O可以capture
//			}
//		}
//	}
//
//private:
//	class UF {
//	private:
//		vector<int> v;
//		vector<int> sz;
//
//		int getRoot(int i) {
//			while (i != v[i]) {
//				v[i] = v[v[i]];
//				i = v[i];
//			}
//			return i;
//		}
//
//	public:
//		UF(int n) {
//			for (int i = 0; i < n; i++) {
//				v.push_back(i);
//				sz.push_back(1);
//			}
//		}
//
//		void quickUnion(int p, int q) {
//			int i = getRoot(p);
//			int j = getRoot(q);
//			if (i == j) return;
//			if (sz[i] < sz[j]) {
//				v[i] = j;
//				sz[j] += sz[i];
//			}
//			else {
//				v[j] = i;
//				sz[i] += sz[j];
//			}
//		}
//
//		bool find(int p, int q) {
//			return getRoot(p) == getRoot(q);
//		}
//	};
//};