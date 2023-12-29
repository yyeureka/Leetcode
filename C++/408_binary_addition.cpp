#include <string>
#include <iostream>
using namespace std;

/*  
给定两个二进制字符串，返回他们的和（用二进制表示）。
*/

class Solution {
public:
	/**
	* @param a: a number
	* @param b: a number
	* @return: the result
	*/
	string addBinary(string &a, string &b) {
		if (a.size() < b.size())
		{
			swap(a, b);
		}

		int i;
		int b_idx = (b.size() - 1);
		int exceed = 0;
		int digit;
		for (i = (a.size() - 1); i >= 0; i--)
		{
			digit = exceed;
			digit += a[i] - '0';
			if (b_idx >= 0)
			{
				digit += b[b_idx] - '0';
				b_idx--;
			}

			if (digit >= 2)
			{
				digit -= 2;
				exceed = 1;
			}
			else
			{
				exceed = 0;
			}

			a[i] = digit + '0';
		}
		if (exceed != 0)
		{
			a.insert(0, to_string(exceed));
		}
		return a;
	}
};

//void main()
//{
//	string a = "11";
//	string b = "1";
//	Solution s;
//	cout << s.addBinary(a, b) << endl;
//}