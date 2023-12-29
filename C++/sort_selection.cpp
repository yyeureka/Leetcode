#include <vector>
#include <iostream>
using namespace std;

/*
找0~n-1的min与0交换
将1~n-1的min与1交换
...
将n-2~n-1的min与n-2交换
*/

void selection_sort(vector<int> &input) {
	for (int i = 0; i < input.size() - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < input.size(); j++) {
			if (input[j] < input[min_idx]) min_idx = j;
		}
		swap(input[i], input[min_idx]);
	}
}

//void main() {
//	vector<int> input = {5,1,4,2,8};
//	selection_sort(input);
//	for (int i : input) cout << i << endl;
//}