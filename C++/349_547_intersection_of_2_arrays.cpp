#include "head.h" 

/*
Given two arrays, write a function to compute their intersection.
Notice
Each element in the result must be unique.
The order of the results needs to be ascending

Example 1:
Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2],
Output: [2].
Example 2:
Input: nums1 = [1, 2], nums2 = [2],
Output: [2].

Challenge
Can you implement it in three different algorithms?

解题思路：
1、hash，sort nums2——n+mlogm
2、two pointer——nlogn+mlogm
3、binary search——nlogn+mlogn
*/

//two pointer
class Solution {
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
		if (nums1.empty() || nums2.empty()) {
			return{};
		}

		vector<int> res;
		int i = 0;
		int j = 0;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		while (i < nums1.size() && j < nums2.size()) {
			if (i > 0 && nums1[i] == nums1[i - 1]) {
				i++;
				continue;
			}
			if (j > 0 && nums2[j] == nums2[j - 1]) {
				j++;
				continue;
			}

			if (nums1[i] == nums2[j]) {
				res.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j]) {
				i++;
			}
			else {
				j++;
			}
		}

		return res;
	}
};

//hash
//class Solution {
//public:
//	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//		if (nums1.empty() || nums2.empty()) {
//			return{};
//		}
//
//		vector<int> res;
//		unordered_set<int> nums;
//
//		for (int i : nums1) {
//			if (nums.find(i) == nums.end()) {
//				nums.insert(i);
//			}
//		}
//
//		sort(nums2.begin(), nums2.end()); //易漏 去重且结果要递增
//		for (int i = 0; i < nums2.size(); i++) {
//			if (i > 0 && nums2[i] == nums2[i - 1]) {
//				continue;
//			}
//
//			if (nums.find(nums2[i]) != nums.end()) {
//				res.push_back(nums2[i]);
//			}
//		}
//
//		return res;
//	}
//};

//binary search
//class Solution {
//public:
//	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//		if (nums1.empty() || nums2.empty()) {
//			return{};
//		}
//
//		unordered_set<int> intersection;
//		vector<int> results;
//
//		sort(nums1.begin(), nums1.end());
//
//		for (int i : nums2) {
//			if (intersection.find(i) != intersection.end()) {
//				continue;
//			}
//
//			if (binary_search(nums1, i)) {
//				intersection.insert(i);
//			}
//		}
//
//		for (int i : intersection) {
//			results.push_back(i);
//		}
//
//		return results;
//	}
//
//	bool binary_search(vector<int> &nums, int target) {
//		if (nums.empty()) {
//			return false;
//		}
//
//		int left = 0;
//		int right = nums.size() - 1;
//
//		while (left + 1 < right) {
//			int mid = left + (right - left) / 2;
//
//			if (target == nums[mid]) {
//				return true;
//			}
//			else if (target < nums[mid]) {
//				right = mid;
//			}
//			else {
//				left = mid;
//			}
//		}
//
//		if (target == nums[left] || target == nums[right]) {
//			return true;
//		}
//		return false;
//	}
//};