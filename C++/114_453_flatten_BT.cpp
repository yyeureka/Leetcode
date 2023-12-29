#include "head.h"

/*
Flatten a binary tree to a fake "linked list" in pre-order traversal.
Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example 1:
Input:{1,2,5,3,4,#,6}
Output：{1,#,2,#,3,#,4,#,5,#,6}
Explanation：
1
/ \
2   5
/ \   \
3   4   6

1
\
2
\
3
\
4
\
5
\
6
Example 2:
Input:{1}
Output:{1}
Explanation：
1
1

Challenge
Do it in-place without any extra memory.

Notice
Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.

1、divide&conquer，O(1)memory
2、iterative traverse，类似preorder traversal，O(n)memory
3、recursive traverse，O(1)memory，非常易错，且逻辑比较绕
*/

class Solution {
public:
	void flatten(TreeNode * root) {
		if (NULL == root) return;

		helper(root);
	}

	TreeNode * helper(TreeNode * root) { //返回最后一个node
		if (NULL == root) return NULL;

		TreeNode * leftLast = helper(root->left);
		TreeNode * rightLast = helper(root->right);

		if (leftLast) {
			leftLast->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}

		if (rightLast) return rightLast;
		if (leftLast) return leftLast;
		return root;
	}
};

////iterative traverse
//class Solution {
//public:
//	void flatten(TreeNode * root) {
//		if (NULL == root) return;
//
//		stack<TreeNode *> s;
//		s.push(root);
//
//		while (!s.empty()) {
//			root = s.top();
//			s.pop();
//
//			if (root->right) s.push(root->right);
//			if (root->left) s.push(root->left);
//
//			if (!s.empty()) root->right = s.top(); //易错，最后一个node时s是空的
//			root->left = NULL;
//		}
//	}
//};

//recursive traverse
//class Solution {
//public:
//	void dfs(TreeNode * root, TreeNode * &last) {
//		if (NULL == root) return;
//
//		if (last) {
//			last->left = NULL;
//			last->right = root;
//		}
//
//		last = root;
//		TreeNode * right = root->right; //易错
//		dfs(root->left, last);
//		dfs(right, last);
//	}
//
//	void flatten(TreeNode * root) {
//		TreeNode * last = NULL;
//		dfs(root, last);
//	}
//};