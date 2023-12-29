#include <vector>
#include <algorithm>
using namespace std;

/*  
Given an integer array, find three numbers whose product is maximum and output the maximum product.
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24

解题思路：
数组是可能有负数的
sort后，返回nums中最大3个值的乘积、最大值和最小2个值的乘积的最大值
*/

#define MAX(a, b)   (a) > (b) ? (a) : (b)

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
	}
};