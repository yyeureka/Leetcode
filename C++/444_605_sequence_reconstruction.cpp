#include "head.h"
/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:
Input:org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Example 2:
Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation:
The reconstructed sequence can only be [1,2].

Example 3:
Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Example 4:
Input:org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Output:true

解题思路：
1、topological sort，根据seqs有且仅有一个拓扑序pos，且pos==org
2、topological sort，org定序pre，seqs根据org的顺序进行校验和排序pos，判断pre和pos是否相同，逻辑复杂易错
*/

class Solution {
public:
	bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
		unordered_map<int, vector<int>> connection;
		unordered_map<int, int> indegree;
		for (auto i : seqs) {
			if (i.size() > 0 && indegree.find(i[0]) == indegree.end()) indegree.insert({ i[0], 0 }); //易错

			for (int j = 1; j < i.size(); j++) {
				connection[i[j - 1]].push_back(i[j]);
				indegree[i[j]]++;
			}
		}

		queue<int> q;
		for (auto i : indegree) if (!i.second) q.push(i.first);

		vector<int> res;
		while (!q.empty()) {
			if (q.size() > 1) return false; //判断有且仅有一个拓扑序

			int cur = q.front();
			q.pop();
			res.push_back(cur);

			for (int i : connection[cur]) if (0 == --indegree[i]) q.push(i);
		}

		if (org.size() != res.size()) return false;
		for (int i = 0; i < org.size(); i++) {
			if (res[i] != org[i]) return false;
		}
		return true;
	}
};

//class Solution {
//public:
//	bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
//		unordered_map<int, int> pre;
//		for (int i = 0; i < org.size(); i++) pre[org[i]] = i;
//
//		unordered_map<int, int> pos;
//		for (auto seq : seqs) {
//			for (int j = 0; j < seq.size(); j++) {
//				if (pre.find(seq[j]) == pre.end()) return false; //pre中没有的数
//				if (j > 0 && pre[seq[j - 1]] > pre[seq[j]]) return false; //顺序与pre不一致
//
//				int idx = 0;
//				if (j > 0) idx = pre[seq[j - 1]] + 1;
//
//				if (pos.find(seq[j]) == pos.end()) pos.insert({ seq[j], idx });
//				else pos[seq[j]] = max(pos[seq[j]], idx);
//			}
//		}
//
//		if (pos.size() != pre.size()) return false; //这个不能省，提高效率，否则过不了[1]和[]的用例
//		for (int i = 0; i < org.size(); i++) {
//			if (pos[org[i]] != i) return false;
//		}
//		return true;
//	}
//};