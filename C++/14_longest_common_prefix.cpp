#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.

解题思路：
1、输入vector为空，返回空
2、第一个string取substr，其他string都能找到即成功
3、prefix是前缀！前缀！！！substr从0开始截取，在其他string中的position也需要是0！！！
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";

		string res = strs[0];
		int len = res.size();

		for (int i = 1; i < strs.size(); i++) {
			len = min(len, (int)strs[i].size());
			while (len > 0 && strs[i].substr(0, len) != res.substr(0, len)) len--; //易错，不等简单从最右开始比较字符
		}
		return res.substr(0, len);
	}
};

//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		string res = "";
//
//		if (0 == strs.size())
//		{
//			return res;
//		}
//
//		string s = strs[0];
//		string tmp;
//		int flag;
//		for (int i = s.size() - 1; i >= 0; i--)
//		{
//			tmp = s.substr(0, i + 1);
//			flag = true;
//			for (int j = 1; j < strs.size(); j++)
//			{
//				if (strs[j].find(tmp) != 0)
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag)
//			{
//				res = tmp;
//				break;
//			}
//		}
//
//		return res;
//	}
//};

//void main()
//{
//	//vector <string> v = {"c","c"};
//	//vector <string> v = { "a"};
//	//vector <string> v = { "ca", "a" };
//	vector <string> v = { "c","acc","ccc"};
//	Solution s;
//	cout << s.longestCommonPrefix(v) << endl;
//}