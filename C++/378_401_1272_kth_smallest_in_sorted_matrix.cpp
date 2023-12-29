#include <vector>
using namespace std;

/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

Example:
matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,
return 13.

解题方案：
1、bs，从matrix[0][0]和matrix[n-1][n-1]开始，找到某个mid在matrix中，并且<=mid的值的个数为k
2、minheap，先放左上点，每pop出一个值，push进去右&下的值
3、minheap，类似lint 486——klogn，n为行数
*/

class Solution {
public:
	int kthSmallest(vector<vector<int>> &matrix, int k) {
		int n = matrix.size();
		int m = matrix[0].size();
		int start = matrix[0][0];
		int end = matrix[n - 1][m - 1];

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			int count = countLessEqual(matrix, mid);

			if (count < k) start = mid;
			else end = mid;
		}

		if (countLessEqual(matrix, start) < k) return end;
		return start;
	}

	int countLessEqual(vector<vector<int>> &matrix, int target) {
		int count = 0;
		int n = matrix.size();
		int m = matrix[0].size();

		int j = m - 1;
		for (int i = 0; i < n; i++) {
			while (j >= 0 && matrix[i][j] > target) { //这里符号很关键，决定怎么return start/end
				j--;
			}

			count += j + 1;
		}

		return count;
	}
};

//minheap
//class Solution {
//public:
//	class Node {
//	public:
//		int row;
//		int col;
//		int val;
//
//		Node(int row, int col, int val) {
//			this->row = row;
//			this->col = col;
//			this->val = val;
//		}
//	};
//
//	struct cmp {
//		bool operator()(Node *a, Node *b) {
//			return a->val > b->val;
//		}
//	};
//
//	int kthSmallest(vector<vector<int>> &matrix, int k) {
//		int n = matrix.size();
//		if (!n) return -1;
//		int m = matrix[0].size();
//		if (!m) return -1;
//
//		priority_queue<Node *, vector<Node *>, cmp> minheap;
//		for (int i = 0; i < n; i++) {
//			minheap.push(new Node(i, 0, matrix[i][0]));
//		}
//
//		for (int i = 0; i < k - 1; i++) {
//			int row = minheap.top()->row;
//			int col = minheap.top()->col;
//			minheap.pop();
//
//			if (col + 1 >= m) continue;
//
//			minheap.push(new Node(row, col + 1, matrix[row][col + 1]));
//		}
//
//		return minheap.top()->val;
//	}
//};

