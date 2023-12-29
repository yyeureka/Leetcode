#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

Example1
Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)
Example2
Input: intervals = [(2,7)]
Output: 1
Explanation:
Only need one meeting room

解题思路：
1、扫描线法
   对于每个interval，起始时间++，结束时间--，全部存进map
   将这些value依次累加，最大值即为结果
2、直接粗暴，将intervals根据start从小到大sort，res保存每个会议室的区间，
   遍历intervals，res中找到可用会议室，则更新那个会议室时间，未找到，添加新的会议室，结果返回res的size
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
	int minMeetingRooms(vector<Interval> &intervals) {
		int res;
		int room = 0;
		map<int, int> m;
		for (Interval i : intervals) {
			m[i.start]++;
			m[i.end]--;
		}
		for (auto j : m) {
			res = max(res, room += j.second);
		}
		return res;
	}
};

//class Solution {
//public:
//	/**
//	* @param intervals: an array of meeting time intervals
//	* @return: the minimum number of conference rooms required
//	*/
//	int minMeetingRooms(vector<Interval> &intervals) {
//		vector<Interval> res;
//		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
//		for (int i = 0; i < intervals.size(); i++) {
//			bool found = false;
//			for (int j = res.size() - 1; j >= 0; j--) {
//				if (intervals[i].start >= res[j].end) {
//					res[j] = intervals[i];
//					found = true;
//					break;
//				}
//			}
//			if (!found) res.push_back(intervals[i]);
//		}
//		return res.size();
//	}
//};

