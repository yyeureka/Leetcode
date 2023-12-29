#include <vector>
using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example:
Consider the following matrix:
[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.

解题思路：类似#74
1、从右上角往左上角查找
2、BS，第一个元素判断是否search那一行，对每一行，找到idx，对之下的行，search 1~idx-1，实现较复杂
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;

		int i = 0;
		int j = matrix[0].size() - 1;

		while (i < matrix.size() && j >= 0) {
			if (matrix[i][j] == target) return true;
			//if (target == matrix[i][j]) {
			//	count++;
			//	i++;
			//  j--;
			//} 
			else if (matrix[i][j] < target) i++;
			else j--;
		}

		return false;
	}
};

//class Solution {
//public:
//	int search(vector<int> &v, int l, int r, int target) {
//		while (l <= r) {
//			int mid = l + (r - l) / 2;
//			if (v[mid] == target) return mid;
//			else if (v[mid] > target) r = mid - 1;
//			else l = mid + 1;
//		}
//		return -1;
//	}
//
//	int searchMatrix(vector<vector<int>> &matrix, int target) {
//		int n = matrix.size();
//		if (!n) return 0;
//		int m = matrix[0].size();
//		if (!m) return 0; //易错，有个用例是{{}}
//
//		int cnt = 0;
//		int r = m - 1;
//		for (int i = 0; i < n; i++) {
//			if (matrix[i][0] == target) {
//				cnt++;
//				break;
//			}
//			else if (matrix[i][0] > target) break;
//
//			int idx = search(matrix[i], 1, r, target);
//			if (idx >= 0) {
//				cnt++;
//				r = idx - 1;
//			}
//		}
//		return cnt;
//	}
//};