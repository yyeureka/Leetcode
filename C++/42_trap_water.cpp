#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
public:
	int trap(vector<int>& height) {
		int res = 0;
		int i = 0;
		int j = height.size() - 1;
		while (j > i)
		{
			int h = min(height[i], height[j]);
			while ((j > i) && (height[i] <= h))
			{
				if (height[i] < h)
				{
					res += (h - height[i]);
				}
				i++;
			}
			while ((j > i) && (height[j] <= h))
			{
				if (height[j] < h)
				{
					res += (h - height[j]);
				}
				j--;
			}
		}
		return res;
	}
};

//void main()
//{
//	vector <int> height = {4,2,3};
//	Solution s;
//	cout << s.trap(height) << endl;
//}