#include "head.h"

/*
Give a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
Find the maximum number of nested layers of envelopes.

Example 1:
Input：[[5,4],[6,4],[6,7],[2,3]]
Output：3
Explanation：
the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:
Input：[[4,5],[4,6],[6,7],[2,3],[1,1]]
Output：4

Explanation：
the maximum number of envelopes you can Russian doll is 4 ([1,1] => [2,3] => [4,5] / [4,6] => [6,7]).

解题思路：#300换汤不换药
1、binary search
2、dp，会TLE！
*/

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	return a.second > b.second; //关键，只要比较second是否递增就能判断整体递增
}

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.empty()) {
			return 0;
		}

		vector<pair<int, int>> lis;
		sort(envelopes.begin(), envelopes.end(), cmp);

		for (int i = 0; i < envelopes.size(); i++) {
			if (lis.empty() || envelopes[i].second > lis.back().second) {
				lis.push_back(envelopes[i]);
			}
			else {
				int index = lowerBound(lis, envelopes[i]);
				lis[index] = envelopes[i];
			}
		}

		return lis.size();
	}

	int lowerBound(vector<pair<int, int>> &lis, pair<int, int> &target) {
		int start = 0;
		int end = lis.size() - 1;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (lis[mid].second >= target.second) {
				end = mid;
			}
			else {
				start = mid;
			}
		}

		if (lis[start].second >= target.second) {
			return start;
		}
		return end;
	}
};

//dp
//bool cmp(pair<int, int> a, pair<int, int> b) {
//	if (a.first != b.first) {
//		return a.first < b.first;
//	}
//	return a.second < b.second;
//}
//
//class Solution {
//public:
//	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
//		if (envelopes.empty()) {
//			return 0;
//		}
//
//		int maxNum = INT_MIN;
//		vector<int> dp(envelopes.size(), 1);
//
//		sort(envelopes.begin(), envelopes.end(), cmp);
//
//		for (int i = 0; i < envelopes.size(); i++) {
//			for (int j = 0; j < i; j++) {
//				if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second && dp[j] + 1 > dp[i]) {
//					dp[i] = dp[j] + 1;
//				}
//			}
//
//			maxNum = max(maxNum, dp[i]);
//		}
//
//		return maxNum;
//	}
//};