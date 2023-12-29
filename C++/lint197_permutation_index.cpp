#include <vector>
#include <algorithm>
using namespace std;

/*
Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.

Example 1:
Input:[1,2,4]
Output:1
Example 2:
Input:[3,2,1]
Output:6

解题思路：与#60相反的过程
以2 4 3 5 1为例
5：1个数比他小——1*1
3：1个数比他小——1*2！
4：2个数比他小——2*3！
2：1个数比他小——1*4！
*/

class Solution {
public:
	long long permutationIndex(vector<int> &A) {
		if (A.empty()) {
			return 0;
		}

		long long index = 1;
		long long factorial = 1;

		for (int i = A.size() - 1; i >= 0; i--) {
			int countless = 0;
			for (int j = i + 1; j < A.size(); j++) {
				if (A[j] < A[i]) {
					countless++;
				}
			}

			index += countless * factorial;
			factorial *= (A.size() - i);
		}

		return index;
	}
};