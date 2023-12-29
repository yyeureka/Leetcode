#include "head.h"
/*
Given a non-empty array of integers, return the k most frequent elements.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]

解题思路：
跟692大同小异，注意是否需要one pass
leetcode不能使用set
*/

class Solution {
private:
	struct cmp {
		bool operator()(pair<int, int> a, pair<int, int> b) {
			if (a.second != b.second) return a.second > b.second; //易错
			return a.first < b.first; 
		}
	};
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> dict;
		set<pair<int, int>, cmp> minHeap;

		for (int i : nums) {
			dict[i]++;
		}

		for (auto i : dict) {
			minHeap.insert(i);
			if (minHeap.size() > k) minHeap.erase(--minHeap.end()); //实现nlogk
		}

		vector<int> res;
		for (auto i : minHeap) {
			res.push_back(i.first);
		}

		return res;
	}
};

//data stream版本
//class Solution {
//public:
//	struct cmp {
//		bool operator()(pair<int, int> a, pair<int, int> b) {
//			if (a.second != b.second) return a.second > b.second;
//			return a.first < b.first;
//		}
//	};
//
//	vector<int> topKFrequent(vector<int> &nums, int k) {
//		unordered_map<int, int> frequent;
//		set<pair<int, int>, cmp> minheap;
//
//		for (int i : nums) {
//			if (frequent.find(i) != frequent.end()) {
//				minheap.erase({ i, frequent[i] }); //易错
//			}
//
//			frequent[i]++;
//
//			minheap.insert({ i, frequent[i] });
//			if (minheap.size() > k) {
//				minheap.erase(--minheap.end());
//			}
//		}
//
//		vector<int> result;
//		for (auto i : minheap) {
//			result.push_back(i.first);
//		}
//
//		return result;
//	}
//};

//class Solution {
//public:
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		vector<int> res;
//		map<int, int> m; // val:count
//		for (int i : nums) m[i]++;
//
//		priority_queue<pair<int, int>> pq;
//		for (auto j : m) {
//			pq.push({j.second, j.first});  // 这里很巧妙，就不用额外写priority queue的算子了
//			if (pq.size() > m.size() - k) {
//				res.push_back(pq.top().second);
//				pq.pop();
//			}
//		}
//		return res;
//	}
//};