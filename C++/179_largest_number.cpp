#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a list of non negative integers, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: [10,2]
Output: "210"
Example 2:
Input: [3,30,34,5,9]
Output: "9534330"

解题思路：
将nums转换为string，sort的cmp函数比较s1+s2和s2+s1
易错点：
1、有全零的坑爹用例，导致结果出现多余前置零，需要额外去掉
2、sort nums用stoi转的话会有用例超过int范围，所以要先将nums转为string再sort，且string可以直接比大小
*/

//bool cmp(string s1, string s2) {
//	return (s1 + s2) > (s2 + s1);
//}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> s;
		for (int i : nums) s.push_back(to_string(i));
		sort(s.begin(), s.end(), [](string s1, string s2) {return (s1 + s2) > (s2 + s1); }); //不能为<=!!
		
		string res = "";
		for (int i = 0; i < s.size(); i++) {
			if ("0" == s[i] && (i < s.size() - 1) && res.empty()) continue; //消除前置零
			res += s[i];
		}
		return res;
	}
};