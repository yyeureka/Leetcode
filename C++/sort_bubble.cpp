#include <vector>
#include <iostream>
using namespace std;

/*
O(n^2) average and worst case runtime. O(1) memory
i从0开始，两两比较交换到n-1
i从0开始，两两比较交换到n-2
…
i从0开始，两两比较交换到1
*/

void bubble_sort(vector<int> &input) {
	for (int i = input.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (input[j] > input[j + 1]) swap(input[j], input[j + 1]);
		}
	}
}

//void main() {
//	vector<int> input = {5,1,4,2,8};
//	bubble_sort(input);
//	for (int i : input) cout << i << endl;
//}