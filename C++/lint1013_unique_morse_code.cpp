#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
摩尔斯电码定义了一种标准编码，把每个字母映射到一系列点和短划线。
给出26个字母的完整编码表格：
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
现在给定一个单词列表，每个单词中每个字母可以写成摩尔斯编码。 例如，cab可以写成-.-.-....-，（把c,a,b的莫尔斯编码串接起来）。 我们称之为一个词的转换。
返回所有单词中不同变换的数量。
样例：
输入: words = ["gin", "zen", "gig", "msg"]
输出: 2
解释:
每一个单词的变换是:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
这里有两种不同的变换结果： "--...-."和"--...--.".
*/

string morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

class Solution {
public:
	/**
	* @param words: the given list of words
	* @return: the number of different transformations among all words we have
	*/
	int uniqueMorseRepresentations(vector<string> &words) {
		vector<string> result;
		int i;
		int j;
		string pattern;
		int found;
		int cnt = 0;

		for (i = 0; i < words.size(); i++)
		{
			pattern = "";
			for (j = 0; j < words[i].size(); j++)
			{
				pattern += morse[words[i][j] - 'a'];
			}

			found = false;
			for (j = 0; j < result.size(); j++)
			{
				if (pattern == result[j])
				{
					found = true;
					break;
				}
			}

			if (found)
			{
				continue;
			}
			else
			{
				result.push_back(pattern);
				cnt++;
			}		
		}
		return cnt;
	}
};
//
//void main()
//{
//	//vector<string> words = { "gin", "zen", "gig", "msg" };
//	vector<string> words = { "a", "b" };
//
//	Solution s;
//	cout << s.uniqueMorseRepresentations(words) << endl;
//}