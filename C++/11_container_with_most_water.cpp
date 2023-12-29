#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0; //防止height的size非法，初始值还是0比较安全
		int l = 0;
		int r = height.size() - 1;
		while (l < r) {
			int h = min(height[l], height[r]);
			res = max(res, h * (r - l));
			while (l < r && height[l] <= h) l++;
			while (l < r && height[r] <= h) r--;
		}
		return res;
	}
};

//void main()
//{
//	//vector <int> height = {1,8,6,2,5,4,8,3,7};
//	vector <int> height = { 1,2,4,3 };
//	Solution s;
//	cout << s.maxArea(height) << endl;
//}