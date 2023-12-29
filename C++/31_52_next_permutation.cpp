#include <vector>
using namespace std;

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

解题思路：
找到最大的index i：nums[i] < nums[i + 1]
找到最大的index j：nums[j] > nums[i]，swap(nums[j], nums[i])——剩下的数中大于nums[i]的min
reverse i+1~n-1
*/

class Solution {
public:
	vector<int> nextPermutation(vector<int> &nums) {
		if (nums.size() <= 1) return nums;

		int i;
		int j;
		for (i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				for (j = nums.size() - 1; j > i; j--) {
					if (nums[j] > nums[i]) {
						swap(nums[j], nums[i]);
						break; //易错
					}
				}
				break; //易错
			}
		}
		//reverse from i+1~n-1
		reverse(nums.begin() + i + 1, nums.end());
		return nums;
	}
};