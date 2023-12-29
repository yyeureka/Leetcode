/*
The trapezoidal area calculation formula is (a + b) * h / 2; Now given a, b, h. Return the area of the trapezoid¡£

Example 1£º
Input : a = 2, b = 4, h = 4
Output : 12
Explanation£ºarea = (2 + 4) * 4 / 2 = 12
Example 2:
Input : a = 4, b = 6, h = 2
Output : 10
Explanation£ºarea = (4 + 6) * 2 / 2 = 10

Notice
The type of area is double
*/

class Solution {
public:
	double AreaOfTrapezoid(int a, int b, int h) {
		return ((double)h / 2) * (a + b);
	}
};