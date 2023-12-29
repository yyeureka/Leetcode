#include <vector>
#include <unordered_map>
using namespace std;

/*
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.
paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.
Also, there is no garden that has more than 3 paths coming into or leaving it.
Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

Example 1:
Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:
Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:
Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

Note:
1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.

解题思路：
greedy，为什么greedy一定正确呢？每个花园indegree/degree最多为3，不管怎么样都能种一种颜色
遍历paths，将小于i的所有garden j放进i的vector
i从0开始，遍历garden i vector中garden的颜色，res[i]为没被用到的那个颜色
*/

class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> res(N, 0);
		vector<vector<int>> v(N);
		for (auto i : paths) {
			if (i[0] > i[1]) v[i[0] - 1].push_back(i[1] - 1);
			else v[i[1] - 1].push_back(i[0] - 1);
		}

		for (int i = 0; i < N; i++) {
			vector<bool> color(5, true);
			for (int j : v[i]) {
				color[res[j]] = false;
			}
			for (int k = 1; k <= 4; k++) {
				if (color[k]) {
					res[i] = k;
					break;
				}
			}
		}
		return res;
	}
};