#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
Note:
You can assume that you can always reach the last index.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.

解题思路：
greedy
起始start为1，end为nums[0]
依次检查里面的num
如果有能到target的，return，如果没有，start为end+1，end为下一跳最远的index，重复步骤1
*/

class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0;
		int end = 0;
		int next_end = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			next_end = max(next_end, i + nums[i]);
			if (i == end) {
				step++;
				if (next_end >= nums.size() - 1) break;
				end = next_end;
			}
		}
		return step;
	}
};

//class Solution {
//public:
//	int jump(vector<int>& nums) {
//		int step = 0;
//		int start = 0;
//		int end = 0;
//		while (end < nums.size() - 1) {
//			step++;
//			int next_end = 0;
//			for (int i = start; i <= end; i++) {
//				next_end = max(next_end, i + nums[i]);
//				if (next_end >= nums.size() - 1) break;
//			}
//			start = end + 1;
//			end = next_end;
//		}
//		return step;
//	}
//};