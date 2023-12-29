#include <vector>
using namespace std;

/*
Given a 2D matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2). And the elements of the matrix could be changed.
You have to implement three functions:
NumMatrix(matrix) The constructor.
sumRegion(row1, col1, row2, col2) Return the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
update(row, col, val) Update the element at (row, col) to val.
Notes:
The matrix is only modifiable by update.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.

Example 1:
Input:
NumMatrix(
[[3,0,1,4,2],
[5,6,3,2,1],
[1,2,0,1,5],
[4,1,0,1,7],
[1,0,3,0,5]]
)
sumRegion(2,1,4,3)
update(3,2,2)
sumRegion(2,1,4,3)
Output:
8
10
Example 2:
Input:
NumMatrix([[1]])
sumRegion(0, 0, 0, 0)
update(0, 0, -1)
sumRegion(0, 0, 0, 0)
Output:
1
-1

解题思路：binary indexed tree
原matrix：
[[3,0,1,4,2],
 [5,6,3,2,1],
 [1,2,0,1,5],
 [4,1,0,1,7],
 [1,0,3,0,5]]
tree matrix：
[[3, 3, 1,8, 2], 3,3+0,1,3+0+1+4,2
 [8, 14,4,24,3], 5+3,6+0+5+3,3+1，...
 [1, 3, 0,4, 5],
 [13,22,4,34,15],
 [1, 1, 3,4, 5]]

 sumRegion(2,1,4,3)为sum(4,3)-sum(4,0)-sum(1,3)+sum(1,0)
*/

class NumMatrix {
private:
	vector<vector<int>> tree;
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return;
		}

		int row = matrix.size();
		int col = matrix[0].size();
		tree = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				for (int k = i; k > i - (i & (-i)); k--) { //易错，括号不能省
					for (int l = j; l > j - (j & (-j)); l--) {
						tree[i][j] += matrix[k - 1][l - 1];
					}
				}
			}
		}
	}

	void update(int row, int col, int val) {
		int delta = val - sumRegion(row, col, row, col); //易错

		for (int i = row + 1; i < tree.size(); i += i & (-i)) {
			for (int j = col + 1; j < tree[0].size(); j += j & (-j)) {
				tree[i][j] += delta;
			}
		}
	}

	int prefixSum(int row, int col) {
		int sum = 0;

		for (int i = row + 1; i > 0; i -= i & (-i)) { //不是>=0
			for (int j = col + 1; j > 0; j -= j & (-j)) {
				sum += tree[i][j];
			}
		}

		return sum;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		//易错
		return prefixSum(row2, col2) - prefixSum(row2, col1 - 1) - prefixSum(row1 - 1, col2) + prefixSum(row1 - 1, col1 - 1);
	}
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* obj.update(row,col,val);
* int param_2 = obj.sumRegion(row1,col1,row2,col2);
*/