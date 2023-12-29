#include "head.h"

/*
Given an directed graph, a topological order of the graph nodes is defined as follow:
For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Example
For graph as follow:
The topological order can be:

[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...
Challenge
Can you do it in both BFS and DFS?
*/


struct DirectedGraphNode {
	int label;
	vector<DirectedGraphNode *> neighbors;
	DirectedGraphNode(int x) : label(x) {};
};

//BFS
class Solution {
public:
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
		if (graph.empty()) return{};

		unordered_map<int, vector<int>> nodes;
		unordered_map<int, int> indegree;
		for (auto i : graph) {
			if (indegree.find(i->label) == indegree.end()) indegree.insert({ i->label, 0 });

			for (auto j : i->neighbors) {
				nodes[i->label].push_back(j->label);
				indegree[j->label]++;
			}
		}

		queue<int> q;
		for (auto i : indegree) {
			if (0 == i.second) q.push(i.first);
		}

		vector<DirectedGraphNode*> res;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			res.push_back(new DirectedGraphNode(cur));

			for (int i : nodes[cur]) {
				if (0 == --indegree[i]) q.push(i);
			}
		}
		return res;
	}
};

////DFS
//class Solution {
//public:
//	void dfs(vector<DirectedGraphNode*> &res, DirectedGraphNode* cur, unordered_map<DirectedGraphNode*, int> &degree) {
//		res.push_back(cur);
//		degree[cur]--; //易错点，主函数里的for循环可能访问到已经加进res里的node
//
//		for (auto i : cur->neighbors) {
//			if (0 == --degree[i]) dfs(res, i, degree);
//		}
//	}
//
//	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
//		unordered_map<DirectedGraphNode*, int> degree;
//		for (auto i : graph) {
//			if (degree.find(i) == degree.end()) degree.insert({ i, 0 });
//
//			for (auto j : i->neighbors) degree[j]++;
//		}
//
//		vector<DirectedGraphNode*> res;
//		for (auto i : degree) {
//			if (0 == i.second) dfs(res, i.first, degree);
//		}
//		return res;
//	}
//};