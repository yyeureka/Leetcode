#include <vector>
using namespace std;

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

解题思路：
stable sort（如merge sort）时计数有多少数从右边移到了左边，O(nlogn)
不能用partition，因为不是stable的
*/

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size();
		if (!n) return{};

		vector<int> res(n, 0);
		vector<pair<int, int>> idx(n);
		for (int i = 0; i < n; i++) idx[i] = { nums[i], i }; //num：index
		mergeSort(idx, res);
		return res;
	}

	void mergeSort(vector<pair<int, int>> &idx, vector<int> &less) {
		int n = idx.size();
		if (n < 2) return; //这个条件不能少

		vector<pair<int, int>> left(idx.begin(), idx.begin() + n / 2);
		vector<pair<int, int>> right(idx.begin() + n / 2, idx.end());
		mergeSort(left, less);
		mergeSort(right, less);

		int i = 0;
		int l = 0;
		int r = 0;
		while (i < n) {
			if (l >= left.size()) idx[i++] = right[r++];
			else if (r >= right.size()) {
				less[left[l].second] += r; //r即为右边比当前数小的数的个数
				idx[i++] = left[l++];
			}
			else if (left[l].first <= right[r].first) { // <=保证是stable sort
				less[left[l].second] += r;
				idx[i++] = left[l++];
			}
			else idx[i++] = right[r++];
		}
	}
};