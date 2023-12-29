#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the ith rectangle.
Find the total area covered by all rectangles in the plane.  Since the answer may be too large, return it modulo 10^9 + 7.
Note:
1 <= rectangles.length <= 200
rectanges[i].length = 4
0 <= rectangles[i][j] <= 10^9
The total area covered by all rectangles will never exceed 2^63 - 1 and thus will fit in a 64-bit signed integer.

Example 1:
Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
Output: 6
Explanation: As illustrated in the picture.
Example 2:
Input: [[0,0,1000000000,1000000000]]
Output: 49
Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 = (-7)^2 = 49.

解题思路：
扫描y轴，x轴range计算面积
O(n^2)
*/

class Solution {
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		vector<vector<int>> scan;
		for (auto i : rectangles) { //1为矩形下起始，-1为矩形上结束
			scan.push_back({ i[1], i[0], i[2], 1 });
			scan.push_back({ i[3], i[0], i[2], -1 });
		}
		sort(scan.begin(), scan.end());

		long long area = 0;
		map<pair<int, int>, int> range; //key为x轴range，为方便计算总range，排序处理
		int pre_y = 0;
		for (auto i : scan) {
			if (i[0] != pre_y) {
				pair<int, int> pre_x = { -1, -1 };
				long long x_range = 0;
				for (auto it = range.begin(); it != range.end(); it++) {
					if (it->second > 0 && it->first.second > pre_x.second) {
						x_range += it->first.second - max(it->first.first, pre_x.second);
						pre_x = it->first;
					}
				} //计算当前y层x轴总覆盖range
				area = (area + (i[0] - pre_y) * x_range % 1000000007) % 1000000007;
				pre_y = i[0];
			}
			range[{i[1], i[2]}] += i[3]; //更新range开始/结束
		}
		return area;
	}
};