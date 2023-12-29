#include <vector>
using namespace std;

/*
Given a matrix A, return the transpose of A.
The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
Note:
1 <= A.length <= 1000
1 <= A[0].length <= 1000

Example 1:
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:
Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

注意！！不一定是个square啊，可能是rectangle
*/

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int n = A.size();
		if (!n) return{};
		int m = A[0].size();
		vector<vector<int>> res(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				res[i][j] = A[j][i];
			}
		}
		return res;
	}
};