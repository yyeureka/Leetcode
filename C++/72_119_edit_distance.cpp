#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

解题思路：双序列dp
res[m+1][n+1]，res[i][j]为word1中0~i-1变为word2中0~j-1最小次数
i/j为0时表示为空
i-1等于j-1时，结果为保留i-1，删除i-1，在i-1后插入的最小值：res[i][j] = min(res[i-1][j-1], res[i - 1][j] + 1, res[i][j - 1] + 1);
否则，结果为替换i-1，删除i-1，在i-1后插入的最小值：res[i][j] = min(res[i-1][j-1] + 1, res[i - 1][j] + 1, res[i][j - 1] + 1);
*/

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (0 == i) { //易错
					dp[i][j] = j;
				}
				else if (0 == j) {
					dp[i][j] = i;
				}
				else if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j] + 1), dp[i][j - 1] + 1);
				}
				else {
					dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
				}
			}
		}

		return dp[n][m];
	}
};