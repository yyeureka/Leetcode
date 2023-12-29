/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.
Notes:
There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

Example1
Input:
2 // next n * (n - 1) lines
0 knows 1
1 does not know 0
Output: 1
Explanation:
Everyone knows 1,and 1 knows no one.
Example2
Input:
3 // next n * (n - 1) lines
0 does not know 1
0 does not know 2
1 knows 0
1 does not know 2
2 knows 0
2 knows 1
Output: 0
Explanation:
Everyone knows 0,and 0 knows no one.
0 does not know 1,and 1 knows 0.
2 knows everyone,but 1 does not know 2.

解题思路：
1、不认识所有人——有认识的人不是
2、所有人认识——有人不认识不是
基于以上任一条件的非，遍历一遍所有人得到一个candidacy
再遍历一遍所有人，判断两个条件是否满足
*/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	/**
	* @param n a party with n people
	* @return the celebrity's label or -1
	*/
	int findCelebrity(int n) {
		int tmp = 0;
		for (int i = 1; i < n; i++) {
			if (knows(tmp, i)) tmp = i; //有人认识tmp，tmp不认识之后所有的人
		}

		for (int i = 0; i < n; i++) {
			if (i < tmp && knows(tmp, i)) return -1;   //tmp认识之前的某人，不是名人
			if (i != tmp && !knows(i, tmp)) return -1; //有人不认识tmp，不是名人
		}
		return tmp;
	}
};

// Forward declaration of the knows API.
//bool knows(int a, int b);
//
//class Solution {
//public:
//	/**
//	* @param n a party with n people
//	* @return the celebrity's label or -1
//	*/
//	int findCelebrity(int n) {
//		int tmp = 0;
//		for (int i = 1; i < n; i++) {
//			if (!knows(i, tmp)) tmp = i; //tmp不认识某人，tmp之后所有的人都认识tmp
//		}
//
//		for (int i = 0; i < n; i++) {
//			if (i < tmp && !knows(i, tmp)) return -1;
//			if (i != tmp && knows(tmp, i)) return -1;
//		}
//		return tmp;
//	}
//};