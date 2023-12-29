#include <vector>
#include <deque>
using namespace std;

/*
Return any binary tree that matches the given preorder and postorder traversals.
Values in the traversals pre and post are distinct positive integers.
Note:
1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

Example 1:
Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

解题思路：
1、preorder中的顶点，在inorder中他左边的为左子树，右边的为右子树，deque+recursive细分
2、[root][......left......][...right..]  ---pre
   [......left......][...right..][root]  ---post
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		if (pre.empty() || post.empty()) return NULL;

		deque<TreeNode*> d;
		d.push_back(new TreeNode(pre[0]));
		for (int i = 1, j = 0; i < pre.size(); i++) {
			TreeNode* node = new TreeNode(pre[i]);
			while (post[j] == d.back()->val) {
				d.pop_back();
				j++;
			}
			if (!d.back()->left) d.back()->left = node;
			else d.back()->right = node;
			d.push_back(node);
		}
		return d.front();
	}
};

//class Solution {
//public:
//	TreeNode* convert(vector<int>& pre, int pre_start, int pre_end, vector<int>& post, int post_start, int post_end) {
//		if (pre_start > pre_end || post_start > post_end) return NULL;
//
//		TreeNode* root = new TreeNode(pre[pre_start]);
//		if (pre_start == pre_end) return root;
//
//		int i;
//		for (i = pre_start + 1; i <= pre_end; i++) {
//			if (pre[i] == post[post_end - 1]) break;
//		}
//		root->left = convert(pre, pre_start + 1, i - 1, post, post_start, post_start + i - pre_start - 2);
//		root->right = convert(pre, i, pre_end, post, post_start + i - pre_start - 1, post_end - 1);
//		return root;
//	}
//
//	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//		return convert(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
//	}
//};