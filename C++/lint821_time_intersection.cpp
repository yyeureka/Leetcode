#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Give two users' ordered online time series, and each section records the user's login time point x and offline time point y. Find out the time periods when both users are online at the same time, and output in ascending order.
Notice
We guarantee that the length of online time series meet 1 <= len <= 1e6.
For a user's online time series, any two of its sections do not intersect.

Example
Example 1:
Input: seqA = [(1,2),(5,100)], seqB = [(1,6)]
Output: [(1,2),(5,6)]
Explanation: In these two time periods (1,2), (5,6), both users are online at the same time.
Example 2:
Input: seqA = [(1,2),(10,15)], seqB = [(3,5),(7,9)]
Output: []
Explanation: There is no time period, both users are online at the same time.

解题思路：line sweep
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	/**
	* @param intervals: an array of meeting time intervals
	* @return: the minimum number of conference rooms required
	*/
	vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
		map<int, int> m;
		for (auto i : seqA) {
			m[i.start]++;
			m[i.end]--;
		}
		for (auto i : seqB) {
			m[i.start]++;
			m[i.end]--;
		}

		vector<Interval> res;
		Interval cur(0, 0);
		int user = 0;
		for (auto i : m) {
			user += i.second;
			if (2 == user) {
				if (!cur.start) cur.start = i.first;
			}
			else {
				if (cur.start) {
					cur.end = i.first;
					res.push_back(cur);
					cur = { 0, 0 };
				}
			}
		}
		return res;
	}
};

//void main() {
//	Solution s;
//	vector<Interval> seqA = { { 1,10 }};
//	vector<Interval> seqB = { { 2,11 }};
//	vector<Interval> res = s.timeIntersection(seqA, seqB);
//	for (auto i : res) {
//		cout << i.start << "~" << i.end << endl;
//	}
//};