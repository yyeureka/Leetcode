#include <vector>
#include <set>
#include <xfunctional>
using namespace std;

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples:
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
1 [3  -1  -3] 5  3  6  7       -1
1  3 [-1  -3  5] 3  6  7       -1
1  3  -1 [-3  5  3] 6  7       3
1  3  -1  -3 [5  3  6] 7       5
1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

解题思路：
1、min&max heap multiset
2、一个multiset，会TLE
*/

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> res;
		// 得用longlong 否则有用例会int溢出
		multiset<long long, greater<long long>> less;  // begin is the largest
		multiset<long long> larger;					   // begin is the smallest
		double median;
		for (int i = 0; i < nums.size(); i++) {
			if (i - k >= 0) {
				if (nums[i - k] > median) larger.erase(larger.find(nums[i - k]));
				else less.erase(less.find(nums[i - k]));
			}
			less.insert(nums[i]);
			larger.insert(*less.begin());
			less.erase(less.begin());
			while (less.size() < larger.size()) {
				less.insert(*larger.begin());
				larger.erase(larger.begin());
			}

			if (i >= k - 1) {
				if (k & 1) median = *less.begin();
				else median = (*larger.begin() + *less.begin()) / 2.0;
				res.push_back(median);
			}
		}
		return res;
	}
};

////会TLE
//class Solution {
//public:
//	vector<int> medianSlidingWindow(vector<int> &nums, int k) {
//		vector<int> res;
//		multiset<int> window;
//
//		for (int i = 0; i < nums.size(); i++) {
//			window.insert(nums[i]);
//
//			if (i >= k) {
//				window.erase(window.find(nums[i - k]));
//			}
//
//			if (i >= k - 1) {
//				res.push_back(*next(window.begin(), (k - 1) / 2));
//			}
//		}
//
//		return res;
//	}
//};