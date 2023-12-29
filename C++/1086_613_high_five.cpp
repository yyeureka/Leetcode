#include "head.h"

/*
There are two properties in the node student id and scores, to ensure that each student will have at least 5 points, find the average of 5 highest scores for each person.

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

解题思路：hash+heap
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
	map<int, double> highFive(vector<Record>& results) {
		unordered_map<int, multiset<int, greater<int>>> scores; //易错，有重复的分数
		for (Record i : results) {
			scores[i.id].insert(i.score);
			if (scores[i.id].size() > 5) {
				scores[i.id].erase(--scores[i.id].end());
			}
		}

		map<int, double> ans;
		for (auto i : scores) {
			double sum = 0;
			for (int j : i.second) {
				sum += j;
			}
			sum /= 5.0;

			ans[i.first] = sum;
		}

		return ans;
	}
};