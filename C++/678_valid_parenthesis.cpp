#include <string>
using namespace std;

/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Note:
The string size will be in the range [1, 100].

Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True

解题思路：
以“(**())”为例：
----At step 0: 1
----At step 1: 0, 1, 2
----At step 2: -1, 0, 1或0, 1, 2或1, 2, 3，即为-1,0,1,2,3，-1表示)已经超过(了，这种可能invalid
    最终的可能为0,1,2,3
----At step 3, 1,2,3,4
----At step 4, 0,1,2,3
----At step 5, -1, 0,1,2, -1 invalid，最终为0,1,2.
因为存在0的可能，即该string valid
可能性用low和high即可确定，high<0时表示)过多，失败，最终low>0，(过多，失败
*/

class Solution {
public:
	bool checkValidString(string s) {
		int low = 0;  //treat * as)
		int high = 0; //treat * as (
		for (char c : s) {
			if ('(' == c) {
				low++;
				high++;
			}
			else if (')' == c) {
				low--;
				if (--high < 0) return false;
			}
			else {
				low--;
				high++;
			}
			if (low < 0) low = 0; //舍掉invalid的可能
		}
		return 0 == low;
	}
};