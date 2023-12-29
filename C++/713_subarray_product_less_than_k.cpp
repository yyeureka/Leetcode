#include <vector>
using namespace std;

/*
Your are given an array of positive integers nums.
Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
Note:
0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

解题思路：同向双指针法
r指针从0开始依次往product里乘
l从0开始
while product>=k，从product中除掉l
从l到r，以r结尾的subarray个数为r-l+1

特殊用例：
k小于nums中任一个数
nums中均为1，所有的乘积小于k
*/

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int res = 0;
		int product = 1;
		int l = 0;
		for (int r = 0; r < nums.size(); r++) {
			product *= nums[r];
			while (l <= r && product >= k) {
				product /= nums[l++];
			}
			res += r - l + 1;
		}
		return res;
	}
};