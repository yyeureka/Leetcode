#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
You have an array of logs.  Each log is a space delimited string of words.
For each log, the first word in each log is an alphanumeric identifier.  Then, either:
Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.
Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.
Return the final order of the logs.
Note:
0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.

Example 1:
Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

解题思路：
多关键字排序，改写sort函数的cmp
因为需要保持数字log的原始顺序，使用stable_sort()，保持原顺序的时候返回false
*/

bool cmp(string a, string b) {
	auto i = a.find(' ');
	auto j = b.find(' ');

	if (isdigit(a[i + 1]) && isdigit(b[j + 1])) return false;  //false能使stable_sort保持相等元素的顺序
	else if (!isdigit(a[i + 1]) && isdigit(b[j + 1])) return true;
	else if (isdigit(a[i + 1]) && !isdigit(b[j + 1])) return false;
	else {
		if (a.substr(i + 1) == b.substr(j + 1)) return a.substr(0, i) < b.substr(0, j);
		else return a.substr(i + 1) < b.substr(j + 1);
	}
};

class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		stable_sort(logs.begin(), logs.end(), cmp);
		return logs;
	}
};