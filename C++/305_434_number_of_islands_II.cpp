#include "head.h"
using namespace std;

/*
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.
Notes:
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Example 1:
Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
Output: [1,1,2,2]
Explanation:
0.  00000
00000
00000
00000
1.  00000
01000
00000
00000
2.  01000
01000
00000
00000
3.  01000
01000
00000
00010
4.  01000
01000
00000
00011
Example 2:
Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
Output: [1,1,2,2]

解题思路：
union find：
count为岛屿的个数，初始为0
vector初始为-1
遍历operators：
-1的点置为id，count++
合并周围的union，如果能合并，count--
*/

class Solution {
private:
	class UF {
	private:
		int getRoot(int i) {
			while (i != v[i]) {
				v[i] = v[v[i]];
				i = v[i];
			}

			return i;
		}

	public:
		vector<int> v;
		vector<int> sz;
		int count = 0; //赋初值不能忘

		UF(int n) {
			v = vector<int>(n, -1);
			sz = vector<int>(n, 1);
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
	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		UF uf(n * m);
		vector<pair<int, int>> delta = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
		vector<int> res;

		for (auto i : operators) {
			int id = i.x * m + i.y;

			if (uf.v[id] < 0) { //超易错 会有重复的点
				uf.count++;
				uf.v[id] = id;

				for (auto j : delta) {
					int x = i.x + j.first;
					int y = i.y + j.second;

					if (x < 0 || x >= n || y < 0 || y >= m || uf.v[x * m + y] < 0) continue;

					uf.quickUnion(id, x * m + y);
				}
			}

			res.push_back(uf.count); //易错 重复的点也需要加进res
		}

		return res;
	}
};