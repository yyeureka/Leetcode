#include "head.h"

/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

Notice
1.Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
2.Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
3.As long as a house is in the heaters' warm radius range, it can be warmed.
4.All the heaters follow your radius standard and the warm radius will the same.

解题思路：
先sort heaters
对每一个点，找到heater最近的distance
max所有distance
*/

class Solution {
public:
	int findRadius(vector<int> &houses, vector<int> &heaters) {
		if (heaters.empty()) {
			return INT_MAX;
		}

		sort(heaters.begin(), heaters.end()); //易错，要bs，先要sort

		int radius = INT_MIN;

		for (int i : houses) {
			int distance = findHeater(heaters, i);
			radius = max(radius, distance);
		}

		return radius;
	}

	int findHeater(vector<int> &heaters, int target) {
		int start = 0;
		int end = heaters.size() - 1;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;

			if (heaters[mid] == target) {
				return 0;
			}
			else if (heaters[mid] > target) {
				end = mid;
			}
			else {
				start = mid;
			}
		}

		return min(abs(target - heaters[start]), abs(target - heaters[end]));
	}
};