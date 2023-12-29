#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

解题思路：
遍历第一个数，对之后的数求two sum类似#167，O(n^2)
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &numbers) {
		if (numbers.empty()) return{};

		vector<vector<int>> res;

		sort(numbers.begin(), numbers.end()); //去重要先sort
		for (int i = 0; i < numbers.size(); i++) {
			if (i > 0 && numbers[i] == numbers[i - 1]) continue; //易错 去重

			int start = i + 1;
			int end = numbers.size() - 1;

			while (start < end) {
				if (0 == numbers[i] + numbers[start] + numbers[end]) {
					res.push_back({ numbers[i], numbers[start], numbers[end] });
					start++;
					end--;

					while (start < end && numbers[start] == numbers[start - 1]) start++; //去重
					while (start < end && numbers[end] == numbers[end + 1]) end--;
				}
				else if (numbers[i] + numbers[start] + numbers[end] > 0) end--;
				else start++;
			}
		}

		return res;
	}
};