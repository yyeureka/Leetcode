#include <vector>
#include <unordered_map>
using namespace std;

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]

解题思路：
1、^所有值，得到重复1次a、b的xor
   获取xor中的某位set bit，即a和b在这个bit分别为0和1
   将所有值根据这个set bit分成两组，两组分别异或将分别得到a和b
2、hash
*/

class Solution {
public:
	vector<int> singleNumberIII(vector<int> &A) {
		int diff = 0;
		vector<int> results(2, 0);

		for (int num : A) {
			diff ^= num;
		}
		diff &= -diff;

		for (int num : A) {
			if (0 == (num & diff)) { //易错 括号不能少
				results[0] ^= num;
			}
			else {
				results[1] ^= num;
			}
		}

		return results;
	}
};

//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums) {
//		vector<int> res;
//		unordered_map<int, int> m;
//		for (int i : nums) {
//			if (m[i] > 0) m.erase(i);
//			else m[i]++;
//		}
//		for (auto i : m) res.push_back(i.first);
//		return res;
//	}
//};