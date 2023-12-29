#include <vector>
using namespace std;

/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

Example 1:
Input:
[[1,1,0],
[1,1,0],
[0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input:
[[1,1,0],
[1,1,1],
[0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

解题思路：
最基础的计算union个数的unionfind题
注意M是对角线对称的，检查一半就行了
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
		int count;

		UF(int n) {
			count = n;
			for (int i = 0; i < n; i++) {
				v.push_back(i);
				sz.push_back(1);
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
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		if (!n) return 0;

		UF uf(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (1 == M[i][j]) uf.quickUnion(i, j);
			}
		}
		return uf.count;
	}
};