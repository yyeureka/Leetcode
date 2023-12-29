#include "head.h"

/*
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Example1
Input:
[3,2,2,1,4]
4
Output:
[1,2,2,3,4]
Example2
Input:
[2,1,1,2,2]
2
Output:
[1,1,2,2,2]

Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?

Notice
You are not suppose to use the library's sort function for this problem.
k <= n

解题思路：
quicksort，先将1~k parition为1~k/2 k/2+1~k，再分别对两边同样处理
*/

class Solution {
public:
	void sortColors2(vector<int> &colors, int k) {
		return quickSort(colors, 0, colors.size() - 1, 1, k);
	}

	void quickSort(vector<int> &colors, int start, int end, int colorStart, int colorEnd) {
		if (start >= end || colorStart >= colorEnd) return;

		int i = start;
		int j = end;
		int mid = colorStart + (colorEnd - colorStart) / 2;

		while (i <= j) {
			while (i <= j && colors[i] <= mid) i++; //易错
			while (i <= j && colors[j] > mid) j--;

			if (i <= j) swap(colors[i++], colors[j--]);
		}

		quickSort(colors, start, j, colorStart, mid);
		quickSort(colors, i, end, mid + 1, colorEnd);
	}
};