/*
Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.
You code should also return the new length of the string after replacement.
Challenge:
Do it in-place.

Example 1:
Input: string[] = "Mr John Smith" and length = 13
Output: string[] = "Mr%20John%20Smith" and return 17
Explanation:
The string after replacement should be "Mr%20John%20Smith", you need to change the string in-place and return the new length 17.
Example 2:
Input: string[] = "LintCode and Jiuzhang" and length = 21
Output: string[] = "LintCode%20and%20Jiuzhang" and return 25
Explanation:
The string after replacement should be "LintCode%20and%20Jiuzhang", you need to change the string in-place and return the new length 25.

解题思路：
1、i从0遍历array，碰到space，将空格后的所有字符右移两位拷贝，中间填进%20
2、i从0遍历array，碰到space，新length+2
   i从length-1遍历，j从新length-1开始，不是space，放进j位置，是空格，%20放进j位置，时间效率不如方法1
*/

class Solution {
public:
	/*
	* @param string: An array of Char
	* @param length: The true length of the string
	* @return: The true length of new string
	*/
	int replaceBlank(char string[], int length) {
		int i = 0;
		while (i < length) {
			if (' ' == string[i]) {
				for (int j = length - 1; j > i; j--) string[j + 2] = string[j];
				string[i] = '%';
				string[++i] = '2';
				string[++i] = '0';
				length += 2;
			}
			else i++;
		}
		return length;
	}
};

//class Solution {
//public:
//	/*
//	* @param string: An array of Char
//	* @param length: The true length of the string
//	* @return: The true length of new string
//	*/
//	int replaceBlank(char string[], int length) {
//		int i = 0;
//		int new_length = length;
//		while (i < length) {
//			if (' ' == string[i++]) new_length += 2;
//		}
//
//		i = length - 1;
//		int j = new_length - 1;
//		while (i >= 0) {
//			if (' ' == string[i]) {
//				string[j--] = '0';
//				string[j--] = '2';
//				string[j--] = '%';
//				i--;
//			}
//			else {
//				string[j--] = string[i--];
//			}
//		}
//		return new_length;
//	}
//};