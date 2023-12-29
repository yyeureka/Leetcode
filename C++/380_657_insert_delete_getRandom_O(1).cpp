#include "head.h"

/*
Design a data structure that supports all following operations in average O(1) time.
insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example:
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();
// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);
// Returns false as 2 does not exist in the set.
randomSet.remove(2);
// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);
// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();
// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);
// 2 was already in the set, so return false.
randomSet.insert(2);
// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

解题思路：
1、unordereds_set，用rand()和next()getRandom
2、unordered_map+array，key为元素，val为这个元素在array中的index，用rand()getRandom

follow up：#381大致知道思路就行了
*/

class RandomizedSet {
public:
	int size;
	unordered_set<int> nums;

	RandomizedSet() {
		size = 0;
	}

	bool insert(int val) {
		if (nums.find(val) != nums.end()) {
			return false;
		}

		nums.insert(val);
		size++;

		return true;
	}

	bool remove(int val) {
		if (nums.find(val) == nums.end()) return false;

		nums.erase(val);
		size--;

		return true;
	}

	int getRandom() {
		int index = rand() % size;

		return *next(nums.begin(), index);
	}
};

////unordered_map+vector
//class RandomizedSet {
//public:
//	unordered_map<int, int> index;
//	vector<int> nums;
//
//	RandomizedSet() {
//
//	}
//
//	bool insert(int val) {
//		if (index.find(val) != index.end()) {
//			return false;
//		}
//
//		index[val] = nums.size();
//		nums.push_back(val);
//
//		return true;
//	}
//
//	bool remove(int val) {
//		if (index.find(val) == index.end()) return false;
//
//		index[nums.back()] = index[val];
//		nums[index[val]] = nums.back();
//		index.erase(val); //易错
//		nums.pop_back();
//
//		return true;
//	}
//
//	int getRandom() {
//		return nums[rand() % nums.size()];
//	}
//};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet* obj = new RandomizedSet();
* bool param_1 = obj->insert(val);
* bool param_2 = obj->remove(val);
* int param_3 = obj->getRandom();
*/