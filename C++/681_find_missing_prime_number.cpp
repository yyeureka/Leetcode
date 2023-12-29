#include "head.h"

/*
Given a list of prime numbers and find the smallest prime number that doesn't appear in this list.

Example1
Input: [3,5,7]
Output: 2
Example2
Input: [2,3,5,7,11,13,17,23,29]
Output: 19

����˼·��2~nums.back()*2��Χ���ҵ�����prime��nums�ȶԣ���������#204��Ϊʲô*2����ȷ����Χ�����
*/

class Solution {
public:
	int firstMissingPrime(vector<int> &nums) {
		if (nums.empty()) return 2; //�״�

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