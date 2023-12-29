#include <vector>
#include <string>
using namespace std;

/*
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.
Note:
1 <= tiles.length <= 7
tiles consists of uppercase English letters.

Example 1:
Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:
Input: "AAABBC"
Output: 188

解题思路：
不把string列出来，只是count可能性
以AAB为例：
第一层for循环count一个元素的情况
第二层for循环count两个元素的情况
第三层for循环count三个元素的情况
   A     B
 AA AB   BA 
AAB ABA  BAA
*/

class Solution {
public:
	int numTilePossibilities(string tiles) {
		vector<int> cnt(26, 0);
		for (char c : tiles) cnt[c - 'A']++;
		return dfs(cnt);
	}

	int dfs(vector<int> &cnt) {
		int res = 0;
		for (int i = 0; i < 26; i++) {
			if (!cnt[i]) continue;

			res++;
			cnt[i]--;
			res += dfs(cnt);
			cnt[i]++;
		}
		return res;
	}
};