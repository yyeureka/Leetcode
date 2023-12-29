#include <string>
#include <unordered_map>
using namespace std;

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:
Input: numerator = 2, denominator = 1
Output: "2"
Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (!denominator) return "";
		else if (!numerator || 1 == denominator) return to_string(numerator);
		else if (-1 == denominator) return to_string(-1 * (long long)numerator);

		string res = numerator > 0 == denominator > 0 ? "" : "-";
		long long dividned = abs((long long)numerator); //防止INT_MIN或*10时overflow
		long long divisor = abs((long long)denominator);

		res += to_string(dividned / divisor);
		dividned %= divisor;
		if (!dividned) return res;
		res += ".";

		unordered_map<int, int> m;
		while (dividned) {
			if (m.find(dividned) != m.end()) {
				res.insert(m[dividned], "(");
				res += ")";
				break;
			}
			m[dividned] = res.size();

			dividned *= 10;
			res += to_string(dividned / divisor);
			dividned %= divisor;
		}
		return res;
	}
};