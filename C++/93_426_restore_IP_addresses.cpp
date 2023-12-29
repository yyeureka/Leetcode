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

����˼·��dfs���ѣ��Ѿ�������ô�ж�segment��valid�ģ����״�
1����0��ͷ�Ķ�ֻ���ǡ�0��
2��1 <= �γ��� <= 3
3��0 <= ��ֵ <= 255
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
			if (isValid(s, start, s.size() - start)) { //����ֱ��substr��Ҫ���ж��Ƿ�Խ��
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
		if (charNum <= 0 || charNum > 3 || start + charNum > a.size()) { //�״�
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