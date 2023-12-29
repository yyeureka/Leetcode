#include <queue>
using namespace std;

/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
struct Node {
int val;
Node *left;
Node *right;
Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.

Example:
Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.

解题思路:
level_ordered traversal的follow up版本，使用已经处理过的next node来连接下一行子node
recursive或者iterative
*/


// Definition for a Node.
class Node {
	public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		Node* start = root;
		while (start) {
			Node* cur = start;
			while (cur) {
				if (cur->left) cur->left->next = cur->right;
				if (cur->right && cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			start = start->left;
		}
		return root;
	}
};

//class Solution {
//public:
//	void populate(Node* root, Node* right) {
//		if (!root) return;
//
//		root->next = right;
//		if (root->left) populate(root->left, root->right);
//		if (root->right) populate(root->right, right ? right->left : NULL);
//	}
//
//	Node* connect(Node* root) {
//		populate(root, NULL);
//		return root;
//	}
//};
