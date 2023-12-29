#include "head.h"

/*
Implement a data structure, provide two interfaces:
add(number). Add a new number in the data structure.
topk(). Return the top k largest numbers in this data structure. k is given when we create the data structure.

Example1
Input:
s = new Solution(3);
s.add(3)
s.add(10)
s.topk()
s.add(1000)
s.add(-99)
s.topk()
s.add(4)
s.topk()
s.add(100)
s.topk()
Output:
[10, 3]
[1000, 10, 3]
[1000, 10, 4]
[1000, 100, 10]
Explanation:
s = new Solution(3);
>> create a new data structure, and k = 3.
s.add(3)
s.add(10)
s.topk()
>> return [10, 3]
s.add(1000)
s.add(-99)
s.topk()
>> return [1000, 10, 3]
s.add(4)
s.topk()
>> return [1000, 10, 4]
s.add(100)
s.topk()
>> return [1000, 100, 10]

Example2
Input:
s = new Solution(1);
s.add(3)
s.add(10)
s.topk()
s.topk()
Output:
[10]
[10]
Explanation:
s = new Solution(1);
>> create a new data structure, and k = 1.
s.add(3)
s.add(10)
s.topk()
>> return [10]
s.topk()
>> return [10]

解题思路：
size为k的minheap，可能有重复数字，最好用multiset
*/

class Solution {
private:
	int size;
	multiset<int, greater<int>> minHeap;
public:
	Solution(int k) {
		size = k;
	}

	void add(int num) {
		minHeap.insert(num);

		if (minHeap.size() > size) minHeap.erase(--minHeap.end());
	}

	vector<int> topk() {
		vector<int> res;

		for (auto iter = minHeap.begin(); iter != minHeap.end(); iter++) {
			res.push_back(*iter);
		}

		return res;
	}
};