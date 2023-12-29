#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <xfunctional>
#include <iostream>
using namespace std;

/*
There are two properties in the node student id and scores, to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.
Example

Example 1:
Input:
[[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],[1,58],[2,100],[1,61]]
Output:
1: 72.40
2: 97.40
Example 2:
Input:
[[1,90],[1,90],[1,90],[1,90],[1,90],[1,90]]
Output:
1: 90.00

解题思路：
1、heap，根据id、score排序，再依次pop出来计算平均score
2、每个id一个min heap，超过5个pop出去，再分别计算平均score
*/

class Record {
public:
  int id, score;
  Record(int id, int score) {
    this->id = id;
    this->score = score;
  }
};

class Solution {
public:
	/**
	* @param results a list of <student_id, score>
	* @return find the average of 5 highest scores for each person
	* map<int, double> (student_id, average_score)
	*/
	map<int, double> highFive(vector<Record>& results) {
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
		for (auto i : results) {
			m[i.id].push(i.score);
			if (m[i.id].size() > 5) m[i.id].pop();
		}

		map<int, double> res;
		for (auto i : m) {
			double score = 0.0;
			while (!i.second.empty()) {
				score += i.second.top();
				i.second.pop();
			}
			res.insert({i.first, score / 5.0});
		}
		return res;
	}
};

//struct cmp {
//	bool operator()(Record a, Record b) {
//		if (a.id == b.id) return a.score < b.score;
//		else return a.id < b.id;
//	}
//};
//
//class Solution {
//public:
//	/**
//	* @param results a list of <student_id, score>
//	* @return find the average of 5 highest scores for each person
//	* map<int, double> (student_id, average_score)
//	*/
//	map<int, double> highFive(vector<Record>& results) {
//		priority_queue<Record, vector<Record>, cmp> pq(results.begin(), results.end());
//
//		map<int, double> res;
//		int id = -1;
//		int point;
//		int score;
//		while (!pq.empty()) {
//			Record cur = pq.top();
//			pq.pop();
//
//			if (cur.id != id) {
//				id = cur.id;
//				point = 0;
//				score = 0;
//			}
//			if (point >= 5) continue;
//
//			point++;
//			score += cur.score;
//			if (5 == point) res.insert({id, (double)score / 5.0});
//		}
//		return res;
//	}
//};

//void main() {
//	Solution s;
//	vector<Record> v = { { 1,91 },{ 1,92 },{ 2,93 },{ 2,99 },{ 2,98 },{ 2,97 },{ 1,60 },{ 1,58 },{ 2,100 },{ 1,61 } };
//	//vector<Record> v = { { 1,90 },{ 1,90 },{ 1,90 },{ 1,90 },{ 1,90 },{ 1,90 }};
//	map<int, double> m = s.highFive(v);
//	for (auto i : m) {
//		cout << i.first << ":" << i.second << endl;
//	}
//}