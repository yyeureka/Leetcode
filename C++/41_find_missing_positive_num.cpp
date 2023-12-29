#include <vector>
#include <algorithm>
using namespace std;

/*
Given an unsorted integer array, find the smallest missing positive integer.
Note:
Your algorithm should run in O(n) time and uses constant extra space.

Example 1:
Input: [1,2,0]
Output: 3
Example 2:
Input: [3,4,-1,1]
Output: 2
Example 3:
Input: [7,8,9,11,12]
Output: 1

解题思路：
1、sort，不知道能不能用，sort平均时间复杂度是O(nlogn)，超过规定的O(n)了，但提交速度超过100%
2、将数字放进对应的位置，如5放进nums[4]中，遍历第二遍的时候，如果哪一位nums[i] != i+1，i+1即为结果
   特殊情况：[]缺的是1，[1,2,3]缺的是4
*/

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		while (i < n) {
			if (i >= 0 && nums[i] == i + 1) i++;  //nums[i]放的是i+1
			else {
				//下标判断，且防止有duplicate的时候死循环
				if ((nums[i] <= 0) || (nums[i] > n) || (nums[nums[i] - 1] == nums[i])) i++;  
				else swap(nums[nums[i] - 1], nums[i]);
			}
		}

		for (i = 0; i < n; i++) {
			if (nums[i] != i + 1) break;  //不能在这里return i + 1，否则不能cover 1~n全满，缺的是n+1的情况
		}
		return i + 1;

		//sort(nums.begin(), nums.end());
		//int res = 1;
		//for (int i = 0; i < nums.size(); i++)
		//{
		//	if (nums[i] == res)
		//	{
		//		res++;
		//	}
		//	else if (nums[i] > res)
		//	{
		//		break;
		//	}
		//}
		//return res;
	}
};