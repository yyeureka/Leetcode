﻿#include <vector>
using namespace std;

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
Note:
If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.

Example 1:
Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:
Input:
gas  = [2,3,4]
cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

解题思路：
1、start从队尾，end从对头开始
   如果从start能走到end，end往后走一步
   如果从start不能走到end，start往前走一步
   最后start和end相遇时，如果能走到，即为成功
2、total gas>=total cost就一定能走完
   起始点start为总gas消耗最多的加油站的下一个
3、brute force：检查每一个gas[i]>=cost[i]是否是起点
*/

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int start = gas.size() - 1;
		int end = 0;
		int sum = gas[start] - cost[start];
		while (start > end) {
			if (sum >= 0) {
				sum += gas[end] - cost[end];
				end++;
			}
			else {
				start--;
				sum += gas[start] - cost[start];
			}
		}
		return sum >= 0 ? start : -1;
	}
};

//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		int total_remain = 0;
//		int min_remain = INT_MAX;
//		int start = 0;
//		for (int i = 0; i < gas.size(); i++) {
//			total_remain += gas[i] - cost[i];
//			if (total_remain < min_remain) {
//				min_remain = total_remain;
//				start = i + 1;
//			}
//		}
//		return total_remain >= 0 ? start % gas.size() : -1; //这里要mod！
//	}
//};

//class Solution {
//public:
//	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//		int n = gas.size();
//		for (int i = 0; i < n; i++) {
//			if (gas[i] >= cost[i]) { //只>会出错
//				int j = i;
//				int tank = 0;
//				while (1) {
//					tank += gas[j] - cost[j];
//					if (tank < 0) break;
//					j = (j + 1) % n;
//					if (j == i) return i;
//				}
//			}
//		}
//		return -1;
//	}
//};