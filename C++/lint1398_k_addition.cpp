#include <string>
#include <iostream>
using namespace std;

/*
给出一个k，a，b，代表a和b都是一个k进制的数，输出a + b的k进制数。
2 <= k <= 10
a, b均为字符串，长度不超过1000。
可能有前导零

解题思路：a，b可能有前导0，但输出不能有！
*/

#define MAX(a, b)  a > b ? a : b

class Solution {
public:
	/**
	* @param k: The k
	* @param a: The A
	* @param b: The B
	* @return: The answer
	*/
	string addition(int k, string &a, string &b) {
		int i;

		for (i = 0; i < a.size(); i++)
		{
			if (a[i] != '0')
			{
				a = a.substr(i);
				break;
			}
		}

		for (i = 0; i < b.size(); i++)
		{
			if (b[i] != '0')
			{
				b = b.substr(i);
				break;
			}
		}

		if (a.size() < b.size())
		{
			swap(a, b);
		}

		int a_idx = a.size() - 1;
		int b_idx = b.size() - 1;
		int exceed = 0;
		int digit = 0;

		while (a_idx >= 0)
		{
			digit = exceed + (a[a_idx] - '0');
			if (b_idx >= 0)
			{
				digit += (b[b_idx] - '0');
				b_idx--;
			}

			if (digit >= k)
			{
				digit -= k;
				exceed = 1;
			}
			else
			{
				exceed = 0;
			}

			a[a_idx] = '0' + digit;
			a_idx--;
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
//	string a = "0011111111111";
//	string b = "1";
//	int k = 2;
//	Solution s;
//	cout << s.addition(k, a, b) << endl;
//}