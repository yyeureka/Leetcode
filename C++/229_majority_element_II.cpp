#include <vector>
#include <unordered_map>
using namespace std;

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.

Example 1:
Input: [3,2,3]
Output: [3]
Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

解题思路：#169的follow up
1、moore voting algorithm
2、hash
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
		int num1;
		int cnt1 = 0;
		int num2;
		int cnt2 = 0;
		for (int i : nums) {
			if (num1 == i) cnt1++;
			else if (num2 == i) cnt2++;
			else if (0 == cnt1) {
				num1 = i;
				cnt1++;
			}
			else if (0 == cnt2) {
				num2 = i;
				cnt2++;
			}
			else {
				cnt1--;
				cnt2--;
			}
		}
		cnt1 = 0;
		cnt2 = 0;
		for (int i : nums) {
			if (num1 == i) cnt1++;
			else if (num2 == i) cnt2++;
		}
		if (cnt1 > nums.size() / 3) res.push_back(num1);
		if (cnt2 > nums.size() / 3) res.push_back(num2);
		return res;
	}
};

//class Solution {
//public:
//	vector<int> majorityElement(vector<int>& nums) {
//		vector<int> res;
//		unordered_map<int, int> m;
//		for (int i : nums) m[i]++;
//		for (auto i : m) {
//			if (i.second > nums.size() / 3) res.push_back(i.first);
//		}
//		return res;
//	}
//};