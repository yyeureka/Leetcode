#include "head.h"

/*
Find top k frequent words in realtime data stream.
Implement three methods for Topk Class:
TopK(k). The constructor.
add(word). Add a new word.
topk(). Get the current top k frequent words.

Example 1:
Input��
TopK(2)
add("lint")
add("code")
add("code")
topk()
Output��["code", "lint"]
Explanation��
"code" appears twice and "lint" appears once, they are the two most frequent words.
Example 2:
Input��
TopK(1)
add("aa")
add("ab")
topk()
Output��["aa"]
Explanation��
"aa" and "ab" appear once , but aa's dictionary order is less than ab's.

Notice
If two words have the same frequency, rank them by dictionary order.

����˼·��#692��online programming�汾
ÿaddһ��string��Ҫ����Ƿ���ڣ�����ڣ�set erase��frequent++����insert
*/

class TopK {
private:
	struct cmp { //ע������д����cntС���ַ�����ȳ�
		const bool operator()(pair<string, int> p1, pair<string, int> p2) const { //ע�����const��λ��
			if (p1.second != p2.second) return p1.second > p2.second;
			else return p1.first < p2.first;
		}
	};

	int size;
	set<pair<string, int>, cmp> minHeap; //cmp�趨����ǰ��
	unordered_map<string, int> words;
public:
	TopK(int k) {
		size = k;
	}

	void add(string &word) {
		if (words.find(word) != words.end()) {
			minHeap.erase({ word, words[word] }); //����
		}
		words[word]++;

		minHeap.insert({ word, words[word] });
		if (minHeap.size() > size) minHeap.erase(--minHeap.end()); //pop�����һ��Ԫ��
	}

	vector<string> topk() {
		vector<string> res;

		for (auto iter = minHeap.begin(); iter != minHeap.end(); iter++) {
			res.push_back((*iter).first);
		}

		return res;
	}
};