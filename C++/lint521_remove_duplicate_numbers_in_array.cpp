#include "head.h"

/*
Given an array of integers, remove the duplicate numbers in it.
You should:
Do it in place in the array.
Move the unique numbers to the front of the array.
Return the total number of the unique numbers.

Example 1:
Input:
nums = [1,3,1,4,4,2]
Output:
[1,3,4,2,?,?]
4
Explanation:
Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
Return the number of unique integers in nums => 4.
Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.
Example 2:
Input:
nums = [1,2,3]
Output:
[1,2,3]
3

Challenge
Do it in O(n) time complexity.
Do it in O(nlogn) time without extra space.

Notice
You don't need to keep the original order of the integers.

解题思路：同向双指针
1、unordered_set保存数字，O(n)时间&空间
2、sort以后去重，O(nlogn)时间，O(1)空间
*/

//unordered_set
class Solution {
public:
	int deduplication(vector<int> &nums) {
		unordered_set<int> s;

		int i = 0;
		for (int j : nums) {
			if (s.find(j) == s.end()) {
				nums[i++] = j;
				s.insert(j);
			}
		}

		return i;
	}
};

////sort
//class Solution {
//public:
//	int deduplication(vector<int> &nums) {
//		sort(nums.begin(), nums.end());
//
//		int i = 0;
//		for (int j = 0; j < nums.size(); j++) {
//			if (j > 0 && nums[j] == nums[j - 1]) continue;
//
//			nums[i++] = nums[j];
//		}
//
//		return i;
//	}
//};