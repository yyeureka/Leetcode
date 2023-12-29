#include "head.h"

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

Example 1:
Input:[2,7,11,15],3
Output:20
Explanation:
2+7+11=20
Example 2:
Input:[-1,2,1,-4],1
Output:2
Explanation:
-1+2+1=2

Challenge
O(n^2) time, O(1) extra space

Notice
You may assume that each input would have exactly one solution.
*/

class Solution {
public:
	int threeSumClosest(vector<int> &numbers, int target) {
		int res = INT_MAX;

		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size(); i++) {
			int start = i + 1;
			int end = numbers.size() - 1;

			while (start < end) {
				int sum = numbers[start] + numbers[end] + numbers[i];

				if (target == sum) return target;
				else if (sum > target) end--;
				else start++;

				if (INT_MAX == res || abs(sum - target) < abs(res - target)) res = sum;
			}
		}

		return res;
	}
};