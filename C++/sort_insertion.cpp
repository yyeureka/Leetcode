#include <vector>
#include <iostream>
using namespace std;

/*
i从1遍历所有元素，对于每一个i，将其插入到正确的位置
*/

void insertion_sort(vector<int> &input) {
	for (int i = 1; i < input.size(); i++) {
		int cur = input[i];
		int pre_idx = i - 1;
		while (pre_idx >= 0 && input[pre_idx] > cur) {
			input[pre_idx + 1] = input[pre_idx];
			pre_idx--;
		}
		input[pre_idx + 1] = cur;
	}
}

//void main() {
//	vector<int> input = { 5,1,4,2,8 };
//	insertion_sort(input);
//	for (int i : input) cout << i << endl;
//}