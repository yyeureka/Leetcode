#include "head.h"

/*
Merge two sorted (ascending) lists of interval and return it as a new sorted list. The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.

Example1
Input: list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)]
Output: [(1,4),(5,6)]
Explanation:
(1,2),(2,3),(3,4) --> (1,4)
(5,6) --> (5,6)
Example2
Input: list1 = [(1,2),(3,4)] and list2 = [(4,5),(6,7)]
Output: [(1,2),(3,5),(6,7)]
Explanation:
(1,2) --> (1,2)
(3,4),(4,5) --> (3,5)
(6,7) --> (6,7)

Notice
The intervals in the given list do not overlap.
The intervals in different lists may overlap.
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
	vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
		if (list1.empty()) {
			return list2;
		}
		if (list2.empty()) {
			return list1;
		}

		vector<Interval> result;
		int i = 0;
		int j = 0;

		while (i < list1.size() || j < list2.size()) {
			if (j >= list2.size() || list1[i].start < list2[j].start) {
				if (result.empty() || list1[i].start > result.back().end) {
					result.push_back(list1[i]);
				}
				else if (list1[i].end > result.back().end) {
					result.back().end = list1[i].end;
				}

				i++;
			}
			else {
				if (result.empty() || list2[j].start > result.back().end) {
					result.push_back(list2[j]);
				}
				else if (list2[j].end > result.back().end) {
					result.back().end = list2[j].end;
				}

				j++;
			}
		}

		return result;
	}
};