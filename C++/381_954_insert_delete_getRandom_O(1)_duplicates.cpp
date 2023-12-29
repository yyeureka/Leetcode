#include "head.h"

/*
Design a data structure that supports all following operations in average O(1) time.

Example 1:
Input:
insert(1)
insert(1)
insert(2)
getRandom()
remove(1)
// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();
// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);
// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);
// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);
// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();
// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);
// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
Example 2:
Input:
insert(1)
insert(1)
getRandom()
remove(1)

Notice
Duplicate elements are allowed.

insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.

解题思路：#380 follow up
unordered_map里存同一个value的所有index
vector里存value以及unordered_map里的序号
*/

class RandomizedCollection {
public:
	unordered_map<int, vector<int>> getIndex;
	vector<pair<int, int>> nums;

	RandomizedCollection() {

	}

	bool insert(int val) {
		getIndex[val].push_back(nums.size());
		nums.push_back({ val, getIndex[val].size() - 1 });

		return true;
	}

	bool remove(int val) {
		if (getIndex.find(val) == getIndex.end()) {
			return false;
		}

		int index = getIndex[val].back();
		getIndex[nums.back().first][nums.back().second] = index; //不能想当然觉得nums.back()一定存在getIndex[].back()
		nums[index] = nums.back();

		getIndex[val].pop_back();
		if (getIndex[val].empty()) { //易错
			getIndex.erase(val);
		}
		nums.pop_back();

		return true;
	}

	int getRandom() {
		return nums[rand() % nums.size()].first;
	}
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/