#include "head.h"

/*
Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.

Example 1:
Input :[1,4,2,2]
Output:3
Example 2:
Input :[1,6,5,3,1]
Output:24

解题思路：lint197 follow up，解决重复问题
*/

class Solution {
public:
	long long permutationIndexII(vector<int> &A) {
		if (A.empty()) {
			return 0;
		}

		long long index = 1;
		long long factorial = 1;
		long long multi = 1;
		unordered_map<int, int> count;

		for (int i = A.size() - 1; i >= 0; i--) {
			count[A[i]]++;
			multi *= count[A[i]]; //计算重复

			int countLess = 0;
			for (int j = i + 1; j < A.size(); j++) {
				if (A[j] < A[i]) {
					countLess++;
				}
			}

			index += countLess * factorial / multi; //解决重复问题
			factorial *= (A.size() - i);
		}

		return index;
	}
};