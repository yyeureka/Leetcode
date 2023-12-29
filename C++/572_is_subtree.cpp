#include <iostream>
using namespace std;

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:
3
/ \
4   5
/ \
1   2
Given tree t:
4
/ \
1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:
3
/ \
4   5
/ \
1   2
/
0
Given tree t:
4
/ \
1   2
Return false.

解题思路：recursive pre-order遍历各node是否为same tree
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (NULL == t || NULL == s) return false;
		if (isSame(s, t)) return true;
		else return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool isSame(TreeNode* s, TreeNode* t) {
		if (NULL == t && NULL == s) return true;
		else if (NULL == t || NULL == s) return false;
		return (s->val == t->val) && isSame(s->left, t->left) && isSame(s->right, t->right);
	}
};