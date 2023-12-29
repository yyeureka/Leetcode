#include <vector>
#include <string>
using namespace std;

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

解题思路：
1、dfs排列
2、BFS 从最末尾数字开始回溯
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string combination = "";
        vector<string> result;
        
        helper(letters, digits, combination, result);
        
        return result;
    }
    
    void helper(vector<string> &letters, string &digits, string combination, vector<string> &result) {
        int index = combination.size();
        
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }

        for (char c : letters[digits[index] - '0']) {
            helper(letters, digits, combination + c, result);
        }
        
    }
};

//class Solution {
//public:
//	vector<string> letterCombinations(string digits) {
//		vector<string> res;
//		vector<string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//
//		for (int i = digits.size() - 1; i >= 0; i--) {
//			res = helper(letters[digits[i] - '0'], res);
//		}
//
//		return res;
//	}
//
//	vector<string> helper(string s, vector<string> input) {
//		vector<string> res;
//		for (int i = 0; i < s.size(); i++) {
//			if (input.empty()) {
//				res.push_back(s.substr(i, 1));
//				continue;
//			}
//
//			for (int j = 0; j < input.size(); j++) {
//				res.push_back(s.substr(i, 1) + input[j]);
//			}
//		}
//		return res;
//	}
//};