#include "head.h"

/*
Given a rotated sorted array, recover it to sorted array in-place.��Ascending��

Example1:
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]
Example2:
[6,8,9,1,2] -> [1,2,6,8,9]

Challenge
In-place, O(1) extra space and O(n) time.

Clarification
What is rotated array?
For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]

����˼·��
��������#153�ҵ�min��index����ʹ��������ת��recover
��45612Ϊ��
�ȷ�ת456 �ٷ�ת12 ������巭ת�õ�12456
*/

class Solution {
public:
	void recoverRotatedSortedArray(vector<int> &nums) {
		int start = 0;
		int end = nums.size() - 1;

		while (start + 1 < end) {
			if (nums[start] < nums[end]) break;

			int mid = start + (end - start) / 2;

			if (nums[mid] == nums[end]) start++; //�״�ֵ����unique��
			else if (nums[mid] < nums[end]) end = mid;
			else start = mid;
		}

		start = nums[start] < nums[end] ? start : end;

		reverse(nums.begin(), nums.begin() + start); //�״����ұ�����
		reverse(nums.begin() + start, nums.end());
		reverse(nums.begin(), nums.end());
	}
};
