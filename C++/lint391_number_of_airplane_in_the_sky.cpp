﻿#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
Given an list interval, which are taking off and landing time of the flight. How many airplanes are there at most at the same time in the sky?
Notes:
If landing and taking off of different planes happen at the same time, we consider landing should happen at first.

Example 1:
Input: [(1, 10), (2, 3), (5, 8), (4, 7)]
Output: 3
Explanation:
The first airplane takes off at 1 and lands at 10.
The second ariplane takes off at 2 and lands at 3.
The third ariplane takes off at 5 and lands at 8.
The forth ariplane takes off at 4 and lands at 7.
During 5 to 6, there are three airplanes in the sky.
Example 2:
Input: [(1, 2), (2, 3), (3, 4)]
Output: 1
Explanation: Landing happen before taking off.

解题思路：跟lint919一毛一样
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
	* @param airplanes: An interval array
	* @return: Count of airplanes are in the sky.
	*/
	int countOfAirplanes(vector<Interval> &airplanes) {
		map<int, int> m;
		for (auto i : airplanes) {
			m[i.start]++;
			m[i.end]--;
		}

		int res = 0;
		int plane = 0;
		for (auto i : m) {
			plane += i.second;
			res = max(res, plane);
		}
		return res;
	}
};