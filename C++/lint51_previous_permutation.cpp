#include <vector>
using namespace std;

/*
Given a list of integers, which denote a permutation.
Find the previous permutation in ascending order.
Note: The list may contains duplicate integers.

Example 1:
Input:[1]
Output:[1]
Example 2:
Input:[1,3,2,3]
Output:[1,2,3,3]
Example 3:
Input:[1,2,3,4]
Output:[4,3,2,1]

解题思路：类似#31
*/

class Solution {
public:
	vector<int> previousPermuation(vector<int> &nums) {
		if (nums.size() <= 1) {
			return nums;
		}

		int i;
		for (i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] > nums[i + 1]) {
				for (int j = nums.size() - 1; j > i; j--) {
					if (nums[j] < nums[i]) {
						swap(nums[j], nums[i]);
						break;
					}
				}
				break;
			}
		}
		
		reverse(nums.begin() + i + 1, nums.end());
		return nums;
	}
};