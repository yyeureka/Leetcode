#include <vector>
#include <algorithm>
using namespace std;

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Example:
Input: [2,1,5,6,2,3]
Output: 10

解题思路：
单调栈
数组idx记录递增heights的index，当前height[i]较小时，将idx中大于height[i]的height计算area并pop出来
*/

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.empty()) {
			return 0;
		}

		int maxArea = INT_MIN;
		vector<int> index = { -1 };  //计算最小height

		for (int i = 0; i <= height.size(); i++) {
			int h = i < height.size() ? height[i] : -1;  //确保所有height都计算面积

			while (index.size() > 1 && h < height[index.back()]) {
				int pre_h = height[index.back()];
				index.pop_back();

				maxArea = max(maxArea, pre_h * (i - index.back() - 1));
			}

			index.push_back(i);
		}

		return maxArea;
	}
};