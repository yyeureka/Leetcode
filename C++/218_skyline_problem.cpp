#include <vector>
#include <set>
#include <algorithm>
#include <xfunctional>
using namespace std;

/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
Notes:
The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]

解题思路：line sweep+multiset
1、将每栋楼的起始点和高度存进vector：{i,h}，{j,-h}
2、sort vector，坐标不相等时以坐标从小到大排，坐标相等时以高度从大到小排
3、遍历vector，当高度>0时，存进multiset，否则从multiset中删除-高度
   从multiset中获取当前高度，当前高度和pre不同时，即为key points将坐标和当前高度存进res
*/

bool cmp(vector<int> a, vector<int> b) {
	if (a[0] != b[0]) return a[0] < b[0];
	return a[1] > b[1];
}

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		if (buildings.empty()) return{};

		vector<vector<int>> v;
		for (auto i : buildings) {
			v.push_back({ i[0], i[2] });
			v.push_back({ i[1], -i[2] });
		}
		sort(v.begin(), v.end(), cmp);

		vector<vector<int>> res;
		int pre = 0;
		multiset<int, greater<int>> s;
		for (auto i : v) {
			if (i[1] > 0) s.insert(i[1]);
			else s.erase(s.find(-i[1])); // s.erase(-i[1])会把所有该值都删掉

			int cur = *s.begin();
			if (pre != cur) {
				res.push_back({ i[0], cur });
				pre = cur;
			}
		}
		return res;
	}
};