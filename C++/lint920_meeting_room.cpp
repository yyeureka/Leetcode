#include <vector>
#include <map>
using namespace std;

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

Example1
Input: intervals = [(0,30),(5,10),(15,20)]
Output: false
Explanation:
(0,30), (5,10) and (0,30),(15,20) will conflict
Example2
Input: intervals = [(5,8),(9,15)]
Output: true
Explanation:
Two times will not conflict

解题思路：
1、扫描线算法，类似lint919
2、将interval根据start进行从小到大sort，遍历所有intervals，如果当前start<上一个的end，false
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
	* @return: if a person could attend all meetings
	*/
	bool canAttendMeetings(vector<Interval> &intervals) {
		map<int, int> m;
		for (auto i : intervals) {
			m[i.start]++;
			m[i.end]--;
		}

		int sum = 0;
		for (auto i : m) {
			sum += i.second;
			if (sum > 1) return false;
		}
		return true;
	}
};

//class Solution {
//public:
//	/**
//	* @param intervals: an array of meeting time intervals
//	* @return: if a person could attend all meetings
//	*/
//	bool canAttendMeetings(vector<Interval> &intervals) {
//		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
//		for (int i = 0; i < intervals.size(); i++) {
//			if (i > 0 && intervals[i].start < intervals[i - 1].end) return false;
//		}
//		return true;
//	}
//};