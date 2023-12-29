#include <string>
#include <unordered_map>
using namespace std;

/*
Given two strings, write a method to decide if one is a permutation of the other.

解题思路：
1、^所有A、B的字符，如果结果==0即互为permutation
两个string size要相等
第一个string所有char加进unordered_map，第二个string从unordered_map减去，如果出现value<0，false
*/

//class Solution {
//public:
//	bool Permutation(string &A, string &B) {
//		if (A.size() != B.size()) return false;
//
//		unordered_map<char, int> m;
//		for (char i : A) m[i]++;
//		for (char i : B) {
//			if (--m[i] < 0) return false;
//		}
//		return true;
//	}
//};