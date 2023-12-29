#include "head.h"
/*
Implement strStr function in O(n + m) time.
strStr return the first index of the target string in a source string. The length of the target string is m and the length of the source string is n.
If target does not exist in source, just return -1.

Example 1:
Input��source = "abcdef"�� target = "bcd"
Output��1
Explanation��
The position of the first occurrence of a string is 1.
Example 2:
Input��source = "abcde"�� target = "e"
Output��4
Explanation��
The position of the first occurrence of a string is 4.

����˼·��
Rabin Karp�㷨��ʹ��hash function����lint128��Ҫ�㣺��Ϊ33�����sizeΪ1000000

abcdef��cdeΪ����
abc��cde�Ƚ�
bcd��cde�Ƚ�
cde��cde�Ƚ�
�����㷨ΪO(m*n)����abc��ΪbcdΪO(m)
Rabin Karp�㷨����abc��ΪbcdΪO(1)
abc��hash codeΪ(a*33^2+b*33^1+c*33^0)%10^6����ΪbcdΪ(abc��hash code*33+d-a*33^3)%10^6
base 33��hash size 10^6Ϊ����ֵ��ģ��ֵԽ��collision����Խ��
���double checkһ��hash code��ȵ��ַ���ȷʵ���
*/

class Solution {
public:
	int HASH_SIZE = 1000000;

	int strStr2(const char* source, const char* target) {
		if (NULL == source || NULL == target) return -1; //����ж�
		int n = strlen(source);
		int m = strlen(target);
		if (!m) return 0; //������˳��ǳ�tricky��""��""������
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
				if (hashCode < 0) hashCode += HASH_SIZE; //�״�
			}

			if (hashCode == targetCode) { //�״����ַ��Ƚ�
				int j = i - m + 1;
				int k = 0;
				while (j >= 0 && j < n && k < m) { //�״�j�ķ�ΧҲ������
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