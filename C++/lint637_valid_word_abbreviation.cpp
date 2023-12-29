#include <string>
using namespace std;

/*
Given a non-empty string word and an abbreviation abbr, return whether the string matches with the given abbreviation.
A string such as "word" contains only the following valid abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string word. Any other string is not a valid abbreviation of word.

Example 1:
Input : s = "internationalization", abbr = "i12iz4n"
Output : true
Example 2:
Input : s = "apple", abbr = "a2e"
Output : false

解题思路：straitforward从做到右比较两个string
易错点：
0不能是数字的开头
两个string要一起reach the end：aa，a2是false
*/

class Solution {
public:
	/**
	* @param word: a non-empty string
	* @param abbr: an abbreviation
	* @return: true if string matches with the given abbr or false
	*/
	bool validWordAbbreviation(string &word, string &abbr) {
		int i = 0;
		int j = 0;
		while (j < abbr.size()) {
			if (i >= word.size()) return false;

			if (abbr[j] >= 'a' && abbr[j] <= 'z') {
				if (abbr[j++] != word[i++]) return false;
			}
			else if (abbr[j] >= '1' && abbr[j] <= '9') {
				int num = abbr[j] - '0';
				while (++j < abbr.size() && (abbr[j] >= '0' && abbr[j] <= '9')) {
					num = num * 10 + abbr[j] - '0';
				}
				i += num;
			}
			else return false;
		}
		if (i == word.size()) return true;
		return false;
	}
};