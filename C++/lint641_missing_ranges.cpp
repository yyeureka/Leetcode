#include <vector>
#include <string>
using namespace std;

/*
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example 1
Input:
nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99
Output:
["2", "4->49", "51->74", "76->99"]
Explanation:
in range[0,99],the missing range includes:range[2,2],range[4,49],range[51,74] and range[76,99]
Example 2
Input:
nums = [0, 1, 2, 3, 7], lower = 0 and upper = 7
Output:
["4->6"]
Explanation:
in range[0,7],the missing range include range[4,6]

解题思路：题不难，顺序遍历就行
易错点：
1、nums为空的时候
2、处理lower和upper边界跟中间节点稍许不同，需要lower--，upper++
3、lower、upper可能为INT_MIN，INT_MAX，使用int会溢出，需要long long
*/

class Solution {
public:
	vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
		vector<string> res;

		int size = nums.size();
		if (!size) {
			add_range(res, (long long)lower - 1, (long long)upper + 1);
			return res;
		}

		add_range(res, (long long)lower - 1, nums[0]);
		for (int i = 1; i < size; i++) {
			add_range(res, nums[i - 1], nums[i]);
		}
		add_range(res, nums[size - 1], (long long)upper + 1);

		return res;
	}

	void add_range(vector<string> &res, long long lower, long long upper) {
		if (upper - lower <= 1) return;
		else if (2 == upper - lower) {
			res.push_back(to_string(lower + 1));
		}
		else {
			res.push_back(to_string(lower + 1) + "->" + to_string(upper - 1));
		}
	}
};