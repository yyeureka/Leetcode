#include "head.h"

/*
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, 
find the shortest path to a destination position, return the length of the route.
Return -1 if destination cannot be reached.

Example 1:
Input:
[[0,0,0],
[0,0,0],
[0,0,0]]
source = [2, 0] destination = [2, 2]
Output: 2
Explanation:
[2,0]->[0,1]->[2,2]
Example 2:
Input:
[[0,1,0],
[0,0,1],
[0,0,0]]
source = [2, 0] destination = [2, 2]
Output:-1

Clarification
If the knight is at (x, y), he can get to the following positions in one step:
(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)

Notice
source and destination must be empty.
Knight can not enter the barrier.
Path length refers to the number of steps the knight takes.

����˼·��
1���ֲ�BFS���߹��ĵ㶼��1����ֹ�ظ�����
2��DP+BFS����ȫû��Ҫ�ˣ��߼����Ը���

ע�⣺
������bidirectional BFS��������Ϊ��һ�����з���ģ����յ�����Ҫ�������ģ���
����ֻ��dp����Ϊ������������ģ�lint630�Ϳ���
*/

class Solution {
public:
	int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
		if (grid.empty() || grid[0].empty() || grid[source.x][source.y]) { //�״�
			return -1;
		}

		int len = 0;
		vector<int> deltaX = { 1,1,-1,-1,2,2,-2,-2 };
		vector<int> deltaY = { 2,-2,2,-2,1,-1,1,-1 };
		queue<Point> q;
		q.push(source);

		while (!q.empty()) {
			int size = q.size();

			for (int i = 0; i < size; i++) {
				Point cur = q.front();
				q.pop();

				if (cur.x == destination.x && cur.y == destination.y) { //����ֱ��Point==Point
					return len;
				}

				for (int j = 0; j < 8; j++) {
					int nextX = cur.x + deltaX[j];
					int nextY = cur.y + deltaY[j];

					if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size() || grid[nextX][nextY]) {
						continue;
					}

					grid[nextX][nextY] = 1; //�ؼ���
					q.push(Point(nextX, nextY));
				}
			}

			len++;
		}

		return -1;
	}
};

//class Solution {
//public:
//	int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
//		int n = grid.size();
//		if (!n) return -1;
//		int m = grid[0].size();
//		if (grid[source.x][source.y] || grid[destination.x][destination.y]) return -1;
//
//		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
//		dp[source.x][source.y] = 0;
//
//		//������ת�������ַ�ʽ����for loop��ʡ������
//		vector<pair<int, int>> next = { { 1, 2 },{ 1, -2 },{ -1, 2 },{ -1, -2 },{ 2, 1 },{ 2, -1 },{ -2, 1 },{ -2, -1 } };
//
//		queue<pair<int, int>> q;
//		q.push({ source.x, source.y });
//		while (!q.empty()) {
//			int x = q.front().first;
//			int y = q.front().second;
//			q.pop();
//
//			for (auto i : next) {
//				int next_x = x + i.first;
//				int next_y = y + i.second;
//				//��һ��step������Ҫע�⣺�±��⡢��Ϊempty��·���������Ž��
//				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !grid[next_x][next_y] && dp[next_x][next_y] > dp[x][y] + 1) {
//					dp[next_x][next_y] = dp[x][y] + 1;
//					//Խ���queue·��Խ�̣����return�Ŀ϶������·��
//					if (destination.x == next_x && destination.y == next_y) return dp[next_x][next_y];
//					q.push({ next_x, next_y });
//				}
//			}
//		}
//		return -1;
//	}
//};