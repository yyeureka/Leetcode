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

�ʱ�临�Ӷ� O(sqrt(n)),��nΪ����ʱ��ȡ�����ʱ�临�Ӷȡ�
�ռ临�Ӷ� O(log(n))����n�������ܶ�ʱ����Ҫ�ռ�󣬵��ܲ������O(log(n))��
*/

class Solution {
public:
	vector<int> primeFactorization(int num) {
		if (num <= 1) return{};

		int upper = sqrt(num);
		vector<int> res;

		for (int i = 2; i <= upper; i++) { //�ؼ��㣬i>upperʱ���ܱ�������ֻ��num�Լ�
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