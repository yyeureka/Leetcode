#include "head.h"
/*
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

Example:
Input:
{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
Explanation:
Node 1's value is 1, and it has two neighbors: Node 2 and 4.
Node 2's value is 2, and it has two neighbors: Node 1 and 3.
Node 3's value is 3, and it has two neighbors: Node 2 and 4.
Node 4's value is 4, and it has two neighbors: Node 1 and 3.

Note:
The number of nodes will be between 1 and 100.
The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
You must return the copy of the given node as a reference to the cloned graph.

解题思路：BFS&DFS
*/

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

//BFS
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (NULL == node) return NULL;  //易错

		unordered_map<Node*, Node*> cp; //已访问的node:已复制的node
		cp[node] = new Node(node->val); //易错
		queue<Node*> q;                 //待访问的node
		q.push(node);

		while (!q.empty()) {
			Node* cur = q.front();
			q.pop();

			for (Node* i : cur->neighbors) {
				if (cp.find(i) == cp.end()) {
					cp[i] = new Node(i->val);
					q.push(i);
				}

				cp[cur]->neighbors.push_back(cp[i]); //易错，已访问过的node不能直接continue
			}
		}

		return cp[node];
	}
};

////DFS
//class Solution {
//public:
//	void dfs(Node* node, Node* cp, unordered_map<Node*, Node*> &m) {
//		for (Node* i : node->neighbors) {
//			if (m.find(i) != m.end()) {
//				cp->neighbors.push_back(m[i]);
//			}
//			else {
//				m[i] = new Node(i->val, {});
//				cp->neighbors.push_back(m[i]);
//				dfs(i, cp->neighbors.back(), m);
//			}
//		}
//	}
//
//	Node* cloneGraph(Node* node) {
//		if (NULL == node) return NULL;
//
//		Node* cp = new Node(node->val, {});
//		unordered_map<Node*, Node*> m;
//		m[node] = cp; //容易忘
//		dfs(node, cp, m);
//		return cp;
//	}
//};