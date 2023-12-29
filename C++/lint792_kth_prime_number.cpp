#include "head.h"

/*
Given the prime number n, output the number of prime numbers

Example1
Input: n = 3
Output: 2
Explanation:
[2,3,5], 3 is the second prime number.
Example2
Input: n = 11
Output: 5
Explanation:
[2,3,5,7,11], 11 is the fifth prime number.
Notice
n <= 100000
The prime number is defined as a natural number greater than 1, and there are no other factors except 1 and it itself.

解题思路：跟#204异曲同工
*/

class Solution {
public:
	int kthPrime(int n) {
		int idx = 1;
		int upper = sqrt(n);
		vector<bool> prime(n, true);

		for (int i = 2; i < n; i++) {
			if (!prime[i]) continue;

			idx++;
			if (i <= upper) {
				for (int j = i * i; j < n; j += i) prime[j] = false;
			}
		}

		return idx;
	}
};