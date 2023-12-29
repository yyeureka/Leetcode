#include <vector>
using namespace std;

/*
Your music player contains N different songs and she wants to listen to L (not necessarily different) songs during your trip.  You create a playlist so that:
Every song is played at least once
A song can only be played again only if K other songs have been played
Return the number of possible playlists.  As the answer can be very large, return it modulo 10^9 + 7.
Note:
0 <= K < N <= L <= 100

Example 1:
Input: N = 3, L = 3, K = 1
Output: 6
Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
Example 2:
Input: N = 2, L = 3, K = 0
Output: 6
Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
Example 3:
Input: N = 2, L = 3, K = 1
Output: 2
Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]

解题思路：dp，O(np)
dp[i][j]表示使用j首歌来生成前i首歌
1.第i首歌跟前(i-1)首都不一样，可以先使用(j-1)首歌排好前(i-1)首歌，剩下的(n-(j-1))任取一首，放在i位置，即：
dp[i][j] += dp[i-1][j-1] * (n - (j - 1))
2.第i首歌跟前(i-1)首存在重复，可以先使用j首歌排好前(i-1)首歌，因为保证任意两首相同的歌之间至少有m首不同的歌，
故对于dp[i-1][j]里面的方案，最后的m首歌一定不一样，选一首跟最后m首歌不一样的歌，放在i位置，即：
dp[i][j] += dp[i-1][j] * (j - m)
初始条件：dp[0][0] = 1
返回：dp[p][n]
*/

class Solution {
public:
	int numMusicPlaylists(int N, int L, int K) {
		int mod = 1000000007;
		vector<vector<long long>> v(L + 1, vector<long long>(N + 1, 0));
		v[0][0] = 1;

		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= N; j++) {
				v[i][j] = (v[i - 1][j - 1] * (N - j + 1)) % mod;
				if (j > K) v[i][j] = (v[i][j] + (v[i - 1][j] * (j - K)) % mod) % mod;
			}
		}
		return v[L][N];
	}
};