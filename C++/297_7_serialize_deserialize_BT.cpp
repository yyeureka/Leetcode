#include "head.h"

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example:
You may serialize the following tree:
1
/ \
2   3
/ \
4   5
as "[1,2,3,null,null,4,5]"

Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

解题思路：不分层BFS
*/



class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (NULL == root) return "#";

		string res = "";
		vector<TreeNode *> v;
		v.push_back(root); //超级坑 用queue会TLE
		for (int i = 0; i < v.size(); i++) {
			TreeNode * cur = v[i];

			if (NULL == cur) res += "#,";
			else {
				res += to_string(cur->val) + ","; //to_string易错
				v.push_back(cur->left);
				v.push_back(cur->right);
			}
		}
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if ("#" == data) return NULL; //易错

		TreeNode* res = new TreeNode(0);
		queue<TreeNode*> q;
		q.push(res);
		bool is_left = 0;
		int i = 0;
		while (i < data.size()) {
			if (',' == data[i]) {
				i++;
				continue;
			}
			else if ('#' == data[i]) i++;
			else {
				int sign = 1;
				if ('-' == data[i]) { //非常贱，val可能是负数
					sign = -1;
					i++;
				}
				else if ('+' == data[i]) i++;

				int num = 0;
				while (i < data.size() && data[i] >= '0' && data[i] <= '9') {
					num = num * 10 + data[i] - '0';
					i++;
				}
				num *= sign;

				TreeNode* cur = new TreeNode(num);
				if (is_left) q.front()->left = cur;
				else q.front()->right = cur;

				q.push(cur);
			}

			if (!is_left) q.pop();
			is_left = !is_left;
		}
		return res->right;
	}
};