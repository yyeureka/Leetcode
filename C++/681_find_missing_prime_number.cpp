#include "head.h"

/*
Given a list of prime numbers and find the smallest prime number that doesn't appear in this list.

Example1
Input: [3,5,7]
Output: 2
Example2
Input: [2,3,5,7,11,13,17,23,29]
Output: 19

解题思路：2~nums.back()*2范围内找到所有prime和nums比对，方法类似#204。为什么*2就能确定范围不清楚
*/

class Solution {
public:
	int firstMissingPrime(vector<int> &nums) {
		if (nums.empty()) return 2; //易错

		int n = 2 * nums.back();
		int upper = sqrt(n);
		vector<bool> prime(n + 1, true);

		int j = 0;
		for (int i = 2; i <= n; i++) {
			if (!prime[i]) continue;

			if (j >= nums.size() || i != nums[j]) return i;
			j++;

			if (i <= upper) {
				for (int k = i * i; k < n; k += i) prime[k] = false;
			}
		}

		return 0;
	}
};