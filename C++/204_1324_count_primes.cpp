#include <vector>
using namespace std;

/*
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

解题思路：
每个非prime，一定能分解为一组prime的乘积，因此对每一个prime，依次把它能产生的非prime记录下来
*/

class Solution {
public:
	int countPrimes(int n) {
		if (n <= 2) return 0;

		vector<bool> is_prime(n, true);
		int upper = sqrt(n);

		int count = 0;
		for (int i = 2; i < n; i++) {
			if (!is_prime[i]) continue;

			count++;
			if (i <= upper) { //坑，不加这个条件会int overflow
				for (int j = i * i; j < n; j += i) is_prime[j] = false;
			}
		}

		return count;
	}
};

//class Solution {
//public:
//	int countPrimes(int n) {
//		int res = 0;
//		vector<bool> prime(n, true);
//		for (int i = 2; i < n; i++) {
//			if (prime[i]) {
//				res++;
//				for (int j = 2; j * i < n; j++) prime[i * j] = false;
//			}
//		}
//		return res;
//	}
//};