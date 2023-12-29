#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3
Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

解题思路：
1、moore voting algorithm
2、hash，某个m[i]>n/2时返回i
3、sort之后，返回nums[n/2]
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> m;
		for (int i : nums) {
			if (++m[i] > nums.size() / 2) return i;
		}
		return nums[0];
	}
};

//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		int res;
//		int cnt = 0;
//		for (int i : nums) {
//			if (res == i) cnt++;
//			else if (0 == cnt) {
//				cnt++;
//				res = i;
//			}
//			else cnt--;
//		}
//		return res;
//	}
//};

//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		sort(nums.begin(), nums.end());
//		return nums[nums.size() / 2];
//	}
//};