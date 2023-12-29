#include "head.h"

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
0
/ \
-3   9
/   /
-10  5

解题思路：
recursive：start为0，end为size()-1, mid作为node，start到mid-1为左子树，mid+1到end为右子树，以此类推直到start>end
*/

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return convert(nums, 0, nums.size() - 1);
	}

	TreeNode* convert(vector<int>& nums, int start, int end) { //传参&nums比nums高效非常多，不只是要不要修改的考虑
		if (start > end) return NULL;
		if (start == end) return new TreeNode(nums[start]);

		int mid = start + (end - start) / 2;
		TreeNode *node = new TreeNode(nums[mid]);
		node->left = convert(nums, start, mid - 1);
		node->right = convert(nums, mid + 1, end);

		return node;
	}
};