#include <vector>
#include <queue>
using namespace std;

/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

Example 1:
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should
also have finished course 1. So it is impossible.

解题思路：
BFS Topological Sort
DFS Topological Sort不会
*/

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> courses(numCourses);
		vector<int> indegree(numCourses, 0); //暂时还不能修的后续课
		for (auto i : prerequisites) {
			courses[i[1]].push_back(i[0]);   //将后续课加入pre的列表
			indegree[i[0]]++;
		}

		queue<int> q;  //可以修的课 没有pre/已修完pre
		for (int i = 0; i < numCourses; i++) if (!indegree[i]) q.push(i); //坑，不是每个course都会出现在列表里
		
		while (!q.empty()) {
			int pre_course = q.front();
			q.pop();
			numCourses--;

			for (int i : courses[pre_course]) {
				if (0 == --indegree[i]) q.push(i);  //该pre的后续课可以修了
			}
		}
		return 0 == numCourses;
	}
};