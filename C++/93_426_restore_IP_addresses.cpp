#include "head.h"

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
(Your task is to add three dots to this string to make it a valid IP address. Return all possible IP address.)

Example 1:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
Explanation: ["255.255.111.35", "255.255.11.135"] will be accepted as well.
Example 2:
Input: "1116512311"
Output: ["11.165.123.11","111.65.123.11"]

Notice
You can return all valid IP address in any order.

解题思路：dfs不难，难就难在怎么判断segment是valid的，超易错
1、以0开头的段只能是“0”
2、1 <= 段长度 <= 3
3、0 <= 段值 <= 255
*/

class Solution {
public:
	vector<string> restoreIpAddresses(string &s) {
		vector<string> results;

		dfs(s, 0, 3, results);

		return results;
	}

	void dfs(string &s, int start, int dotNum, vector<string> &results) {
		if (0 == dotNum) {
			if (isValid(s, start, s.size() - start)) { //不能直接substr，要先判断是否越界
				results.push_back(s);
			}

			return;
		}

		for (int i = 1; i <= 3; i++) {
			if (!isValid(s, start, i)) {
				break;
			}

			s.insert(start + i, ".");
			dfs(s, start + i + 1, dotNum - 1, results);
			s.erase(start + i, 1);
		}
	}

	bool isValid(string a, int start, int charNum) {
		if (charNum <= 0 || charNum > 3 || start + charNum > a.size()) { //易错
			return false;
		}

		if ('0' == a[start]) {
			return 1 == charNum;
		}

		int num = 0;
		for (int i = start; i < start + charNum; i++) {
			num = num * 10 + a[i] - '0';
		}

		return num <= 255;
	}
};