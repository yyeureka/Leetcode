#include <vector>
using namespace std;

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

Example:
Given nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

解题思路：binary indexed tree
*/

class NumArray {
private:
	vector<int> tree;
public:
	NumArray(vector<int> nums) {
		if (nums.empty()) {
			return;
		}

		tree = vector<int>(nums.size() + 1, 0);

		for (int i = 1; i <= nums.size(); i++) {
			for (int j = i; j > i - (i & (-i)); j--) { //易错！！括号不能省
				tree[i] += nums[j - 1];
			}
		}
	}

	void update(int i, int val) {
		int delta = val - sumRange(i, i); //这里tricky，是变为val，所以要自己求增加量

		i++; //易错
		while (i < tree.size()) {
			tree[i] += delta;
			i += i & (-i);
		}
	}

	int prefixSum(int i) {
		int sum = 0;

		i++; //易错
		while (i > 0) { //不是>=0
			sum += tree[i];
			i -= i & (-i);
		}

		return sum;
	}

	int sumRange(int i, int j) {
		return prefixSum(j) - prefixSum(i - 1); //易错
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/