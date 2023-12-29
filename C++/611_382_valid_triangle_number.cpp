#include "head.h"

/*
Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?

Example 1:
Input: [3, 4, 6, 7]
Output: 3
Explanation:
They are (3, 4, 6),
(3, 6, 7),
(4, 6, 7)
Example 2:
Input: [4, 4, 4, 4]
Output: 4
Explanation:
Any three numbers can form a triangle.
So the answer is C(3, 4) = 4

����˼·��
�����ζ��壺�����̱ߺ�>����
sort��������ߣ�two sum��ö̱�
*/

class Solution {
public:
	int triangleCount(vector<int> &S) {
		int count = 0;

		sort(S.begin(), S.end()); //�ؼ���
		for (int i = 2; i < S.size(); i++) {
			int start = 0;
			int end = i - 1;

			while (start < end) {
				if (S[start] + S[end] > S[i]) {
					count += end - start; //�ؼ���
					end--;
				}
				else start++;
			}
		}

		return count;
	}
};