#include "head.h"

/*
Design and implement a TwoSum class. It should support the following operations: add and find.
add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) // return true
find(7) // return false

����˼·��
1��hash��add O(1) find O(n)������

����add��find��������Ƶ��������ʹ��2/3
2��two pointer1��add O(1) find ���� O(nlogn)
3��two pointer2��add ά���������� O(n) find O(n)
*/

class TwoSum {
public:
	vector<int> v;

	void add(int number) {
		v.push_back(number);
	}

	bool find(int value) {
		unordered_set<int> s;

		for (int i : v) {
			if (s.find(value - i) != s.end()) return true;

			if (s.find(i) == s.end()) s.insert(i);
		}

		return false;
	}
};

//class TwoSum {
//public:
//	vector<int> v;
//	unordered_map<int, int> m;
//
//	void add(int number) {
//		v.push_back(number);
//		m[number]++;
//	}
//
//	bool find(int value) {
//		for (int i : v) {
//			int num2 = value - i;
//
//			if (i == num2 && m[i] > 1) return true;
//			if (i != num2 && m[num2] > 0) return true; //���������״�
//		}
//
//		return false;
//	}
//};