#include "head.h"

/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
with the number of occurrence being 4, 3, 2 and 1 respectively.

解题思路：
1、unordered_map+set，leetcode不支持
   map里存string和frequent
   iter直接输出topk
2、unordered_map+priority_queue
   每次找topk时都得重新form一次priority_queue，不如set可以增删查改
3、unordered_map+bucket_sort+trie
   unordered_map记录string和frequent
   bucket_sort以frequent分筒，frequent从1~words的个数，共size个筒
   将同frequent即一个桶内的word加进trie中，trie来完成字符排序，共size个trie
   从frequent最大的筒开始，将trie中的word加进结果数组中
   实现复杂，且时间和空间复杂度感觉没办法达到follow up的要求
*/

class Solution {
private:
	struct cmp {
		bool operator()(pair<string, int> p1, pair<string, int> p2) const { //注意这个const的位置
			if (p1.second != p2.second) return p1.second > p2.second;
			else return p1.first < p2.first;
		}
	};
public:
	vector<string> topKFrequentWords(vector<string> &words, int k) {
		unordered_map<string, int> m;
		set<pair<string, int>, cmp> minHeap;

		for (string s : words) {
			m[s]++;
		}

		for (auto i : m) {
			minHeap.insert(i);

			if (minHeap.size() > k) {
				minHeap.erase(--minHeap.end());
			}
		}

		vector<string> res;
		for (auto i : minHeap) {
			res.push_back(i.first);
		}

		return res;
	}
};


//class Solution {
//private:
//	struct cmp { //注意算子的写法
//		bool operator()(pair<string, int> a, pair<string, int> b) { //将次数少/asicII值大的先pop出去
//			if (a.second != b.second) return a.second > b.second;
//			return a.first < b.first;
//		}
//	};
//public:
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		unordered_map<string, int> m;
//		for (string i : words) {
//			m[i]++;
//		}
//
//		priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq; //map的key value就是一对pair
//		for (auto iter = m.begin(); iter != m.end(); iter++) {
//			pq.push(*iter); //简便写法
//
//			if (pq.size() > k) pq.pop();
//		}
//
//		int i = min((int)pq.size(), k) - 1; //pq可能不满，.size()是uint型，不强转会报错
//		vector<string> res(i + 1);
//		while (i >= 0) {
//			res[i--] = pq.top().first; //这样就不用reverse了
//			pq.pop();
//		}
//
//		return res;
//	}
//};