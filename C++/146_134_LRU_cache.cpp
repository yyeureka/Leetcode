#include "head.h"

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Finally, you need to return the data from each get.

Example1
Input:
LRUCache(2)
set(2, 1)
set(1, 1)
get(2)
set(4, 1)
get(1)
get(2)
Output: [1,-1,1]
Explanation��
cache cap is 2��set(2,1)��set(1, 1)��get(2) and return 1��set(4,1) and delete (1,1)��because ��1,1��is the least use��get(1) and return -1��get(2) and return 1.
Example 2:
Input��
LRUCache(1)
set(2, 1)
get(2)
set(3, 2)
get(2)
get(3)
Output��[1,-1,2]
Explanation��
cache cap is 1��set(2,1)��get(2) and return 1��set(3,2) and delete (2,1)��get(2) and return -1��get(3) and return 2.

����˼·��
linked list������м�ɾ������Ҫ��doublely�������״�
hash��洢��list node��ǰһ��list node

������д�� ����д���ΰ�
*/

class LRUCache {
public:
	class cacheNode {
	public:
		int key;
		int val;
		cacheNode *next;

		cacheNode(int key, int val) {
			this->key = key;
			this->val = val;
		}
	};

	int size;
	int maxSize;
	cacheNode * head;
	cacheNode * tail;
	unordered_map<int, cacheNode *> cache;
	/*
	* @param capacity: An integer
	*/
	LRUCache(int capacity) {
		size = 0;
		maxSize = capacity;
		head = new cacheNode(-1, -1);
		tail = head;
	}

	/*
	* @param key: An integer
	* @return: An integer
	*/
	int get(int key) {
		if (cache.find(key) == cache.end()) {
			return -1;
		}

		cacheNode * cur = cache[key]->next;
		deleteNode(cache[key]); //�״�
		addNode(cur);

		return tail->val;
	}

	/*
	* @param key: An integer
	* @param value: An integer
	* @return: nothing
	*/
	void set(int key, int value) {
		if (get(key) > 0) { //�״�����set��value
			cache[key]->next->val = value;
			return;
		}

		addNode(new cacheNode(key, value));
		size++;

		if (size > maxSize) {
			cache.erase(head->next->key); //�״�map��Ҳ��ɾ��
			deleteNode(head);
			size--;
		}
	}

	void addNode(cacheNode * node) {
		cache[node->key] = tail;
		node->next = NULL; //�״���ֹcycle
		tail->next = node;
		tail = tail->next;
	}

	void deleteNode(cacheNode * pre) {
		if (pre->next->next) {
			cache[pre->next->next->key] = pre;
			pre->next = pre->next->next;
		}
		else { //�״�ɾ��tail node�����
			pre->next = NULL;
			tail = pre;
		}
	}
};