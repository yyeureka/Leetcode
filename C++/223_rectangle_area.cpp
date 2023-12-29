#include <algorithm>
using namespace std;

/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Note:
Assume that the total area is never beyond the maximum possible value of int.

Example:
Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45

解题思路：
方法很简单，两个rec的area和-overlap的area
虽然结果不会overflow，但过程变量会！！！
解体的关键变为，如何不使用long long得到结果：
1、right-left时可能overflow，先比较后再减
2、计算两个rec area和时可能overflow，先减overlap再加另外一个
*/

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int left = max(A, E);
		int bottom = max(B, F);
		int right = max(min(C, G), left);
		int top = max(min(D, H), bottom);

		return (C - A) * (D - B) - (right - left) * (top - bottom) + (G - E) * (H - F);
	}
};

//class Solution {
//public:
//	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
//		long long total = (long long)(C - A) * (D - B) + (G - E) * (H - F); //各种overflow
//
//		long long width = (long long)min(C, G) - max(A, E); //各种overflow
//		long long height = (long long)min(D, H) - max(B, F);
//		if (width > 0 && height > 0) total -= width * height;
//
//		return total;
//	}
//};