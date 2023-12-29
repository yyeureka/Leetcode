#include <vector>
#include <algorithm>
using namespace std;

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

解题思路：
先对intervals的start进行sort
只需要比较res中最后一个Interval的end和每一个start
res.back().end < intervals[i].start，不重叠，将intervals[i]加进res
否则重叠，更新res.back().end = max(res.back().end, intervals[i].end)
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size() < 2) return intervals;

		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; }); // 这里用<=会内存出错，暂不清楚原因
		vector<Interval> res(1, Interval(intervals[0].start, intervals[0].end));

		for (int i = 1; i < intervals.size(); i++)
		{
			if (res.back().end < intervals[i].start)
			{
				res.push_back(intervals[i]);
			}
			else
			{
				res.back().end = max(res.back().end, intervals[i].end);
			}
		}

		return res;
	}
};