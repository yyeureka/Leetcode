#include "head.h"
/*
Implement strStr function in O(n + m) time.
strStr return the first index of the target string in a source string. The length of the target string is m and the length of the source string is n.
If target does not exist in source, just return -1.

Example 1:
Input：source = "abcdef"， target = "bcd"
Output：1
Explanation：
The position of the first occurrence of a string is 1.
Example 2:
Input：source = "abcde"， target = "e"
Output：4
Explanation：
The position of the first occurrence of a string is 4.

解题思路：
Rabin Karp算法，使用hash function，见lint128。要点：底为33，最大size为1000000

abcdef找cde为例：
abc和cde比较
bcd和cde比较
cde和cde比较
正常算法为O(m*n)，从abc变为bcd为O(m)
Rabin Karp算法，从abc变为bcd为O(1)
abc的hash code为(a*33^2+b*33^1+c*33^0)%10^6，变为bcd为(abc的hash code*33+d-a*33^3)%10^6
base 33和hash size 10^6为经验值，模的值越大collision几率越低
最后double check一下hash code相等的字符串确实相等
*/

class Solution {
public:
	int HASH_SIZE = 1000000;

	int strStr2(const char* source, const char* target) {
		if (NULL == source || NULL == target) return -1; //入参判断
		int n = strlen(source);
		int m = strlen(target);
		if (!m) return 0; //这两个顺序非常tricky，""和""的用例
		if (!n) return -1;

		int targetCode = 0;
		int power = 1;
		for (int i = 0; i < m; i++) {
			targetCode = (targetCode * 33 + target[i]) % HASH_SIZE;
			power = (power * 33) % HASH_SIZE;
		}

		int hashCode = 0;
		for (int i = 0; i < n; i++) {
			hashCode = (hashCode * 33 + source[i]) % HASH_SIZE;

			if (i >= m) {
				hashCode -= (source[i - m] * power) % HASH_SIZE;
				if (hashCode < 0) hashCode += HASH_SIZE; //易错
			}

			if (hashCode == targetCode) { //易错，逐字符比较
				int j = i - m + 1;
				int k = 0;
				while (j >= 0 && j < n && k < m) { //易错，j的范围也到考虑
					if (source[j] != target[k]) break;
					j++;
					k++;
				}
				if (m == k) return i - m + 1; 
			}
		}
		return -1;
	}
};