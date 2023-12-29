#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:
Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
Example 2:
Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

解题思路：
对points中每一个i，map记录i与之后每一个points的斜率及相同斜率的个数，更新res
注意：
1、可能会有overlap的点
2、slope本来用(double)y/x就可以了（注意x=0特殊操作），但有用例两个不同的slope差异超出double的精度导致错误
*/

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.empty()) return 0;

		int res = 0;
		for (int i = 0; i < points.size(); i++) {
			unordered_map<string, int> m;
			int overlap = 1; //重合点
			int horiz = 0;	 //水平线
			int verti = 0;	 //垂直线
			int cur_max = 0;
			for (int j = i + 1; j < points.size(); j++) {
				int x = points[j][0] - points[i][0];
				int y = points[j][1] - points[i][1];
				if (!x && !y) overlap++;
				else if (!y) cur_max = max(cur_max, ++horiz);
				else if (!x) cur_max = max(cur_max, ++verti);
				else {
					int gcd = getGCD(x, y);
					x /= gcd;
					y /= gcd;
					cur_max = max(cur_max, ++m[to_string(x) + to_string(y)]);
				}
			}
			res = max(res, cur_max + overlap);
		}
		return res;
	}

	int getGCD(int x, int y) {
		while (y) {
			int tmp = x % y;
			x = y;
			y = tmp;
		}
		return x;
	}
};

//class Solution {
//public:
//	int maxPoints(vector<vector<int>>& points) {
//		if (points.empty()) return 0;
//
//		int res = 0;
//		for (int i = 0; i < points.size(); i++) {
//			unordered_map<double, int> m;
//			int overlap = 1;
//			int cur_max = 0;
//			for (int j = i + 1; j < points.size(); j++) {
//				int x = points[j][0] - points[i][0];
//				int y = points[j][1] - points[i][1];
//				if (!x && !y) {
//					overlap++;
//					continue;
//				}
//				else if (!x) cur_max = max(cur_max, ++m[INT_MAX]); //垂直斜率
//				else cur_max = max(cur_max, ++m[(double)y / x]); //double精度不够
//			}
//			res = max(res, cur_max + overlap);
//		}
//		return res;
//	}
//};