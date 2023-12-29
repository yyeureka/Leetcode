#include <vector>
#include <set>
#include <xfunctional>
#include <queue>
using namespace std;

/*
Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. Buildings may overlap if you see them from far away，find the outline of them。
An outline can be represented by a triple, (start, end, height), where start is the start position on x-axis of the outline, end is the end position on x-axis and height is the height of the outline.
Please merge the adjacent outlines if they have the same height and make sure different outlines cant overlap on x-axis.

Example 1
Input:
[
[1, 3, 3],
[2, 4, 4],
[5, 6, 1]
]
Output:
[
[1, 2, 3],
[2, 4, 4],
[5, 6, 1]
]
Example 2
Input:
[
[1, 4, 3],
[6, 9, 5]
]
Output:
[
[1, 4, 3],
[6, 9, 5]
]

解题思路：类似218
*/

class Solution {
public:
	/**
	* @param buildings: A list of lists of integers
	* @return: Find the outline of those buildings
	*/
	vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
		vector<vector<int>> res;
		if (buildings.empty()) return res;

		vector<pair<int, int>> skyline; //idx:height
		for (auto i : buildings) {
			skyline.push_back({ i[0], i[2] });
			skyline.push_back({ i[1], -i[2] });
		}
		sort(skyline.begin(), skyline.end(), [](pair<int, int>a, pair<int, int>b) {
			if (a.first == b.first) return a.second > b.second;
			else return a.first < b.first;
		});

		multiset<int, greater<int>> s;
		int pre = 0;
		vector<int> v(3, 0);
		for (auto i : skyline) {
			if (i.second > 0) s.insert(i.second);
			else s.erase(s.find(-i.second));

			int cur = *s.begin();
			if (pre != cur) {
				if (pre) {
					v[1] = i.first;
					res.push_back(v);
				}
				if (cur) {
					v[0] = i.first;
					v[2] = cur;
				}
				pre = cur;
			}
		}
		return res;
	}
};