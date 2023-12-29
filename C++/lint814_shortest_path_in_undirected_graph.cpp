#include "head.h"

/*
Given an undirected graph in which each edge's length is 1, and two nodes from the graph. Return the length of the shortest path between two given nodes.

Example 1:
Input: graph = {1,2,4#2,1,4#3,5#4,1,2#5,3}, node1 = 3, node2 = 5
Output: 1
Explanation:
1------2  3
\     |  |
\    |  |
\   |  |
\  |  |
4   5
Example 2:
Input: graph = {1,2,3,4#2,1,3#3,1#4,1,5#5,4}, node1 = 1, node2 = 5
Output: 2

解题思路：
1、BFS
2、bidirectional BFS
*/

//BFS
class Solution {
public:
	int shortestPath(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A, UndirectedGraphNode* B) {
		if (graph.empty() || NULL == A || NULL == B) return -1;
		if (A == B) return 0;

		queue<UndirectedGraphNode*> q;
		q.push(A);
		unordered_set<int> nodes;
		nodes.insert(A->label);

		int len = 1;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				UndirectedGraphNode* cur = q.front();
				q.pop();

				for (auto j : cur->neighbors) {
					if (nodes.find(j->label) != nodes.end()) continue;
					nodes.insert(j->label);

					if (j == B) return len;
					q.push(j);
				}
			}

			len++;
		}

		return -1;
	}
};

////bidirectional BFS
//class Solution {
//public:
//	int shortestPath(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A, UndirectedGraphNode* B) {
//		if (graph.empty() || NULL == A || NULL == B) return -1;
//		if (A == B) return 0;
//
//		unordered_set<UndirectedGraphNode*> head;
//		head.insert(A);
//		unordered_set<UndirectedGraphNode*> tail;
//		tail.insert(B);
//		unordered_set<UndirectedGraphNode*> *phead = &head;
//		unordered_set<UndirectedGraphNode*> *ptail = &tail;
//
//		int len = 1;
//		while (!head.empty() && !tail.empty()) {
//			if (head.size() > tail.size()) swap(phead, ptail);
//
//			unordered_set<UndirectedGraphNode*> tmp;
//			for (auto it = phead->begin(); it != phead->end(); it++) {
//				for (auto j : (*it)->neighbors) {
//					if (ptail->find(j) != ptail->end()) return len;
//					tmp.insert(j);
//				}
//			}
//
//			phead->swap(tmp);
//			len++;
//		}
//
//		return -1;
//	}
//};