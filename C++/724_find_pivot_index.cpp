#include <vector>
using namespace std;

/*
Given an array of integers nums, write a method that returns the "pivot" index of this array.
We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
Note:
The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].

Example 1:
Input:
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input:
nums = [1, 2, 3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

解题思路：
1、total_sum - nums[i] = 2 * left_sum
   第一次遍历，得到total_sum
   第二次遍历，如满足上面条件，即找到，若不满足，left_sum += nums[i]继续
2、intuitive，left和right vector，左边的sum放在left里，右边的sum放在right里，比较left和right
*/

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sum = 0;
		for (int i : nums) sum += i;
		int left_sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (left_sum * 2 == sum - nums[i]) return i;
			left_sum += nums[i];
		}
		return -1;
	}
};

//class Solution {
//public:
//	int pivotIndex(vector<int>& nums) {
//		int n = nums.size();
//		vector<int> left(n, 0);
//		vector<int> right(n, 0);
//		for (int i = 0; i < n - 1; i++) {
//			left[i + 1] = left[i] + nums[i];
//			right[n - i - 2] = right[n - i - 1] + nums[n - i - 1];
//		}
//		for (int i = 0; i < n; i++) {
//			if (left[i] == right[i]) return i;
//		}
//		return -1;
//	}
//};