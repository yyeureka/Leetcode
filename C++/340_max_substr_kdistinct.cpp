#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a string S, find the length of the longest substring T that contains at most k distinct characters.
挑战
O(n) time

样例
Example 1:
Input: S = "eceba" and k = 3
Output: 4
Explanation: T = "eceb"
Example 2:
Input: S = "WORLD" and k = 4
Output: 4
Explanation: T = "WORL" or "ORLD"

解题思路：
同向双指针法，128位1维数组用来字符计数
注意！input中不一定有超过k种字符，因此找到小于k个字符的时候就可以计算长度
*/

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string &s, int k) {
		int res = 0;
		int l = 0;
		int r = 0;
		vector<int> v(128, 0);
		while (r < s.size()) {
			if (!v[s[r++]]++) k--;
			while (k < 0) if (1 == v[s[l++]]--) k++;
			res = max(res, r - l);  // 这句不能放在while循环中
		}
		return res;
	}
};