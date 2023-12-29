#include "head.h"

/*
Find top k frequent words in realtime data stream.
Implement three methods for Topk Class:
TopK(k). The constructor.
add(word). Add a new word.
topk(). Get the current top k frequent words.

Example 1:
Input：
TopK(2)
add("lint")
add("code")
add("code")
topk()
Output：["code", "lint"]
Explanation：
"code" appears twice and "lint" appears once, they are the two most frequent words.
Example 2:
Input：
TopK(1)
add("aa")
add("ab")
topk()
Output：["aa"]
Explanation：
"aa" and "ab" appear once , but aa's dictionary order is less than ab's.

Notice
If two words have the same frequency, rank them by dictionary order.

解题思路：#692的online programming版本
每add一个string需要检查是否存在，如存在，set erase、frequent++后再insert
*/

class TopK {
private:
	struct cmp { //注意算子写法，cnt小和字符大的先出
		const bool operator()(pair<string, int> p1, pair<string, int> p2) const { //注意这个const的位置
			if (p1.second != p2.second) return p1.second > p2.second;
			else return p1.first < p2.first;
		}
	};

	int size;
	set<pair<string, int>, cmp> minHeap; //cmp需定义在前面
	unordered_map<string, int> words;
public:
	TopK(int k) {
		size = k;
	}

	void add(string &word) {
		if (words.find(word) != words.end()) {
			minHeap.erase({ word, words[word] }); //增改
		}
		words[word]++;

		minHeap.insert({ word, words[word] });
		if (minHeap.size() > size) minHeap.erase(--minHeap.end()); //pop出最后一个元素
	}

	vector<string> topk() {
		vector<string> res;

		for (auto iter = minHeap.begin(); iter != minHeap.end(); iter++) {
			res.push_back((*iter).first);
		}

		return res;
	}
};