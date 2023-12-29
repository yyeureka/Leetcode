#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true
Example 2:
Input: [1,2,3,4]
Output: false
Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

解题思路：
1、sort
2、hash，次数>1 return true
3、set，貌似比hash略慢
*/

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) return true;
		}
		return false;
	}
};

//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		unordered_map<int, int> m;
//		for (int i : nums) {
//			if (m[i]++ > 0) return true;
//		}
//		return false;
//	}
//};

//class Solution {
//public:
//	bool containsDuplicate(vector<int>& nums) {
//		set<int> s;
//		for (int i : nums) {
//			if (s.count(i)) return true;
//			s.insert(i);
//		}
//		return false;
//	}
//};