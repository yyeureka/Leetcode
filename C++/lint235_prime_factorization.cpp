#include "head.h"

/*
Prime factorize a given integer.

Example 1:
Input: 10
Output: [2, 5]
Example 2:
Input: 660
Output: [2, 2, 3, 5, 11]
Notice
You should sort the factors in ascending order.

最坏时间复杂度 O(sqrt(n)),当n为质数时，取到其最坏时间复杂度。
空间复杂度 O(log(n))，当n质因数很多时，需要空间大，但总不会多于O(log(n))个
*/

class Solution {
public:
	vector<int> primeFactorization(int num) {
		if (num <= 1) return{};

		int upper = sqrt(num);
		vector<int> res;

		for (int i = 2; i <= upper; i++) { //关键点，i>upper时，能被整除的只有num自己
			if (1 == num) break;

			while (0 == num % i) {
				num /= i;
				res.push_back(i);
			}
		}

		if (num > 1) res.push_back(num);

		return res;
	}
};