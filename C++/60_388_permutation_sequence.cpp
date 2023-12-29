#include <vector>
#include <string>
using namespace std;

/*
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"
Example 2:
Input: n = 4, k = 9
Output: "2314"

解题思路：
1、以4、9为例：nums为1234,找以0开始的8th
   digit 1：后3个数字6种排列，idx=8/6=1即为2，nums去掉2
   digit 2：后2个数字2种排列，idx=2/2=1即为3，nums去掉3
   digit 3，后1个数字1种排列，idx=0/1=0即为1，nums去掉1
   digit 4，后0个数字1种排列，idx=0/1=0即为4
2、lexicographically枚举出所有的permutation，返回kth，时间效率很低O(n!)
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		if (n <= 0 || k <= 0) {
			return "";
		}

		string nums = "";
		vector<int> factorial(n, 1); //1,1,2,6,24...
		for (int i = 1; i <= n; i++) {
			nums += i + '0';

			if (i < n) {
				factorial[i] = factorial[i - 1] * i;
			}
		}

		string permutation = "";
		k--;
		for (int i = n - 1; i >= 0; i--) {
			int index = k / factorial[i];
			k %= factorial[i];

			permutation += nums[index];
			nums.erase(index, 1);
		}

		return permutation;
	}
};

//class Solution {
//public:
//	void expand(vector<string> &res, string nums, string s) {
//		if (nums.empty()) {
//			res.push_back(s);
//			return;
//		}
//
//		for (int i = 0; i < nums.size(); i++) {
//			string tmp = nums.substr(i, 1);
//			s += tmp;
//			nums.erase(i, 1);
//			expand(res, nums, s);
//			s.erase(s.size() - 1);
//			nums.insert(i, tmp);
//		}
//	}
//
//	string getPermutation(int n, int k) {
//		vector<string> res;
//		string nums;
//		string s;
//		for (int i = 1; i <= n; i++) nums += i + '0';
//		expand(res, nums, s);
//		return res[k - 1];
//	}
//};