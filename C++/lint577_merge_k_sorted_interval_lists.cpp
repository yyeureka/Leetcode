#include "head.h"

/*
Merge K sorted interval lists into one sorted interval list. You need to merge overlapping intervals too.

Example1
Input: [
[(1,3),(4,7),(6,8)],
[(1,2),(9,10)]
]
Output: [(1,3),(4,8),(9,10)]
Example2
Input: [
[(1,2),(5,6)],
[(3,4),(7,8)]
]
Output: [(1,2),(3,4),(5,6),(7,8)]

解题思路：类似lint486
priority_queue
merge sort
*/

class Interval{
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

class Solution {
public:
	vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
		if (intervals.empty()) {
			return{};
		}

		return mergeSort(intervals, 0, intervals.size() - 1);
	}

	vector<Interval> mergeSort(vector<vector<Interval>> &intervals, int start, int end) {
		if (start >= end) {
			return intervals[start];
		}

		int mid = (start + end) / 2;
		vector<Interval> left = mergeSort(intervals, start, mid);
		vector<Interval> right = mergeSort(intervals, mid + 1, end);

		vector<Interval> result;
		int i = 0;
		int j = 0;

		while (i < left.size() || j < right.size()) {
			if (i >= left.size()) {
				merge(result, right[j]);
				j++;
			}
			else if (j >= right.size()) {
				merge(result, left[i]);
				i++;
			}
			else if (left[i].start < right[j].start) {
				merge(result, left[i]);
				i++;
			}
			else {
				merge(result, right[j]);
				j++;
			}
		}


		return result;
	}

	void merge(vector<Interval> &result, Interval a) {
		if (result.empty() || a.start > result.back().end) {
			result.push_back(a);
		}
		else {
			result.back().end = max(result.back().end, a.end);
		}
	}
};