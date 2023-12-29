#include <vector>
using namespace std;

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 5
Output:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (!numRows) return{};
		vector<vector<int>> res = { { 1 } };
		int row = 1;
		while (row < numRows) {
			int size = res.back().size();
			res.push_back(vector<int>(size + 1, 1));
			for (int i = 1; i < size; i++) {
				res[row][i] = res[row - 1][i - 1] + res[row - 1][i];
			}
			row++;
		}
		return res;
	}
};