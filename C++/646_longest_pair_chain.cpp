#include <vector>
#include <algorithm>
using namespace std;

/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
Note:
The number of given pairs will be in the range [1, 1000].

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

解题思路：
sort完之后，判断first是否比前一个的pre大
如果是，len++，当前second为pre
如果否，pre为pre和当前second的min
*/

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end());
		int res = 0;
		int pre;
		for (int i = 0; i < pairs.size(); i++) {
			if (0 == i || pairs[i][0] > pre) {
				res++;
				pre = pairs[i][1];
			}
			else pre = min(pre, pairs[i][1]);
		}
		return res;
	}
};