#include <vector>
#include <algorithm> 
using namespace std;

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

解题思路：
2、straitforward，O(n)时间&空间
   先将新的区间插入进去，保持start有序
   合并overlap的区间放进res vector
*/

class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		int i;
		for (i = 0; i < intervals.size(); i++) {
			if (newInterval.start < intervals[i].start) {
				intervals.insert(intervals.begin() + i, newInterval);
				break;
			}
		}
		if (intervals.size() == i) intervals.push_back(newInterval); //易错

		vector<Interval> res;
		for (int i = 0; i < intervals.size(); i++) {
			if (res.empty() || res.back().end < intervals[i].start) { //易错
				res.push_back(intervals[i]);
			}
			else {
				res.back().end = max(res.back().end, intervals[i].end);
			}
		}

		return res;
	}
};