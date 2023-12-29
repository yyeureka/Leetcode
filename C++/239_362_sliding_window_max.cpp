#include "head.h"

/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
Follow up:
Could you solve it in linear time?

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1  [3  -1  -3] 5  3  6  7       3
1   3 [-1  -3  5] 3  6  7       5
1   3  -1 [-3  5  3] 6  7       5
1   3  -1  -3 [5  3  6] 7       6
1   3  -1  -3  5 [3  6  7]      7

解题思路：
1、deque，保存val的idx，val递减，front永远是max
当front出window，pop_front(),如果back的val小于x，pop_back(),最后push_back x的idx
2、带window的maxheap
*/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> d;

		for (int i = 0; i < nums.size(); i++) {
			if (!d.empty() && d.front() <= i - k) d.pop_front();

			while (!d.empty() && nums[d.back()] < nums[i]) d.pop_back();
			d.push_back(i);

			if (i >= k - 1) res.push_back(nums[d.front()]);
		}

		return res;
	}
};

//class Solution {
//public:
//	struct cmp {
//		bool operator()(int a, int b) {
//			return a >= b;
//		}
//	};
//
//	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
//		vector<int> res;
//		multiset<int, greater<int>> window;
//
//		for (int j = 0; j < nums.size(); j++) {
//			window.insert(nums[j]);
//			if (j >= k) {
//				window.erase(window.find(nums[j - k]));
//			}
//
//			if (j >= k - 1) {
//				res.push_back(*window.begin());
//			}
//		}
//
//		return res;
//	}
//};