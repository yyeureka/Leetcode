#include "head.h"

/*
There are k sorted arrays nums. Find the median of the given k sorted arrays.

Example 1:
Input:
[[1],[2],[3]]
Output:
2.00
Example 2:
Input:
[[1,1,2],[2,4,8],[3,7,10,20]]
Output:
3.50

Notice
The length of the given arrays may not equal to each other.
The elements of the given arrays are all positive number.
Return 0 if there are no elements in the array.
In order to ensure time complexity, the program will be executed repeatedly.

解题思路：kth+binary search
以总数N为例，在所有array中找第N/2个
*/

class Solution {
public:
	double findMedian(vector<vector<int>> &nums) {
		int count = 0;
		int top = INT_MIN;
		int bottom = INT_MAX;
		for (auto i : nums) {
			if (i.empty()) { //易错，可能有array为空
				continue;
			}

			count += i.size();
			top = max(top, i.back());
			bottom = min(bottom, i[0]);
		}

		if (0 == count) {
			return 0.0;
		}
		else if (count & 1) {
			return findKth(nums, count / 2 + 1, top, bottom);
		}
		return (findKth(nums, count / 2, top, bottom) + findKth(nums, count / 2 + 1, top, bottom)) / 2.0;
	}

	double findKth(vector<vector<int>> &nums, int k, int end, int start) {
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (getLTE(nums, mid) < k) { //易错 =的时候target可能更小
				start = mid;
			}
			else {
				end = mid;
			}
		}

		if (k == getLTE(nums, start)) {
			return start;
		}
		return end;
	}

	int getLTE(vector<vector<int>> &nums, int target) {
		int count = 0;

		for (auto i : nums) {
			if (i.empty()) { //易错，可能有array为空
				continue;
			}

			int start = 0;
			int end = i.size() - 1;

			while (start + 1 < end) {
				int mid = start + (end - start) / 2;

				if (i[mid] <= target) {
					start = mid;
				}
				else {
					end = mid;
				}
			}

			if (i[end] <= target) {
				count += end + 1;
			}
			else if (i[start] <= target) {
				count += start + 1;
			}
		}

		return count;
	}
};