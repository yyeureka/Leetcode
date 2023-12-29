#include <stack>
#include <iostream>
using namespace std;

/*
sort a stack in ascending order, you may use at most one additional stack to hold items

解题思路：
res为ascending order的stack，top为max
input中pop出元素存进tmp，while res中top元素>tmp，将该元素pop出来push进input，处理完input中所有元素
*/

class Solution {
public:
	stack<int> SortStack(stack<int> &input) {
		stack<int> res;
		while (!input.empty()) {
			int tmp = input.top();
			input.pop();
			while (!res.empty() && res.top() > tmp) {
				input.push(res.top());
				res.pop();
			}
			res.push(tmp);
		}
		return res;
	}
};

//void main()
//{
//	Solution s;
//	stack<int> input;
//	input.push(7);
//	input.push(10);
//	input.push(5);
//	input.push(1);
//	input.push(12);
//	input.push(8);
//	input.push(3);
//	stack<int> res = s.SortStack(input);
//	while (!res.empty()) {
//		cout << res.top() << endl;
//		res.pop();
//	}
//}