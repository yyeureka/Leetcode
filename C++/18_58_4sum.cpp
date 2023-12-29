#include "head.h"

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Example 1:
Input:[2,7,11,15],3
Output:[]
Example 2:
Input:[1,0,-1,0,-2,2],0
Output:
[[-1, 0, 0, 1]
,[-2, -1, 1, 2]
,[-2, 0, 0, 2]]

Notice
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

解题思路：类似3sum
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int> &numbers, int target) {
		if (numbers.empty()) return{};

		vector<vector<int>> res;

		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size(); i++) {
			if (i > 0 && numbers[i] == numbers[i - 1]) continue;

			for (int j = i + 1; j < numbers.size(); j++) {
				if (j > i + 1 && numbers[j] == numbers[j - 1]) continue; //易错，j>i+1不能少

				int left = j + 1;
				int right = numbers.size() - 1;

				while (left < right) {
					int sum = numbers[i] + numbers[j] + numbers[left] + numbers[right];

					if (target == sum) {
						res.push_back({ numbers[i], numbers[j], numbers[left], numbers[right] });
						left++;
						right--;

						while (left < right && numbers[left] == numbers[left - 1]) left++;
						while (left < right && numbers[right] == numbers[right + 1]) right--;
					}
					else if (sum < target) left++;
					else right--;
				}
			}
		}

		return res;
	}
};