#include <vector>
using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 3
Output: true
Example 2:
Input:
matrix = [
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
target = 13
Output: false

解题思路：
1、起始i=0，j=m-1开始——O(m+n)
   <target时 i++
   >target时 j--
2、matrix当成sorted数组做一维的binary search——O(logm*n)
3、对row、col分别做binary search
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.empty()) return false;

		int i = 0;
		int j = matrix[0].size() - 1;
		while (i < matrix.size() && j >= 0) {
			if (target == matrix[i][j]) return true;

			if (target > matrix[i][j]) i++;
			else j--;
		}

		return false;
	}
};

//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		int n = matrix.size();
//		if (!n) return false;
//		int m = matrix[0].size();
//		if (!m) return false;
//
//		int start = 0;
//		int end = n * m - 1;
//		while (start <= end) {
//			int mid = start + (end - start) / 2;
//			if (matrix[mid / m][mid % m] > target) end = mid - 1;
//			else if (matrix[mid / m][mid % m] < target) start = mid + 1;
//			else return true;
//		}
//		return false;
//	}
//};

//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		// 这些怎么都不能省！
//		int n = matrix.size();
//		if (!n) return false;
//		int m = matrix[0].size();
//		if (!m) return false;
//
//		int start = 0;
//		int end = n - 1;
//		while (start <= end) { //这里不能是<，只有一行/一列的情况出错
//			int row = start + (end - start) / 2;
//			if (matrix[row][0] > target) end = row - 1;
//			else if (row + 1 < n && matrix[row + 1][0] <= target) start = row + 1;  // 1.这里要判断数组越界 2.是<=!!
//			else {
//				start = 0;
//				end = m - 1;
//				while (start <= end) {
//					int col = start + (end - start) / 2;
//					if (matrix[row][col] > target) end = col - 1;
//					else if (matrix[row][col] < target) start = col + 1;
//					else return true;
//				}
//				break;
//			}
//		}
//		return false;
//	}
//};