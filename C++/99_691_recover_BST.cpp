#include "head.h"

/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]

1
/
3
\
2
Output: [3,1,null,null,2]
3
/
1
\
2
Example 2:
Input: [3,1,4,null,null,2]
3
/ \
1   4
/
2
Output: [2,1,4,null,null,3]
2
/ \
1   4
/
3

Follow up:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?

����˼·��
1��inorder traversal����¼������˳�������node��������O(n)ʱ�䣬O(1)�ռ�
2��inorder traversal��������val���޸ĸ�node��val��O(nlogn)ʱ�䣬O(n)�ռ�
3��inorder traversal+bubble sort��˼·������������˳��ľ��������������O(n^2)ʱ�䣬O(n)�ռ�
*/

class Solution {
public:
	TreeNode * bstSwappedNode(TreeNode * root) {
		if (NULL == root) return NULL;

		TreeNode * lastNode = NULL;
		TreeNode * first = NULL;
		TreeNode * second = NULL;
		inorder(root, lastNode, first, second);

		if (first) swap(first->val, second->val); //�״�����Ҫ����ʱ����swap����NULLָ��
		return root;
	}

	void inorder(TreeNode * root, TreeNode * &lastNode, TreeNode * &first, TreeNode * &second) {
		if (NULL == root) return;

		inorder(root->left, lastNode, first, second);

		if (lastNode && lastNode->val > root->val) {
			if (NULL == first) first = lastNode; //�״����������������node�����µ�����
			second = root;
		}
		lastNode = root;

		inorder(root->right, lastNode, first, second);
	}
};

////sort
//class Solution {
//public:
//	TreeNode * bstSwappedNode(TreeNode * root) {
//		if (NULL == root) return NULL;
//
//		vector<TreeNode *> nodes;
//		vector<int> vals;
//		inorder(root, nodes, vals);
//
//		sort(vals.begin(), vals.end());
//		for (int i = 0; i < nodes.size(); i++) {
//			nodes[i]->val = vals[i];
//		}
//
//		return root;
//	}
//
//	void inorder(TreeNode * root, vector<TreeNode *> &nodes, vector<int> &vals) {
//		if (NULL == root) return;
//
//		inorder(root->left, nodes, vals);
//		nodes.push_back(root);
//		vals.push_back(root->val);
//		inorder(root->right, nodes, vals);
//	}
//};

//bubble sort
//class Solution {
//public:
//	TreeNode * bstSwappedNode(TreeNode * root) {
//		if (NULL == root) return NULL;
//
//		bool change = true;
//
//		while (change) {
//			change = false;
//
//			stack<TreeNode *> s;
//			TreeNode * node = root;
//			TreeNode * lastNode = NULL;
//
//			while (node || !s.empty()) {
//				while (node) {
//					s.push(node);
//					node = node->left;
//				}
//
//				node = s.top();
//				s.pop();
//
//				if (lastNode && lastNode->val > node->val) {
//					swap(lastNode->val, node->val);
//					change = true;
//				}
//				lastNode = node;
//
//				node = node->right;
//			}
//		}
//
//		return root;
//	}
//};