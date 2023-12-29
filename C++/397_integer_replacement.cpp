#include <algorithm>
using namespace std;

/*
Given a positive integer n and you can do operations as follow:
If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:
Input:
8
Output:
3
Explanation:
8 -> 4 -> 2 -> 1
Example 2:
Input:
7
Output:
4
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

解题思路：
如果n为偶数，n/2
如果n为奇数，n-1和n+1哪个有更少的1就做哪种操作：例如*01是-1,*11是+1，通过判断倒数第二位是1还是0
例外：
INT_MAX，按上述规则应该+1，但是会溢出，所以直接return 32
3，唯一不符合上述规则，3-2-1好于3-4-2-1
*/

class Solution {
public:
	int integerReplacement(int n) {
		if (INT_MAX == n) return 32;

		int cnt = 0;
		while (n != 1) {
			if (n & 1) {
				if (3 == n || 0 == ((n / 2) & 1)) n--;
				else n++;
			}
			else n /= 2;
			cnt++;
		}
		return cnt;
	}
};

//class Solution {
//public:
//	int integerReplacement(int n) {
//		if (1 == n) return 0;
//		else if (INT_MAX == n) return 32;
//		else if (n & 1) {
//			if (3 == n || 0 == ((n >> 1) & 1)) return 1 + integerReplacement(n - 1);
//			else return 1 + integerReplacement(n + 1);
//		}
//		else return 1 + integerReplacement(n / 2);
//	}
//};