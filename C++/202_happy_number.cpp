#include <unordered_set>
using namespace std;

/*
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example:
Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

解题思路：
1、hash保存每次得到的n，如果出现重复，即失败
2、fast、slow大法，slow每次square sum一次，fast两次，最终fast和slow会相等，如果=1即成功，否则失败
*/

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0) return false; //入参判断

		unordered_set<int> s;
		while (n != 1) {
			if (s.find(n) != s.end()) return false;
			s.insert(n);

			int next = 0;
			while (n > 0) {
				next += (n % 10) * (n % 10);
				n /= 10;
			}
			n = next;
		}
		return true;
	}
};

//class Solution {
//public:
//	int squareSum(int n) {
//		int res = 0;
//		while (n > 0) {
//			res += (n % 10) * (n % 10);
//			n /= 10;
//		}
//		return res;
//	}
//
//	bool isHappy(int n) {
//		if (n <= 0) return false;
//
//		int slow = n;
//		int fast = squareSum(n);
//
//		while (slow != fast) {
//			slow = squareSum(slow);
//			fast = squareSum(fast);
//			fast = squareSum(fast);
//		}
//		return 1 == slow;
//	}
//};