#include <vector>
#include <unordered_map>
using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

解题思路：
用map查找会比再一层for循环快非常多
1. map <int, int> my_map; key为nums[i]，value为在nums中的序号
2. 对每一个num进行查找：map.find(target - nums[i])
   如果找到，成功
   如果未找到，存入map
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(target - nums[i]) != m.end()) return{ m[target - nums[i]], i };
			m[nums[i]] = i;
		}
		return{};
	}
};

//void main()
//{
//	vector <int> numbers = { 15, 12, 17, 11 };
//	int target = 9;
//	Solution s;
//	vector <int> result = s.twoSum(numbers, target);
//	cout << result[0] << ' ' << result[1] << endl;
//}